#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

    char** create_board(int row, int col);
    void print_board(char** board, int row, int col);
    void destroy_board(char** board, int row);

#endif // BOARD_H_INCLUDED
