/*
** EPITECH PROJECT, 2021
** check
** File description:
** check
*/

#include <stdio.h>

int check_win(char **map, char **save, int x)
{
    int a = 0;

    for (int i = 0, j = 0; map[i] != NULL; j += 1) {
        if (map[i][j] == 'X' && save[i][j] == 'O')
            a += 1;
        if (map[i][j] == '\0') {
            i++;
            j = 0;
        }
    }
    if (a == x)
        return (0);
    else
        return (-1);
}

static int check_x(char **map, int x, int y)
{
    if (map[x][y + 1] == '#' && map[x + 1][y] == '#')
        return (1);
    if (map[x][y + 1] == '#' && map[x - 1][y] == '#')
        return (1);
    if (map[x][y - 1] == '#' && map[x + 1][y] == '#')
        return (1);
    if (map[x][y - 1] == '#' && map[x - 1][y] == '#')
        return (1);
    return (0);
}

int check_loose(char **map, int x)
{
    int a = 0;

    for (int i = 0, j = 0; map[i] != NULL; j += 1) {
        for (; map[i][j] != 'X' && map[i][j] != '\0'; j++);
        if (map[i][j] == 'X')
            a += check_x(map, i, j);
        if (map[i][j] == '\0') {
            i++;
            j = 0;
        }
    }
    if (a == x)
        return (0);
    else
        return (-1);
}