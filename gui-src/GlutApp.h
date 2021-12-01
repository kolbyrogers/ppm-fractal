#ifndef _GLUTAPP_H_
#define _GLUTAPP_H_
#define GL_SILENCE_DEPRECATION

#include "../src/ActionData.h"
#include "../src/MenuData.h"
#include <sstream>

enum InteractionMode { IM_FRACTAL, IM_COLORTABLE, IM_COLOR1, IM_COLOR2 };
enum FractalMode { M_MANDELBROT, M_JULIA, M_COMPLEX };

class GlutApp {
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

  void displayColorTable();
  void setInteractionMode(InteractionMode mode);
  void setColorTable();
  void decreaseColorTableSize();
  void increaseColorTableSize();
  void zoomIn();
  void zoomOut();
  void moveLeft();
  void moveRight();
  void moveDown();
  void moveUp();
  void setFractalMode(FractalMode mode);
  void increaseMaxNumber();
  void decreaseMaxNumber();
  void setAB(int x, int y);
  void resetPlane();
  void createFractal();

  void increaseChannel(Color &color, int channel);
  void decreaseChannel(Color &color, int channel);
  Color &fetchColor();
  void increaseRed();
  void decreaseRed();
  void increaseGreen();
  void decreaseGreen();
  void increaseBlue();
  void decreaseBlue();

protected:
  int mHeight, mWidth;
  std::stringstream mInputStream;
  std::stringstream mOutputStream;
  ActionData mActionData;
  MenuData mMenuData;
  double mMinX, mMaxX, mMinY, mMaxY;
  double mA, mB;
  InteractionMode mInteractionMode;
  FractalMode mFractalMode;
  int mMaxNumber;
  Color mColor1;
  Color mColor2;
  Color mColor3;
  int mNumColor;
};

#endif /* _GLUTAPP_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
