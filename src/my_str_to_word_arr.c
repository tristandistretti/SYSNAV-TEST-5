/*
** EPITECH PROJECT, 2022
** B-PSU-101-STG-1-1-minishell1-tristan.distretti
** File description:
** my_str_to_word_arr
*/

#include "../include/test.h"

int nb_words(char *str, char c)
{
    int res = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            res++;
    }
    return (res);
}

int my_lim_len(char *str, char c)
{
    int res = 0;

    while (str[res] != '\0') {
        if (str[res] == c)
            return (res);
        res++;
    }
    return (res);
}

char **my_str_to_word_arr(char *str, char stop)
{
    char **tab = malloc(sizeof(char *) * nb_words(str, stop));
    int *all_lenghts = malloc(sizeof(int) * nb_words(str, stop));
    int nb_word = nb_words(str, stop);
    int b = 0;

    for (int i = 0; i < nb_words(str, stop); i++)
        all_lenghts[i] = 0;
    for (int i = 0; str[i] != '\0'; i++)
        str[i] == stop ? b++ : all_lenghts[b]++;
    for (int i = 0; i < nb_word; i++) {
        tab[i] = malloc(sizeof(char) * all_lenghts[i] + 1);
        for (int a = 0; a < all_lenghts[i]; a++)
            tab[i][a] = str[a];
        str = &str[all_lenghts[i] + 1];
    }
    free(all_lenghts);
    return (tab);
}
