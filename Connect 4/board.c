#include <stdio.h>
#include <stdlib.h>
#include "board.h"

char** create_board(int row, int col){                      //Creates a new board and fills it with '*'
	int i, j;
	char** board = (char**)malloc(row * sizeof(char*));
	for(i = 0; i < row; i++){
		board[i] = (char*)malloc(col * sizeof(char));
	}
	for (i = 0; i <  row; i++){
        for (j = 0; j < col; j++)
            board[i][j] = '*';
	}
	return board;
}

void print_board(char** board, int row, int col){           //Prints the board with current values
    int i, j;
    for (i = row - 1; i >= 0; i--){
        printf("%d ", i);
        for (j = 0; j < col; j++){
          printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (j = 0; j < col; j++){
        printf("%d ", j);
    }
    printf("\n");
}

void destroy_board(char** board, int row){                  //Releases memory after game ends
    int i;
    for(i = 0; i < row; i++){
        free(board[i]);
    }
    free(board);
}
