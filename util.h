#ifndef UTIL_FILE
#define UTIL_FILE

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_BALLS 20

struct ball{
	bool active;
	float x;
	float y;
	float vx;
	float vy;
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

struct light{
	float x;
	float y;
	bool on;
};

struct mainCharacter{
	float x;
	float y;
	float vx;
	float vy;
	bool latchedOn;
	int latchedIndex;
};

struct handle{
	float x;
	float y;
	double angle;
	float angularSpeed;
	float radPos;
	float radSpeed;
	float radius;
	bool active;
	//enum handleType type;
};

struct candy{
	float x;
	float y;
	bool active;
};

struct flash{
	float x[5];
	float y[5];
	int countDown;
	int len;
};

struct stageData{
	struct ball balls[MAX_BALLS];
	struct light light;
};

struct runData{
	int handlesTouched;
	char *music;
};

struct inputData{
	int mouseX;
	int mouseY;
	bool mouseButton;
	bool quit;
};

#endif