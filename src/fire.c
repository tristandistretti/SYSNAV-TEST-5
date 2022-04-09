/*
** EPITECH PROJECT, 2022
** sysnav_tests
** File description:
** fire
*/

#include "../include/test.h"

static void stars_to_burn(global_t *global)
{
    for (int i = 0; i < global->nb_line; i++) {
        for (int j = 0; j < global->nb_col; j++) {
            if (global->tab[i][j] == '*')
                global->tab[i][j] = 'F';
        }
    }
}

static void expand_fire(global_t *global)
{
    for (int i = 0; i < global->nb_line; i++) {
        for (int j = 0; j < global->nb_col; j++) {
            if (global->tab[i][j] == 'F') {
                if (i >= 1)
                    global->tab[i - 1][j] = '*';
                if (j >= 1)
                    global->tab[i][j - 1] = '*';
                if (i < global->nb_line - 1)
                    global->tab[i + 1][j] = '*';
                if (j < global->nb_col - 1)
                    global->tab[i][j + 1] = '*';
            }
        }
    }
    stars_to_burn(global);
}

static int is_possible(global_t *global, int pos)
{
    if (pos == 1) {
        if (global->tab[global->pos_player->line + 1][global->pos_player->col] != '#'
        && global->tab[global->pos_player->line + 1][global->pos_player->col] != 'F')
            return (0);
        else
            return (1);
    }
    if (pos == 2) {
        if (global->tab[global->pos_player->line - 1][global->pos_player->col] != '#'
        && global->tab[global->pos_player->line - 1][global->pos_player->col] != 'F')
            return (0);
        else
            return (1);
    }
    if (pos == 3) {
        if (global->tab[global->pos_player->line][global->pos_player->col + 1] != '#'
        && global->tab[global->pos_player->line][global->pos_player->col + 1] != 'F')
            return (0);
        else
            return (1);
    }
    if (pos == 4) {
        if (global->tab[global->pos_player->line][global->pos_player->col - 1] != '#'
        && global->tab[global->pos_player->line][global->pos_player->col - 1] != 'F')
            return (0);
        else
            return (1);
    }
}

void move_player(global_t *global)
{
    if (global->good_exit->line == global->pos_player->line &&
    global->good_exit->col == global->pos_player->col) {
        global->is_playing = WON;
        return;
    }
    if (global->good_exit->line > global->pos_player->line && is_possible(global, 1) == 0) {
        down_move(global);
        global->buffer = add_letter(global->buffer, 'D');
        return;
    }
    if (global->good_exit->line < global->pos_player->line && is_possible(global, 2) == 0) {
        up_move(global);
        global->buffer = add_letter(global->buffer, 'U');
        return;
    }
    if (global->good_exit->line == global->pos_player->line &&
    global->good_exit->col > global->pos_player->col && is_possible(global, 3) == 0) {
        right_move(global);
        global->buffer = add_letter(global->buffer, 'R');
        return;
    }
    if (global->good_exit->line == global->pos_player->line &&
    global->good_exit->col < global->pos_player->col && is_possible(global, 4) == 0) {
        left_move(global);
        global->buffer = add_letter(global->buffer, 'L');
        return;
    }
    return;
}

void escape(global_t *global)
{
    expand_fire(global);
    move_player(global);
}