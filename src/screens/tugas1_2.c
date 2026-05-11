#include "coords.h"
#include "raylib.h"
#include "screen_type.h"
#include "src/algo/bresenham.h"
#include "src/algo/midcircle.h"
#include "src/screens/tugas1_2.h"
#include "src/ui/back_button.h"
#include <math.h>

void DrawTugas1_2(void) {
  G_OriginX = SCREEN_W / 2;
  G_OriginY = SCREEN_H / 2 + 30;
  G_TickStep = 38;

  ClearBackground((Color){10, 12, 26, 255});
  DrawRectangle(0, 0, SCREEN_W, 64, (Color){0, 0, 0, 210});
  DrawBackButton();
  DrawText("TUGAS 1.2 - Kenapa d0 = 3 - 2r", 140, 12, 28, WHITE);
  DrawText("Soal + Jawaban", 140, 40, 14, LIGHTGRAY);

  DrawRectangleRounded((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                       0.02f, 8, (Color){0, 0, 0, 150});
  DrawRectangleRoundedLines((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                            0.02f, 8, SKYBLUE);

  DrawText("SOAL:", 56, 132, 22, (Color){255, 220, 120, 255});
  DrawText("Jelaskan mengapa implementasi pakai d0 = 3 - 2r, bukan 1.25 - r.",
           56, 170, 20, LIGHTGRAY);

  DrawText("JAWABAN:", 56, 230, 22, (Color){120, 255, 180, 255});
  DrawText("Nilai teoritis midpoint awal: f(1, r-0.5) = 1.25 - r.", 56,
           222 + 32, 20, (Color){190, 230, 255, 255});
  DrawText("Agar tanpa pecahan: kalikan 4 -> 5 - 4r.", 56, 248 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("Bresenham memakai bentuk integer ekuivalen 3 - 2r (skala berbeda).",
           56, 274 + 32, 20, (Color){190, 230, 255, 255});
  DrawText(
      "Keputusan tanda (d<0 atau d>=0) tetap sama, jadi jalur piksel identik.",
      56, 300 + 32, 20, (Color){190, 230, 255, 255});
  DrawText("Hasil: operasi lebih cepat, murni integer, cocok untuk raster.", 56,
           326 + 32, 20, (Color){190, 230, 255, 255});

  DrawText("[ESC/BACKSPACE] Kembali  |  Klik BACK", 12, SCREEN_H - 22, 14,
           DARKGRAY);
}
