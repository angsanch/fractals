/*
** EPITECH PROJECT, 2024
** fractlas stumper1
** File description:
** main funct
*/

#include "../include/my.h"
#include "../include/fractals.h"

void print_str_array(char **a)
{
    size_t i = 0;

    while (a[i] != NULL){
        my_dputstr(1, a[i]);
        my_putchar('\n');
        i++;
    }
}

int main(int argc, char **argv)
{
    frac_t *f;

    if (argc != 4){
        my_dputstr(2, "Invalid amount of arguments.\n");
        return (84);
    }
    f = prepare_fractal(my_getnbr(argv[1]), argv[2], argv[3]);
    if (f == NULL)
        return (84);
    create_fractal(f);
    print_str_array(f->fractal);
    destroy_fractal(f);
    return (0);
}
