#include "defines.h"
#include "objects.h"
#include <raylib.h>
#include <stdint.h>


void player_moviment(PLAYER_T *p);
void ball_moviment(BALL_T *ball);
void ball_collisium(BALL_T *ball, uint8_t brick_colided, uint8_t player_colided,
                    int8_t player_direction);
void Update(PLAYER_T *p, BRICKS_T b[], BALL_T *ball,int *score);
