/*
** EPITECH PROJECT, 2024
** fractals.h
** File description:
** Utils for fractals
*/

#ifndef FRACTALS_H_
    #define FRACTALS_H_
    #include <unistd.h>
    #include <stdlib.h>

typedef struct parsed_pattern {
    char **lines;
    size_t width;
    size_t height;
} patern;

typedef struct fractal_table {
    char **fractal;
    size_t width;
    size_t height;
    patern black;
    patern white;
} frac;

frac *prepare_fractals(size_t size, char *black, char *white);
void destroy_fractal(frac *f);
void print_str_array(char **arr);

#endif
