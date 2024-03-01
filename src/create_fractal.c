/*
** EPITECH PROJECT, 2024
** create_fractal.c
** File description:
** Create the fractal it self
*/

#include "../include/my.h"
#include "../include/fractals.h"

static void draw_pattern(frac *f, partern *p, size_t x_offset, size_t y_offset)
{
    for (size_t y = 0; y < p->height; y ++) {
        for (size_t x = 0; x < p->width; x ++) {
            f->fractal[y_offset + y][x_offset + x] = patern->lines[y][x];
        }
    }
}

static void divide_table(frac *f, rect *container, size_t depth, int black)
{
    rect r = {0, 0, container->width / f->black.width,
        container->height / f->black.height};
    patern *p = (black) ? &f->black : &f->white;

    if (depth == 1) {
        draw_pattern(f, p, container->x, container->y);
        return;
    }
    for (size_t y = 0; y < f->black.height; y ++) {
        for (size_t x = 0; x < f->black.width; x ++) {
            r.x = container.x + (x * frac->black.width);
            r.y = container.y + (y * frac->black.height);
            divide_table(f, &r, depth - 1,
                p->lines[y][x] == '#');
        }
    }
}

void create_fractal(frac *f)
{
    rect r = {0, 0, f->width, f->height};

    if (f->depth == 0) {
        f->fractal[0][0] = f->black.lines[0][0];
        return ;
    }
    divide_table(f, &r, f->depth, 1);
}
