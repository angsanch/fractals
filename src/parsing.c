/*
** EPITECH PROJECT, 2024
** duostumper01
** File description:
** parsing the patterns
*/

#include "../include/fractals.h"
#include "../include/my.h"

static size_t pat_lines_len(char **lines)
{
    int i = 1;
    size_t len;

    if (lines[0] == NULL)
        return (0);
    len = my_str_len(lines[0]);
    while (lines[i] != NULL){
        if (my_str_len(lines[i]) != len){
            my_dputstr(2, "Error, pattern is not a rectangular len length.\n");
            return (-1);
        }
        i++;
    }
    return (len);
}

static int init_patern(patern *p, char *raw)
{
    int l = 0;
    int i;

    for (i = 0; raw[i] != '\0'; i++){
        if (raw[i] != '#' && raw[i] != '@' && raw[i] != '.'){
            my_dputstr(2, "Error, invalid characters in pattern.\n");
            return (-1);
        }
        if (raw[i] == '@' && raw[i + 1] == '@'){
            my_dputstr(2, "Error, invalid characters in pattern " \
                "(two '@'s together).\n");
            return (-1);
        }
        if (raw[i] == '@')
            l++;
    }
    if (raw[0] == '@' || raw[i - 1] == '@') {
        my_dputstr(2, "Error, '@' cant be at the begining or the end.\n");
        return (-1);
    }
    p->lines = my_split(raw, '@');
    if (p->lines == NULL) {
        my_dputstr(2, "Not enough memory\n");
        return (-1);
    }
    p->height = l + 1;
    p->width = pat_lines_len(p->lines);
    return (0);
}

static void free_str_array(char **a)
{
    if (a == NULL)
        return;
    for (int i = 0; a[i] != NULL; i++)
        free(a[i]);
    free(a);
}

static char **create_str_array(size_t width, size_t height)
{
    char **s = malloc(sizeof(char *) * (height + 1));

    if (s == NULL)
        return (NULL);
    s[0] = NULL;
    for (size_t i = 0; i < height; i ++) {
        s[i + 1] = NULL;
        s[i] = malloc(sizeof(char) * (width + 1));
        if (s[i] == NULL) {
            free_str_array(s);
            return (NULL);
        }
        s[i][width] = '\0';
    }
    return (s);
}

frac *prepare_fractal(size_t nb, char *black, char *white)
{
    frac *f = malloc(sizeof(frac));

    if (f == NULL)
        return (NULL);
    if (init_patern(&f->black, black) == -1 ||
        init_patern(&f->white, white) == -1) {
        destroy_fractal(f);
        return (NULL);
    }
    if (f->black.width != f->white.width ||
        f->black.height != f->white.height) {
        my_dputstr(2, "Error, pattern sizes are not the same.\n");
        destroy_fractal(f);
        return (NULL);
    }
    f->depth = nb;
    f->height = my_compute_power_rec(f->black.height, nb);
    f->width = my_compute_power_rec(f->black.width, nb);
    create_str_array(f->width, f->height);
    return 0;
}

void destroy_fractal(frac *f)
{
    if (f == NULL)
    return;
    free_str_array(f->fractal);
    free_str_array(f->black.lines);
    free_str_array(f->white.lines);
    free(f);
}
