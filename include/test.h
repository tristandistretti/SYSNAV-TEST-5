/*
** EPITECH PROJECT, 2022
** sysnav_tests
** File description:
** test
*/

#ifndef TEST_H_
    #define TEST_H_

    #include "struct.h"
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    #define IS_PLAYING 0
    #define WON 1
    #define LOST 2

    int fill_map(int ac, char **av, global_t *global);
    char **my_str_to_word_arr(char *str, char stop);
    int nb_words(char *str, char c);
    void map_handling(global_t *global);
    void escape(global_t *global);
    void free_exit(global_t *global, int status);
    pos_t *find_good_exit(global_t *global);
    void move_player(global_t *global);
    void up_move(global_t *global);
    void right_move(global_t *global);
    void down_move(global_t *global);
    void left_move(global_t *global);
    char *add_letter(char *str, char c);
    void check_win_lose(global_t *global);
#endif /* !TEST_H_ */
