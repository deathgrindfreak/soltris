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
                        rotate();
                        break;

                    case 'k': 
                        rotate();
                        break;

                    case SDLK_DOWN:
                        input.down = true;
                        break;

                    case 'j':
                        input.down = true;
                        break;

                    case SDLK_LEFT:
                        input.left = true;
                        break;

                    case 'h':
                        input.left = true;
                        break;

                    case SDLK_RIGHT:
                        input.right = true;
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
