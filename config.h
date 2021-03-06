/*
 * The Game of Life is a cellular automaton devised by Dr John Conway in 1970. The game is a 
 * zero-player game, meaning that its evolution is determined by its initial state. One interacts with
 *  the Game of Life by creating an initial configuration and observing how it evolves.
 */

#ifndef CONFIG_HH
#define CONFIG_HH

#include <stdlib.h>
#include <stdio.h>

#define ROWS 6
#define COLS 6
class GameConfig{
    /** Default constructor. Does something.
        */
    GameConfig();

    /** Default destructor.
        */
    ~GameConfig();

  public:
    typedef int Board[ROWS][COLS];

    /**
     * displays the board
     * board - the 2D board of size [ROWS][COLS] to be displays
    */
    void display_board(Board board);

    /**
     * counts neighbors of a given cell 
     * board - 2D array at a given time of size [ROWS][COLS]
     * x - position of a cell in a row
     * y - position of a cell in a column 
    */
    int count_neighbors(Board board, int x, int y);

    /**
     * computes the new board at time t+1
     * board_t -  initial 2D board at time t
     * board_t_1 - new 2D board at time t+1 
    */
    void compute_new_board(Board board_t, Board board_t_1);

    /**
     * generates random board 
     * board - 2D board to be generated
    */
    void random_board(Board board);
};

#endif