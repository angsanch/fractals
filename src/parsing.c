/*
** EPITECH PROJECT, 2024
** duostumper01
** File description:
** parsing the patterns
*/

#include "../include/fractals.h"
#include "../include/my.h"

static int pat_lines_len(char **lines)
{
    int i = 0;

    while (lines[i] != NULL){
	if (my_str_len(lines[i]) != my_str_len(lines[i + 1])){
	    my_dputstr(2, "Error, pattern is not a rectangular len length.\n");
	    return (-1);
	}
	i++;
    }
    return (my_strlen(lines[1]);
}

static int init_pattern(pattern *p, char *raw)
{
    int l = 0;
    int h = 0;
    int i = 0;

    for (int i = 0; p[i] != '\0'; i++){
	if (p[i] != '#' || p[i] != '@' || p[i] != '.'){
	    my_dputstr(2, "Error, invalid characters in pattern.\n");
	    return (-1);
	}
	if (p[i] == '@' && p[i + 1] == '@'){
	    my_dputstr(2, "Error, invalid characters in patter (two '@'s back together).\n");
	    return (-1);
	}
	if (p[i] == '@')
	    l++;
    }
    p->lines = my_split(raw, '@');
    p->height = l + 1;
    p->width = pat_lines_len(p->lines);
    return (0);
}

frac *prepare_fractal(size_t size, int nb, char *black, char *white)
{
    frac *f = malloc(sizeof(frac));
    int height = 0;

    if (f == NULL)
	return (NULL);
    init_patern(&f->black, black);
    init_patern(&f->white, white);
    f->depth = nb;
    f->height = my_compute_power_rec(&f->black.height, nb);
    f->width = my_compute_power_rec(&f->black.width, nb);
    return 0;
}

static void free_str_array(char **a)
{
    for (int i = 0; a[i] != NULL; i++)
	free(a[i]);
    free(a);
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
