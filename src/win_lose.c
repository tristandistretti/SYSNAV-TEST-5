/*
** EPITECH PROJECT, 2022
** sysnav_tests
** File description:
** win_lose
*/

#include "../include/test.h"

void check_win_lose(global_t *global)
{
    if (global->tab[global->good_exit->line][global->good_exit->col] == 'F' ||
    global->tab[global->pos_player->line][global->pos_player->col] == 'F') {
        global->is_playing = LOST;
        free_exit(global, 1);
    }
    else if (global->tab[global->good_exit->line][global->good_exit->col] == 'S')
        global->is_playing = WON;
    return;
}
