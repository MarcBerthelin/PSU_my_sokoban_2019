/*
** EPITECH PROJECT, 2019
** my_h.c
** File description:
** coding the -h
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

void my_putstr_carr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    my_putchar('\n');
}

int my_h(char *str)
{
    if (str[0] == '-' && str[1] == 'h') {
        my_putstr_carr("USAGE");
        my_putstr_carr("     ./my_sokoban map");
        my_putstr("DESCRIPTION\n");
        my_putstr("     map  file representing the warehouse map, ");
        my_putstr_carr("containing '#' for walls, ");
        my_putstr("         ‘P’ for the player, ");
        my_putstr("‘X’ for boxes and ‘O’ ");
        my_putstr_carr("for storage locations.");
        return (1);
    }
    return (0);
}
