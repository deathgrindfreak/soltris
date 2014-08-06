#include "input.h"


/* get_input - get input from the user and perform appropriate actions */
void get_input() {

    SDL_Event event;

    /* Loop through events */
    while (SDL_PollEvent(&event)) {

        switch(event.type) {

            case SDL_QUIT:
                exit(0);
                break;

            /* In case of a key press */
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {

                    case SDLK_UP:
	                    if (!game.paused) {
							rotate();
	                    } else {
		                    if (arrow.y == 0) {
			                    arrow.y = 100;
		                    } else {
			                    arrow.y -= 50;
		                    }
	                    }
                        break;

                    case 'k': 
                        rotate();
                        break;

                    case SDLK_DOWN:
	                    if (!game.paused) {
							input.down = true;
	                    } else {
		                    if (arrow.y == 100) {
			                    arrow.y = 0;
		                    } else {
			                    arrow.y += 50;
		                    }
	                    }
                        break;

                    case 'j':
                        input.down = true;
                        break;

                    case SDLK_LEFT:
	                    if (!game.game_over) {
							input.left = true;
	                    } else {
		                    if (arrow.x == 0) {
			                    arrow.x = 1;
		                    } else if (arrow.x == 1) {
			                    arrow.x = 0;
		                    }
	                    }
                        break;

                    case 'h':
                        input.left = true;
                        break;

                    case SDLK_RIGHT:
	                    if (!game.game_over) {
							input.right = true;
	                    } else {
		                    if (arrow.x == 0) {
			                    arrow.x = 1;
		                    } else if (arrow.x == 1) {
			                    arrow.x = 0;
		                    }
	                    }
                        break;

                    case 'l':
                        input.right = true;
                        break;
                        
					case 'p':
						game.paused = !game.paused;
						break;

					case SDLK_ESCAPE:
						game.paused = !game.paused;
						break;
						
					case SDLK_RETURN:
						if (game.paused) {
							if (arrow.y == 0) {
								new_game();
							} else if (arrow.y == 50) {
								/* high score stuff */
							} else if (arrow.y == 100) {
								exit(0);
							}
						} else if (game.game_over) {
							if (arrow.x == 0) {
								game.game_over = false;
								new_game();
							} else if (arrow.x == 1) {
								exit(0);
							}
						}
						break;

                    default:
                        break;
                }
                break;

            /* In case of a key release */
            case SDL_KEYUP:
                switch(event.key.keysym.sym) {

                    case SDLK_DOWN:
                        input.down = false;
                        break;

                    case 'j':
                        input.down = false;
                        break;

                    case SDLK_LEFT:
                        input.left = false;
                        break;

                    case 'h':
                        input.left = false;
                        break;

                    case SDLK_RIGHT:
                        input.right = false;
                        break;

                    case 'l':
                        input.right = false;
                        break;

                    default:
                        break;
                }
                break;
        }
    }
}
