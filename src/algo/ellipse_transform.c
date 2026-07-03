#include "ellipse_transform.h"
#include <math.h>

#ifndef PI
#define PI 3.14159265358979323846
#endif

// Translasi: Menggeser titik pusat elips
void TranslateEllipse2D(Ellipse2D *el, float tx, float ty) {
  el->cx += tx;
  el->cy += ty;
}

// Scaling: Memperbesar/memperkecil jari-jari elips
void ScaleEllipse2D(Ellipse2D *el, float sx, float sy) {
  el->rx *= sx;
  el->ry *= sy;
}

// Rotasi: Memutar titik (x,y) terhadap pusat (cx,cy) sejauh angle_deg
void RotatePoint2D(float *x, float *y, float cx, float cy, float angle_deg) {
  float rad = angle_deg * PI / 180.0f;
  float s = sinf(rad);
  float c = cosf(rad);

  // Geser titik ke titik asal (0,0) relatif terhadap pusat rotasi
  float nx = *x - cx;
  float ny = *y - cy;

  // Terapkan matriks rotasi 2D lalu kembalikan ke posisi awal
  *x = nx * c - ny * s + cx;
  *y = nx * s + ny * c + cy;
}
