#include "coords.h"
#include "raylib.h"
#include "screen_type.h"
#include "src/algo/bresellipse.h"
#include "src/algo/midellipse.h"
#include "src/screens/menu.h"

void DrawMenu(void) {
  G_OriginX = 0;
  G_OriginY = 0;
  G_TickStep = 1;

  ClearBackground((Color){10, 12, 25, 255});

  // Header
  DrawRectangle(0, 0, SCREEN_W, 80, (Color){20, 20, 50, 255});
  DrawText("Tugas 1: Grafika Komputer", SCREEN_W / 2 - 180, 15, 30, WHITE);
  DrawText("Algoritma & Transformasi Elips  |  Raylib 6.0", SCREEN_W / 2 - 200,
           50, 18, LIGHTGRAY);
  DrawLine(0, 80, SCREEN_W, 80, (Color){60, 80, 160, 255});

  // Main Card for Tugas 1 Creation
  int cW = 380, cH = 160;
  int startX = SCREEN_W / 2 - cW / 2;
  int startY = 160;

  DrawRectangleRounded((Rectangle){startX, startY, cW, cH}, 0.1f, 8,
                       (Color){15, 40, 70, 255});
  DrawRectangleRoundedLines((Rectangle){startX, startY, cW, cH}, 0.1f, 8,
                            SKYBLUE);

  DrawText("TUGAS 1", startX + 25, startY + 20, 24, SKYBLUE);
  DrawText("Kreasi Tata Surya 2D Statis", startX + 25, startY + 55, 16, WHITE);

  // Mini visual flair on the card
  MidpointEllipse(startX + cW - 75, startY + 65, 40, 20,
                  (Color){100, 200, 255, 150});
  MidpointEllipseFilled(startX + cW - 75, startY + 65, 12, 12,
                        (Color){255, 200, 100, 255});

  DrawText("Implementasi Midpoint & Bresenham", startX + 25, startY + 95, 13,
           LIGHTGRAY);
  DrawText("Serta Transformasi Translasi & Skala", startX + 25, startY + 115,
           13, LIGHTGRAY);
  DrawText("[Tekan 1]", startX + cW - 90, startY + cH - 30, 16, SKYBLUE);

  // About Button
  int abBtnW = 200, abBtnH = 40;
  int abBtnX = SCREEN_W / 2 - abBtnW / 2;
  int abBtnY = startY + cH + 50;
  Vector2 mouse = GetMousePosition();
  int abHover = CheckCollisionPointRec(
      mouse, (Rectangle){abBtnX, abBtnY, abBtnW, abBtnH});

  DrawRectangleRounded((Rectangle){abBtnX, abBtnY, abBtnW, abBtnH}, 0.3f, 6,
                       abHover ? (Color){60, 100, 180, 230}
                               : (Color){25, 35, 70, 220});
  DrawRectangleRoundedLines((Rectangle){abBtnX, abBtnY, abBtnW, abBtnH}, 0.3f,
                            6, abHover ? WHITE : (Color){80, 110, 200, 255});
  DrawText("[ A ] About", abBtnX + 55, abBtnY + 11, 16, WHITE);

  // Footer
  DrawRectangle(0, SCREEN_H - 45, SCREEN_W, 45, (Color){15, 15, 35, 255});
  DrawLine(0, SCREEN_H - 45, SCREEN_W, SCREEN_H - 45,
           (Color){60, 80, 160, 255});
  DrawText("[1] Buka Tugas 1  |  [A] About Profile  |  [ESC] Keluar",
           SCREEN_W / 2 - 180, SCREEN_H - 30, 14, GRAY);
}
