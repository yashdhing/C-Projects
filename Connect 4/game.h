#include <stdbool.h>
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

    bool play_is_valid (char**, int row, int col, int test_col);
    int get_play(char**, int row, int col);
    void play_game(char** board, int row, int col, int winNum);

#endif // GAME_H_INCLUDED
