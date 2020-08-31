/*
** EPITECH PROJECT, 2019
** make_map.c
** File description:
** creating the map
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include "struct.h"
#include "my.h"
#include "lib/my/my.h"

size_t read_size(char *txt)
{
    struct stat filestat;
    if (stat(txt, &filestat) != 0)
        return (0);
    return (filestat.st_size);
}

char *my_strdup(char *str)
{
    int i = 0;
    char *dest = malloc(my_strlen(str) + 1);
    for (;str[i]; dest[i] = str[i], i++);
    dest[i] = '\0';
    return (dest);
}

int make_map(map_t *map)
{
    int fd = 0;
    map->size = read_size(map->txt);
    map->buff = malloc(sizeof(char) * (map->size + 1));
    fd = open(map->txt, O_RDONLY);
    if (fd == -1)
        return (84);
    read(fd, map->buff, map->size);
    map->buff[map->size] = '\0';
    map->old = my_strdup(map->buff);
    close(fd);
    return (0);
}
