#include "win.h"

int game_over(char** board, int row, int col, int winNum){          //Returns type of game ending
    if(game_won(board, row, col, winNum, 'X'))
        return 1;
    else if (game_won(board, row, col, winNum, 'O'))
        return 2;
    else if (board_full(board, row, col))
        return -1;
    else
        return 0;
}

bool board_full(char** board, int row, int col){
    bool full = true;
    int j;
    for(j = 0; j < col; j++){
        if(board[row-1][j] == '*'){
            full = false;
            break;
        }
    }
    return full;
}

bool game_won(char** board, int row, int col, int winNum, char token){
    if(row_win(board, row, col, winNum, token) || col_win(board, row, col, winNum, token) || right_diag_win(board, row, col, winNum, token) || left_diag_win(board, row, col, winNum, token))
        return true;
    else
        return false;
}

bool row_win(char** board, int row, int col, int winNum, char token){
    if (winNum > col)
        return false;
    int i, j, count;
    for(i = 0; i < row; i++){
        count = 0;
        for(j = 0; j < col; j++)
        {
            if (board[i][j] == token)
                count++;
            else
                count = 0;
            if(count == winNum)
                return true;
        }
    }
    return false;
}

bool col_win(char** board, int row, int col, int winNum, char token){
    if (winNum > row)
        return false;
    int i, j, count;
    for(j = 0; j < col; j++){
        count = 0;
        for(i = 0; i < row; i++)
        {
            if (board[i][j] == token)
                count++;
            else
                count = 0;
            if(count == winNum)
                return true;
        }
    }
    return false;
}

bool right_diag_win(char** board, int row, int col, int winNum, char token){
    if ((winNum > row) || winNum > col)
        return false;
    int i, j, k, count;
    for(i = 0; i <= row - winNum; i++){
        count = 0;
        for(j = 0; j < col - winNum; j++){
            for(k = 0; k < winNum; k++){
                if (board[i+k][j+k] == token)
                    count++;
                else
                    count = 0;
                if(count == winNum)
                    return true;
            }
        }
    }
    return false;
}

bool left_diag_win(char** board, int row, int col, int winNum, char token){
    if ((winNum > row) || winNum > col)
        return false;
    int i, j, k, count;
    for(i = 0; i <= row - winNum; i++){
        count = 0;
        for(j = winNum - 1 ; j < col; j++){
            for(k = 0; k < winNum; k++){
                if (board[i+k][j-k] == token)
                    count++;
                else
                    count = 0;
                if(count == winNum)
                    return true;
            }
        }
    }
    return false;
}
