/*
** EPITECH PROJECT, 2021
** test_up
** File description:
** test_up
*/

#include <criterion/criterion.h>
#include "../../include/my_sokoban.h"

Test(mv_up, without_box)
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

    map = mv_up(map, save, p);
    cr_assert_str_eq(map[3], expected);
    cr_assert_str_eq(map[2], expected_2);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_up, with_box)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#  X     #\n" \
                "#  P   ###\n" \
                "#        #\n" \
                "#      O #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "#      ###";
    char *expected_2 = "#  P     #";
    char *expected_3 = "#  X     #";
    int p[] = {3, 3};

    map = mv_up(map, save, p);
    cr_assert_str_eq(map[3], expected);
    cr_assert_str_eq(map[2], expected_2);
    cr_assert_str_eq(map[1], expected_3);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_up, nothing)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#  O     #\n" \
                "#  P X ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "#    X ###";
    char *expected_2 = "#  P     #";
    int p[] = {3, 3};

    map = mv_up(map, save, p);
    cr_assert_str_eq(map[3], expected);
    cr_assert_str_eq(map[2], expected_2);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_up, two_x)
{
    char *str = "##########\n" \
                "#   X    #\n" \
                "#   X    #\n" \
                "#   P  ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "#   P  ###";
    int p[] = {3, 4};

    map = mv_up(map, save, p);
    cr_assert_str_eq(map[3], expected);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_up, border)
{
    char *str = "##########\n" \
                "#   #    #\n" \
                "#   X    #\n" \
                "#   P  ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "#   P  ###";
    int p[] = {3, 4};

    map = mv_up(map, save, p);
    cr_assert_str_eq(map[3], expected);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(mv_up, spawn_o)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#   O    #\n" \
                "#   P  ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *expected = "#   P    #";
    char *expected_2 = "#   O    #";
    int p[] = {3, 4};

    map = mv_up(map, save, p);
    p[0] = 2;
    map = mv_up(map, save, p);
    cr_assert_str_eq(map[1], expected);
    cr_assert_str_eq(map[2], expected_2);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}