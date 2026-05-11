#include "coords.h"
#include "raylib.h"
#include "screen_type.h"
#include "src/algo/bresenham.h"
#include "src/algo/midcircle.h"
#include "src/screens/tugas1_3.h"
#include "src/ui/back_button.h"
#include <math.h>

void DrawTugas1_3(void) {
  G_OriginX = SCREEN_W / 2;
  G_OriginY = SCREEN_H / 2 + 30;
  G_TickStep = 38;

  ClearBackground((Color){10, 12, 26, 255});
  DrawRectangle(0, 0, SCREEN_W, 64, (Color){0, 0, 0, 210});
  DrawBackButton();
  DrawText("TUGAS 1.3 - Midcircle setengah atas", 140, 12, 28, WHITE);
  DrawText("Soal + Jawaban", 140, 40, 14, LIGHTGRAY);

  DrawRectangleRounded((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                       0.02f, 8, (Color){0, 0, 0, 150});
  DrawRectangleRoundedLines((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                            0.02f, 8, SKYBLUE);

  DrawText("SOAL:", 56, 132, 22, (Color){255, 220, 120, 255});
  DrawText("Ubah Midcircle agar hanya gambar setengah atas (oktan 1,2,7,8).",
           56, 170, 20, LIGHTGRAY);

  DrawText("JAWABAN:", 56, 230, 22, (Color){120, 255, 180, 255});
  DrawText("Gunakan loop midpoint normal, tapi plot 4 titik atas saja:", 56,
           222 + 32, 20, (Color){190, 230, 255, 255});
  DrawText("(cx+x,cy-y), (cx+y,cy-x), (cx-y,cy-x), (cx-x,cy-y).", 56, 248 + 32,
           20, (Color){190, 230, 255, 255});
  DrawText("Di bawah ini ditampilkan demo hasil modifikasi tersebut.", 56,
           274 + 32, 20, (Color){190, 230, 255, 255});

  // Demo setengah lingkaran atas (oktan 1,2,7,8)
  int cx = SCREEN_W - 220, cy = 290, r = 92;
  int x = 0, y = r, d = 3 - 2 * r;
  while (y >= x) {
    DrawPixel(cx + x, cy - y, YELLOW);
    DrawPixel(cx + y, cy - x, YELLOW);
    DrawPixel(cx - y, cy - x, YELLOW);
    DrawPixel(cx - x, cy - y, YELLOW);
    if (d < 0)
      d += 4 * x + 6;
    else {
      d += 4 * (x - y) + 10;
      y--;
    }
    x++;
  }
  DrawText("Demo: upper semicircle", SCREEN_W - 300, 398, 16, YELLOW);

  DrawText("[ESC/BACKSPACE] Kembali  |  Klik BACK", 12, SCREEN_H - 22, 14,
           DARKGRAY);
}
