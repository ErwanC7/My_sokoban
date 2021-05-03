/*
** EPITECH PROJECT, 2021
** get_lines_cols
** File description:
** get_lines_cols
*/

#include <unistd.h>

int get_l(char **map)
{
    int car = 0;

    for (; map[0][car] != '\n' && map[0][car] != '\0'; car += 1);
    return (car);
}

int get_n(char **map)
{
    int line = 0;

    for (; map[line] != NULL; line += 1);
    return (line);
}
