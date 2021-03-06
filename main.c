#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include "./game/game.h"
#include "./console/draw_board.h"

int main() 
{    
    // version 1 for clipped, 2 for circular boundary and neighbourhood
    int version = 2; // 1:2
    srand(time(NULL));
    // create 2D board at time t
    Board board_t;
    random_board(board_t);

    // create 2D board at time t+1
    int board_t_1[ROWS][COLS] = {{0}};

    // create pointers to the boards 
    Board *ptr_board_t = &board_t;
    Board *ptr_board_t_1 = &board_t_1;

    while (true)
    {
        // clear the console after each iteraction
		printf("\033[H\033[2J");

        display_board(*ptr_board_t);
        //printf("\033[0m");
        compute_new_board(*ptr_board_t, *ptr_board_t_1, version);

        // create temporary board to repeat iteraction with the board at time t+1
        // i.e board at time t+1 becomes board at time t to continue iteractions
        Board *tmp_board = ptr_board_t;
        ptr_board_t = ptr_board_t_1;
        ptr_board_t_1 = tmp_board;

        // wait before each iteraction
        usleep(100000);
    } 
    return 0;
}