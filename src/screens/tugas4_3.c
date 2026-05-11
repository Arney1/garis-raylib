#include "coords.h"
#include "raylib.h"
#include "screen_type.h"
#include "src/algo/bresenham.h"
#include "src/algo/midcircle.h"
#include "src/screens/tugas4_3.h"
#include "src/ui/back_button.h"
#include <math.h>

void DrawTugas4_3(void) {
  G_OriginX = SCREEN_W / 2;
  G_OriginY = SCREEN_H / 2 + 30;
  G_TickStep = 38;

  ClearBackground((Color){10, 12, 26, 255});
  DrawRectangle(0, 0, SCREEN_W, 64, (Color){0, 0, 0, 210});
  DrawBackButton();
  DrawText("TUGAS 4.3 - DrawPetalAnim", 140, 12, 28, WHITE);
  DrawText("Soal + Jawaban", 140, 40, 14, LIGHTGRAY);

  DrawRectangleRounded((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                       0.02f, 8, (Color){0, 0, 0, 150});
  DrawRectangleRoundedLines((Rectangle){34, 86, SCREEN_W - 68, SCREEN_H - 140},
                            0.02f, 8, SKYBLUE);

  DrawText("SOAL:", 56, 132, 22, (Color){255, 220, 120, 255});
  DrawText("Gabungkan DrawPetal (P8) + animasi busur (P7).", 56, 170, 20,
           LIGHTGRAY);

  DrawText("JAWABAN:", 56, 230, 22, (Color){120, 255, 180, 255});
  DrawText("Solusi: progress p di-ease dulu, lalu halfArc 180->60 derajat.", 56,
           222 + 32, 20, (Color){190, 230, 255, 255});
  DrawText("Geometri C1/C2 tetap sama seperti DrawPetal statis.", 56, 248 + 32,
           20, (Color){190, 230, 255, 255});
  DrawText("Yang berubah hanya rentang start/end arc terhadap halfArc.", 56,
           274 + 32, 20, (Color){190, 230, 255, 255});

  DrawText("Prototype:", 56, 388, 18, YELLOW);
  DrawText("void DrawPetalAnim(int cx,int cy,int r,float a,float p,Color c)",
           56, 414, 18, LIGHTGRAY);
  DrawText("{ float pe = p*p*(3-2*p); /* smoothstep */", 56, 440, 18,
           LIGHTGRAY);
  DrawText("  float half = PI - pe*(PI-PI/3); /* 180 -> 60 */", 56, 466, 18,
           LIGHTGRAY);
  DrawText("  // hitung PM,C1,C2 seperti DrawPetal lalu draw arc parsial", 56,
           492, 18, LIGHTGRAY);
  DrawText("}", 56, 518, 18, LIGHTGRAY);

  DrawText("[ESC/BACKSPACE] Kembali  |  Klik BACK", 12, SCREEN_H - 22, 14,
           DARKGRAY);
}
