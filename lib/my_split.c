/*
** EPITECH PROJECT, 2024
** my_split.c
** File description:
** Split strings
*/

#include "../include/my.h"

static void *my_memcpy(void *dest, const void *src, size_t n)
{
    size_t i = 0;
    char *destchr = dest;
    const char *srcchr = src;

    if (dest == NULL && src == NULL)
        return (NULL);
    while (i < n){
        destchr[i] = srcchr[i];
        i ++;
    }
    return (dest);
}

static void *my_memset(void *b, int c, size_t len)
{
    size_t i = 0;
    char *strint = b;

    while (i < len){
        strint[i] = c;
        i ++;
    }
    return (b);
}

static char *find_next_start(const char *str, char delimiter)
{
    size_t i = 0;

    while (str[i] != 0){
        if (str[i] != delimiter)
            break;
        i ++;
    }
    return ((char *)str + i);
}

static char *find_next_end(const char *str, char delimiter)
{
    size_t i = 0;

    while (str[i] != 0){
        if (str[i] == delimiter)
            break;
        i ++;
    }
    return ((char *)str + i);
}

static int word_count(const char *str, char delimiter)
{
    int i = 0;

    while (*str != 0){
        str = find_next_start(str, delimiter);
        str = find_next_end(str, delimiter);
        if (*str != 0 || *(str - 1) != delimiter)
            i ++;
    }
    return (i);
}

static char **free_string_array(char **result)
{
    int i = 0;

    if (result == NULL)
        return (NULL);
    while (result[i]){
        free(result[i]);
        i ++;
    }
    free(result);
    return (NULL);
}

char **my_split(char const *s, char c)
{
    int i = 0;
    int n = word_count(s, c);
    char **result = malloc(sizeof(char *) * (n + 1));
    char *end;

    if (result == NULL)
        return (NULL);
    my_memset(result, 0, sizeof(char *) * (n + 1));
    while (i < n){
        s = find_next_start(s, c);
        end = find_next_end(s, c);
        result[i] = malloc(sizeof(char) * (end - s + 1));
        if (result[i] == NULL)
            return (free_string_array(result));
        my_memcpy(result[i], s, end - s);
        result[i][end - s] = 0;
        i ++;
        s = end;
    }
    return (result);
}
