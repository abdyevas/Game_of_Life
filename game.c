#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int count_neighbors(Board board, int x, int y, int version)
{
    int neighbors = 0, i, j, row, col;
    // for clipped version
    if(version == 1)
    {
        for(i = -1; i < 2; i++)
        {
            for(j = -1; j < 2; j++)
            {
                if(x+i < 0 || y+j < 0 || x+i == ROWS || y+j == COLS) break;
                else neighbors += board[x+i][y+j]; 
            }
        }
        // subtract the position of cell 
        neighbors -= board[x][y];
    }
    // for circular verion
    else if(version == 2)
    {
        for(i = -1; i < 2; i++)
        {
            for(j = -1; j < 2; j++)
            {
                // find the positions of cell's neighbors
                row = (x + i + ROWS) % ROWS;
                col = (y + j + COLS) % COLS;

                neighbors += board[row][col]; 
            }
        }
        // subtract the position of cell 
        neighbors -= board[x][y];
    }

    return neighbors;
}

void compute_new_board(Board board_t,Board board_t_1, int version)
{
    int i, j, state, n_neighbors;
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            state = board_t[i][j];

            // count neighbors for each cell
            n_neighbors = count_neighbors(board_t, i, j, version);

            // cell becomes alive if it has exactly 3 neighbors
            if(state == 0 && n_neighbors == 3) board_t_1[i][j] = 1;
            // cell dies if it has less than two or more than three neighbors
            else if(state == 1 && (n_neighbors < 2 || n_neighbors > 3)) board_t_1[i][j] = 0;
            // otherwise cell stays at the same state
            else board_t_1[i][j] = board_t[i][j];
        }
    }
}

void random_board(Board board)
{
    int i, j;
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            // randomly gives each cell a state 0 or 1
            board[i][j] = rand() % 2;
        }
    }
}