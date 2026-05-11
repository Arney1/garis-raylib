#include "coords.h"
#include "raylib.h"
#include "screen_type.h"
#include "src/algo/bresenham.h"
#include "src/algo/midcircle.h"
#include "src/screens/tugas4_2.h"
#include "src/ui/back_button.h"
#include <math.h>

void DrawTugas4_2(void) {
  G_OriginX = SCREEN_W / 2;
  G_OriginY = SCREEN_H / 2 + 30;
  G_TickStep = 38;

  ClearBackground((Color){10, 12, 26, 255});
  DrawRectangle(0, 0, SCREEN_W, 64, (Color){0, 0, 0, 210});
  DrawBackButton();
  DrawText("TUGAS 4.2 - roundf vs truncation", 140, 12, 28, WHITE);
  DrawText("Soal + Jawaban", 140, 40, 14, LIGHTGRAY);

  DrawRectangleRounded((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                       0.02f, 8, (Color){0, 0, 0, 150});
  DrawRectangleRoundedLines((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                            0.02f, 8, SKYBLUE);

  DrawText("SOAL:", 56, 132, 22, (Color){255, 220, 120, 255});
  DrawText("Kenapa C1/C2 dikonversi dengan roundf() bukan (int)?", 56, 170, 20,
           LIGHTGRAY);

  DrawText("JAWABAN:", 56, 230, 22, (Color){120, 255, 180, 255});
  DrawText("roundf memilih piksel terdekat; truncation selalu potong ke nol.",
           56, 222 + 32, 20, (Color){190, 230, 255, 255});
  DrawText("Truncation memberi bias posisi (geser konsisten ke satu arah).", 56,
           248 + 32, 20, (Color){190, 230, 255, 255});
  DrawText("Akibat visual: busur tampak agak miring/asimetris.", 56, 274 + 32,
           20, (Color){190, 230, 255, 255});
  DrawText("roundf menjaga simetri bentuk vesica lebih stabil.", 56, 300 + 32,
           20, (Color){190, 230, 255, 255});

  DrawText("[ESC/BACKSPACE] Kembali  |  Klik BACK", 12, SCREEN_H - 22, 14,
           DARKGRAY);
}
