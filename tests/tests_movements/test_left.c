/*
** EPITECH PROJECT, 2021
** test_left
** File description:
** test_left
*/

#include <criterion/criterion.h>
#include "../../include/my_sokoban.h"

Test(mv_left, without_box)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#        #\n" \
                "#  P   ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "# P    ###";
    int p[] = {3, 3};

    map = mv_left(map, save, p);
    cr_assert_str_eq(map[3], expected);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_left, with_box)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#        #\n" \
                "# XP O ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "#XP  O ###";
    int p[] = {3, 3};

    map = mv_left(map, save, p);
    cr_assert_str_eq(map[3], expected);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_left, nothing)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#        #\n" \
                "# OP X ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "# P  X ###";
    int p[] = {3, 3};

    map = mv_left(map, save, p);
    cr_assert_str_eq(map[3], expected);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_left, two_x)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#        #\n" \
                "# XXP  ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "# XXP  ###";
    int p[] = {3, 4};

    map = mv_left(map, save, p);
    cr_assert_str_eq(map[3], expected);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_left, border)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#        #\n" \
                "# #XP  ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "# #XP  ###";
    int p[] = {3, 4};

    map = mv_left(map, save, p);
    cr_assert_str_eq(map[3], expected);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}