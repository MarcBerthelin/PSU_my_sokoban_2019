/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** checking errors
*/

#include "struct.h"
#include <stdio.h>

int check_char(map_t *map)
{
    for (int i = 0; map->buff[i] != '\0'; i++) {
        if (map->buff[i] != ' ' && map->buff[i] != 'P' &&
            map->buff[i] != '#' && map->buff[i] != 'X' && map->buff[i] != 'O' &&
            map->buff[i] != '\n' && map->buff[i] != '\0')
            return (84);
    }
    return (0);
}

int count_char(map_t *map)
{
    if (check_char(map) == 84)
        return (84);
    int p = 0;
    int x = 0;
    int o = 0;
    for (int i = 0; map->buff[i] != '\0'; i++) {
        if (map->buff[i] == 'P')
            p++;
        if (map->buff[i] == 'X')
            x++;
        if (map->buff[i] == 'O')
            o++;
    }
    if (p != 1 || o != x)
        return (84);
    return (0);
}
