#include "src/screens/menu.h"
#include "src/algo/dda.h"
#include "src/algo/bresenham.h"
#include "coords.h"
#include "screen_type.h"
#include "raylib.h"

void DrawMenu(void) {
    G_OriginX = 0; G_OriginY = 0; G_TickStep = 1;

    ClearBackground((Color){8,8,20,255});
    DrawRectangle(0, 0, SCREEN_W, 80, (Color){20,20,50,255});
    DrawText("Aplikasi Grafika Komputer", SCREEN_W/2-210, 12, 30, WHITE);
    DrawText("Algoritma DDA & Bresenham  |  Raylib + C", SCREEN_W/2-200, 48, 18, LIGHTGRAY);
    DDALine(0, 80, SCREEN_W, 80, (Color){60,80,160,255});

    int cW = 450, cH = 155;
    int c1 = SCREEN_W/2 - cW - 15;
    int c2 = SCREEN_W/2 + 15;
    int r[3] = {100, 0, 0};
    for (int i = 1; i <= 3; i++) {
        r[i] = 100 + i*168;
    }

    DrawRectangleRounded((Rectangle){c1,r[0],cW,cH}, 0.1f, 8, (Color){15,40,70,255});
    DrawRectangleRoundedLines((Rectangle){c1,r[0],cW,cH}, 0.1f, 8, SKYBLUE);
    DrawText("PROGRAM 1", c1+18, r[0]+14, 22, SKYBLUE);
    DrawText("Diagram Kartesian - DDA", c1+18, r[0]+42, 16, WHITE);
    DDALine(c1+18, r[0]+66, c1+200, r[0]+66, RED);
    DDALine(c1+18, r[0]+80, c1+200, r[0]+80, YELLOW);
    DDALine(c1+18, r[0]+94, c1+180, r[0]+74, SKYBLUE);
    DrawText("Garis DDA pada bidang kartesian", c1+18, r[0]+112, 13, LIGHTGRAY);
    DrawText("[Tekan 1]", c1+cW-100, r[0]+cH-28, 16, SKYBLUE);

    DrawRectangleRounded((Rectangle){c2,r[0],cW,cH}, 0.1f, 8, (Color){50,15,60,255});
    DrawRectangleRoundedLines((Rectangle){c2,r[0],cW,cH}, 0.1f, 8, VIOLET);
    DrawText("PROGRAM 2", c2+18, r[0]+14, 22, VIOLET);
    DrawText("Style Garis - DDA", c2+18, r[0]+42, 16, WHITE);
    DDA_DashedLine(c2+18, r[0]+66, c2+200, r[0]+66, 12, 8, ORANGE);
    DDA_ThickLine(c2+18, r[0]+84, c2+200, r[0]+84, 5, PINK);
    DDA_DashDotLine(c2+18, r[0]+102, c2+200, r[0]+102, YELLOW);
    DrawText("Normal, dash, tebal, dash-dot  [DDA]", c2+18, r[0]+120, 13, LIGHTGRAY);
    DrawText("[Tekan 2]", c2+cW-100, r[0]+cH-28, 16, VIOLET);

    DrawRectangleRounded((Rectangle){c1,r[1],cW,cH}, 0.1f, 8, (Color){15,50,25,255});
    DrawRectangleRoundedLines((Rectangle){c1,r[1],cW,cH}, 0.1f, 8, GREEN);
    DrawText("PROGRAM 3", c1+18, r[1]+14, 22, GREEN);
    DrawText("Diagram Kartesian - Bresenham", c1+18, r[1]+42, 16, WHITE);
    BresenhamLine(c1+18, r[1]+80, c1+200, r[1]+64, (Color){255,120,80,255});
    BresenhamLine(c1+18, r[1]+64, c1+200, r[1]+80, (Color){80,220,255,255});
    BresenhamLine(c1+18, r[1]+93, c1+200, r[1]+93, (Color){180,255,100,255});
    DrawText("Garis Bresenham pada bidang kartesian", c1+18, r[1]+110, 13, LIGHTGRAY);
    DrawText("[Tekan 3]", c1+cW-100, r[1]+cH-28, 16, GREEN);

    DrawRectangleRounded((Rectangle){c2,r[1],cW,cH}, 0.1f, 8, (Color){50,30,10,255});
    DrawRectangleRoundedLines((Rectangle){c2,r[1],cW,cH}, 0.1f, 8, ORANGE);
    DrawText("PROGRAM 4", c2+18, r[1]+14, 22, ORANGE);
    DrawText("Style Garis - Bresenham", c2+18, r[1]+42, 16, WHITE);
    Bres_DashedLine(c2+18, r[1]+66, c2+200, r[1]+66, 12, 8, ORANGE);
    Bres_ThickLine(c2+18, r[1]+84, c2+200, r[1]+84, 5, RED);
    Bres_DashDotLine(c2+18, r[1]+102, c2+200, r[1]+102, YELLOW);
    DrawText("Normal, dash, tebal, dash-dot  [Bresenham]", c2+18, r[1]+120, 13, LIGHTGRAY);
    DrawText("[Tekan 4]", c2+cW-100, r[1]+cH-28, 16, ORANGE);

    DrawRectangleRounded((Rectangle){(c1 + c2)/2,r[2],cW,cH}, 0.1f, 8, (Color){50,10,10,255});
        DrawRectangleRoundedLines((Rectangle){(c1 + c2)/2,r[2],cW,cH}, 0.1f, 8, RED);
        DrawText("TUGAS 1", (c1 + c2)/2+18, r[2]+14, 22, RED);
        DrawText("Nama panggilan dalam garis", (c1 + c2)/2+18, r[2]+42, 16, WHITE);
        int startY = r[2]+64, endY = r[2]+100, midY = startY + (endY-startY)/2;
            int x = (c1 + c2)/2+18, spx = 10;

            //A
                BresenhamLine(x+spx, startY, x, endY, BLUE);
                BresenhamLine(x+spx, startY, x+2*spx, endY, BLUE);
                BresenhamLine(x+3*spx/2, midY, x+spx/2, midY, BLUE);

                x += 3*spx;
                //r
                BresenhamLine(x, midY, x, endY, BLUE);
                BresenhamLine(x, midY, x+spx, midY, BLUE);

                x += 2*spx;
                //k
                BresenhamLine(x, startY, x, endY, BLUE);
                BresenhamLine(x, midY+(endY-midY)/2, x+spx, endY, BLUE);
                BresenhamLine(x, midY+(endY-midY)/2, x+spx, midY, BLUE);

                x += 2*spx;
                //a
                BresenhamLine(x, midY, x+spx, midY, BLUE);
                BresenhamLine(x+spx, midY, x+spx, endY, BLUE);
                BresenhamLine(x+spx/5, midY+(endY-midY)/2, x+spx, midY+(endY-midY)/2, BLUE);
                BresenhamLine(x+spx/5, midY+(endY-midY)/2, x, endY, BLUE);
                BresenhamLine(x, endY, x+spx, endY, BLUE);

                x += 2*spx;
                //n
                BresenhamLine(x, midY, x, endY, BLUE);
                BresenhamLine(x, midY, x+spx, midY, BLUE);
                BresenhamLine(x+spx, midY, x+spx, endY, BLUE);
        DrawText("Nama Panggilan", (c1 + c2)/2+18, r[2]+110, 13, LIGHTGRAY);
        DrawText("[Tekan 5]", (c1 + c2)/2+cW-100, r[2]+cH-28, 16, RED);

    int abBtnX = SCREEN_W/2 - 80, abBtnY = r[2] + cH + 14;
    Vector2 mouse = GetMousePosition();
    int abHover = CheckCollisionPointRec(mouse, (Rectangle){abBtnX, abBtnY, 160, 36});
    DrawRectangleRounded((Rectangle){abBtnX, abBtnY, 160, 36}, 0.3f, 6,
                         abHover ? (Color){60,100,180,230} : (Color){25,35,70,220});
    DrawRectangleRoundedLines((Rectangle){abBtnX, abBtnY, 160, 36}, 0.3f, 6,
                              abHover ? WHITE : (Color){80,110,200,255});
    DrawText("[ A ] About", abBtnX + 22, abBtnY + 10, 16, WHITE);

    DrawRectangle(0, SCREEN_H-50, SCREEN_W, 50, (Color){15,15,35,255});
    DDALine(0, SCREEN_H-50, SCREEN_W, SCREEN_H-50, (Color){60,80,160,255});
    DrawText("[1] P1  [2] P2  [3] P3  [4] P4 [5] T1 [A] About  |  [ESC] Keluar [Backspace] Back",
             SCREEN_W/2-300, SCREEN_H-33, 16, GRAY);
}
