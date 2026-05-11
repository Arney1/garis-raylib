#include "coords.h"
#include "raylib.h"
#include "screen_type.h"
#include "src/algo/bresenham.h"
#include "src/algo/midcircle.h"
#include "src/screens/tugas2_1.h"
#include "src/ui/back_button.h"
#include <math.h>

void DrawTugas2_1(void) {
  G_OriginX = SCREEN_W / 2;
  G_OriginY = SCREEN_H / 2 + 30;
  G_TickStep = 38;

  ClearBackground((Color){10, 12, 26, 255});
  DrawRectangle(0, 0, SCREEN_W, 64, (Color){0, 0, 0, 210});
  DrawBackButton();
  DrawText("TUGAS 2.1 - Koordinat kelopak (R=80)", 140, 12, 28, WHITE);
  DrawText("Soal + Jawaban", 140, 40, 14, LIGHTGRAY);

  DrawRectangleRounded((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                       0.02f, 8, (Color){0, 0, 0, 150});
  DrawRectangleRoundedLines((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                            0.02f, 8, SKYBLUE);

  DrawText("SOAL:", 56, 132, 22, (Color){255, 220, 120, 255});
  DrawText("Dengan pusat (400,300) dan R=80, hitung 6 kelopak utama.", 56, 170,
           20, LIGHTGRAY);

  DrawText("JAWABAN:", 56, 230, 22, (Color){120, 255, 180, 255});
  DrawText("Utara=(400,220), Selatan=(400,380).", 56, 222 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("Timur=(480,300), Barat=(320,300).", 56, 248 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("dx=R*cos30=80*0.866=69.28, dy=R*sin30=40.", 56, 274 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("TimurLaut=(469,260) (pembulatan), BaratDaya=(331,340).", 56,
           300 + 32, 20, (Color){190, 230, 255, 255});

  // Demo titik kelopak — diskalakan, di sisi kanan agar tidak tumpang tindih
  int dcx = SCREEN_W - 200, dcy = 270, dR = 60;
  int ddx = (int)(dR * 0.866f); // R * cos(30°)
  int ddy = dR / 2;             // R * sin(30°)
  int dpx[6] = {dcx, dcx, dcx + dR, dcx - dR, dcx + ddx, dcx - ddx};
  int dpy[6] = {dcy - dR, dcy + dR, dcy, dcy, dcy - ddy, dcy + ddy};
  const char *lbl[6] = {"U", "S", "T", "B", "TL", "BD"};
  for (int i = 0; i < 6; i++)
    DrawLine(dcx, dcy, dpx[i], dpy[i], (Color){80, 80, 80, 180});
  for (int i = 0; i < 6; i++) {
    Midcircle(dpx[i], dpy[i], 6, ORANGE);
    DrawText(lbl[i], dpx[i] + 8, dpy[i] - 8, 14, ORANGE);
  }
  DrawPixel(dcx, dcy, WHITE);
  DrawText("Visual (diskalakan)", dcx - 60, dcy + dR + 18, 14, ORANGE);

  DrawText("[ESC/BACKSPACE] Kembali  |  Klik BACK", 12, SCREEN_H - 22, 14,
           DARKGRAY);
}
