/*
** EPITECH PROJECT, 2021
** gameplay
** File description:
** gameplay
*/

#include "../include/my_sokoban.h"

static int get_pos_x(char **map, char c)
{
    for (int i = 0, j; map[i] != NULL; i++) {
        for (j = 0; map[i][j] != '\0' && map[i][j] != c; j++);
        if (map[i][j] == c)
            return (i);
    }
    return (-1);
}

static int get_pos_y(char **map, char c)
{
    for (int i = 0, j; map[i] != NULL; i++) {
        for (j = 0; map[i][j] != '\0' && map[i][j] != c; j++);
        if (map[i][j] == c)
            return (j);
    }
    return (-1);
}

char **restart_map(char **map, char **save, int const *p)
{
    if (p[0] == -1)
        return (map);
    for (int i = 1, j = 0; map[i] != NULL; j += 1) {
        map[i][j] = save[i][j];
        if (map[i][j] == '\0') {
            i += 1;
            j = 0;
        }
    }
    return (map);
}

char **gameplay(char **map, char **save, int key)
{
    int p[] = {get_pos_x(map, 'P'), get_pos_y(map, 'P')};

    for (int i = 0; i < tab_size; i += 1) {
        if (key == tab[i].key)
            tab[i].mv(map, save, p);
    }
    return (map);
}