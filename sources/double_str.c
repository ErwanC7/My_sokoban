/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include <stdlib.h>

static int my_nbrlen(char const *str, char const c)
{
    int i = 0;

    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == c)
            i++;
    }
    return (i + 1);
}

static int my_wordlen(char const *str, int i, char const c)
{
    int j = 0;

    for (;str[i] != c && str[i] != '\0'; j++, i++);
    return (j + 1);
}

char **double_str(char const *buffer, char c)
{
    int size = my_nbrlen(buffer, c);
    char **str = malloc(sizeof(char *) * (size + 1));
    int i = 0;
    int a = 0;

    for (int b; buffer[i] != '\0'; a++) {
        str[a] = malloc(sizeof(char) * my_wordlen(buffer, i, c));
        for (b = 0; buffer[i] != c && buffer[i] != '\0'; i++, b++)
            str[a][b] = buffer[i];
        str[a][b] = '\0';
        if (buffer[i] != '\0')
            i++;
    }
    str[a] = NULL;
    return (str);
}
