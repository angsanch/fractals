/*
** EPITECH PROJECT, 2024
** rostring stumper05
** File description:
** headerfile
*/

#ifndef STUMPER_01_
    #define STUMPER_01_

    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <errno.h>
    #include <stddef.h>

void my_putchar(char c);
int my_dputstr(int fd, char const *str);
int my_str_len(char const *str);
int my_getnbr(char const *str);
char **my_split(char const *s, char c);
int my_compute_power_rec(int nb, int p);


#endif
