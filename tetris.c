#include "tetris.h"


int main(int argv, char **args) {

    /* Set the framelimit */
    unsigned int frame_limit = SDL_GetTicks() + 16;

    /* Game loop boolean */
    bool running = true;
    
    /* Seed for random numbers */
	srand(time(NULL));

    /* Start SDL */
    init("Tetris");

    /* Initialize the game struct */
    init_game();

    /* Create a new tetromino */
    next = new_tetromino(0);
    tetromino = new_tetromino(1);
    assert(next != NULL && tetromino != NULL);

    /* Initialize the board */
    init_board();

    /* Clean up on exit */
    atexit(cleanup);


    /* Game loop */
    while (running) {
	    
        /* Get user input */
        get_input();

        /* If the game isn't paused */
        if (!game.paused) {
	        
			/* Move the tetromino accordingly */
			move_tetromino();
        }
        
        if (!(game.animate || game.remove)) {
	        
			/* Check for full rows */
			check_full_row();
        }

        /* Draw the tetromino */
        draw();

        /* Sleep for a bit */
        delay(frame_limit);
        frame_limit = SDL_GetTicks() + 16;
    }

    /* Exit the program */
    exit(0);
}


/* init_game - initialize the game struct */
void init_game() {

	int i;

    game.font = load_font("font/blackWolf.ttf", 22);
    game.large_font = load_font("font/blackWolf.ttf", 32);
    game.current_wait_time = INITIAL_WAIT_TIME;
    game.game_over = game.paused = game.animate = game.remove = false;
    game.num_animation_rows = game.animate_time = game.current_score = 0;
    game.animate_times = 4;
    game.current_level = 1;
    
    for (i = 0; i < 20; i++) {
	    game.remove_rows[i] = 0;
    }
}
