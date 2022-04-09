/*
** EPITECH PROJECT, 2022
** sysnav_tests
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct pos_s {
        int line;
        int col;
    } pos_t;

    typedef struct global_s {
        pos_t *pos_player;
        pos_t **pos_exit;
        pos_t *pos_fire;
        pos_t *good_exit;
        char **tab;
        char *map;
        char *buffer;
        int nb_line;
        int nb_col;
        int is_playing;
        int nb_exit;
    } global_t;

#endif /* !STRUCT_H_ */
