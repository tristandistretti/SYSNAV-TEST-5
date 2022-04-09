/*
** EPITECH PROJECT, 2022
** sysnav_tests
** File description:
** free
*/

#include "../include/test.h"

void free_exit(global_t *global, int status)
{
    free(global->map);
    free(global->tab);
    free(global->buffer);
    exit(status);
}
