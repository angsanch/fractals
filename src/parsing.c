/*
** EPITECH PROJECT, 2024
** duostumper01
** File description:
** parsing the patters
*/

#include "../include/fractals.h"
#include "../include/my.h"

static int first_len(char *p)
{
    int i = 0;

    while (p[i] != '@'){
	i++;
    }
    return (i);
}

static pat_lines(char *p)
{
    
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
    p->height = l + 1;
    p->width = first_len(p);
    return (0);
}

frac *prepare_fractal(size_t size, char *black, char *white)
{
    frac *f = malloc(sizeof(frac));
    if (f == NULL)
	return (NULL);
    init_patern(&f->black, black);
    init_patern(&f->white, white);
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

void print_str_array()
{
    //
}
