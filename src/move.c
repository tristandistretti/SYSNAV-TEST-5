/*
** EPITECH PROJECT, 2022
** sysnav_tests
** File description:
** move
*/

#include "../include/test.h"

void up_move(global_t *global)
{
    global->tab[global->pos_player->line][global->pos_player->col] = '.';
    global->tab[global->pos_player->line - 1][global->pos_player->col] = 'S';
    global->pos_player->line--;
}

void right_move(global_t *global)
{
    global->tab[global->pos_player->line][global->pos_player->col] = '.';
    global->tab[global->pos_player->line][global->pos_player->col + 1] = 'S';
    global->pos_player->col++;
}

void left_move(global_t *global)
{
    global->tab[global->pos_player->line][global->pos_player->col] = '.';
    global->tab[global->pos_player->line][global->pos_player->col - 1] = 'S';
    global->pos_player->col--;
}

void down_move(global_t *global)
{
    global->tab[global->pos_player->line][global->pos_player->col] = '.';
    global->tab[global->pos_player->line + 1][global->pos_player->col] = 'S';
    global->pos_player->line++;
}