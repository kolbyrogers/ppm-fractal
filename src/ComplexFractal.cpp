#include "ComplexFractal.h"
#include <cmath>

ComplexFractal::ComplexFractal()
    : NumberGrid(200, 300), mMinX(-1.5), mMaxX(1.5), mMinY(-1.0), mMaxY(1.0),
      mDeltaX(.01), mDeltaY(.01) {}
ComplexFractal::ComplexFractal(const int &height, const int &width,
                               const double &min_x, const double &max_x,
                               const double &min_y, const double &max_y)
    : NumberGrid(height, width), mMinX(min_x), mMaxX(max_x), mMinY(min_y),
      mMaxY(max_y) {}

ComplexFractal::~ComplexFractal() {}

double ComplexFractal::getMinX() const { return mMinX; }
double ComplexFractal::getMaxX() const { return mMaxX; }
double ComplexFractal::getMinY() const { return mMinY; }
double ComplexFractal::getMaxY() const { return mMaxY; }

void ComplexFractal::setGridSize(const int &height, const int &width) {
  if (height >= 2 && width >= 2) {
    NumberGrid::setGridSize(height, width);
    double delta_x = calculateDeltaX();
    double delta_y = calculateDeltaY();
    setDeltas(delta_x, delta_y);
  }
}
void ComplexFractal::setPlaneSize(const double &min_x, const double &max_x,
                                  const double &min_y, const double &max_y) {
  if (-2.0 <= min_x && min_x <= 2.0 && -2.0 <= max_x && max_x <= 2.0 &&
      -2.0 <= min_y && min_y <= 2.0 && -2.0 <= max_y && max_y <= 2.0 &&
      min_x != max_x && min_y != max_y) {
    mMinX = min_x;
    mMaxX = max_x;
    mMinY = min_y;
    mMaxY = max_y;
    if (min_x > max_x) {
      mMinX = max_x;
      mMaxX = min_x;
    }
    if (min_y > max_y) {
      mMinY = max_y;
      mMaxY = min_y;
    }
    double delta_x = calculateDeltaX();
    double delta_y = calculateDeltaY();
    setDeltas(delta_x, delta_y);
  }
}

double ComplexFractal::getDeltaX() const { return mDeltaX; }
double ComplexFractal::getDeltaY() const { return mDeltaY; }

void ComplexFractal::setDeltas(const double &delta_x, const double &delta_y) {
  if (delta_x >= 0 && delta_y >= 0) {
    mDeltaX = delta_x;
    mDeltaY = delta_y;
  }
}
double ComplexFractal::calculateDeltaY() const {
  return (mMaxY - mMinY) / (getHeight() - 1);
}
double ComplexFractal::calculateDeltaX() const {
  return (mMaxX - mMinX) / (getWidth() - 1);
}
double ComplexFractal::calculatePlaneXFromPixelColumn(const int &column) const {
  double rVal;
  column < 0 || column >= mWidth ? rVal = 0 : rVal = mMinX + column * mDeltaX;
  return rVal;
}
double ComplexFractal::calculatePlaneYFromPixelRow(const int &row) const {
  double rVal;
  row < 0 || row >= mHeight ? rVal = 0 : rVal = mMaxY - row * mDeltaY;
  return rVal;
}
void ComplexFractal::calculatePlaneCoordinatesFromPixelCoordinates(
    const int &row, const int &column, double &x, double &y) const {
  x = calculatePlaneXFromPixelColumn(column);
  y = calculatePlaneYFromPixelRow(row);
  if (x == 0 || y == 0) {
    x = 0;
    y = 0;
  }
}
int ComplexFractal::calculateNumber(const int &row, const int &column) const {
  double x, y;
  int rVal;
  calculatePlaneCoordinatesFromPixelCoordinates(row, column, x, y);
  x == 0 || y == 0
      ? rVal = -1
      : rVal = std::abs(getMaxNumber() * std::sin(10 * x) * std::cos(10 * y));
  return rVal;
}
