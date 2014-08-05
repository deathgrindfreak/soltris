#include "collision.h"


/* collision - check if there's a collision on the board */
int collision(int x1, int y1, int x2, int y2) {

    return (x1 == x2 && y1 == y2);
}

/* check if a movement will result in a collision */
bool check_collision(int x_move, int y_move) {

    int i, j;

    /* Check for a collision */
    for (i = 0; i < 200; i++) {
        for (j = 0; j < 4; j++) {
            if (board[i].type != NO_SHAPE) {
	            if (collision(tetromino->x + (tetromino->coords[j][0] + x_move) * BLOCK_SIZE, 
	                          tetromino->y + (tetromino->coords[j][1] + y_move) * BLOCK_SIZE, 
                              board[i].x, 
                              board[i].y)) {
                    return true;
                }
            }
        }
    }
    
    if (tetromino->y + ((tetromino->h + y_move) * BLOCK_SIZE) - tetromino->offset_y > END_HEIGHT) {
		return true;
	}
		
    return false;
}
