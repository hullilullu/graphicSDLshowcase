
#include <float.h>
#include <stdlib.h>
#include <math.h>

#include <stdio.h>
#include "util.h"
#include "physics.h"


#define MAX_BALLS 20

#define DEBUG false

void spawnBall(struct stageData *data, float x, float y, uint8_t red, uint8_t green, uint8_t blue){
	for (int i = 0; i < MAX_BALLS; i++){
		if (!data->balls[i].active){
			data->balls[i].active = true;
			data->balls[i].x = x;
			data->balls[i].y = y;
			data->balls[i].vx = -0.25;
			data->balls[i].vy = 0;
			data->balls[i].red = red;
			data->balls[i].green = green;
			data->balls[i].blue = blue;
			break;
		}
	}
}

void ballMovement(struct stageData *data, struct inputData *input, float deltaTime){
	for (int i = 0; i < MAX_BALLS; i++){
		data->balls[i].x += data->balls[i].vx;
		data->balls[i].y += data->balls[i].vy;		
	}
}

void lightMovement(struct stageData *data, struct inputData *input, int windowWidth, int windowHeight){
	data->light.x = input->mouseX - (input->mouseX - windowWidth/2)/2; //input->mouseX;//windowWidth/2 + (input->mouseX - windowWidth/2)/2;
	data->light.y = input->mouseY - (input->mouseY - windowHeight/2)/2; //input->mouseY;//windowHeight/2 + (input->mouseY - windowHeight/2)/2;
}