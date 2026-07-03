#include "raylib.h"
#include "screen_type.h"
#include "src/screens/about.h"
#include "src/screens/menu.h"
#include "src/screens/tugas1_creation.h"
#include "src/ui/back_button.h"

int main(void) {
  // Judul window disesuaikan dengan topik tugas 1 Anda
  InitWindow(SCREEN_W, SCREEN_H,
             "Tugas 1 Grafika Komputer - Algoritma & Transformasi Elips");
  SetTargetFPS(60);

  Screen current = MENU;

  // Koordinat tombol About disesuaikan dengan menu.c baru:
  // startY(160) + cH(160) + offset(50) = 370
  int abBtnW = 200;
  int abBtnH = 40;
  int abBtnX = SCREEN_W / 2 - abBtnW / 2;
  int abBtnY = 370;

  while (!WindowShouldClose()) {
    if (current == MENU) {
      // Hanya merespon input ke Tugas 1 atau ke About screen
      if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_KP_1))
        current = TUGAS1;
      if (IsKeyPressed(KEY_A))
        current = ABOUT;

      // Deteksi klik mouse pada tombol About yang baru
      Vector2 m = GetMousePosition();
      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
          CheckCollisionPointRec(m,
                                 (Rectangle){(float)abBtnX, (float)abBtnY,
                                             (float)abBtnW, (float)abBtnH})) {
        current = ABOUT;
      }
    }

    // Menangani tombol back atau ESC/Backspace untuk kembali ke menu utama
    if (current != MENU && BackButtonPressed())
      current = MENU;

    BeginDrawing();
    switch (current) {
    case MENU:
      DrawMenu();
      break;
    case TUGAS1:
      DrawTugas1Creation();
      break;
    case ABOUT:
      DrawAbout();
      break;
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
