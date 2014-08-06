#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

#include "graphics.h"
#include "tetrominoes.h"
#include "tetris.h"
#include "types.h"

extern Blocks board[200];

void init_board();
void add_to_board();
void check_full_row();
void remove_row(int y);
void copy_board(Blocks *board_one, Blocks *board_two);
void print_board();
void check_floating();

#endif
