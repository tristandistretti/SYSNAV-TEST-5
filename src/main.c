/*
** EPITECH PROJECT, 2022
** sysnav_tests
** File description:
** main
*/

/* Excusez moi si les headers des fichiers vous dérange, c'est une norme qu'epitech
nous impose parmi d'autres et j'ai appris / pris l'habitude de coder avec un header
dans mes fichers.
*/

#include "../include/test.h"

char *add_letter(char *str, char c)
{
    char *res;

    if (str == NULL) {
        res = malloc(sizeof(char) * 2);
        res[0] = c;
        res[1] = '\0';
        return (res);
    }
    else
        res = malloc(sizeof(char) * strlen(str) + 2);
    for (int i = 0; i < strlen(str); i++)
        res[i] = str[i];
    res[strlen(str)] = c;
    res[strlen(str) + 1] = '\0';
    return (res);
}

static void error_handling(int ac, char **av)
{
    if (ac != 2) {
        write(2, "You should give one file to the program\n", 40);
        exit(1);
    }
}

static void malloc_all(global_t *global)
{
    global->pos_player = malloc(sizeof(pos_t));
    global->pos_fire = malloc(sizeof(pos_t));
    global->good_exit = malloc(sizeof(pos_t));
    global->is_playing = IS_PLAYING;
    global->buffer = NULL;
    global->nb_exit = 0;
}

int main(int ac, char **av)
{
    global_t *global = malloc(sizeof(global_t));

    error_handling(ac, av);
    malloc_all(global);
    fill_map(ac, av, global);
    global->tab = my_str_to_word_arr(global->map, '\n');
    map_handling(global);
    global->good_exit = find_good_exit(global);
    while (global->is_playing == IS_PLAYING) {
        escape(global);
        check_win_lose(global);
    }
    printf("%s\n", global->buffer);
    free_exit(global, 0);
    return (0);
}