/*
** EPITECH PROJECT, 2019
** movement_x.c
** File description:
** moving boxes
*/

#include <fcntl.h>
#include <ncurses.h>
#include "struct.h"
#include "my.h"

int move_x_right(map_t *map)
{
    if (map->buff[map->x + 1] == 'X' &&
    (map->buff[map->x + 2] != '#' && map->buff[map->x + 2] != 'X')) {
        map->buff[map->x + 2] = 'X';
        map->x += 1;
        map->buff[map->x] = 'P';
        map->buff[map->x - 1] = ' ';
        check_o(map);
        mvprintw(0, 0, "%s", map->buff);
        return (1);
    }
    if (map->buff[map->x + 1] == 'X' &&
    (map->buff[map->x + 2] == '#' || map->buff[map->x + 2] == 'X'))
        return (2);
    return (0);
}

int move_x_left(map_t *map)
{
    if (map->buff[map->x - 1] == 'X' &&
    (map->buff[map->x - 2] != '#' && map->buff[map->x - 2] != 'X')) {
        map->buff[map->x - 2] = 'X';
        map->x -= 1;
        map->buff[map->x] = 'P';
        map->buff[map->x + 1] = ' ';
        check_o(map);
        mvprintw(0, 0, "%s", map->buff);
        return (1);
    }
    if (map->buff[map->x - 1] == 'X' &&
    (map->buff[map->x - 2] == '#' || map->buff[map->x - 2] == 'X'))
        return (2);
    return (0);
}

int move_x_up(map_t *map)
{
    int up = calc_up(map);
    int up_x = calc_up_x(map);
    int checkw = up + up_x;
    if (map->buff[map->x - up] == 'X' &&
    (map->buff[map->x - checkw] != '#' && map->buff[map->x - checkw] != 'X')) {
        map->buff[map->x] = ' ';
        map->buff[map->x - checkw] = 'X';
        map->x -= up;
        map->buff[map->x] = 'P';
        check_o(map);
        mvprintw(0, 0, "%s", map->buff);
        return (1);
    }
    if (map->buff[map->x - up] == 'X' &&
    (map->buff[map->x - checkw] == '#' || map->buff[map->x - checkw] == 'X'))
        return (2);
    return (0);
}

int move_x_down(map_t *map)
{
    int down = calc_down(map);
    int down_x = calc_down_x(map);
    int checkw = down + down_x;
    if (map->buff[map->x + down] == 'X' &&
    (map->buff[map->x + checkw] != '#' && map->buff[map->x + checkw] != 'X')) {
        map->buff[map->x] = ' ';
        map->buff[map->x + checkw] = 'X';
        map->x += down;
        map->buff[map->x] = 'P';
        check_o(map);
        mvprintw(0, 0, "%s", map->buff);
        return (1);
    }
    if (map->buff[map->x + down] == 'X' &&
    (map->buff[map->x + checkw] == '#' || map->buff[map->x + checkw] == 'X'))
        return (2);
    return (0);
}
