/*
** EPITECH PROJECT, 2021
** my_sokoban.h
** File description:
** header of my_sokoban
*/

#ifndef MY_H
#define MY_H

#include <ncurses.h>

static const int SPACE = 32;

typedef struct move_s {
    int key;
    char **(*mv)(char **, char **, int const *);
}move_t;

int sokoban(char const *path, int size);

char *open_map(char const *filepath, int size);
char **double_str(char const *buffer, char c);
char **gameplay(char **map, char **save, int key);
char **save_map(char **map);
int check_win(char **map, char **save, int x);
int check_loose(char **map, int x);

char **mv_right(char **map, char **save, int const *pos);
char **mv_left(char **map, char **save, int const *pos);
char **mv_up(char **map, char **save, int const *pos);
char **mv_down(char **map, char **save, int const *pos);
char **restart_map(char **map, char **save, int const *p);

int get_l(char **map);
int get_n(char **map);

static const move_t tab[] = {
        {.key = KEY_RIGHT, mv_right},
        {.key = KEY_LEFT, mv_left},
        {.key = KEY_UP, mv_up},
        {.key = KEY_DOWN, mv_down},
        {.key = SPACE, restart_map}
};

static const int tab_size = sizeof(tab) / sizeof(tab[0]);

#endif
