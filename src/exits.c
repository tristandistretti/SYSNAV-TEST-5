/*
** EPITECH PROJECT, 2022
** sysnav_tests
** File description:
** exits
*/

#include "../include/test.h"

pos_t *find_good_exit(global_t *global)
{
    pos_t *res = malloc(sizeof(pos_t));
    int calcul = (global->pos_exit[0]->line + global->pos_exit[0]->col) -
    (global->pos_fire->line + global->pos_fire->col); //calcul pour trouver la sortie la plus loin du feu de base

    for (int i = 0; i < global->nb_exit; i++) {
        if ((global->pos_exit[i]->line + global->pos_exit[i]->col) -
        (global->pos_fire->line + global->pos_fire->col) > calcul) {
            res->line = global->pos_exit[i]->line;
            res->col = global->pos_exit[i]->col;
        }
    }
    return (res);
}
