/*
** EPITECH PROJECT, 2021
** test_gameplay
** File description:
** test_gameplay
*/

#include <criterion/criterion.h>
#include "../include/my_sokoban.h"

Test(gameplay, test_gameplay)
{
    char *str = "#######\n" \
                "#     #\n" \
                "#     #\n" \
                "#  P  #\n" \
                "#######\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *str2 = map[3];

    map = gameplay(map, save, 32);
    cr_assert_str_eq(map[3], str2);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}

Test(gameplay, error_gameplay)
{
    char *str = "#######\n" \
                "#     #\n" \
                "#X    #\n" \
                "#O    #\n" \
                "#######\n";
    char **map = double_str(str,'\n');
    char **save = save_map(map);
    char *str2 = map[3];

    map = gameplay(map, save, 32);
    cr_assert_str_eq(map[3], str2);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int i = 0; save[i] != NULL; i++)
        free(save[i]);
    free(save);
}