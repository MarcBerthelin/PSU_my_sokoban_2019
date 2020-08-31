/*
** EPITECH PROJECT, 2019
** movement.c
** File description:
** moving characters
*/

#include <fcntl.h>
#include <ncurses.h>
#include "struct.h"
#include "my.h"
#include <stdlib.h>

int move_left(map_t *map)
{
    if (move_x_left(map) != 0)
        return (1);
    if (map->buff[map->x - 1] != '#') {
        map->buff[map->x] = ' ';
        map->x -= 1;
        map->buff[map->x] = 'P';
        check_o(map);
        mvprintw(0, 0, "%s", map->buff);
    }
    return (0);
}

int move_down(map_t *map)
{
    int down = calc_down(map);

    if (move_x_down(map) != 0)
        return (1);
    if (map->buff[map->x + down] != '#') {
        map->buff[map->x] = ' ';
        map->x += down;
        map->buff[map->x] = 'P';
        check_o(map);
        mvprintw(0, 0, "%s", map->buff);
    }
    return (0);
}

int move_right(map_t *map)
{
    if (move_x_right(map) != 0)
        return (1);
    if (map->buff[map->x + 1] != '#') {
        map->buff[map->x] = ' ';
        map->x += 1;
        map->buff[map->x] = 'P';
        check_o(map);
        mvprintw(0, 0, "%s", map->buff);
    }
    return (0);
}

int move_up(map_t *map)
{
    int up = calc_up(map);

    if (move_x_up(map) != 0)
        return (1);
    if (map->buff[map->x - up] == ' ' || map->buff[map->x - up] == 'O') {
        map->buff[map->x] = ' ';
        map->x -= up;
        map->buff[map->x] = 'P';
        check_o(map);
        mvprintw(0, 0, "%s", map->buff);
    }
    return (0);
}

void movement(map_t *map)
{
    switch(map->key) {
    case 260:
        move_left(map);
        break;
    case 259:
        move_up(map);
        break;
    case 261:
        move_right(map);
        break;
    case 258:
        move_down(map);
        break;
    case 32:
        free(map->buff);
        map->x = map->save_x;
        map->buff = my_strdup(map->old);
        mvprintw(0, 0, "%s", map->buff);
        break;
    }
}
