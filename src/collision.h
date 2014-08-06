#ifndef COLLISION_H
#define COLLISION_H

#include <stdbool.h>

#include "types.h"
#include "tetris.h"
#include "board.h"

int collision(int x1, int y1, int x2, int y2);
bool check_collision(int x_move, int y_move);

#endif
