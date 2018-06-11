#include <SDL.h>
#include <SDL_mixer.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stageInit.h"
#include "graphics.h"
#include "util.h"
#include "frame.h"



int main(){

	int windowWidth = 640;
	int windowHeight = 480;



	// INIT SDL etc.
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
	//logSDLError("INIT_VIDEO");
		printf("%s\n", "INIT_VIDEO != 0");
		return 1;
	}

	SDL_Window *win = SDL_CreateWindow("SWINGER", 100,100,windowWidth,windowHeight, SDL_WINDOW_SHOWN);
	if (win == NULL){
		//logSDLError("CreateWindow");
		printf("%s\n", "WINDOW = NULL");
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL){
		SDL_DestroyWindow(win);
		//logSDLError("SDL_CreateRenderer");
		printf("%s\n", "Renderer = NULL");
		SDL_Quit();
		return 1;
	}

	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return 1;    
    }
    Mix_Music *music;

    //Seed random number generator
    //int seed = currentTimeAsInt();
	//srand(seed);    


	//. GAME LOOP:

	float deltaTime = 1000/60;


	struct inputData id = {.quit = false};

	struct stageData data;
	initStage(&data);



	music = Mix_LoadMUS("swinger.wav");

	if( Mix_PlayMusic( music, -1 ) == -1 ){
		return 1;
	}

	int time = 0;

	bool run = true;

	while(run){

		//TODO AUDIO HANDLER

		run = oneFrame(&data, &id, time, deltaTime, windowWidth, windowHeight);
		draw(ren, &data, &id, time, windowWidth, windowHeight);
		time++;
		SDL_PumpEvents();
		SDL_Delay(deltaTime);

		time++;	

	}

	// CLEAN UP BEFORE EXIT

	Mix_FreeMusic(music);


	Mix_CloseAudio();
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();
	return 0;

}