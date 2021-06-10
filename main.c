#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include "game.h"

int main() 
{    
    // create 2D board at time t
    Board board_t = 
    {
        {0,0,0,0,0,0},
        {0,0,0,1,0,0},
        {0,1,0,1,0,0},
        {0,0,1,1,0,0},
        {0,0,0,0,0,0},
    };

    // create 2D board at time t+1
    int board_t_1[ROWS][COLS];
    // copy characters of board at time t to the board at time t+1
    memcpy(board_t_1, board_t, sizeof(board_t));

    // create pointers to the boards 
    Board *ptr_board_t = &board_t;
    Board *ptr_board_t_1 = &board_t_1;

    while(true)
    {
        // clear the console after each iteraction
		printf("\033[H\033[J");
        display_board(*ptr_board_t);

        compute_new_board(*ptr_board_t, *ptr_board_t_1);

        // create temporary board to repeat iteraction with the board at time t+1
        // i.e board at time t+1 becomes board at time t to continue iteractions
        Board *tmp_board = ptr_board_t;
        ptr_board_t = ptr_board_t_1;
        ptr_board_t_1 = tmp_board;

        // wait before each iteraction
        usleep(250000);
    }    
    return 0;
}