#include "MandelbrotSet.h"

MandelbrotSet::MandelbrotSet() : ComplexFractal() {}
MandelbrotSet::MandelbrotSet(const int &height, const int &width,
                             const double &min_x, const double &max_x,
                             const double &min_y, const double &max_y)
    : ComplexFractal(height, width, min_x, max_x, min_y, max_y) {}
MandelbrotSet::~MandelbrotSet() {}
void MandelbrotSet::calculateNextPoint(const double x0, const double y0,
                                       const double &a, const double &b,
                                       double &x1, double &y1) const {
  x1 = x0 * x0 - y0 * y0 + a;
  y1 = 2 * x0 * y0 + b;
  // Calculates x1 and y1 using the function described above for the Mandelbrot
  // set.
}
int MandelbrotSet::calculatePlaneEscapeCount(const double &a,
                                             const double &b) const {
  int escapeCount = 0;
  double newX = a;
  double newY = b;
  while ((newX * newX) + (newY * newY) <= 4 && escapeCount < mMax) {
    double tmpX = newX;
    double tmpY = newY;
    calculateNextPoint(tmpX, tmpY, a, b, newX, newY);
    escapeCount++;
  }
  return escapeCount;
  // Uses calculateNextPoint to find the escape count for the point at (a,b).
  // The first iteration from x,y = 0,0 to x,y = a,b doesn’t count as an
  // iteration.
}
int MandelbrotSet::calculateNumber(const int &row, const int &column) const {
  if (row < 0 || row >= mHeight || column < 0 || column >= mWidth) {
    return -1;
  }
  double x, y;
  calculatePlaneCoordinatesFromPixelCoordinates(row, column, x, y);
  return calculatePlaneEscapeCount(x, y);
}
