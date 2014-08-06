#ifndef TETROMINOES_H
#define TETROMINOES_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

#include "tetris.h"
#include "collision.h"

extern int colors[8][3];

Tetromino *new_tetromino(int init);
int get_min_x(Tetromino* tetro);
int get_max_x(Tetromino* tetro);
int get_min_y(Tetromino* tetro);
int get_max_y(Tetromino* tetro);
int get_tetro_width(Tetromino* tetro);
int get_tetro_height(Tetromino* tetro);
int get_offset_y(Tetromino* tetro);
int get_offset_x(Tetromino* tetro);
void move_tetromino();
void rotate();
void print_tetromino(Tetromino *mino);
bool check_rotation();

#endif
