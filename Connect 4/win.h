#include <stdbool.h>
#ifndef WIN_H_INCLUDED
#define WIN_H_INCLUDED

    int game_over(char** board, int row, int col, int winNum);
    bool game_won(char** board, int row, int col, int winNum, char token);
    bool board_full(char** board, int row, int col);
    bool row_win(char** board, int row, int col, int winNum, char token);
    bool col_win(char** board, int row, int col, int winNum, char token);
    bool right_diag_win(char** board, int row, int col, int winNum, char token);
    bool left_diag_win(char** board, int row, int col, int winNum, char token);

#endif // WIN_H_INCLUDED
