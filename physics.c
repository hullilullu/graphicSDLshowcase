#include <math.h>

float getXcoordFromPolar(float x, float radius, float angle){
	return x + radius * cos(angle);
}

float getYcoordFromPolar(float y, float radius, float angle){
	return y + radius * sin(angle);
}

float distanceSquared(float x1, float y1, float x2, float y2){
	float x = x1 - x2;
	float y = y1 - y2;
	return  x*x + y*y;
}