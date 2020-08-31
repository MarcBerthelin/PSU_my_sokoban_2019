/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** t1
*/

#include "my.h"

int my_putstr(char const *str)
{
    int counter = 0;
    while (str[counter] != '\0')
    {

        my_putchar(str[counter]);
        counter++;
    }
}
