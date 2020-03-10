/*
** EPITECH PROJECT, 2019
** step2.c
** File description:
** step 2
*/

#include "my.h"

int first_step(int ac, char **av)
{
    int count = 0;
    char c = av[ac][0];

    my_strlowcase(av[1]);
    my_strlowcase(av[ac]);
    for (int i = 0; av[1][i] != '\0'; i++)
        if (av[1][i] == av[ac][0])
            count++;
    if (ac > 2)
        first_step(ac - 1, av);
    my_putchar(c);
    my_putchar(':');
    my_put_nbr(count);
    my_putchar('\n');
    return (0);
}

int first_error_gest(int ac, char **av)
{
    if (ac < 3)
        return (-1);
    for (int i = 2; i < ac; i++) {
        if (av[i][0] < 'A' || (av[i][0] > 'Z'
                                && av[i][0] < 'a') || av[i][0] > 'z')
            return (-1);
        if (av[i][1] != '\0')
            return (-1);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (first_error_gest(ac, av) == -1)
        return (84);
    return (first_step(ac - 1, av));
}
