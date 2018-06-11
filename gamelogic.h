#ifndef GAMELOGIC_FILE
#define GAMELOGIC_FILE


void spawnBall(struct stageData *data, float x, float y, uint8_t red, uint8_t green, uint8_t blue);

void ballMovement(struct stageData *data, struct inputData *input, float deltaTime);

void lightMovement(struct stageData *data, struct inputData *input, int windowWidth, int windowHeight);

#endif