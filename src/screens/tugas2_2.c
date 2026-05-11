#include "coords.h"
#include "raylib.h"
#include "screen_type.h"
#include "src/algo/bresenham.h"
#include "src/algo/midcircle.h"
#include "src/screens/tugas2_2.h"
#include "src/ui/back_button.h"
#include <math.h>

void DrawTugas2_2(void) {
  G_OriginX = SCREEN_W / 2;
  G_OriginY = SCREEN_H / 2 + 30;
  G_TickStep = 38;

  ClearBackground((Color){10, 12, 26, 255});
  DrawRectangle(0, 0, SCREEN_W, 64, (Color){0, 0, 0, 210});
  DrawBackButton();
  DrawText("TUGAS 2.2 - Efek pembulatan dy", 140, 12, 28, WHITE);
  DrawText("Soal + Jawaban", 140, 40, 14, LIGHTGRAY);

  DrawRectangleRounded((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                       0.02f, 8, (Color){0, 0, 0, 150});
  DrawRectangleRoundedLines((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                            0.02f, 8, SKYBLUE);

  DrawText("SOAL:", 56, 132, 22, (Color){255, 220, 120, 255});
  DrawText("Analisis dy = R/2 vs (int)(R*0.5f) pada offset diagonal.", 56, 170,
           20, LIGHTGRAY);

  DrawText("JAWABAN:", 56, 230, 22, (Color){120, 255, 180, 255});
  DrawText("Untuk R integer positif, R/2 dan (int)(R*0.5f) memberi hasil sama.",
           56, 222 + 32, 20, (Color){190, 230, 255, 255});
  DrawText("Contoh R=81: keduanya 40 (trunc/floor).", 56, 248 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("Dampak visual biasanya datang dari dx=R*0.866... (bukan dy).", 56,
           274 + 32, 20, (Color){190, 230, 255, 255});
  DrawText(
      "Error 1 piksel terlihat saat radius kecil atau pola ditumpuk rapat.", 56,
      300 + 32, 20, (Color){190, 230, 255, 255});

  DrawText("[ESC/BACKSPACE] Kembali  |  Klik BACK", 12, SCREEN_H - 22, 14,
           DARKGRAY);
}
