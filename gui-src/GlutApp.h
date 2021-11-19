#ifndef _GLUTAPP_H_
#define _GLUTAPP_H_

#include "ActionData.h"
#include "MenuData.h"
#include <sstream>

class GlutApp
{
public:
  GlutApp(int height, int width);
  void setSize(int height, int width);
  int getHeight() const;
  int getWidth() const;
  void display();
  void selectJulia();
  void selectMandelbrot();
  void selectComplexFractal();
  void configureGrid(int max);
  void juliaParameters(double a, double b);
  void fractalPlaneSize(double x_min, double x_max, double y_min, double y_max);
  void fractalCalculate();
  void gridApplyColorTable();
  void createJulia();
  void createJulia2();
  void createMandelbrot();
  void createMandelbrot2();
  void createComplexFractal();
  void createComplexFractal2();

protected:
  int mHeight, mWidth;
  std::stringstream mInputStream;
  std::stringstream mOutputStream;
  ActionData mActionData;
  MenuData mMenuData;
};

#endif /* _GLUTAPP_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
