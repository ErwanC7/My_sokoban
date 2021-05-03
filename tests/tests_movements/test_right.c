/*
** EPITECH PROJECT, 2021
** test_movements
** File description:
** test_movements
*/

#include <criterion/criterion.h>
#include "../../include/my_sokoban.h"

Test(mv_right, without_box)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#        #\n" \
                "# P    ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "#  P   ###";
    int p[] = {3, 2};

    map = mv_right(map, save, p);
    cr_assert_str_eq(map[3], expected);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_right, with_box)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#        #\n" \
                "# PX O ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "#  PXO ###";
    int p[] = {3, 2};

    map = mv_right(map, save, p);
    cr_assert_str_eq(map[3], expected);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_right, nothing)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#        #\n" \
                "# PO X ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "#  P X ###";
    int p[] = {3, 2};

    map = mv_right(map, save, p);
    cr_assert_str_eq(map[3], expected);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_right, two_x)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#        #\n" \
                "# PXX  ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "# PXX  ###";
    int p[] = {3, 2};

    map = mv_right(map, save, p);
    cr_assert_str_eq(map[3], expected);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_right, border)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#        #\n" \
                "# PX#  ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "# PX#  ###";
    int p[] = {3, 2};

    map = mv_right(map, save, p);
    cr_assert_str_eq(map[3], expected);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}