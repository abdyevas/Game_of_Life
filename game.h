#define ROWS 10
#define COLS 10

typedef int Board[ROWS][COLS];

/*
 * counts neighbors of a given cell 
 * board - 2D array at a given time of size [ROWS][COLS]
 * x - position of a cell in a row
 * y - position of a cell in a column 
 * version - the boundary and neighbourhood type, 1 for clipped; 2 for circular
*/
int count_neighbors(Board board, int x, int y, int version);

/*
 * computes the new board at time t+1
 * board_t -  initial 2D board at time t
 * board_t_1 - new 2D board at time t+1 
 * version - the boundary and neighbourhood type, 1 for clipped; 2 for circular
*/
void compute_new_board(Board board_t, Board board_t_1, int version);

/*
 * generates random board 
 * board - 2D board to be generated
*/
void random_board(Board board);