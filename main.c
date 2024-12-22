#include "./inc/cam.h"
#include "./inc/render.h"
#include <raylib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

int main() {
  srand(time(0));
  InitWindow(WIDTH, GAME_SCREEN_HEIGHT, "Aquele jogo la");
  // Defines
  // Rectangle player = {520, 560, 120, 10};
  PLAYER_T player;
  BRICKS_T bricks[TOTAL_OF_BLOCKS];
  Camera2D camera = {0};
  Rectangle hud_bar = {0, 600, WIDTH, 100};
  BALL_T ball;
  set_ball(&ball);
  // sets
  SetTargetFPS(60);
  set_block(bricks);
  set_player(&player);
  set_camera(&camera);
  Color background = {0x1E, 0x20, 0x1E};

  while (!WindowShouldClose()) {
    ClearBackground(background);

    // Begin Draw
    BeginDrawing();
    BeginMode2D(camera);
    // DrawRectangleRec(ball_collision, RED);

    if (IsKeyPressed(KEY_SPACE)) {
      ball.ballPosition.y = HEIGHT / 2;
      ball.ballPosition.x = WIDTH / 2;
    }
    Update(&player, bricks, &ball);
    DrawRectangleRec(hud_bar, WHITE);
    EndMode2D();
    EndDrawing();
  }

  CloseWindow();
}