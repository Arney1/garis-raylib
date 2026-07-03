#ifndef ELLIPSE_TRANSFORM_H
#define ELLIPSE_TRANSFORM_H

#include "raylib.h"

// Struct untuk mempermudah transformasi
typedef struct {
    float cx, cy;
    float rx, ry;
} Ellipse2D;

// Transformasi dasar elips
void TranslateEllipse2D(Ellipse2D *el, float tx, float ty);
void ScaleEllipse2D(Ellipse2D *el, float sx, float sy);

// Rotasi sebuah titik (berguna untuk menempatkan planet di orbit atau rotasi sumbu)
void RotatePoint2D(float *x, float *y, float cx, float cy, float angle_deg);

#endif
