/*
** EPITECH PROJECT, 2019
** detect_language.c
** File description:
** step4
*/

#include "my.h"
#include "struct.h"

#define ABS(value) (((value) > 0) ? (value) : (-value))

int my_count_size(double one, double two, double three, double four)
{
    int i = 0;

    if (one > two)
        i++;
    if (one > three)
        i++;
    if (one > four)
        i++;
    return (i);
}

void print_language(int *prt)
{
    if (my_count_size(prt[0], prt[1], prt[2], prt[3]) == 0) {
        my_putstr("=> English\n");
        return;
    }
    if (my_count_size(prt[1], prt[2], prt[3], prt[0]) == 0) {
        my_putstr("=> French\n");
        return;
    }
    if (my_count_size(prt[2], prt[3], prt[0], prt[1]) == 0) {
        my_putstr("=> German\n");
        return;
    }
    if (my_count_size(prt[3], prt[0], prt[1], prt[2]) == 0) {
        my_putstr("=> Spanish\n");
        return;
    }
}

void my_counter_language(lang_t lang, int stock, int *prt, int nb)
{
    double en = ABS(lang.eng[nb] - stock);
    double fr = ABS(lang.fra[nb] - stock);
    double ge = ABS(lang.ger[nb] - stock);
    double es = ABS(lang.spa[nb] - stock);

    prt[0] = prt[0] + my_count_size(en, fr, ge, es);
    prt[1] = prt[1] + my_count_size(fr, ge, es, en);
    prt[2] = prt[2] + my_count_size(ge, es, en, fr);
    prt[3] = prt[3] + my_count_size(es, en, fr, ge);
}

void check_language(lang_t lang, char *str, int *prt, int nb)
{
    int count = 0;
    int len = 0;
    double stock = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            len++;
        if (str[i] == 'a' + nb)
            count++;
    }
    stock = count * 100;
    stock = stock / len;
    my_counter_language(lang, stock, prt, nb);
    if (nb < 26)
        check_language(lang, str, prt, nb + 1);
}

int detect_language(char *str)
{
    int prt[] = {0, 0, 0, 0};
    lang_t lang = {{8.167, 1.492, 2.789, 4.253, 12.702, 2.228, 2.015, 6.094,
    6.966, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987,
    6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074}, {7.636, 0.901,
    3.260, 3.669, 14.715, 1.066, 0.866, 0.737, 7.529, 0.613, 0.074, 5.456,
    2.968, 7.095, 5.796, 2.521, 1.362, 6.693, 7.948, 7.244, 6.311, 1.838,
    0.049, 0.427, 0.128, 0.326}, {6.516, 1.886, 2.732, 5.076, 16.396, 1.656,
    3.009, 4.577, 6.550, 0.268, 1.417, 3.437, 2.534, 9.776, 2.594, 0.670,
    0.018, 7.003, 7.270, 6.154, 4.166, 0.846, 1.921, 0.034, 0.039, 1.134},
    {11.525, 2.215, 4.019, 5.010, 12.181, 0.692, 1.768, 0.703, 6.247, 0.493,
    0.011, 4.967, 3.157, 6.712, 8.683, 2.510, 0.877, 6.871, 7.977, 4.632, 2.927,
    1.138, 0.017, 0.215, 1.008, 0.467}};

    check_language(lang, str, prt, 0);
    print_language(prt);
    return (0);
}
