#include "tetrominoes.h"


static int coordinates[8][4][2] = {
    { {0, 0}, { 0, 0}, { 0,  0}, { 0,  0} },    /* no shape */
    { {0, 0}, {-1, 0}, { 1,  0}, { 2,  0} },    /* line */
    { {0, 0}, { 1, 0}, { 0,  1}, { 1,  1} },    /* square */
    { {0, 0}, { 0,-1}, {-1,  0}, { 1,  0} },    /* T shape */
    { {0, 0}, { 1, 0}, {-1,  0}, {-1, -1} },    /* J shape */
    { {0, 0}, { 1, 0}, {-1,  0}, {-1,  1} },    /* L shape */
    { {0, 0}, { 0,-1}, { 1, -1}, {-1,  0} },    /* S shape */
    { {0, 0}, { 0, -1}, { -1, -1}, { 1,  0} },    /* Z shape */
};

int colors[8][3] = {
    /* {240, 232, 213},  no shape */
	{0  , 43 , 54 },  /* no shape */
    {42 , 117, 152},  /* line */
    {181, 137, 0  },  /* square */
    {211, 54 , 130},  /* T shape */
    {38 , 139, 145},  /* J shape */
    {203, 75 , 22 },  /* L shape */
    {133, 153, 0  },  /* S shape */
    {220, 50 , 47 },  /* Z shape */
};


/* new_tetromino - initialize a new tetromino */
Tetromino *new_tetromino(int init) {

    int i, tetro;
    
	Tetromino *temp = malloc(sizeof(Tetromino));
	assert(temp != NULL);


    /* get a random tetromino */
    tetro = rand() % 7 + 1;

    temp->wait_time = 0;
    temp->type = tetro;
    temp->color.r = colors[tetro][0]; 
    temp->color.g = colors[tetro][1]; 
    temp->color.b = colors[tetro][2]; 

    for (i = 0; i < 4; i++) {
	    temp->coords[i][0] = coordinates[tetro][i][0];
	    temp->coords[i][1] = coordinates[tetro][i][1];
    }

    temp->offset_x = get_offset_x(temp);
    temp->offset_y = get_offset_y(temp);
    
    /* If init is 1, then the tetromino will be in use, if not it's
       the 'next' tetromino and should be displayed in the sidebar */
    if (init) {
		temp->x = BOARD_START + 5 * BLOCK_SIZE - temp->offset_x;
		temp->y = START_HEIGHT + temp->offset_y;
    } else {
	    if (temp->type == LINE) {
			temp->x = NEXT_X + temp->offset_x - BLOCK_SIZE / 2;
			temp->y = NEXT_Y + temp->offset_y + 25 + BLOCK_SIZE / 2;
	    } else if (temp->type == SQUARE) {
			temp->x = NEXT_X + temp->offset_x + BLOCK_SIZE / 2;
			temp->y = NEXT_Y + temp->offset_y + 25;
	    } else {
			temp->x = NEXT_X + temp->offset_x;
			temp->y = NEXT_Y + temp->offset_y + 25;
	    }
    }
    
    temp->w = get_tetro_width(temp);
    temp->h = get_tetro_height(temp);

    return temp;
}


/* get_min_x - get the minimum x value for a tetromino */
int get_min_x(Tetromino *tetro) {

    int i, min = 2;
    for (i = 0; i < 4; i++) {
        if (tetro->coords[i][0] < min)
            min = tetro->coords[i][0];
    }
    return min;
}

/* get_max_x - get the maximum x value for a tetromino */
int get_max_x(Tetromino *tetro) {

    int i, max = -1;
    for (i = 0; i < 4; i++) {
        if (tetro->coords[i][0] > max)
            max = tetro->coords[i][0];
    }
    return max;
}

/* get_min_y - get the minimum y value for a tetromino */
int get_min_y(Tetromino *tetro) {

    int i, min = 2;
    for (i = 0; i < 4; i++) {
        if (tetro->coords[i][1] < min)
            min = tetro->coords[i][1];
    }
    return min;
}

/* get_max_y - get the maximum y value for a tetromino */
int get_max_y(Tetromino *tetro) {

    int i, max = -1;
    for (i = 0; i < 4; i++) {
        if (tetro->coords[i][1] > max)
            max = tetro->coords[i][1];
    }
    return max;
}

/* get_tetro_width - get the width of a tetromino */
int get_tetro_width(Tetromino *tetro) {
    return (get_max_x(tetro) - get_min_x(tetro) + 1);
}

/* get_tetro_height - get the width of a tetromino */
int get_tetro_height(Tetromino *tetro) {
    return (get_max_y(tetro) - get_min_y(tetro) + 1);
}

/* get_offset_y - get the y offset for the tetromino */
int get_offset_y(Tetromino *tetro) {

    /* get the y offset for the tetromino */
    if (get_min_y(tetro) == -1) {
        return BLOCK_SIZE;
    } else if (get_min_y(tetro) == -2) {
        return 2 * BLOCK_SIZE;
    } else {
        return 0;
    }
}

