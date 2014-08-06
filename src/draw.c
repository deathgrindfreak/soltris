#include "draw.h"


void draw() {
	
	char level[20], score[20];

    /* Blank the screen */
    SDL_FillRect(game.screen, NULL, SDL_MapRGB(game.screen->format, 
                                               BACKGROUND_R,
                                               BACKGROUND_G,
                                               BACKGROUND_B));
    
    /* Draw the background boxes */
    draw_score_next_boxes();
    
    
    /* If rows are to be animated and removed */
    if (game.animate && game.remove) {
	    
	    int i, k, row_nums[20];
	    
		/* set the number of rows to zero */
		game.num_animation_rows = 0;
		
		/* Move the row numbers into the row_nums */
		for (i = 0; i < 20; i++) {
			if (game.remove_rows[i]) {
				row_nums[game.num_animation_rows++] = i;
			}
		}
		
		/* Move the colors for the rows to moved into the animate_colors array */
		for (i = 0; i < game.num_animation_rows; i++) {
			for (k = 0; k < 10; k++) {
				if (board[10 * row_nums[i] + k].color.r != 255) {
					game.animate_colors[10 * i + k].r = board[10 * row_nums[i] + k].color.r;
					game.animate_colors[10 * i + k].g = board[10 * row_nums[i] + k].color.g;
					game.animate_colors[10 * i + k].b = board[10 * row_nums[i] + k].color.b;
				}
			}
		}
	    
	    if (game.animate_times) {
	    
			if (game.animate_time >= ANIMATE_TIME) {

				if (game.animate_times % 2 == 0) {
					swap_animate_colors(true);
					game.animate_times--;
				} else {
					swap_animate_colors(false);
					game.animate_times--;
				}

				game.animate_time = 0;

			} else {
				game.animate_time++;
			}
		
	    } else {
		    game.animate = false;
	    }
	        
    } else if (game.remove) {
	    
	    int i, num_rows = 0;

	    /* reset the animation count */
		game.animate_times = 4;
		
		/* for every full row, remove and count */
		for (i = 0; i < 20; i++) {
			if (game.remove_rows[i]) {
				remove_row(i);
				num_rows++;
			}
		}
	
		/* Increment the score if rows were removed */
		if (num_rows == 1) {
			game.current_score += 40 * game.current_level; 
		} else if (num_rows == 2) {
			game.current_score += 100 * game.current_level; 
		} else if (num_rows == 3) {
			game.current_score += 300 * game.current_level; 
		} else if (num_rows == 4) {
			game.current_score += 1200 * game.current_level; 
		}


		/* Increment the level every 1000 points and speed up the movement */
		while ((game.current_score / game.current_level) >= 1000) {

			if (game.current_level <= 99)
				game.current_level += 1;

			if (game.current_wait_time > 5)
				game.current_wait_time -= 3;
		}
		
		game.remove = false;
    }

    /* Draw the board */
    draw_board();
    
    /* Draw the strings */
    draw_string("Next", NEXT_WINDOW_X + 30, NEXT_WINDOW_Y + 5, game.font, false, false);
    draw_string("Score", SCORE_X + 25, SCORE_Y + 5, game.font, false, false);
    draw_string("Level", LEVEL_X + 28, LEVEL_Y + 5, game.font, false, false);
    
    sprintf(level, "%d", game.current_level);
    sprintf(score, "%d", game.current_score);
    draw_string(score, SCORE_X + 55, SCORE_Y + 37, game.font, true, false);
    draw_string(level, LEVEL_X + 55, LEVEL_Y + 37, game.font, true, false);

    /* Draw the tetromino */
	draw_tetromino(next);
		
    if (!game.game_over) {
		draw_tetromino(tetromino);
    } else {
	    draw_trunc_tetromino(tetromino);
    }
    
    /* if the game is paused, draw the menu */
    if (game.paused) {
	    draw_menu();
	    draw_arrow();
    }
    
    if (game.game_over) {
	    draw_game_over_menu();
	    draw_arrow();
    }


    /* Flip the buffer */
    SDL_Flip(game.screen);

    /* Sleep Briefly */
    SDL_Delay(1);
}


/* delay - set a delay for the CPU (minimum of 60 FPS) */
void delay(unsigned int frame_limit) {
unsigned int ticks = SDL_GetTicks(); 
    if (frame_limit < ticks) {
        return;
    } else if (frame_limit > ticks + 16) {
        SDL_Delay(16);
    } else {
        SDL_Delay(frame_limit - ticks);
    }
}


/* animate - animates a full row before it's removed */
void swap_animate_colors(bool white) {

	int i, k, rows = 0, row_nums[20];
	
	/* Move the row numbers into the row_nums */
	for (i = 0; i < 20; i++) {
		if (game.remove_rows[i]) {
			row_nums[rows++] = i;
		}
	}

	if (white) {
		
		for (i = 0; i < game.num_animation_rows; i++) {
			for (k = 0; k < 10; k++) {
				board[10 * row_nums[i] + k].color.r = 255;
				board[10 * row_nums[i] + k].color.g = 255;
				board[10 * row_nums[i] + k].color.b = 255;
			}
		}
		
	} else {
		
		for (i = 0; i < game.num_animation_rows; i++) {
			for (k = 0; k < 10; k++) {
				board[10 * row_nums[i] + k].color.r = game.animate_colors[10 * i + k].r;
				board[10 * row_nums[i] + k].color.g = game.animate_colors[10 * i + k].g;
				board[10 * row_nums[i] + k].color.b = game.animate_colors[10 * i + k].b;
			}
		}
	}
}
