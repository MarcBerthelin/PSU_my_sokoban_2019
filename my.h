/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** contains all functions
*/

#include <stddef.h>

size_t read_size(char *);
int make_map(map_t *);
int calc_up(map_t *);
int calc_down(map_t *);
int calc_up_x(map_t *);
int calc_down_x(map_t *);
void movement(map_t *);
int move_up(map_t *);
int move_right(map_t *);
int move_down(map_t *);
int move_left(map_t *);
int move_x_right(map_t *);
int move_x_left(map_t *);
int move_x_up(map_t *);
int move_x_down(map_t *);
void check_o(map_t *);
void make_o(map_t *);
int o_count(map_t *);
int my_h(char *);
char *my_strdup(char *);
void make_struct(map_t *);
void set_x(map_t *);
void loss(map_t *);
void clear_mem(map_t *);
int count_char(map_t *);
