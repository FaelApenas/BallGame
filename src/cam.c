#include "../inc/cam.h"

void set_camera(Camera2D *c) {
  c->target = (Vector2){0, 0};
  c->offset = (Vector2){0, 0};
  c->rotation = 0.0f;
  c->zoom = 1.0f;
}
