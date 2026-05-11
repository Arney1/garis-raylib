#include "coords.h"
#include "raylib.h"
#include "screen_type.h"
#include "src/algo/bresenham.h"
#include "src/algo/midcircle.h"
#include "src/screens/tugas3_3.h"
#include "src/ui/back_button.h"
#include <math.h>

void DrawTugas3_3(void) {
  G_OriginX = SCREEN_W / 2;
  G_OriginY = SCREEN_H / 2 + 30;
  G_TickStep = 38;

  ClearBackground((Color){10, 12, 26, 255});
  DrawRectangle(0, 0, SCREEN_W, 64, (Color){0, 0, 0, 210});
  DrawBackButton();
  DrawText("TUGAS 3.3 - Easing smoothstep", 140, 12, 28, WHITE);
  DrawText("Soal + Jawaban", 140, 40, 14, LIGHTGRAY);

  DrawRectangleRounded((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                       0.02f, 8, (Color){0, 0, 0, 150});
  DrawRectangleRoundedLines((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                            0.02f, 8, SKYBLUE);

  DrawText("SOAL:", 56, 132, 22, (Color){255, 220, 120, 255});
  DrawText("Ganti interpolasi linear dengan easing f(t)=t^2(3-2t).", 56, 170,
           20, LIGHTGRAY);

  DrawText("JAWABAN:", 56, 230, 22, (Color){120, 255, 180, 255});
  DrawText("Implementasi: tLin -> tEase = tLin*tLin*(3-2*tLin).", 56, 222 + 32,
           20, (Color){190, 230, 255, 255});
  DrawText("Gunakan tEase saat hitung currentHalfArc.", 56, 248 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("Hasil: awal-akhir lebih halus, tanpa perubahan mendadak.", 56,
           274 + 32, 20, (Color){190, 230, 255, 255});

  float t = fmodf((float)GetTime(), 1.0f);
  float s = t * t * (3.0f - 2.0f * t);
  DrawRectangle(56, 360, 380, 20, (Color){50, 50, 70, 255});
  DrawRectangle(56, 360, (int)(380 * s), 20, (Color){120, 220, 255, 255});
  DrawText("smoothstep(t)=t*t*(3-2*t)", 56, 388, 18, SKYBLUE);

  DrawText("[ESC/BACKSPACE] Kembali  |  Klik BACK", 12, SCREEN_H - 22, 14,
           DARKGRAY);
}
