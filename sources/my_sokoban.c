/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** my_sokoban
*/

#include <stdlib.h>
#include "../include/my_sokoban.h"

static int quit_scr(WINDOW **scr, char **map, char **save, int value)
{
    endwin();
    delwin(*scr);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
    return (value);
}

static int loop(WINDOW *scr, char **map, char **save, int x)
{
    int line = get_l(map);
    int col = get_n(map);

    for (int key = -1; key != 'q'; key = getch()) {
        clear();
        if (col > LINES || line > COLS) {
            mvprintw(LINES / 2, COLS / 2 - 13, "Resize the terminal please\n");
            refresh();
            continue;
        }
        map = gameplay(map, save, key);
        keypad(scr, TRUE);
        for (int i = 0, a = col / 2; map[i] != NULL; i++, a--, refresh())
            mvprintw(LINES / 2 - a, COLS / 2 - line / 2, map[i]);
        if (check_win(map, save, x) == 0)
            return (0);
        if (check_loose(map, x) == 0)
            return (1);
    }
    return (0);
}

static int start(char **map, char **save, int x)
{
    WINDOW *scr = initscr();
    int win;

    curs_set(0);
    noecho();
    win = loop(scr, map, save, x);
    if (win == 0)
        return (quit_scr(&scr, map, save, 0));
    else if (win == 1)
        return (quit_scr(&scr, map, save, 1));
    else
        return (quit_scr(&scr, map, save, 84));
}

static int get_x(char **map)
{
    int x = 0;

    for (int i = 1, j = 0; map[i] != NULL; j += 1) {
        if (map[i][j] == 'X')
            x += 1;
        if (map[i][j] == '\0') {
            i += 1;
            j = 0;
        }
    }
    return (x);
}

int sokoban(char const *filepath, int size)
{
    char *str = open_map(filepath, size);
    char **map;
    char **save;
    int x;

    if (str == NULL)
        return (84);
    map = double_str(str, '\n');
    save = save_map(map);
    free(str);
    x = get_x(map);
    return (start(map, save, x));
}