/*
** EPITECH PROJECT, 2021
** tests_my_sokoban
** File description:
** unit tests of my_sokoban
*/

#include <criterion/criterion.h>
#include "../include/my_sokoban.h"

static int check_null(char const *str)
{
    if (str == NULL)
        return (1);
    return (0);
}

Test(open_map, wrong_file)
{
    char *str = open_map("aazqw", 10);

    cr_assert_eq(check_null(str), 1);
}

Test(open_map, wrong_char)
{
    char *str = open_map("tests/map/map_1", 17);

    cr_assert_eq(check_null(str), 1);
}

Test(open_map, no_player)
{
    char *str = open_map("tests/map/map_2", 18);

    cr_assert_eq(check_null(str), 1);
}

Test(open_map, too_much_x)
{
    char *str = open_map("tests/map/map_3", 21);

    cr_assert_eq(check_null(str), 1);
}

Test(open_map, no_x)
{
    char *str = open_map("tests/map/map_4", 21);

    cr_assert_eq(check_null(str), 1);
}

Test(open_map, wrong_size)
{
    char *str = open_map("tests/map/map_4", -1);

    cr_assert_eq(check_null(str), 1);
}

Test(open_map, wrong_malloc)
{
    char *str = open_map("tests/map/map_4", -5);

    cr_assert_eq(check_null(str), 1);
}

Test(open_map, good_file)
{
    char *str = open_map("tests/map/map_0", 143);
    char *map;

    map = "##########\n" \
          "#        #\n" \
          "#        #\n" \
          "# PXO  ###\n" \
          "#        #\n" \
          "# OX     #\n" \
          "##########\n";
    cr_assert_str_eq(str, map);
}