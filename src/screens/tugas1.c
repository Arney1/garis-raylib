#include "src/screens/program4.h"
#include "src/algo/bresenham.h"
#include "src/ui/back_button.h"
#include "src/ui/primitives.h"
#include "screen_type.h"
#include "raylib.h"

void DrawTugas1(void) {
    ClearBackground((Color){12,18,12,255});
    DrawRectangle(0, 0, SCREEN_W, 56, (Color){0,0,0,210});
    DrawBackButton();
    DrawText("Tugas 1 - Nama Panggilan dalam garis", 135, 10, 18, WHITE);
    DrawText("Semua segmen dibangun dari Bresenham integer-only: normal, putus-putus, tebal, dll", 135, 33, 12, LIGHTGRAY);

    int startY = 70, endY = SCREEN_H-70, midY = startY + (endY-startY)/2;
    int x = 100, spx = 75;

    //A
    BresenhamLine(x+spx, startY, x, endY, BLUE);
    BresenhamLine(x+spx, startY, x+2*spx, endY, BLUE);
    BresenhamLine(x+3*spx/2, midY, x+spx/2, midY, BLUE);

    x += 3*spx;
    //r
    BresenhamLine(x, midY, x, endY, BLUE);
    BresenhamLine(x, midY+(midY/8), x+spx, midY, BLUE);

    x += 2*spx;
    //k
    BresenhamLine(x, startY, x, endY, BLUE);
    BresenhamLine(x, midY+(endY-midY)/2, x+spx, endY, BLUE);
    BresenhamLine(x, midY+(endY-midY)/2, x+spx, midY, BLUE);

    x += 2*spx;
    //a
    BresenhamLine(x, midY, x+spx, midY, BLUE);
    BresenhamLine(x+spx, midY, x+spx, endY, BLUE);
    BresenhamLine(x+20, midY+(endY-midY)/2, x+spx, midY+(endY-midY)/2, BLUE);
    BresenhamLine(x+20, midY+(endY-midY)/2, x, endY, BLUE);
    BresenhamLine(x, endY, x+spx, endY, BLUE);

    x += 2*spx;
    //n
    BresenhamLine(x, midY, x, endY, BLUE);
    BresenhamLine(x, midY+10, x+spx, midY, BLUE);
    BresenhamLine(x+spx, midY, x+spx, endY, BLUE);
}
