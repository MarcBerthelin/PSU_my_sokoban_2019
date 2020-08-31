/*
** EPITECH PROJECT, 2019
** defeat.c
** File description:
** handling loss condition
*/

#include "struct.h"
#include <stdio.h>
#include <ncurses.h>

int calc_prev_line(map_t *map, int pos)
{
    int line = 0;
    while (map->buff[pos] != '\n' && pos > 1)
        pos--;
    while (map->buff[pos - 1] != '\n' && pos > 1) {
        line++;
        pos--;
    }
    line++;
    return (line);
}

int calc_curr_lin(map_t *map, int pos)
{
    int line = 0;
    while (map->buff[pos] != '\n')
        pos--;
    while (map->buff[pos + 1] != '\n' && map->buff[pos + 1] != '\0') {
        line++;
        pos++;
    }
    line++;
    return (line);
}

void check_block(map_t *map, int pos)
{
    int wall = 0;
    int c_line = calc_curr_lin(map, pos);
    int p_line = calc_prev_line(map, pos);
    if (map->buff[pos + 1] == '#' || map->buff[pos + 1] == 'X')
        wall += 1;
    if (map->buff[pos - 1] == '#' || map->buff[pos - 1] == 'X')
        wall += 1;
    if (map->buff[pos + c_line] == '#' || map->buff[pos + c_line] == 'X')
        wall += 2;
    if (map->buff[pos - p_line] == '#' || map->buff[pos - p_line] == 'X')
        wall += 2;
    if (wall == 3 || wall >= 5)
        map->block++;
}

int count_x(map_t *map)
{
    int i = 0;
    int box = 0;
    while (map->buff[i] != '\0') {
        if (map->buff[i] == 'X')
            box++;
        i++;
    }
    return (box);
}

void loss(map_t *map)
{
    int i = 0;
    while (map->buff[i] != '\0') {
        if (map->buff[i] == 'X') {
            check_block(map, i);
        }
        i++;
    }
    i = count_x(map);
    if (i == map->block)
        map->key = 27;
    map->block = 0;
}
