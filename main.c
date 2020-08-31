/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** starting the game
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ncurses.h>
#include "struct.h"
#include "my.h"

void set_x(map_t *map)
{
    map->x = 0;
    while (map->buff[map->x] != 'P')
        map->x++;
    map->save_x = map->x;
}

void count_o(map_t *map)
{
    map->cheat = 0;
    int i = 0;
    while (map->old[i] != '\0') {
        if (map->old[i] == 'O' && map->buff[i] == 'P') {
            map->cheat = 1;
            break;
        }
        i++;
    }
}

int count_ob(map_t *map)
{
    int i = 0;
    int o = 0;
    while (map->old[i] != '\0') {
        if (map->buff[i] == 'O')
            o++;
        i++;
    }
    return (o);
}

void win(map_t *map)
{
    int ob = count_ob(map);
    count_o(map);
    if (ob == 0 && map->cheat == 0)
        map->key = 27;
}

int main(__attribute__((unused)) int argc, char **argv)
{
    map_t map;
    map.txt = argv[1];
    if (my_h(argv[1]) == 1)
        return (0);
    if (make_map(&map) == 84 || count_char(&map) == 84)
        return (84);
    make_struct(&map);
    initscr();
    keypad(stdscr, TRUE);
    mvprintw(0, 0, "%s", map.buff);
    while (map.key != 27) {
        map.key = getch();
        movement(&map);
        loss(&map);
        win(&map);
    }
    refresh();
    clear_mem(&map);
    endwin();
    return (0);
}
