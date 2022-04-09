/*
** EPITECH PROJECT, 2022
** sysnav_tests
** File description:
** map_handling
*/

#include "../include/test.h"

static void fill_pos_exit(global_t *global)
{
    int k = 0;

    global->pos_exit = malloc(sizeof(pos_t) * global->nb_exit + 1);
    for (int a = 0; a < global->nb_exit; a++)
        global->pos_exit[a] = malloc(sizeof(pos_t));
    for (int i = 0; i < global->nb_line; i++) {
        for (int j = 0; j < global->nb_col; j++) {
            if (global->tab[i][j] == 'E') {
                global->pos_exit[k]->line = i;
                global->pos_exit[k]->col = j;
                k++;
            }
        }
    }
}

static int special_len(char *str, char delim)
{
    int i = 0;

    while (str[i] != delim)
        i++;
    return (i);
}

void map_handling(global_t *global)
{
    int nb_player = 0; //nombre de players sur la map

    global->nb_col = special_len(global->map, '\n'); //nombre de colonnes de mon char**
    global->nb_line = nb_words(global->map, '\n') - 1; //nombre de lignes
    for (int i = 0; i < global->nb_line - 1; i++) {
        for (int j = 0; j < global->nb_col; j++) {
            if (global->tab[i][j] == 'S') {
                nb_player++;
                global->pos_player->line = i;
                global->pos_player->col = j;
            }
            if (global->tab[i][j] == 'E')
                global->nb_exit++;
            if (global->tab[i][j] == 'F') {
                global->pos_fire->line = i;
                global->pos_fire->col = j;
            }
            if (nb_player > 1) {
                write(2, "Plus de 1 player sur la map, map invalide\n", 43);
                free_exit(global, 1);
            }
        }
    }
    fill_pos_exit(global);
}

int fill_map(int ac, char **av, global_t *global)
{
    int fd = open(av[1], O_RDONLY);
    struct stat buffer;
    int len;

    stat(av[1], &buffer);
    len = buffer.st_size;
    global->map = malloc(sizeof(char) * len + 1);
    if (fd == -1) {
        free(global->map);
        exit(1);
    }
    if (len <= 0) {
        free(global->map);
        exit(1);
    }
    read(fd, global->map, len);
    close(fd);
    global->map[len] = '\0';
    return (0);
}