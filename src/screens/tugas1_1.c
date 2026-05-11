#include "coords.h"
#include "raylib.h"
#include "screen_type.h"
#include "src/algo/bresenham.h"
#include "src/algo/midcircle.h"
#include "src/screens/tugas1_1.h"
#include "src/ui/back_button.h"
#include <math.h>

void DrawTugas1_1(void) {
  G_OriginX = SCREEN_W / 2;
  G_OriginY = SCREEN_H / 2 + 30;
  G_TickStep = 38;

  ClearBackground((Color){10, 12, 26, 255});
  DrawRectangle(0, 0, SCREEN_W, 64, (Color){0, 0, 0, 210});
  DrawBackButton();
  DrawText("TUGAS 1.1 - Midpoint Circle r=3", 140, 12, 28, WHITE);
  DrawText("Soal + Jawaban", 140, 40, 14, LIGHTGRAY);

  DrawRectangleRounded((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                       0.02f, 8, (Color){0, 0, 0, 150});
  DrawRectangleRoundedLines((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                            0.02f, 8, SKYBLUE);

  DrawText("SOAL:", 56, 132, 22, (Color){255, 220, 120, 255});
  DrawText("1) Buat tabel iterasi midpoint circle untuk pusat (0,0), r=3.", 56,
           170, 20, LIGHTGRAY);
  DrawText("2) Kolom: x, y, d, keputusan (E/SE), titik yang diplot.", 56, 196,
           20, LIGHTGRAY);

  DrawText("JAWABAN:", 56, 256, 22, (Color){120, 255, 180, 255});
  DrawText("d0 = 3 - 2r = 3 - 6 = -3, mulai (x,y)=(0,3).", 56, 248 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("Iter0: d=-3 <0 -> E, d=-3+4(0)+6=3, x=1,y=3.", 56, 274 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("Iter1: d=3 >=0 -> SE, d=3+4(1-3)+10=5, x=2,y=2.", 56, 300 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("Iter2: d=5 >=0 -> SE, d=5+4(2-2)+10=15, x=3,y=1 (stop).", 56,
           326 + 32, 20, (Color){190, 230, 255, 255});
  DrawText("Titik unik per langkah: (0,3),(1,3),(2,2) lalu simetri 8-way.", 56,
           352 + 32, 20, (Color){190, 230, 255, 255});

  Midcircle(SCREEN_W - 210, 260, 90, RED);
  DrawText("Visual r=3 (diskalakan)", SCREEN_W - 290, 360, 16, RED);

  DrawText("[ESC/BACKSPACE] Kembali  |  Klik BACK", 12, SCREEN_H - 22, 14,
           DARKGRAY);
}
