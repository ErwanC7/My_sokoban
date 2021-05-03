/*
** EPITECH PROJECT, 2021
** test_check
** File description:
** test_check
*/

#include <criterion/criterion.h>
#include "../include/my_sokoban.h"

Test(get_l, get_nb_lines)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#        #\n" \
                "# P    ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');

    cr_assert_eq(get_l(map), 10);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

Test(get_l, get_nb_lines_2)
{
    char *str = "##########\ni" \
                "#        #\n" \
                "#        #\n" \
                "# P    ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'i');

    cr_assert_eq(get_l(map), 10);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

Test(get_n, get_nb_char)
{
    char *str = "##########\n" \
                "#        #\n" \
                "#        #\n" \
                "# P    ###\n" \
                "#        #\n" \
                "# OX     #\n" \
                "##########\n";
    char **map = double_str(str,'\n');

    cr_assert_eq(get_n(map), 7);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}