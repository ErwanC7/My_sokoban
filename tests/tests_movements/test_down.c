/*
** EPITECH PROJECT, 2021
** test_down
** File description:
** test_down
*/

#include <criterion/criterion.h>
#include "../../include/my_sokoban.h"

Test(mv_down, without_box)
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
    char *expected = "#      ###";
    char *expected_2 = "#  P     #";
    int p[] = {3, 3};

    map = mv_down(map, save, p);
    cr_assert_str_eq(map[3], expected);
    cr_assert_str_eq(map[4], expected_2);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_down, with_box)
{
    char *str = "##########\n" \
                "#  O     #\n" \
                "#    X   #\n" \
                "#  P O ###\n" \
                "#  X     #\n" \
                "#        #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "#    O ###";
    char *expected_2 = "#  P     #";
    char *expected_3 = "#  X     #";
    int p[] = {3, 3};

    map = mv_down(map, save, p);
    cr_assert_str_eq(map[3], expected);
    cr_assert_str_eq(map[4], expected_2);
    cr_assert_str_eq(map[5], expected_3);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_down, nothing)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#        #\n" \
                "#  P X ###\n" \
                "#  O     #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "#    X ###";
    char *expected_2 = "#  P     #";
    int p[] = {3, 3};

    map = mv_down(map, save, p);
    cr_assert_str_eq(map[3], expected);
    cr_assert_str_eq(map[4], expected_2);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_down, two_x)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#        #\n" \
                "#   P  ###\n" \
                "#   X    #\n" \
                "# OXX    #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "#   P  ###";
    int p[] = {3, 4};

    map = mv_down(map, save, p);
    cr_assert_str_eq(map[3], expected);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_down, border)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#        #\n" \
                "#   P  ###\n" \
                "#   X    #\n" \
                "# OX#    #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "#   P  ###";
    int p[] = {3, 4};

    map = mv_down(map, save, p);
    cr_assert_str_eq(map[3], expected);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}