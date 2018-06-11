#include <SDL.h>
#include "util.h"
#include <stdbool.h>

void handleEvents(struct inputData *input){
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			printf("%s\n", "QUIT");
			input->quit = true;
		} else if (event.type == SDL_MOUSEBUTTONDOWN){
			input->mouseButton = true;
		} else if (event.type == SDL_MOUSEBUTTONUP){
			input->mouseButton = false;
		}else if (event.type == SDL_MOUSEMOTION){
			input->mouseX = event.motion.x;
			input->mouseY = event.motion.y;
		}
	}
}