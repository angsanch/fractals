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

int my_putstr(int fd, char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(fd, str + i, 1);
        i ++;
    }
    return (0);
}

int my_str_len(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

static int my_isnumeric(char c)
{
    return (c >= '0' && c <= '9');
}

int my_getnbr(char const *str)
{
    long result = 0;
    long n;
    int i = 0;
    int multiplicator = 1;

    while (!my_isnumeric(str[i])){
        if (str[i] != '+' && str[i] != ' ' && str[i] != '-')
            return (0);
        if (str[i] == '-')
            multiplicator *= -1;
        i ++;
    }
    while (my_isnumeric(str[i])){
        result = result * 10 + (str[i] - '0');
        n = result * multiplicator;
        if (n > 2147483647 || n < -2147483648)
            return (0);
        i ++;
    }
    return (result * multiplicator);
}
