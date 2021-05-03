/*
** EPITECH PROJECT, 2021
** movement
** File description:
** movement
*/

#include "../include/my_sokoban.h"

static char **check_o(char **map, char **save)
{
    for (int i = 1, j = 0; map[i] != NULL; j += 1) {
        if (map[i][j] == ' ' && save[i][j] == 'O')
            map[i][j] = 'O';
        if (map[i][j] == '\0') {
            i += 1;
            j = 0;
        }
    }
    return (map);
}

char **mv_right(char **map, char **save, int const *pos)
{
    int x = pos[0];
    int y = pos[1];

    if (map[x][y + 1] == 'X' && map[x][y + 2] != '#' && map[x][y + 2] != 'X') {
        map[x][y] = ' ';
        map[x][y + 1] = 'P';
        map[x][y + 2] = 'X';
    }
    if (map[x][y + 1] == ' ' || map[x][y + 1] == 'O') {
        map[x][y] = ' ';
        map[x][y + 1] = 'P';
    }
    return (check_o(map, save));
}

char **mv_left(char **map, char **save, int const *pos)
{
    int x = pos[0];
    int y = pos[1];

    if (map[x][y - 1] == 'X' && map[x][y - 2] != '#' && map[x][y - 2] != 'X') {
        map[x][y] = ' ';
        map[x][y - 1] = 'P';
        map[x][y - 2] = 'X';
    }
    if (map[x][y - 1] == ' ' || map[x][y - 1] == 'O') {
        map[x][y] = ' ';
        map[x][y - 1] = 'P';
    }
    return (check_o(map, save));
}

char **mv_up(char **map, char **save, int const *pos)
{
    int x = pos[0];
    int y = pos[1];

    if (map[x - 1][y] == 'X' && map[x - 2][y] != '#' && map[x - 2][y] != 'X') {
        map[x][y] = ' ';
        map[x - 1][y] = 'P';
        map[x - 2][y] = 'X';
    }
    if (map[x - 1][y] == ' ' || map[x - 1][y] == 'O') {
        map[x][y] = ' ';
        map[x - 1][y] = 'P';
    }
    return (check_o(map, save));
}

char **mv_down(char **map, char **save, int const *pos)
{
    int x = pos[0];
    int y = pos[1];

    if (map[x + 1][y] == 'X' && map[x + 2][y] != '#' && map[x + 2][y] != 'X') {
        map[x][y] = ' ';
        map[x + 1][y] = 'P';
        map[x + 2][y] = 'X';
    }
    if (map[x + 1][y] == ' ' || map[x + 1][y] == 'O') {
        map[x][y] = ' ';
        map[x + 1][y] = 'P';
    }
    return (check_o(map, save));
}