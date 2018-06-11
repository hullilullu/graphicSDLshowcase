#include <SDL.h>
#include <SDL_image.h>
#include <math.h>
#include <stdlib.h>
#include "util.h"

#define MAX_BALLS 20



void drawRandomlyFlickeringCircle(SDL_Renderer *ren, float x, float y, float radius, Uint8 red, Uint8 green, Uint8 blue){

	for (int yp = y-radius; yp < y+radius; yp++){

		int sinus = (int) sqrt(radius*radius - (y-yp)*(y-yp));
		for (int xp = x - sinus; xp < x + sinus; xp++){
			float randomFactor = 0.5 + 0.5*(float)rand()/(float)RAND_MAX;
			//SDL_Rect fillRect = { xp - 1, yp - 1, 5, 5 };
    		SDL_SetRenderDrawColor( ren, randomFactor*(red - red*(((y-yp)*(y-yp)+(x-xp)*(x-xp))/radius / (radius + 2))), 
    			randomFactor*(green - green*(((y-yp)*(y-yp)+(x-xp)*(x-xp))/radius / (radius + 2))), 
    			randomFactor*(blue - blue*(((y-yp)*(y-yp)+(x-xp)*(x-xp))/radius / (radius + 2))), 0xFF);        
    		//SDL_RenderFillRect( ren, &fillRect );
    		SDL_RenderDrawPoint( ren, xp, yp);
    	}
	}


}

void drawRoundMirror(SDL_Renderer *ren, float x, float y, float radius, Uint8 red, Uint8 green, Uint8 blue, float lightX, float lightY){

	for (int yp = y-radius; yp < y+radius; yp++){

		int sinus = (int) sqrt(radius*radius - (y-yp)*(y-yp));
		for (int xp = x - sinus; xp < x + sinus; xp++){
			float randomFactor = 0.5 + 0.5*(float)rand()/(float)RAND_MAX;

			float xl = 0.45*(xp - lightX)/radius;
			float yl = 0.45*(yp - lightY)/radius;
			float r = (xl*xl + yl*yl);
			float factor;
			if (r > 1) factor = 1;
			else factor = r;
			//SDL_Rect fillRect = { xp - 1, yp - 1, 5, 5 };
    		SDL_SetRenderDrawColor( ren, red - red * factor, 
    			0, 0, 0xFF);        
    		//SDL_RenderFillRect( ren, &fillRect );
    		SDL_RenderDrawPoint( ren, xp, yp);
    	}
	}


}



void drawBall(SDL_Renderer *ren, struct ball b, int cameraX, int cameraY){
	drawRandomlyFlickeringCircle(ren, b.x, b.y, 8, b.red, b.green, b.blue);
}


void draw(SDL_Renderer *ren, struct stageData *data, struct inputData *id, int time, int screenWidth, int screenHeight){

	int cameraX = data->light.x;
	int cameraY = data->light.y;

	SDL_SetRenderDrawColor( ren, 0, 0, 0, 0xFF );
	SDL_RenderClear(ren);

	for(int i = 0; i < MAX_BALLS; i++){
		if(data->balls[i].active){
		drawBall(ren, data->balls[i], cameraX, cameraY);
		}	
	}

	drawRoundMirror(ren, screenWidth/2, screenHeight/2, 100, 125, 0, 0, data->light.x, data->light.y);
	

    SDL_RenderPresent(ren);
}