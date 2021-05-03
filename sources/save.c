/*
** EPITECH PROJECT, 2021
** save
** File description:
** save
*/

#include <stdlib.h>
#include <ncurses.h>

static int nb_lines(char **map)
{
    int i = 0;

    for (; map[i] != NULL; i += 1);
    return (i);
}

static int nb_cols(char **map)
{
    int j = 0;

    for (; map[0][j] != '\0'; j += 1);
    return (j + 1);
}

char **save_map(char **map)
{
    int n = nb_lines(map);
    int c = nb_cols(map);
    int i = 0;
    char **save = malloc(sizeof(char *) * (n + 1));

    for (int j = 0; i < n; i += 1) {
        save[i] = malloc(sizeof(char) * c + 1);
        for (j = 0; j < c; j += 1)
            save[i][j] = map[i][j];
        save[i][j] = '\0';
    }
    save[n] = NULL;
    return (save);
}