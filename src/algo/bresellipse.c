#include "bresellipse.h"

/*
 * Plot 4 titik simetri (kuadran I-IV) sekaligus.
 * Karena elips simetris terhadap sumbu X dan Y, cukup hitung 1 kuadran.
 */
static void DrawEllipsePoints(int cx, int cy, int x, int y, Color color) {
  DrawPixel(cx + x, cy + y, color); // Kuadran I
  DrawPixel(cx - x, cy + y, color); // Kuadran II
  DrawPixel(cx + x, cy - y, color); // Kuadran IV
  DrawPixel(cx - x, cy - y, color); // Kuadran III
}

void BresenhamEllipse(int cx, int cy, int rx, int ry, Color color) {
  if (rx == 0 || ry == 0)
    return;

  long rx2 = (long)rx * rx;
  long ry2 = (long)ry * ry;

  int x = 0;
  int y = ry;

  // Region 1: iterasi berdasarkan x (gradien landai)
  long d1 = ry2 - rx2 * ry + rx2 / 4;

  while (ry2 * x < rx2 * y) {
    DrawEllipsePoints(cx, cy, x, y, color);

    x++;
    if (d1 < 0) {
      d1 += ry2 * (2 * x + 3);
    } else {
      y--;
      d1 += ry2 * (2 * x + 3) - rx2 * (2 * y + 2);
    }
  }

  // Region 2: iterasi berdasarkan y (gradien curam)
  long d2 = ry2 * (x * x + x) + rx2 * (y * y - 2 * y + 1) - rx2 * ry2;

  while (y >= 0) {
    DrawEllipsePoints(cx, cy, x, y, color);

    y--;
    if (d2 > 0) {
      d2 += rx2 * (3 - 2 * y);
    } else {
      x++;
      d2 += ry2 * (2 * x + 2) + rx2 * (3 - 2 * y);
    }
  }
}

/*
 * Elips Tebal
 * Ide: sama seperti Bres_ThickLine (garis paralel bergeser tegak lurus),
 * hanya saja untuk elips "pergeseran" paling sederhana & murah secara
 * komputasi adalah menumpuk beberapa elips konsentris dengan radius
 * rx±t, ry±t untuk t = 0..thick/2. Hasilnya cincin elips yang tebal.
 */
void Bres_ThickEllipse(int cx, int cy, int rx, int ry, int thick, Color color) {
  if (thick <= 1) {
    BresenhamEllipse(cx, cy, rx, ry, color);
    return;
  }

  int half = thick / 2;
  for (int t = -half; t <= half; t++) {
    int trx = rx + t;
    int try_ = ry + t;
    if (trx <= 0 || try_ <= 0)
      continue;
    BresenhamEllipse(cx, cy, trx, try_, color);
  }
}

/*
 * Elips Putus-putus
 * Ide: gunakan state-machine dash/gap yang sama seperti Bres_DashedLine,
 * tetapi "langkah" dihitung berdasarkan jumlah iterasi decision parameter
 * (bukan jarak Euclidean), sama seperti pendekatan MidcircleDashed.
 * Counter bertambah setiap kali algoritma pindah ke titik (x,y) baru,
 * dan status gambar (drawing on/off) dicek sebelum memanggil DrawEllipsePoints.
 */
void Bres_DashedEllipse(int cx, int cy, int rx, int ry, int dashLen, int gapLen,
                        Color color) {
  if (rx == 0 || ry == 0)
    return;

  long rx2 = (long)rx * rx;
  long ry2 = (long)ry * ry;

  int x = 0;
  int y = ry;

  int counter = 0;
  int drawing = 1;
  int current_limit = dashLen;

  long d1 = ry2 - rx2 * ry + rx2 / 4;

  while (ry2 * x < rx2 * y) {
    if (drawing)
      DrawEllipsePoints(cx, cy, x, y, color);

    counter++;
    if (counter >= current_limit) {
      counter = 0;
      drawing = !drawing;
      current_limit = drawing ? dashLen : gapLen;
    }

    x++;
    if (d1 < 0) {
      d1 += ry2 * (2 * x + 3);
    } else {
      y--;
      d1 += ry2 * (2 * x + 3) - rx2 * (2 * y + 2);
    }
  }

  long d2 = ry2 * (x * x + x) + rx2 * (y * y - 2 * y + 1) - rx2 * ry2;

  while (y >= 0) {
    if (drawing)
      DrawEllipsePoints(cx, cy, x, y, color);

    counter++;
    if (counter >= current_limit) {
      counter = 0;
      drawing = !drawing;
      current_limit = drawing ? dashLen : gapLen;
    }

    y--;
    if (d2 > 0) {
      d2 += rx2 * (3 - 2 * y);
    } else {
      x++;
      d2 += ry2 * (2 * x + 2) + rx2 * (3 - 2 * y);
    }
  }
}
