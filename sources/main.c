/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** first my_sokoban
*/

#include <curses.h>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../include/my_sokoban.h"

int display_help(void)
{
    write(1, "USAGE\n     ./my_sokoban map\n\nDESCRIPTION\n     map  ", 51);
    write(1, "file representing the warehouse map, containing \'#\' ", 52);
    write(1, "for walls\n          \'P\' for the player, \'X\' for boxes", 53);
    write(1, " and \'O\' for storage locations.\n", 32);
    return (0);
}

int main(int ac, char *av[])
{
    struct stat st;

    if (ac != 2 || av[1][0] == '\0')
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h')
        return (display_help());
    if (stat(av[1], &st) == -1 || st.st_size == 0)
        return (84);
    return (sokoban(av[1], st.st_size));
}
