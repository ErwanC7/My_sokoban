/*
** EPITECH PROJECT, 2021
** open_path
** File description:
** open_path
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/my_sokoban.h"

static int check_map(char const *str)
{
    char c;
    int nb_p = 0;
    int nb_x = 0;
    int nb_o = 0;
    char n = '\n';

    for (int i = 0; str[i] != '\0'; i++) {
        c = str[i];
        if (c != ' ' && c != 'P' && c != '#' && c != 'X' && c != 'O' && c != n)
            return (-1);
        if (c == 'P')
            nb_p += 1;
        if (c == 'X')
            nb_x += 1;
        if (c == 'O')
            nb_o += 1;
    }
    if (nb_p != 1 || nb_x != nb_o || nb_x < 1)
        return (-1);
    return (0);
}

char *open_map(char const *filepath, int size)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * size + 1);

    if (fd == -1 || buffer == NULL || read(fd, buffer, size) == -1)
        return (NULL);
    buffer[size] = '\0';
    if (check_map(buffer) == -1)
        return (NULL);
    close(fd);
    return (buffer);
}