/*
** EPITECH PROJECT, 2019
** check_o.c
** File description:
** checking o's
*/

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

int o_count(map_t *map)
{
    int i = 0;
    int o = 0;
    while (map->old[i] != '\0') {
        if (map->old[i] == 'O')
            o++;
        i++;
    }
    return (o);
}

void make_o(map_t *map)
{
    int i = 0;
    int c = 0;
    map->o = malloc(sizeof(int) * (o_count(map) + 1));
    while (map->old[i] != '\0') {
        if (map->old[i] == 'O') {
            map->o[c] = i;
            c++;
        }
        i++;
    }
    map->o[c] = -1;
}

void check_o(map_t *map)
{
    int i = 0;
    while (map->o[i] != -1) {
        if (map->buff[map->o[i]] == ' ')
            map->buff[map->o[i]] = 'O';
        i++;
    }
}
