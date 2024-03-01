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
    partern black;
    partern white;
} frac;

#endif