/* get_offset_x - get the x offset for the tetromino */
int get_offset_x(Tetromino *tetro) {

    /* get the y offset for the tetromino */
    if (get_min_x(tetro) == -1) {
        return BLOCK_SIZE;
    } else if (get_min_x(tetro) == -2) {
        return 2 * BLOCK_SIZE;
    } else {
        return 0;
    }
}


/* move_tetromino - move a tetromino */
void move_tetromino() {

    /* Increment the wait time */
    tetromino->wait_time++;

    /* Increment the wait time for down/left/right movement */
    tetromino->move_time++;
    
    /* If we've waited long enough, move the tetromino down */
    if (tetromino->wait_time >= game.current_wait_time) {
        tetromino->y += BLOCK_SIZE;
        tetromino->wait_time = 0;
    }

    /* Move the tetromino down quickly if the down key is active */
    if (input.down && !check_collision(0, 1)) {
	    
        if (tetromino->move_time >= MIN_MOVE_TIME) { 
            tetromino->y += BLOCK_SIZE;
            tetromino->move_time = 0;
        }
    }  

    /* Move the tetromino left or right based on active key */
    if (input.right && !check_collision(1, 0)) {

        if (tetromino->move_time >= MIN_MOVE_TIME) { 
            tetromino->x += BLOCK_SIZE;
            tetromino->move_time = 0;
        }

        if (tetromino->x + (tetromino->w * BLOCK_SIZE) - tetromino->offset_x > BOARD_END) {
            tetromino->x = BOARD_END - (tetromino->w * BLOCK_SIZE) + tetromino->offset_x;
        }
    }

    if (input.left && !check_collision(-1, 0)) {

        if (tetromino->move_time >= MIN_MOVE_TIME) { 
            tetromino->x -= BLOCK_SIZE;
            tetromino->move_time = 0;
        }

        if (tetromino->x - tetromino->offset_x < BOARD_START) {
            tetromino->x = tetromino->offset_x + BOARD_START;
        }
    }
    
    /* If the tetromino has reached the end of the board */
    if (check_collision(0, 1)) {
	    
	    /* Add the tetromino to the board */
	    add_to_board();
	    
	    /* Free the tetromino struct */
	    free(tetromino);
	    
	    /* Set the current tetromino to the 'next' tetromino and set the proper coordinates*/
	    tetromino = next;
		tetromino->x = BOARD_START + 5 * BLOCK_SIZE - tetromino->offset_x;
		tetromino->y = START_HEIGHT + tetromino->offset_y;
		
		/* Instantiate a new 'next' tetromino */
	    next = new_tetromino(0);
    }
}


/* rotate - rotate a tetromino */
void rotate() {

    int i, temp;

    if (tetromino->type != SQUARE) {

        /* rotate the tetromino */
        for (i = 0; i < 4; i++) {
            temp = tetromino->coords[i][0];
            tetromino->coords[i][0] = tetromino->coords[i][1];
            tetromino->coords[i][1] = -1 * temp;
        }
        
        /* Update the width and height of the tetromino */
        tetromino->w = get_tetro_width(tetromino);
        tetromino->h = get_tetro_height(tetromino);
        
        /* Update the offsets */
        tetromino->offset_x = get_offset_x(tetromino);
        tetromino->offset_y = get_offset_y(tetromino);

        /* If the rotation forces the tetromino off-screen, move it */
        if (tetromino->x - tetromino->offset_x < BOARD_START) {
            tetromino->x = tetromino->offset_x + BOARD_START;
        }

        if (tetromino->x + (tetromino->w * BLOCK_SIZE) - tetromino->offset_x > BOARD_END) {
            tetromino->x = BOARD_END - (tetromino->w * BLOCK_SIZE) + tetromino->offset_x;
        }
    }
}


/* print_tetromino - prints a Tetromino struct */
void print_tetromino(Tetromino *mino) {
	
	int i;

	printf("x: %d y: %d h: %d w: %d\n", mino->x, mino->y, mino->h, mino->w);
	printf("wait_time: %d move_time: %d\n", mino->wait_time, mino->move_time);
	printf("offset_x: %d offset_y %d\n", mino->offset_x, mino->offset_y);
	
	printf("coords: {");
	for (i = 0; i < 4; i++) {
		printf("{%d, %d} ", mino->coords[i][0], mino->coords[i][1]);
	}
	printf("}\n");
	
	if (mino->type == NO_SHAPE) {
		printf("type: NO_SHAPE\n");
	} else if (mino->type == LINE) {
		printf("type: LINE\n");
	} else if (mino->type == SQUARE) {
		printf("type: SQUARE\n");
	} else if (mino->type == T_SHAPE) {
		printf("type: T_SHAPE\n");
	} else if (mino->type == J_SHAPE) {
		printf("type: J_SHAPE\n");
	} else if (mino->type == L_SHAPE) {
		printf("type: L_SHAPE\n");
	} else if (mino->type == S_SHAPE) {
		printf("type: S_SHAPE\n");
	} else if (mino->type == Z_SHAPE) {
		printf("type: Z_SHAPE\n");
	}
	
	printf("color: (%d, %d, %d)\n", mino->color.r, mino->color.g, mino->color.b);
}
