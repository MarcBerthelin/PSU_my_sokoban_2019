/*
** EPITECH PROJECT, 2019
** make_struct.c
** File description:
** making the structure
*/

#include "struct.h"
#include "my.h"

void make_struct(map_t *map)
{
    map->key = 0;
    map->block = 0;
    set_x(map);
    make_o(map);
}
