/*
** EPITECH PROJECT, 2021
** test_my_sokoban
** File description:
** test_my_sokoban
*/

#include <criterion/criterion.h>
#include "../include/my_sokoban.h"

Test(double_str, normal)
{
    char *str = "He Ho";
    char **map = double_str(str, ' ');

    cr_assert_str_eq(map[0], "He");
    cr_assert_str_eq(map[1], "Ho");
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

Test(save, normal)
{
    char **map = malloc(sizeof(char *) * 3);
    char **str;

    map[0] = malloc(sizeof(char) * 3);
    map[0] = "He\0";
    map[1] = malloc(sizeof(char) * 3);
    map[1] = "Ho\0";
    str = save_map(map);
    cr_assert_str_eq(str[0], map[0]);
    cr_assert_str_eq(str[1], map[1]);
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
}