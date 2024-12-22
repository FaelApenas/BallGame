#include "../inc/render.h"
#include <raylib.h>
#include <stdint.h>
#include <stdio.h>

/*UPDATE CYCLE FUNCTION
 *
 *
 *
 */
void Update(PLAYER_T *p, BRICKS_T b[], BALL_T *ball) {
  uint8_t brick_check = 0;
  uint8_t brick_colided = 0;
  uint8_t player_colided = 0;

  DrawRectangleRec(p->player, WHITE);
  player_moviment(p);
  ball_moviment(ball);
  DrawCircleV(ball->ballPosition, ball->ballRadius, WHITE);
#ifdef DEBUGMODE
  DrawRectangleRec(ball->ballCollision, RED);

#endif

  for (int i = 0; i < TOTAL_OF_BLOCKS; i++) {
    if (b[i].IsAlive) {
      DrawRectangleRec(b[i].block, b[i].color);
      brick_check = CheckCollisionRecs(b[i].block, ball->ballCollision);
      if (brick_check) {
        brick_colided = 1;
        b[i].IsAlive = 0;
      }
    }
  }

  player_colided = CheckCollisionRecs(p->player, ball->ballCollision);
  ball_collisium(ball, brick_colided, player_colided, p->playerDirection);
  printf("%f\n", ball->ballAccX);
}

/*BALL COLLISIUM FUNCTION
 *
 *
 *
 */
void ball_collisium(BALL_T *ball, uint8_t brick_colided, uint8_t player_colided,
                    int8_t player_direction) {
  if (ball->ballPosition.x >= WIDTH - 10 || ball->ballPosition.x <= 10) {
    ball->ballDirection[1] = ball->ballDirection[1] * -1;
  }
  if (ball->ballPosition.y <= 10) {
    ball->ballDirection[2] = ball->ballDirection[2] * -1;
  }
  if (player_colided) {
    if (player_direction != 0) {
      ball->ballDirection[1] = player_direction;
      // ball->ballAccX -= 0.3;
      //  ball->ballAccY += 0.2;
    } else {
      ball->ballAccX -= 0.3;
      ball->ballAccY += 0.3;
    }
    if (player_direction == ball->ballDirection[1]) {
      ball->ballAccX += 0.3;
      ball->ballAccY -= 0.3;
    }
    ball->ballDirection[2] = ball->ballDirection[2] * -1;
  }
  if (brick_colided) {

    if (ball->ballDirection[2] == 1) {
      ball->ballDirection[1] = ball->ballDirection[1] * -1;
      //      ball->ballAccY += 0.3;
      //      ball->ballAccX -= 0.1;
    }
    ball->ballDirection[2] = ball->ballDirection[2] * -1;
  }
}

/*BALL MOVIMENT FUNCITION
 *
 *
 */
void ball_moviment(BALL_T *ball) {
  if (ball->ballAccX > MAX_ACC) {
    ball->ballAccX = MAX_ACC;
  }
  if (ball->ballAccY > MAX_ACC)
    ball->ballAccY = MAX_ACC;
  if (ball->ballAccX < MIN_ACC) {
    ball->ballAccX = MIN_ACC;
  }
  if (ball->ballAccY < MIN_ACC)
    ball->ballAccY = MIN_ACC;
  ball->ballPosition.y += ball->ballDirection[2] * ball->ballAccY * 4.00f;
  ball->ballPosition.x += ball->ballDirection[1] * ball->ballAccX * 4.00f;
  ball->ballCollision.y = ball->ballPosition.y - ball->ballRadius;
  ball->ballCollision.x = ball->ballPosition.x - ball->ballRadius;
}

/*PLAYER MOVIMENT FUNCTION
 *
 *
 *
 */
void player_moviment(PLAYER_T *p) {
  int BARRIER_X_BEHIND = 10;
  int BARRIER_X_FRONT = WIDTH - 120 - 10; // WIDTH - PLAYER_WIDTH-10
  if (IsKeyDown(KEY_RIGHT)) {
    p->player.x += PLAYER_VELOCITY;
    p->playerDirection = 1;
  } else if (IsKeyDown(KEY_LEFT)) {
    p->player.x -= PLAYER_VELOCITY;
    p->playerDirection = -1;
  } else {
    p->playerDirection = 0;
  }

  // BARRIER CHECK
  if (p->player.x > BARRIER_X_FRONT) {
    p->player.x = BARRIER_X_FRONT;
  }
  if (p->player.x < BARRIER_X_BEHIND) {
    p->player.x = BARRIER_X_BEHIND;
  }
}
