#include "board.h"
#include <stdio.h>
#include <string.h>

/* Array of blocks representing the board */
Blocks board[200];


/* init_board - initialize the board */
void init_board() {

    int i, j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 10; j++) {
            board[10 * i + j].x = BOARD_START + j * BLOCK_SIZE;
            board[10 * i + j].y = START_HEIGHT + i * BLOCK_SIZE;
            board[10 * i + j].color.r = colors[0][0];
            board[10 * i + j].color.g = colors[0][1];
            board[10 * i + j].color.b = colors[0][2];
            board[10 * i + j].type = NO_SHAPE;
        }
    }
}


/* add_to_board - adds the current tetromino to the board */
void add_to_board() {

    Blocks cur_block;
    int i;

    for (i = 0; i < 4; i++) {
        cur_block.x = tetromino->x + (tetromino->coords[i][0] * BLOCK_SIZE);
        cur_block.y = tetromino->y + (tetromino->coords[i][1] * BLOCK_SIZE);
        cur_block.color = tetromino->color;
        cur_block.type = tetromino->type;
        board[10 * ((cur_block.y - START_HEIGHT)/BLOCK_SIZE) 
              + (cur_block.x - BOARD_START)/BLOCK_SIZE] = cur_block;
    }
}


/* check_full_row - check if there's a full row */
void check_full_row() {

	int i, j, row_count = 0;
	for (i = 0; i < 20; i++)
		game.remove_rows[i] = 0;

	for (i = 0; i < 20; i++) {
		for (j = 0; j < 10; j++) {
			if (board[10 * i + j].type != NO_SHAPE)
				row_count++;
		}			
		
		/* If there's a full row, flip the remove_row bit, and set remove and animate bools to true */
		if (row_count == 10) {
			game.remove_rows[i] = 1;
			game.remove = game.animate = true;
		}

		row_count = 0;
	}
}


/* remove_row - remove a row at a specified y */
void remove_row(int y) {
	
    int i, j;
	for (i = y; i > 0; i--) {
		for (j = 0; j < 10; j++) {
			copy_board(&board[10 * i + j], &board[10 * (i - 1) + j]);
        }
    }
}


/* copy_board - copy one board struct into another */
void copy_board(Blocks *board_one, Blocks *board_two) {

	(*board_one).color = (*board_two).color;
	(*board_one).type = (*board_two).type;
}


/* print_board - prints a representation of the current board */
void print_board() {
	
	int i, j;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 10; j++) {
			if (board[10 * i + j].type != NO_SHAPE)
				printf("1 ");
			else
				printf("0 ");
		}
		printf("\n");
	}
	printf("\n");
}
