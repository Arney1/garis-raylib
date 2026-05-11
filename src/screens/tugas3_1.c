#include "coords.h"
#include "raylib.h"
#include "screen_type.h"
#include "src/algo/bresenham.h"
#include "src/algo/midcircle.h"
#include "src/screens/tugas3_1.h"
#include "src/ui/back_button.h"
#include <math.h>

void DrawTugas3_1(void) {
  G_OriginX = SCREEN_W / 2;
  G_OriginY = SCREEN_H / 2 + 30;
  G_TickStep = 38;

  ClearBackground((Color){10, 12, 26, 255});
  DrawRectangle(0, 0, SCREEN_W, 64, (Color){0, 0, 0, 210});
  DrawBackButton();
  DrawText("TUGAS 3.1 - halfArc saat animProgress=0.5", 140, 12, 28, WHITE);
  DrawText("Soal + Jawaban", 140, 40, 14, LIGHTGRAY);

  DrawRectangleRounded((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                       0.02f, 8, (Color){0, 0, 0, 150});
  DrawRectangleRoundedLines((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                            0.02f, 8, SKYBLUE);

  DrawText("SOAL:", 56, 132, 22, (Color){255, 220, 120, 255});
  DrawText("Hitung halfArc (derajat) saat animProgress = 0.5.", 56, 170, 20,
           LIGHTGRAY);

  DrawText("JAWABAN:", 56, 230, 22, (Color){120, 255, 180, 255});
  DrawText("Rumus: halfArc = PI - t*(PI - PI/3).", 56, 222 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("t=0.5 -> halfArc = PI - 0.5*(2PI/3) = 2PI/3 = 120 deg.", 56,
           248 + 32, 20, (Color){190, 230, 255, 255});
  DrawText("Artinya tiap lingkaran menggambar busur 240 deg (2*halfArc).", 56,
           274 + 32, 20, (Color){190, 230, 255, 255});
  DrawText("Visual: belum jadi vesica penuh, tetapi lebih ramping dari "
           "lingkaran penuh.",
           56, 300 + 32, 20, (Color){190, 230, 255, 255});

  DrawText("[ESC/BACKSPACE] Kembali  |  Klik BACK", 12, SCREEN_H - 22, 14,
           DARKGRAY);
}
