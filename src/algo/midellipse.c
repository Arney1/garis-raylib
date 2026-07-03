#include "midellipse.h"

static void DrawEllipsePoints(int cx, int cy, int x, int y, Color color) {
  DrawPixel(cx + x, cy + y, color); // Kuadran I
  DrawPixel(cx - x, cy + y, color); // Kuadran II
  DrawPixel(cx + x, cy - y, color); // Kuadran IV
  DrawPixel(cx - x, cy - y, color); // Kuadran III
}

void MidpointEllipse(int cx, int cy, int rx, int ry, Color color) {
  if (rx == 0 || ry == 0)
    return;

  long rx2 = (long)rx * rx;
  long ry2 = (long)ry * ry;

  int x = 0;
  int y = ry;

  // Region 1: |slope| < 1, iterasi berdasarkan x
  // 4*p1 = 4*ry² - 4*rx²*ry + rx²  (di-scale 4x agar bebas pembagian)
  long p1 = 4 * ry2 - 4 * rx2 * ry + rx2;

  while (ry2 * x < rx2 * y) {
    DrawEllipsePoints(cx, cy, x, y, color);

    x++;
    if (p1 < 0) {
      p1 += 4 * ry2 * (2 * x + 3);
    } else {
      y--;
      p1 += 4 * ry2 * (2 * x + 3) - 4 * rx2 * (2 * y + 2);
    }
  }

  // Region 2: |slope| >= 1, iterasi berdasarkan y
  long p2 = ry2 * (2 * x + 1) * (2 * x + 1) + 4 * rx2 * (y - 1) * (y - 1) -
            4 * rx2 * ry2;

  while (y >= 0) {
    DrawEllipsePoints(cx, cy, x, y, color);

    y--;
    if (p2 > 0) {
      p2 += 4 * rx2 * (-2 * y + 3);
    } else {
      x++;
      p2 += 4 * ry2 * (2 * x + 2) + 4 * rx2 * (-2 * y + 3);
    }
  }
}

/*
 * Elips Solid (Filled)
 * Ide: sama seperti MidcircleFilled - alih-alih memplot satu titik per
 * kuadran, tarik garis horizontal dari -x sampai +x (dan -y sampai +y untuk
 * region 2) di setiap baris yang ditemukan algoritma Midpoint Ellipse.
 * Tetap 100% integer, tetap hanya memakai DrawPixel().
 */
void MidpointEllipseFilled(int cx, int cy, int rx, int ry, Color color) {
  if (rx == 0 || ry == 0)
    return;

  long rx2 = (long)rx * rx;
  long ry2 = (long)ry * ry;

  int x = 0;
  int y = ry;
  long p1 = 4 * ry2 - 4 * rx2 * ry + rx2;

  while (ry2 * x < rx2 * y) {
    for (int px = cx - x; px <= cx + x; px++) {
      DrawPixel(px, cy + y, color);
      DrawPixel(px, cy - y, color);
    }

    x++;
    if (p1 < 0) {
      p1 += 4 * ry2 * (2 * x + 3);
    } else {
      y--;
      p1 += 4 * ry2 * (2 * x + 3) - 4 * rx2 * (2 * y + 2);
    }
  }

  long p2 = ry2 * (2 * x + 1) * (2 * x + 1) + 4 * rx2 * (y - 1) * (y - 1) -
            4 * rx2 * ry2;

  while (y >= 0) {
    for (int px = cx - x; px <= cx + x; px++) {
      DrawPixel(px, cy + y, color);
      DrawPixel(px, cy - y, color);
    }

    y--;
    if (p2 > 0) {
      p2 += 4 * rx2 * (-2 * y + 3);
    } else {
      x++;
      p2 += 4 * ry2 * (2 * x + 2) + 4 * rx2 * (-2 * y + 3);
    }
  }
}

/*
 * Elips Tebal
 * Sama seperti Bres_ThickEllipse: menumpuk elips konsentris rx±t, ry±t.
 */
void MidpointEllipseThick(int cx, int cy, int rx, int ry, int thick,
                          Color color) {
  if (thick <= 1) {
    MidpointEllipse(cx, cy, rx, ry, color);
    return;
  }

  int half = thick / 2;
  for (int t = -half; t <= half; t++) {
    int trx = rx + t;
    int try_ = ry + t;
    if (trx <= 0 || try_ <= 0)
      continue;
    MidpointEllipse(cx, cy, trx, try_, color);
  }
}
