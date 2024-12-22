#include "defines.h"
#include <raylib.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
  Rectangle block;
  Rectangle Collisium;
  bool IsAlive;
  Color color;
} BRICKS_T;

typedef struct {
  Vector2 ballPosition;
  float ballRadius;
  Rectangle ballCollision;
  int ballDirection[3];
  float ballAccX;
  float ballAccY;
} BALL_T;

typedef struct {
  Rectangle player;
  float playerVelocity;
  int8_t playerDirection;

} PLAYER_T;
// Color greenBlock, blueBlock, brownBlock, grayBlock, orangeBlock;

void set_ball(BALL_T *b);
void set_block(BRICKS_T bricks[]);
void set_player(PLAYER_T *p);
