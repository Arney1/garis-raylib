#ifndef MIDELLIPSE_H
#define MIDELLIPSE_H

#include "raylib.h"

/*
 * Midpoint Ellipse Algorithm  (versi Tugas 1)
 *
 * Menggambar elips dengan membagi kurva menjadi 2 region berdasarkan
 * decision parameter (di-scale x4 supaya tetap integer, tanpa pembagian):
 *
 *   Region 1 (|slope| < 1) : iterasi x++, p1 = ry² - rx²*ry + rx²/4
 *   Region 2 (|slope| >= 1): iterasi y--, p2 = ry²*(x+0.5)² + rx²*(y-1)² - rx²*ry²
 *
 * Simetri 4-kuadran: 1 titik dihitung -> digambar di 4 titik sekaligus.
 *
 * Selain versi outline, disediakan juga:
 *   - MidpointEllipseFilled : elips solid (diisi penuh, per baris horizontal)
 *   - MidpointEllipseThick  : elips tebal (beberapa elips konsentris berlapis)
 */

void MidpointEllipse(int cx, int cy, int rx, int ry, Color color);
void MidpointEllipseFilled(int cx, int cy, int rx, int ry, Color color);
void MidpointEllipseThick(int cx, int cy, int rx, int ry, int thick, Color color);

#endif
