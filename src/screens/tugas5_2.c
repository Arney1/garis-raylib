#include "coords.h"
#include "raylib.h"
#include "screen_type.h"
#include "src/algo/bresenham.h"
#include "src/algo/midcircle.h"
#include "src/screens/tugas5_2.h"
#include "src/ui/back_button.h"
#include <math.h>

void DrawTugas5_2(void) {
  G_OriginX = SCREEN_W / 2;
  G_OriginY = SCREEN_H / 2 + 30;
  G_TickStep = 38;

  ClearBackground((Color){10, 12, 26, 255});
  DrawRectangle(0, 0, SCREEN_W, 64, (Color){0, 0, 0, 210});
  DrawBackButton();
  DrawText("TUGAS 5.2 - Bukti DrawLens == DrawPetal (Selatan)", 140, 12, 28,
           WHITE);
  DrawText("Soal + Jawaban", 140, 40, 14, LIGHTGRAY);

  DrawRectangleRounded((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                       0.02f, 8, (Color){0, 0, 0, 150});
  DrawRectangleRoundedLines((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                            0.02f, 8, SKYBLUE);

  DrawText("SOAL:", 56, 132, 22, (Color){255, 220, 120, 255});
  DrawText("Buktikan kesetaraan koordinat C1/C2 untuk lensa Selatan.", 56, 170,
           20, LIGHTGRAY);

  DrawText("JAWABAN:", 56, 230, 22, (Color){120, 255, 180, 255});
  DrawText("P8 Selatan: PM=(cx,cy+h), angleDirection=+pi/2.", 56, 222 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("Dari rumus P8 -> C1=(cx-R/2, cy+h), C2=(cx+R/2, cy+h).", 56,
           248 + 32, 20, (Color){190, 230, 255, 255});
  DrawText("P9 Selatan: mx=cx,my=cy+h, angle=0.", 56, 274 + 32, 20,
           (Color){190, 230, 255, 255});
  DrawText("Dari rumus P9 -> C1=(cx-R/2, cy+h), C2=(cx+R/2, cy+h).", 56,
           300 + 32, 20, (Color){190, 230, 255, 255});
  DrawText("Maka C1 dan C2 identik, jadi busur hasil sama.", 56, 326 + 32, 20,
           (Color){190, 230, 255, 255});

  DrawText("[ESC/BACKSPACE] Kembali  |  Klik BACK", 12, SCREEN_H - 22, 14,
           DARKGRAY);
}
