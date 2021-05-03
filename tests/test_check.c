/*
** EPITECH PROJECT, 2021
** test_check
** File description:
** test_check
*/

#include <criterion/criterion.h>
#include "../include/my_sokoban.h"

Test(check_win, win)
{
    char *str = "######\n" \
                "# PXO#\n" \
                "######\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    int p[] = {1, 2};

    map = mv_right(map, save, p);
    cr_assert_eq(check_win(map, save, 1), 0);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(check_win, no_win)
{
    char *str = "#######\n" \
                "#OPX  #\n" \
                "#######\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    int p[] = {1, 2};

    map = mv_right(map, save, p);
    cr_assert_eq(check_win(map, save, 1), -1);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(check_loose, loose)
{
    char *str = "######\n" \
                "#OPX #\n" \
                "######\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    int p[] = {1, 2};

    map = mv_right(map, save, p);
    cr_assert_eq(check_loose(map, 1), 0);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

    Test(check_loose, no_loose)
{
    char *str = "#######\n" \
                "#OPX  #\n" \
                "#     #\n" \
                "#######\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    int p[] = {1, 2};

    map = mv_right(map, save, p);
    cr_assert_eq(check_loose(map, 1), -1);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(check_loose, no_loose_down_r)
{
    char *str = "#######\n" \
                "#O    #\n" \
                "#  PX #\n" \
                "#######\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    int p[] = {2, 3};

    map = mv_right(map, save, p);
    cr_assert_eq(check_loose(map, 1), 0);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(check_loose, no_loose_down_l)
{
    char *str = "#######\n" \
                "#O    #\n" \
                "# XP  #\n" \
                "#######\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    int p[] = {2, 3};

    map = mv_left(map, save, p);
    cr_assert_eq(check_loose(map, 1), 0);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(check_loose, no_loose_up_l)
{
    char *str = "#######\n" \
                "# XP  #\n" \
                "#    O#\n" \
                "#######\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    int p[] = {1, 3};

    map = mv_left(map, save, p);
    cr_assert_eq(check_loose(map, 1), 0);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(check_loose, no_loose_up_r)
{
    char *str = "#######\n" \
                "#O PX #\n" \
                "#     #\n" \
                "#######\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    int p[] = {1, 3};

    map = mv_right(map, save, p);
    cr_assert_eq(check_loose(map, 1), 0);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(check_loose, no_loose_up)
{
    char *str = "#######\n" \
                "#XOPOX#\n" \
                "#XO OX#\n" \
                "#######\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);

    cr_assert_eq(check_loose(map, 4), 0);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(check_loose, no_loose_down)
{
    char *str = "#######\n" \
                "#    X\n" \
                "#O   X#\n" \
                "#    P#\n" \
                "#######\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    int p[] = {3, 5};

    map = mv_up(map, save, p);
    cr_assert_eq(check_loose(map, 1), -1);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(check_loose, no_loose_d)
{
    char *str = "#######\n" \
                "#X    #\n" \
                "#X   O#\n" \
                "#P    #\n" \
                "#######\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    int p[] = {4, 2};

    map = mv_up(map, save, p);
    cr_assert_eq(check_loose(map, 1), 0);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}