#include <SDL.h>
#include <stdbool.h>
#include "util.h"
#include "eventHandling.h"
#include "gamelogic.h"



bool oneFrame(struct stageData *data, struct inputData *input, int time, float deltaTime, int windowWidth, int windowHeight){

	//GETS mouse and keyboard input
	handleEvents(input);
	if (input->quit){
		return false;
	}

	//spawn a new ball every second
	if (time % 180 == 0){
		spawnBall(data, (float) windowWidth, (float) windowHeight/2, time%255, 0xFF, 0xFF);
	}

	ballMovement(data, input, deltaTime);
	lightMovement(data, input, windowWidth, windowHeight);

	return true;
}