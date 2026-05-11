#include "coords.h"
#include "raylib.h"
#include "screen_type.h"
#include "src/algo/bresenham.h"
#include "src/algo/midcircle.h"
#include "src/screens/tugas5_3.h"
#include "src/ui/back_button.h"
#include <math.h>

void DrawTugas5_3(void) {
  G_OriginX = SCREEN_W / 2;
  G_OriginY = SCREEN_H / 2 + 30;
  G_TickStep = 38;

  ClearBackground((Color){10, 12, 26, 255});
  DrawRectangle(0, 0, SCREEN_W, 64, (Color){0, 0, 0, 210});
  DrawBackButton();
  DrawText("TUGAS 5.3 - Gradien HSV real-time", 140, 12, 28, WHITE);
  DrawText("Soal + Jawaban", 140, 40, 14, LIGHTGRAY);

  DrawRectangleRounded((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                       0.02f, 8, (Color){0, 0, 0, 150});
  DrawRectangleRoundedLines((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                            0.02f, 8, SKYBLUE);

  DrawText("SOAL:", 56, 132, 22, (Color){255, 220, 120, 255});
  DrawText("Buat warna 2 busur lensa berubah terhadap waktu (GetTime).", 56,
           170, 20, LIGHTGRAY);

  DrawText("JAWABAN:", 56, 230, 22, (Color){120, 255, 180, 255});
  DrawText("Pseudocode: hue1=fmod(time*speed,360), hue2=hue1+offset.", 56,
           222 + 32, 20, (Color){190, 230, 255, 255});
  DrawText("col1=ColorFromHSV(hue1,s,v), col2=ColorFromHSV(hue2,s,v).", 56,
           248 + 32, 20, (Color){190, 230, 255, 255});
  DrawText("Panggil DrawLens(..., col1, col2) setiap frame.", 56, 274 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("Untuk banyak lensa, tambah fase per indeks agar gradien menyebar.",
           56, 300 + 32, 20, (Color){190, 230, 255, 255});

  float t = (float)GetTime();
  float h1 = fmodf(t * 60.0f, 360.0f);
  float h2 = fmodf(h1 + 120.0f, 360.0f);
  Color c1 = ColorFromHSV(h1, 0.9f, 1.0f);
  Color c2 = ColorFromHSV(h2, 0.9f, 1.0f);
  DrawRectangle(56, 420, 140, 24, c1);
  DrawRectangle(204, 420, 140, 24, c2);
  DrawText("HSV hue berputar vs waktu", 56, 454, 18, LIGHTGRAY);

  DrawText("[ESC/BACKSPACE] Kembali  |  Klik BACK", 12, SCREEN_H - 22, 14,
           DARKGRAY);
}
