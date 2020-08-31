/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** t2
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_length = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[dest_length + i] = src[i];
    dest[dest_length + i] = '\0';

    return dest;
}
