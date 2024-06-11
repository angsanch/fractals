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
} patern_t;

typedef struct fractal_table {
    char **fractal;
    size_t width;
    size_t height;
    patern_t black;
    patern_t white;
    size_t depth;
} frac_t;

typedef struct rectangle_data {
    size_t x;
    size_t y;
    size_t width;
    size_t height;
} rect_t;

//Sofia's zone
frac_t *prepare_fractal(size_t nb, char *black, char *white);
void destroy_fractal(frac_t *f);
void print_str_array(char **arr);

//Dani's
void create_fractal(frac_t *c);
#endif
