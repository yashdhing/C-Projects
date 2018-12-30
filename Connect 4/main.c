#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "game.h"
#include "win.h"

void read_args(char **argv, int argc, int* row, int* col, int* winNum);

////////////////////////////////////////////////////
//Main() function

int main(int argc, char* argv[]){
    int row, col, winNum;
    read_args(argv, argc, &row, &col, &winNum);
    char** board = create_board(row, col);          //Create board
    print_board(board, row, col);                   //Print empty board
    play_game(board, row, col, winNum);             //Executes game
    destroy_board(board, row);                      //Releases memory
    return 0;
}


//////////////////////////////////////////////////////
//Function Definitions
void read_args(char **argv, int argc, int *row, int *col, int *winNum){
    //Check for no. of arguments entered in command line
    if (argc < 3+1){
        printf("1.Not enough arguments entered\n");
        printf("2.Usage connectn.out num_rows num_columns\n");
        printf("number_of_pieces_in_a_row_needed_to_win");
            exit(0);
    }
    else if (argc > 3+1){
        printf("1.Too many arguments entered\n");
        printf("2.Usage connectn.out num_rows num_columns\n");
        printf("number_of_pieces_in_a_row_needed_to_win");
               exit(0);
    }
    *row = atoi(argv[1]);                //atoi() is a predefined function of stdlib.h
    *col = atoi(argv[2]);
    *winNum = atoi(argv[3]);
}
