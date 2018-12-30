#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game.h"
#include "win.h"
#include "board.h"

bool play_is_valid (char** board, int row, int col,int test_col){       //To check for a valid column entry
    if ((test_col >= col) || (test_col < 0))
        return false;
    if (board[row-1][test_col] != '*')
        return false;
    return true;
}

int get_play(char** board, int row, int col){                           //To get a column as an input from a user
    int in_col;
    do{
    printf("Enter a column between 0 and %d to play in: ", col-1);
    scanf("%d", &in_col);
    }while(play_is_valid(board, row, col, in_col) == false);
    return in_col;
}

void fill_col(char** board, int row, int col, int in_col, char token){  //To fill a value in a column selected
    int i;
    for(i = 0; i < row; i++){
        if(board[i][in_col] == '*'){
            board[i][in_col] = token;
            break;
        }
    }
}

void play_game(char** board, int row, int col, int winNum)              //Main game
{
    int turns = 0;
    char token;
    int in_col, game_end;
    while(turns < (row*col)){
        if(turns % 2 == 0)                                              //Selection of Player on the basis of turns
            token = 'X';
        else
            token = 'O';
        in_col = get_play(board, row, col);                             //Column Input
        fill_col(board, row, col, in_col, token);                       //Column fill
        print_board(board, row, col);                                   //Boards's current status
        game_end = game_over(board, row, col, winNum);                  //Game over check
        switch(game_end)
        {
        case 1:
            printf("Player %d Won!", game_end);
            turns = row * col;
            break;
        case 2:
            printf("Player %d Won!", game_end);
            turns = row * col;
            break;
        case -1:
            printf("Tie game!");
            break;
        }
        turns++;
    }
}
