#ifndef MANDELBROTSET_H
#define MANDELBROTSET_H

#include "ComplexFractal.h"

class MandelbrotSet : public ComplexFractal {
public:
  MandelbrotSet();
  MandelbrotSet(const int &height, const int &width, const double &min_x,
                const double &max_x, const double &min_y, const double &max_y);
  virtual ~MandelbrotSet();
  virtual void calculateNextPoint(const double x0, const double y0,
                                  const double &a, const double &b, double &x1,
                                  double &y1) const;
  int calculatePlaneEscapeCount(const double &a, const double &b) const;
  virtual int calculateNumber(const int &row, const int &column) const;
};

#endif /* MANDELBROTSET_H */
