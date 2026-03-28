#include "src/screens/menu.h"
#include "coords.h"
#include "raylib.h"
#include "screen_type.h"
#include "src/algo/bresenham.h"
#include "src/algo/dda.h"
#include "src/algo/midcircle.h"

// Global variable to track clicked program
static int clickedProgram = 0;
static int activeTab = 1;
int GetClickedProgram(void) {
  int result = clickedProgram;
  clickedProgram = 0;
  return result;
}

void DrawMenu(void) {
  G_OriginX = 0;
  G_OriginY = 0;
  G_TickStep = 1;

  ClearBackground((Color){8, 8, 20, 255});
  DrawRectangle(0, 0, SCREEN_W, 80, (Color){20, 20, 50, 255});
  DrawText("Aplikasi Grafika Komputer", SCREEN_W / 2 - 210, 12, 30, WHITE);
  DrawText("Algoritma DDA, Bresenham & Midcircle  |  Raylib + C",
           SCREEN_W / 2 - 220, 48, 18, LIGHTGRAY);
  DDALine(0, 80, SCREEN_W, 80, (Color){60, 80, 160, 255});

  int cW = 450, cH = 83;
  int c1 = SCREEN_W / 2 - cW - 15;
  int c2 = SCREEN_W / 2 + 15;
  int rr = 140 - 92, srr = 92;

  Vector2 mouse = GetMousePosition();
  int mousePressed = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

  int tab1BtnX = SCREEN_W / 2 - 165, tab1BtnY = rr + 40;
  Color tab1Color;
  int tab1Hover =
      CheckCollisionPointRec(mouse, (Rectangle){tab1BtnX, tab1BtnY, 160, 36});
  if (tab1Hover && mousePressed)
    activeTab = 1;
  int tab2BtnX = SCREEN_W / 2 + 5, tab2BtnY = rr + 40;
  int tab2Hover =
      CheckCollisionPointRec(mouse, (Rectangle){tab2BtnX, tab2BtnY, 160, 36});
  if (tab2Hover && mousePressed)
    activeTab = 2;
  if (activeTab == 1) {
    tab1Color = (Color){80, 130, 220, 255};
    ab2Color = (Color){25, 35, 70, 220};

    DrawRectangleRounded((Rectangle){tab1BtnX, tab1BtnY, 160, 36}, 0.3f, 6,
                         tab1Color);
    DrawRectangleRoundedLines((Rectangle){tab1BtnX, tab1BtnY, 160, 36}, 0.3f, 6,
                              tab1Hover ? WHITE : (Color){80, 110, 200, 255});
    DrawText("[ P ] Programs", tab1BtnX + 22, tab1BtnY + 10, 16, WHITE);
    DrawRectangleRounded((Rectangle){tab2BtnX, tab2BtnY, 160, 36}, 0.3f, 6,
                         tab2Hover ? (Color){60, 100, 180, 230} : tab2Color);
    DrawRectangleRoundedLines((Rectangle){tab2BtnX, tab2BtnY, 160, 36}, 0.3f, 6,
                              tab2Hover ? WHITE : (Color){80, 110, 200, 255});
    DrawText("[ T ] Tugas", tab2BtnX + 22, tab2BtnY + 10, 16, WHITE);
    rr += srr;
    // Program 1 - DDA Kartesian
    int hover1 = CheckCollisionPointRec(mouse, (Rectangle){c1, rr, cW, cH});
    DrawRectangleRounded((Rectangle){c1, rr, cW, cH}, 0.1f, 8,
                         hover1 ? (Color){25, 55, 95, 255}
                                : (Color){15, 40, 70, 255});
    DrawRectangleRoundedLines((Rectangle){c1, rr, cW, cH}, 0.1f, 8,
                              hover1 ? WHITE : SKYBLUE);
    DrawText("PROGRAM 1", c1 + 18, rr + 8, 16, SKYBLUE);
    DrawText("Diagram Kartesian - DDA", c1 + 18, rr + 28, 12, WHITE);
    DDALine(c1 + 18, rr + 48, c1 + 120, rr + 48, RED);
    DDALine(c1 + 18, rr + 58, c1 + 120, rr + 58, YELLOW);
    DDALine(c1 + 18, rr + 68, c1 + 100, rr + 52, SKYBLUE);
    DrawText("Garis DDA pada bidang kartesian", c1 + 18, rr + 72, 10,
             LIGHTGRAY);
    DrawText("[Tekan 1]", c1 + cW - 80, rr + cH - 18, 12, SKYBLUE);
    if (hover1 && mousePressed)
      clickedProgram = 1;

    // Program 2 - DDA Style
    int hover2 = CheckCollisionPointRec(mouse, (Rectangle){c2, rr, cW, cH});
    DrawRectangleRounded((Rectangle){c2, rr, cW, cH}, 0.1f, 8,
                         hover2 ? (Color){70, 30, 80, 255}
                                : (Color){50, 15, 60, 255});
    DrawRectangleRoundedLines((Rectangle){c2, rr, cW, cH}, 0.1f, 8,
                              hover2 ? WHITE : VIOLET);
    DrawText("PROGRAM 2", c2 + 18, rr + 8, 16, VIOLET);
    DrawText("Style Garis - DDA", c2 + 18, rr + 28, 12, WHITE);
    DDA_DashedLine(c2 + 18, rr + 48, c2 + 120, rr + 48, 8, 5, ORANGE);
    DDA_ThickLine(c2 + 18, rr + 58, c2 + 120, rr + 58, 3, PINK);
    DDA_DashDotLine(c2 + 18, rr + 68, c2 + 120, rr + 68, YELLOW);
    DrawText("Normal, dash, tebal, dash-dot", c2 + 18, rr + 72, 10, LIGHTGRAY);
    DrawText("[Tekan 2]", c2 + cW - 80, rr + cH - 18, 12, VIOLET);
    if (hover2 && mousePressed)
      clickedProgram = 2;

    rr += srr;

    // Program 3 - Bresenham Kartesian
    int hover3 = CheckCollisionPointRec(mouse, (Rectangle){c1, rr, cW, cH});
    DrawRectangleRounded((Rectangle){c1, rr, cW, cH}, 0.1f, 8,
                         hover3 ? (Color){25, 65, 35, 255}
                                : (Color){15, 50, 25, 255});
    DrawRectangleRoundedLines((Rectangle){c1, rr, cW, cH}, 0.1f, 8,
                              hover3 ? WHITE : GREEN);
    DrawText("PROGRAM 3", c1 + 18, rr + 8, 16, GREEN);
    DrawText("Diagram Kartesian - Bresenham", c1 + 18, rr + 28, 12, WHITE);
    BresenhamLine(c1 + 18, rr + 50, c1 + 120, rr + 44,
                  (Color){255, 120, 80, 255});
    BresenhamLine(c1 + 18, rr + 44, c1 + 120, rr + 50,
                  (Color){80, 220, 255, 255});
    BresenhamLine(c1 + 18, rr + 60, c1 + 120, rr + 60,
                  (Color){180, 255, 100, 255});
    DrawText("Garis Bresenham pada bidang kartesian", c1 + 18, rr + 72, 10,
             LIGHTGRAY);
    DrawText("[Tekan 3]", c1 + cW - 80, rr + cH - 18, 12, GREEN);
    if (hover3 && mousePressed)
      clickedProgram = 3;

    // Program 4 - Bresenham Style
    int hover4 = CheckCollisionPointRec(mouse, (Rectangle){c2, rr, cW, cH});
    DrawRectangleRounded((Rectangle){c2, rr, cW, cH}, 0.1f, 8,
                         hover4 ? (Color){70, 45, 20, 255}
                                : (Color){50, 30, 10, 255});
    DrawRectangleRoundedLines((Rectangle){c2, rr, cW, cH}, 0.1f, 8,
                              hover4 ? WHITE : ORANGE);
    DrawText("PROGRAM 4", c2 + 18, rr + 8, 16, ORANGE);
    DrawText("Style Garis - Bresenham", c2 + 18, rr + 28, 12, WHITE);
    Bres_DashedLine(c2 + 18, rr + 48, c2 + 120, rr + 48, 8, 5, ORANGE);
    Bres_ThickLine(c2 + 18, rr + 58, c2 + 120, rr + 58, 3, RED);
    Bres_DashDotLine(c2 + 18, rr + 68, c2 + 120, rr + 68, YELLOW);
    DrawText("Normal, dash, tebal, dash-dot", c2 + 18, rr + 72, 10, LIGHTGRAY);
    DrawText("[Tekan 4]", c2 + cW - 80, rr + cH - 18, 12, ORANGE);
    if (hover4 && mousePressed)
      clickedProgram = 4;

    rr += srr;
    // Program 5 - Midcircle
    int hover5 = CheckCollisionPointRec(mouse, (Rectangle){c1, rr, cW, cH});
    DrawRectangleRounded((Rectangle){c1, rr, cW, cH}, 0.1f, 8,
                         hover5 ? (Color){55, 30, 65, 255}
                                : (Color){40, 20, 50, 255});
    DrawRectangleRoundedLines((Rectangle){c1, rr, cW, cH}, 0.1f, 8,
                              hover5 ? WHITE : MAGENTA);
    DrawText("PROGRAM 5", c1 + 18, rr + 8, 16, MAGENTA);
    DrawText("Midpoint Circle Algorithm", c1 + 18, rr + 28, 12, WHITE);
    Midcircle(c1 + 70, rr + 52, 18, RED);
    Midcircle(c1 + 110, rr + 52, 14, SKYBLUE);
    Midcircle(c1 + 145, rr + 52, 10, YELLOW);
    DrawText("Lingkaran dengan 8-way symmetry", c1 + 18, rr + 72, 10,
             LIGHTGRAY);
    DrawText("[Tekan 5]", c1 + cW - 80, rr + cH - 18, 12, MAGENTA);
    if (hover5 && mousePressed)
      clickedProgram = 5;

    // Program 6 - Flower of Life
    int hover6 = CheckCollisionPointRec(mouse, (Rectangle){c2, rr, cW, cH});
    DrawRectangleRounded((Rectangle){c2, rr, cW, cH}, 0.1f, 8,
                         hover6 ? (Color){30, 60, 65, 255}
                                : (Color){20, 45, 50, 255});
    DrawRectangleRoundedLines((Rectangle){c2, rr, cW, cH}, 0.1f, 8,
                              hover6 ? WHITE : (Color){100, 220, 200, 255});
    DrawText("PROGRAM 6", c2 + 18, rr + 8, 16, (Color){100, 220, 200, 255});
    DrawText("Flower of Life Pattern", c2 + 18, rr + 28, 12, WHITE);
    int fcx = c2 + 85, fcy = rr + 52, fr = 14;
    Midcircle(fcx, fcy, fr, RAYWHITE);
    Midcircle(fcx, fcy - fr, fr, RED);
    Midcircle(fcx, fcy + fr, fr, BLUE);
    Midcircle(fcx + fr, fcy, fr, GREEN);
    Midcircle(fcx - fr, fcy, fr, ORANGE);
    DrawText("Pola geometri sakral", c2 + 18, rr + 72, 10, LIGHTGRAY);
    DrawText("[Tekan 6]", c2 + cW - 80, rr + cH - 18, 12,
             (Color){100, 220, 200, 255});
    if (hover6 && mousePressed)
      clickedProgram = 6;

    rr += srr;
    // Program 7 - Animated Flower of Life
    int hover7 = CheckCollisionPointRec(mouse, (Rectangle){c1, rr, cW, cH});
    DrawRectangleRounded((Rectangle){c1, rr, cW, cH}, 0.1f, 8,
                         hover7 ? (Color){60, 40, 70, 255}
                                : (Color){45, 25, 55, 255});
    DrawRectangleRoundedLines((Rectangle){c1, rr, cW, cH}, 0.1f, 8,
                              hover7 ? WHITE : (Color){200, 150, 255, 255});
    DrawText("PROGRAM 7", c1 + 18, rr + 8, 16, (Color){200, 150, 255, 255});
    DrawText("Animated Flower of Life", c1 + 18, rr + 28, 12, WHITE);
    // Mini animated preview (static for menu)
    int a7cx = c1 + 85, a7cy = rr + 52, a7r = 14;
    Midcircle(a7cx, a7cy, a7r, RAYWHITE);
    Midcircle(a7cx, a7cy - a7r, a7r, RED);
    Midcircle(a7cx, a7cy + a7r, a7r, BLUE);
    Midcircle(a7cx + a7r, a7cy, a7r, GREEN);
    Midcircle(a7cx - a7r, a7cy, a7r, ORANGE);
    DrawText("Animasi transisi lingkaran ke lensa", c1 + 18, rr + 72, 10,
             LIGHTGRAY);
    DrawText("[Tekan 7]", c1 + cW - 80, rr + cH - 18, 12,
             (Color){200, 150, 255, 255});
    if (hover7 && mousePressed)
      clickedProgram = 7;

    // Program 8 - Vesica Piscis (4 Kelopak Murni)
    int hover8 = CheckCollisionPointRec(mouse, (Rectangle){c2, rr, cW, cH});
    DrawRectangleRounded((Rectangle){c2, rr, cW, cH}, 0.1f, 8,
                         hover8 ? (Color){70, 50, 30, 255}
                                : (Color){55, 35, 20, 255});
    DrawRectangleRoundedLines((Rectangle){c2, rr, cW, cH}, 0.1f, 8,
                              hover8 ? WHITE : (Color){255, 200, 100, 255});
    DrawText("PROGRAM 8", c2 + 18, rr + 8, 16, (Color){255, 200, 100, 255});
    DrawText("Vesica Piscis (4 Kelopak)", c2 + 18, rr + 28, 12, WHITE);
    // Mini preview - Vesica Piscis shapes
    int a8cx = c2 + 85, a8cy = rr + 52, a8r = 14;
    Midcircle(a8cx, a8cy - a8r / 2, a8r, RED);
    Midcircle(a8cx, a8cy + a8r / 2, a8r, BLUE);
    DrawText("Tanpa lingkaran tengah", c2 + 18, rr + 72, 10, LIGHTGRAY);
    DrawText("[Tekan 8]", c2 + cW - 80, rr + cH - 18, 12,
             (Color){255, 200, 100, 255});
    if (hover8 && mousePressed)
      clickedProgram = 8;

    rr += srr;
    // Program 9 - Quarter Arc Vesica Piscis
    int hover9 = CheckCollisionPointRec(mouse, (Rectangle){c1, rr, cW, cH});
    DrawRectangleRounded((Rectangle){c1, rr, cW, cH}, 0.1f, 8,
                         hover9 ? (Color){20, 55, 75, 255}
                                : (Color){10, 40, 60, 255});
    DrawRectangleRoundedLines((Rectangle){c1, rr, cW, cH}, 0.1f, 8,
                              hover9 ? WHITE : (Color){80, 200, 255, 255});
    DrawText("PROGRAM 9", c1 + 18, rr + 8, 16, (Color){80, 200, 255, 255});
    DrawText("Vesica Piscis - Pergeseran Jari-Jari", c1 + 18, rr + 28, 12,
             WHITE);
    // Mini preview - busur seperempat + pergeseran
    int a9cx = c1 + 85, a9cy = rr + 52, a9r = 20;
    Midcircle(a9cx - a9r / 2, a9cy, a9r, (Color){80, 200, 255, 60});
    Midcircle(a9cx + a9r / 2, a9cy, a9r, (Color){255, 120, 80, 60});
    DrawText("2 busur 120 deg, pusat digeser r/2", c1 + 18, rr + 72, 10,
             LIGHTGRAY);
    DrawText("[Tekan 9]", c1 + cW - 80, rr + cH - 18, 12,
             (Color){80, 200, 255, 255});
    if (hover9 && mousePressed)
      clickedProgram = 9;

    // rr += srr;
    // About button
    int abBtnX = SCREEN_W / 2 - 80, abBtnY = rr + cH + 14;
    int abHover =
        CheckCollisionPointRec(mouse, (Rectangle){abBtnX, abBtnY, 160, 36});
    DrawRectangleRounded((Rectangle){abBtnX, abBtnY, 160, 36}, 0.3f, 6,
                         abHover ? (Color){60, 100, 180, 230}
                                 : (Color){25, 35, 70, 220});
    DrawRectangleRoundedLines((Rectangle){abBtnX, abBtnY, 160, 36}, 0.3f, 6,
                              abHover ? WHITE : (Color){80, 110, 200, 255});
    DrawText("[ A ] About", abBtnX + 22, abBtnY + 10, 16, WHITE);
  } else if (activeTab == 2) {
    Color tab2Color = (Color){80, 130, 220, 255};
    Color tab1Color = (Color){25, 35, 70, 220};

    DrawRectangleRounded((Rectangle){tab1BtnX, tab1BtnY, 160, 36}, 0.3f, 6,
                         tab1Color);
    DrawRectangleRoundedLines((Rectangle){tab1BtnX, tab1BtnY, 160, 36}, 0.3f, 6,
                              tab1Hover ? WHITE : (Color){80, 110, 200, 255});
    DrawText("[ P ] Programs", tab1BtnX + 22, tab1BtnY + 10, 16, WHITE);
    DrawRectangleRounded((Rectangle){tab2BtnX, tab2BtnY, 160, 36}, 0.3f, 6,
                         tab2Hover ? (Color){60, 100, 180, 230} : tab2Color);
    DrawRectangleRoundedLines((Rectangle){tab2BtnX, tab2BtnY, 160, 36}, 0.3f, 6,
                              tab2Hover ? WHITE : (Color){80, 110, 200, 255});
    DrawText("[ T ] Tugas", tab2BtnX + 22, tab2BtnY + 10, 16, WHITE);
  }
  // Footer
  DrawRectangle(0, SCREEN_H - 50, SCREEN_W, 50, (Color){15, 15, 35, 255});
  DDALine(0, SCREEN_H - 50, SCREEN_W, SCREEN_H - 50, (Color){60, 80, 160, 255});
  DrawText("[1-9] Program  [A] About  |  [ESC] Keluar", SCREEN_W / 2 - 180,
           SCREEN_H - 33, 16, GRAY);
}
