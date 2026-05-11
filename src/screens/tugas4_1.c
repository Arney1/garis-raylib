#include "coords.h"
#include "raylib.h"
#include "screen_type.h"
#include "src/algo/bresenham.h"
#include "src/algo/midcircle.h"
#include "src/screens/tugas4_1.h"
#include "src/ui/back_button.h"
#include <math.h>

void DrawTugas4_1(void) {
  G_OriginX = SCREEN_W / 2;
  G_OriginY = SCREEN_H / 2 + 30;
  G_TickStep = 38;

  ClearBackground((Color){10, 12, 26, 255});
  DrawRectangle(0, 0, SCREEN_W, 64, (Color){0, 0, 0, 210});
  DrawBackButton();
  DrawText("TUGAS 4.1 - Hitung PM, C1, C2 (NE)", 140, 12, 28, WHITE);
  DrawText("Soal + Jawaban", 140, 40, 14, LIGHTGRAY);

  DrawRectangleRounded((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                       0.02f, 8, (Color){0, 0, 0, 150});
  DrawRectangleRoundedLines((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                            0.02f, 8, SKYBLUE);

  DrawText("SOAL:", 56, 132, 22, (Color){255, 220, 120, 255});
  DrawText("R=100, pangkal (300,300), angle=-pi/4 (Timur Laut).", 56, 170, 20,
           LIGHTGRAY);

  DrawText("JAWABAN:", 56, 230, 22, (Color){120, 255, 180, 255});
  DrawText("h=R*sqrt(3)/2=86.60, halfR=50.", 56, 222 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("PM=(300+61.24, 300-61.24)=(361.24,238.76).", 56, 248 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("C1=(325.88,203.40), C2=(396.60,274.12).", 56, 274 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("Arc C1: -15 deg..105 deg, Arc C2: 165 deg..285 deg.", 56, 300 + 32,
           20, (Color){190, 230, 255, 255});

  DrawText("[ESC/BACKSPACE] Kembali  |  Klik BACK", 12, SCREEN_H - 22, 14,
           DARKGRAY);
}
