#ifndef BRESELLIPSE_H
#define BRESELLIPSE_H

#include "raylib.h"

/*
 * Bresenham Ellipse Algorithm  (versi Tugas 1)
 *
 * Variasi algoritma Bresenham untuk menggambar elips menggunakan
 * decision parameter integer, dibagi menjadi 2 region berdasarkan
 * gradien kurva:
 *
 *   Region 1 (landai) : d1 = ry² - rx²*ry + rx²/4     -> iterasi x++
 *   Region 2 (curam)  : d2 = ry²*(x+0.5)² + rx²*(y-1)² - rx²*ry²  -> iterasi y--
 *
 * Rumus elips: (x/rx)² + (y/ry)² = 1
 *
 * Selain versi dasar, disediakan juga:
 *   - Bres_ThickEllipse  : elips tebal (beberapa elips konsentris berlapis)
 *   - Bres_DashedEllipse : elips putus-putus (state-machine dash/gap,
 *                          sama seperti Bres_DashedLine pada garis)
 *
 * Semua fungsi 100% integer (kecuali ThickEllipse yang memakai loop radius),
 * tidak ada satupun yang memakai fungsi gambar bawaan Raylib (DrawEllipse,
 * DrawCircle, dll) — murni DrawPixel().
 */

void BresenhamEllipse(int cx, int cy, int rx, int ry, Color color);
void Bres_ThickEllipse(int cx, int cy, int rx, int ry, int thick, Color color);
void Bres_DashedEllipse(int cx, int cy, int rx, int ry, int dashLen, int gapLen, Color color);

#endif
