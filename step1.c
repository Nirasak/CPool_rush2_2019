/*
** EPITECH PROJECT, 2019
** step1.c
** File description:
** step1
*/

#include "my.h"

int first_step(char **av)
{
    int count = 0;
    char c = av[2][0];

    my_strlowcase(av[1]);
    my_strlowcase(av[2]);
    for (int i = 0; av[1][i] != '\0'; i++)
        if (av[1][i] == av[2][0])
            count++;
    my_putchar(c);
    my_putchar(':');
    my_put_nbr(count);
    my_putchar('\n');
    return (0);
}

int first_error_gest(int ac, char *str)
{
    if (ac != 3)
        return (-1);
    if (str[0] < 'A' || (str[0] > 'Z' && str[0] < 'a') || str[0] > 'z')
        return (-1);
    if (str[1] != '\0')
        return (-1);
    return (0);
}

int main(int ac, char **av)
{
    if (first_error_gest(ac, av[2]) == -1)
        return (84);
    return (first_step(av));
}
