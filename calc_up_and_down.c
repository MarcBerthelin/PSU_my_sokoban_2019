/*
** EPITECH PROJECT, 2019
** calc_up_and_down.c
** File description:
** calculating movement up and down
*/

#include "struct.h"
#include "my.h"

int calc_up(map_t *map)
{
    int y = map->x;
    int line = 0;
    while (map->buff[y] != '\n' && y > 1)
        y--;
    while (map->buff[y - 1] != '\n' && y > 1) {
        line++;
        y--;
    }
    line++;
    return (line);
}

int calc_down(map_t *map)
{
    int y = map->x;
    int line = 0;
    while (map->buff[y] != '\n')
        y--;
    while (map->buff[y + 1] != '\n' && map->buff[y + 1] != '\0') {
        line++;
        y++;
    }
    line++;
    return (line);
}

int calc_up_x(map_t *map)
{
    int up = calc_up(map);
    int save = map->x;
    int up_x = 0;
    map->x -= up;
    up_x = calc_up(map);
    map->x = save;
    return (up_x);
}

int calc_down_x(map_t *map)
{
    int down = calc_down(map);
    int save = map->x;
    int down_x = 0;
    map->x += down;
    down_x = calc_down(map);
    map->x = save;
    return (down_x);
}
