#include "../inc/objects.h"
#include <raylib.h>

void set_ball(BALL_T *b) {
  // BALL
  b->ballPosition.x = WIDTH / 2;
  b->ballPosition.y = HEIGHT / 2;
  b->ballRadius = 12.00f;
  b->ballDirection[1] = 1;
  b->ballDirection[2] = 1;
  // ball rectangle colissium;
  b->ballCollision.x = b->ballPosition.x - b->ballRadius;
  b->ballCollision.y = b->ballPosition.y - b->ballRadius;
  b->ballCollision.width = (b->ballRadius * 2) + 3;
  b->ballCollision.height = (b->ballRadius * 2) + 3;
  b->ballAccX = 1.00f;
  b->ballAccY = 1.00f;
}
void set_block(BRICKS_T bricks[]) {
  int block_x = 10;
  int block_y = 10;
  int shift_block = 0;
  int row_counter = 0;

  Color purpleBlock = GetColor(0x7A1CAC);
  Color orangeblock = GetColor(0xD95F59);
  Color greenBlock = GetColor(0x697565);
  Color blueBlock = GetColor(0xff00ffff);
  Color block_colors[5] = {orangeblock, greenBlock, blueBlock, purpleBlock};

  for (int i = 0; i < TOTAL_OF_BLOCKS; i++) {
    if (block_x + (row_counter * 80) > (WIDTH - 70)) {
      block_x = 10;
      block_y = block_y + 60;
      row_counter = 0;
    }

    bricks[i].block.x = block_x + (row_counter * 80);
    bricks[i].block.y = block_y;
    bricks[i].block.width = 70;
    bricks[i].block.height = 50;
    bricks[i].color = block_colors[rand() % 4];
    bricks[i].IsAlive = 1;
    row_counter++;
    bricks[i].Collisium.x = bricks[i].block.x;
    bricks[i].Collisium.y = bricks[i].block.y;
    bricks[i].Collisium.width = bricks[i].block.width + 20;
    bricks[i].Collisium.height = bricks[i].block.height + 20;
  }
}

void set_player(PLAYER_T *p) {
  //  Rectangle player = {520, 560, 120, 10};
  p->player.width = 120;
  p->player.height = 10;
  p->player.x = 520;
  p->player.y = 560;
  p->playerVelocity = 1;
  p->playerAcc=1;
  p->playerDirection = 0;
}
