#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include "game.h"
void display_board(Board board)
{
    int i, j;
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(board[i][j] == 1) printf("#");
            else printf("-");
        }
        printf("\n");
    }
}

int count_neighbors(Board board, int x, int y)
{
    int neighbors = 0, i, j, row, col;

    for(i = -1; i < 2; i++)
    {
        for(j = -1; j < 2; j++)
        {
            row = (x + i + ROWS) % ROWS;
            col = (y + j + COLS) % COLS;

            neighbors += board[row][col]; 
        }
    }
    neighbors -= board[row][col];
    return neighbors;
}

void compute_new_board(Board board_t,Board board_t_1)
{
    int i, j, state, n_neighbors;
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            state = board_t[i][j];
            n_neighbors = count_neighbors(board_t, i, j);

            if(state == 0 && n_neighbors == 3) board_t_1[i][j] = 1;
            else if(state == 1 && (n_neighbors < 2 || n_neighbors > 3)) board_t_1[i][j] = 0;
            else board_t_1[i][j] = board_t[i][j];
        }
    }
}
