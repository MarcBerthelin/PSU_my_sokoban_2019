/*
** EPITECH PROJECT, 2019
** my_strncat.c
** File description:
** t3
*/

#include <string.h>
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_length = my_strlen(dest);
    int i;

    for (i = 0 ; i < nb && src[i] != '\0' ; i++)
        dest[dest_length + i] = src[i];
    dest[dest_length + i] = '\0';

    return dest;
}
