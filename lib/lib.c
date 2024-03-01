/*
** EPITECH PROJECT, 2024
** duostumper01
** File description:
** libfuncts
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int l = 0;

    while (str[l] != '\0') {
        my_putchar(str[l]);
        l++;
    }
    return (0);
}

int my_put_nbr(int nb)
{
    unsigned int n;
    char c;

    n = nb;
    if (nb < 0){
        n = -nb;
        c = '-';
        write(1, &c, 1);
    }
    if (nb == 0){
        c = '0';
        write(1, &c, 1);
        return (0);
    }
}

int my_str_len(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
	i++;
    return (i);
}
