#include "../algo/bresellipse.h"
#include "../algo/ellipse_transform.h"
#include "../algo/midellipse.h"
#include "raylib.h"
#include "tugas1_creation.h"
#include <math.h>

#ifndef PI
#define PI 3.14159265358979323846
#endif

void DrawTugas1Creation(void) {
  // Latar belakang tata surya
  ClearBackground((Color){10, 12, 25, 255});

  int screenW = GetScreenWidth();
  int screenH = GetScreenHeight();
  int centerX = screenW / 2;
  int centerY = screenH / 2 + 20;

  // ==========================================
  // LAYER 1: GAMBAR SEMUA ORBIT (Z-Index Paling Bawah)
  // ==========================================

  // Orbit 1 (Earth-like)
  Ellipse2D orbit1 = {(float)centerX, (float)centerY, 220.0f, 130.0f};
  Bres_DashedEllipse((int)orbit1.cx, (int)orbit1.cy, (int)orbit1.rx,
                     (int)orbit1.ry, 12, 8, DARKGRAY);

  // Orbit 2 (Gas Giant)
  Ellipse2D orbit2 = {(float)centerX, (float)centerY, 360.0f, 210.0f};
  Bres_ThickEllipse((int)orbit2.cx, (int)orbit2.cy, (int)orbit2.rx,
                    (int)orbit2.ry, 2, (Color){50, 50, 70, 255});

  // Orbit Komet
  Ellipse2D cometOrbit = {(float)centerX, (float)centerY, 100.0f, 40.0f};
  ScaleEllipse2D(&cometOrbit, 3.5f, 1.8f);
  TranslateEllipse2D(&cometOrbit, 120.0f, 80.0f);
  Bres_DashedEllipse((int)cometOrbit.cx, (int)cometOrbit.cy, (int)cometOrbit.rx,
                     (int)cometOrbit.ry, 20, 15, (Color){255, 255, 255, 60});

  // ==========================================
  // LAYER 2: MATAHARI & PLANET
  // ==========================================

  // Matahari (Core & Corona)
  MidpointEllipseFilled(centerX, centerY, 45, 45, (Color){255, 200, 0, 255});
  MidpointEllipseThick(centerX, centerY, 52, 52, 4, (Color){255, 120, 0, 150});

  // Planet 1 (Earth-like)
  float angle1 = 60.0f * PI / 180.0f;
  int p1_x = orbit1.cx + orbit1.rx * cosf(angle1);
  int p1_y = orbit1.cy + orbit1.ry * sinf(angle1);

  MidpointEllipseFilled(p1_x, p1_y, 16, 16, (Color){50, 150, 255, 255});
  MidpointEllipse(p1_x, p1_y, 26, 26, GRAY); // Orbit Bulan

  // Posisi Bulan dihitung menggunakan sin/cos agar presisi berada di garis
  // orbit
  float moonAngle = 45.0f * PI / 180.0f;
  int m_x = p1_x + 26 * cosf(moonAngle);
  int m_y = p1_y + 26 * sinf(moonAngle);
  MidpointEllipseFilled(m_x, m_y, 5, 5, LIGHTGRAY);

  // Planet 2 (Gas Giant)
  float angle2 = 210.0f * PI / 180.0f;
  int p2_x = orbit2.cx + orbit2.rx * cosf(angle2);
  int p2_y = orbit2.cy + orbit2.ry * sinf(angle2);

  MidpointEllipseFilled(p2_x, p2_y, 28, 28, (Color){200, 160, 120, 255});
  Bres_ThickEllipse(p2_x, p2_y, 50, 15, 3,
                    (Color){220, 200, 150, 180}); // Cincin

  // ==========================================
  // LAYER 3: KOMET & EKOR
  // ==========================================

  // Kita tempatkan ekor di sudut yang sedikit tertinggal di belakang komet
  float t1 = 181.0f * PI / 180.0f;
  MidpointEllipseFilled(cometOrbit.cx + cometOrbit.rx * cosf(t1),
                        cometOrbit.cy + cometOrbit.ry * sinf(t1), 6, 6,
                        (Color){200, 220, 255, 200});

  float t2 = 177.0f * PI / 180.0f;
  MidpointEllipseFilled(cometOrbit.cx + cometOrbit.rx * cosf(t2),
                        cometOrbit.cy + cometOrbit.ry * sinf(t2), 4, 4,
                        (Color){150, 180, 255, 150});

  float t3 = 173.0f * PI / 180.0f;
  MidpointEllipseFilled(cometOrbit.cx + cometOrbit.rx * cosf(t3),
                        cometOrbit.cy + cometOrbit.ry * sinf(t3), 2, 2,
                        (Color){100, 150, 255, 100});

  // Kepala Komet (Digambar terakhir agar menimpa ekornya)
  float angle3 = 185.0f * PI / 180.0f;
  int c_x = cometOrbit.cx + cometOrbit.rx * cosf(angle3);
  int c_y = cometOrbit.cy + cometOrbit.ry * sinf(angle3);
  MidpointEllipseFilled(c_x, c_y, 8, 8, WHITE);

  // ==========================================
  // UI / HEADER
  // ==========================================
  DrawRectangle(0, 0, screenW, 60, (Color){0, 0, 0, 200});
  DrawText("TUGAS 1 - Kreasi Tata Surya 2D Statis", 20, 10, 20, WHITE);
  DrawText("Murni menggunakan algoritma Bresenham/Midpoint kustom & Modul "
           "Transformasi",
           20, 35, 14, LIGHTGRAY);
}
