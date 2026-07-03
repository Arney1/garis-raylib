# Tugas 1: Algoritma & Transformasi Elips (Raylib)

Proyek ini adalah bentuk *refactoring* dan implementasi dari materi elips yang diberikan, disederhanakan menjadi satu program utama (Tugas 1). Semua fungsi penggambaran bentuk dilakukan murni dengan iterasi piksel, tanpa menggunakan fungsi bawaan Raylib seperti `DrawEllipse` atau `DrawCircle`.

## 📌 Fitur & Implementasi

1. **Midpoint Ellipse Algorithm (`src/algo/midellipse.c`)**
   * Implementasi dasar Midpoint.
   * Variasi: `MidpointEllipseFilled` (Solid) & `MidpointEllipseThick` (Tebal).

2. **Bresenham Ellipse Algorithm (`src/algo/bresellipse.c`)**
   * Implementasi algoritma Bresenham berbasis decision parameter integer.
   * Variasi: `Bres_ThickEllipse` & `Bres_DashedEllipse` (Elips putus-putus).

3. **2D Transformations (`src/algo/ellipse_transform.c`)**
   * Menggunakan struct `Ellipse2D`.
   * **Translasi**: Pergeseran koordinat pusat (`cx, cy`).
   * **Scaling**: Skala jari-jari (`rx, ry`).
   * **Rotasi**: Modul komputasi matriks rotasi 2D untuk titik koordinat kustom.

4. **Hasil Kreasi (`src/screens/tugas1_creation.c`)**
   * Ilustrasi Tata Surya 2D statis.
   * Menggabungkan elips solid (Matahari, Planet), elips tebal (Korona, Cincin Planet), dan elips putus-putus (Garis Orbit).
   * Orbit komet dibuat menggunakan kombinasi *Scaling* dan *Translasi* agar terlihat asimetris terhadap pusat layar.
