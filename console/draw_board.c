#include <stdio.h>
#include "draw_board.h"

void display_board(Board board)
{
    int i, j;
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            // state 1 is for alive cell, colored at magenta 
            // state 0 if for dead cell, colorless
            int c = (board[i][j] == 1) ? 104 : 0;
			printf("\033[%dm  ",c);

        }
	    printf("\033[0m");
        printf("\n");
    }
}