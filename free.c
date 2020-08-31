/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** using free
*/

#include "struct.h"
#include <stdlib.h>

void clear_mem(map_t *map)
{
    free(map->buff);
    free(map->o);
    free(map->old);
}
