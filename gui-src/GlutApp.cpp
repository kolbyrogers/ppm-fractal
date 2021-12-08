#include "GlutApp.h"
#include "../src/image_menu.h"
#include "glut_app.h"

GlutApp::GlutApp(int height, int width)
    : mHeight(height), mWidth(width), mActionData(mInputStream, mOutputStream),
      mMinX(-2.0), mMaxX(2.0), mMinY(-2.0), mMaxY(2.0),
      mInteractionMode(IM_FRACTAL), mFractalMode(M_MANDELBROT), mMaxNumber(200),
      mColor1(243, 254, 176), mColor2(129, 47, 51), mColor3(50, 50, 0),
      mNumColor(32), mHSVColor(false) {

  configureMenu(mMenuData);
  mActionData.setGrid(new ComplexFractal);

  setColorTable();
  createFractal();

  // // read1
  // mOutputStream.clear();
  // mInputStream.clear();
  // mInputStream.str("pretty-mandel-1.ppm");
  // takeAction("read1", mMenuData, mActionData);

  // // copy
  // mOutputStream.clear();
  // mInputStream.clear();
  // mInputStream.str("");
  // takeAction("copy", mMenuData, mActionData);
}

void GlutApp::setSize(int height, int width) {
  mHeight = height;
  mWidth = width;
}

int GlutApp::getHeight() const { return mHeight; }
int GlutApp::getWidth() const { return mWidth; }

void GlutApp::display() {
  if (mInteractionMode == IM_FRACTAL) {
    PPM &p = mActionData.getOutputImage();
    double max = static_cast<double>(p.getMaxColorValue());
    double r, g, b;
    int row, column;
    glBegin(GL_POINTS);
    for (row = 0; row < p.getHeight(); row++) {
      for (column = 0; column < p.getWidth(); column++) {
        r = p.getChannel(row, column, 0) / max;
        g = p.getChannel(row, column, 1) / max;
        b = p.getChannel(row, column, 2) / max;
        glColor3d(r, g, b);
        glVertex2i(column, p.getHeight() - row - 1);
      }
    }
  } else if (mInteractionMode == IM_COLORTABLE ||
             mInteractionMode == IM_COLOR1 || mInteractionMode == IM_COLOR2 ||
             mInteractionMode == IM_COLOR3) {
    displayColorTable();
  }
  glEnd();
}

void GlutApp::selectJulia() {
  // Sets up the input and output streams, and calls takeAction with the “julia”
  // choice.
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("julia", mMenuData, mActionData);
}
void GlutApp::selectMandelbrot() {
  // Sets up the input and output streams, and calls takeAction with the
  // “mandelbrot” choice.
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("mandelbrot", mMenuData, mActionData);
}
void GlutApp::selectComplexFractal() {
  // Sets up the input and output streams, and calls takeAction with the
  // “complex-fractal” choice.
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("complex-fractal", mMenuData, mActionData);
}
void GlutApp::configureGrid(int max) {
  //  Sets up the input and output streams, and calls takeAction with the “grid”
  //  choice. Uses mHeight and mWidth for the height and width, and max for the
  //  maximum number.
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << mHeight << " " << mWidth << " " << max;
    mInputStream.str(tmp.str());
  }
  takeAction("grid", mMenuData, mActionData);
}
void GlutApp::juliaParameters(double a, double b) {
  // Sets up the input and output streams, and calls takeAction with the
  // “julia-parameters” choice.
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << a << " " << b;
    mInputStream.str(tmp.str());
  }
  takeAction("julia-parameters", mMenuData, mActionData);
}
void GlutApp::fractalPlaneSize(double x_min, double x_max, double y_min,
                               double y_max) {
  // Sets up the input and output streams, and calls takeAction with the
  // “fractal-plane-size” choice.
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << x_min << " " << x_max << " " << y_min << " " << y_max;
    mInputStream.str(tmp.str());
  }
  takeAction("fractal-plane-size", mMenuData, mActionData);
}
void GlutApp::fractalCalculate() {
  // Sets up the input and output streams, and calls takeAction with the
  // “fractal-calculate” choice.
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("fractal-calculate", mMenuData, mActionData);
}
void GlutApp::gridApplyColorTable() {
  // Sets up the input and output streams, and calls takeAction with the
  // “grid-apply-color-table” choice.
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("grid-apply-color-table", mMenuData, mActionData);
}

void GlutApp::createJulia() {
  selectJulia();
  configureGrid(100);
  juliaParameters(-0.8, 0.156);
  fractalPlaneSize(-2.0, 2.0, -2.0, 2.0);
  fractalCalculate();
  gridApplyColorTable();
}
void GlutApp::createJulia2() {
  selectJulia();
  configureGrid(100);
  juliaParameters(0.285, 0.01);
  fractalPlaneSize(-1.5, 1.5, -1.5, 1.5);
  fractalCalculate();
  gridApplyColorTable();
}
void GlutApp::createMandelbrot() {
  selectMandelbrot();
  configureGrid(100);
  fractalPlaneSize(-1.5, 1.5, -1.5, 1.5);
  fractalCalculate();
  gridApplyColorTable();
  // Creates a Mandelbrot set. Must look interesting. Use the methods defined
  // above, as appropriate.
}
void GlutApp::createMandelbrot2() {
  selectMandelbrot();
  configureGrid(1000);
  fractalPlaneSize(-2.0, 2.0, -2.0, 2.0);
  fractalCalculate();
  gridApplyColorTable();
  // Creates a Mandelbrot set. Must be different than the other one. Must look
  // interesting. Use the methods defined above, as appropriate.
}
void GlutApp::createComplexFractal() {
  selectComplexFractal();
  configureGrid(1000);
  fractalPlaneSize(-1.5, 1.5, -1.5, 1.5);
  fractalCalculate();
  gridApplyColorTable();
  // Creates a Complex Fractal. Use the methods defined above, as appropriate.
}
void GlutApp::createComplexFractal2() {
  selectComplexFractal();
  configureGrid(100);
  fractalPlaneSize(-2.0, 2.0, -2.0, 2.0);
  fractalCalculate();
  gridApplyColorTable();
  // Creates a Complex Fractal. Must be different than the other one. Use the
  // methods defined above, as appropriate.
}

void GlutApp::displayColorTable() {
  glBegin(GL_POINTS);
  int row, col;
  for (row = 0; row < mHeight; ++row) {
    for (col = 0; col < mWidth; ++col) {
      int i = col * mNumColor / mWidth;
      Color c1 = mActionData.getTable()[i];
      double red = c1.getRed();
      double green = c1.getGreen();
      double blue = c1.getBlue();
      red /= 255.0;
      green /= 255.0;
      blue /= 255.0;
      glColor3d(red, green, blue);
      glVertex2i(col, row);
    }
  }
  glEnd();
}
void GlutApp::setInteractionMode(InteractionMode mode) {
  mInteractionMode = mode;
}
void GlutApp::setColorTable() {
  mActionData.getTable().setNumberOfColors(mNumColor);
  // mOutputStream.clear();
  // mOutputStream.str("");
  // mInputStream.clear();
  // mInputStream.str("");
  //{
  // std::stringstream tmp;
  // tmp << mNumColor;
  // mInputStream.str(tmp.str());
  //}
  // takeAction("set-color-table-size", mMenuData, mActionData);
  if (!mHSVColor) {
    mActionData.getTable().insertGradient(mColor1, mColor2, 0, mNumColor / 2);
    mActionData.getTable().insertGradient(mColor2, mColor3, mNumColor / 2,
                                          mNumColor - 1);
    // mOutputStream.clear();
    // mOutputStream.str("");
    // mInputStream.clear();
    // mInputStream.str("");
    //{
    // std::stringstream tmp;
    // tmp << 0 << " " << mColor1.getRed() << " " << mColor1.getGreen() << " "
    //<< mColor1.getBlue() << " " << mNumColor - 1 << " " << mColor2.getRed()
    //<< " " << mColor2.getGreen() << " " << mColor2.getBlue();
    // mInputStream.str(tmp.str());
    //}
    // takeAction("set-color-gradient", mMenuData, mActionData);

  } else {
    double hue1, saturation1, value1;
    mColor1.getHSV(hue1, saturation1, value1);
    double hue2, saturation2, value2;
    mColor2.getHSV(hue2, saturation2, value2);
    double hue3, saturation3, value3;
    mColor3.getHSV(hue3, saturation3, value3);
    Color hsv1;
    Color hsv2;
    Color hsv3;
    hsv1.setFromHSV(hue1, saturation1, value1);
    hsv2.setFromHSV(hue2, saturation2, value2);
    hsv3.setFromHSV(hue3, saturation3, value3);
    mActionData.getTable().insertHueSaturationValueGradient(hsv1, hsv2, 0,
                                                            mNumColor / 2);
    mActionData.getTable().insertHueSaturationValueGradient(
        hsv2, hsv3, mNumColor / 2, mNumColor - 1);

    // mOutputStream.clear();
    // mOutputStream.str("");
    // mInputStream.clear();
    // mInputStream.str("");
    //{
    // std::stringstream tmp;
    // tmp << 0 << " " << hue1 << " " << saturation1 << " " << value1 << " "
    //<< mNumColor / 2 << " " << mColor2.getRed() << " "
    //<< mColor2.getGreen() << " " << mColor2.getBlue();
    // mInputStream.str(tmp.str());
    //}
    // takeAction("set-hsv-gradient", mMenuData, mActionData);

    // mOutputStream.clear();
    // mOutputStream.str("");
    // mInputStream.clear();
    // mInputStream.str("");
    //{
    // std::stringstream tmp;
    // tmp << mNumColor / 2 << " " << hue2 << " " << saturation2 << " " <<
    // value2
    //<< " " << mNumColor - 1 << " " << hue3 << " " << saturation3 << " "
    //<< value3;
    // mInputStream.str(tmp.str());
    //}
    // takeAction("set-hsv-gradient", mMenuData, mActionData);
  }
}
void GlutApp::decreaseColorTableSize() {
  if (mNumColor > 10) {
    mNumColor /= 1.1;
    setColorTable();
    gridApplyColorTable();
  }
}
void GlutApp::increaseColorTableSize() {
  if (mNumColor < 1024) {
    mNumColor *= 1.1;
    setColorTable();
    gridApplyColorTable();
  }
}
void GlutApp::zoomIn() {
  double dx, dy;
  dx = (1.0 - 0.9) * (mMaxX - mMinX) / 2.0;
  mMinX += dx;
  mMaxX -= dx;
  dy = (1.0 - 0.9) * (mMaxY - mMinY) / 2.0;
  mMinY += dy;
  mMaxY -= dy;
}
void GlutApp::zoomOut() {
  double dx, dy;
  dx = (1.0 - 0.9) * (mMaxX - mMinX) / 2.0;
  mMinX -= dx;
  mMaxX += dx;
  dy = (1.0 - 0.9) * (mMaxY - mMinY) / 2.0;
  mMinY -= dy;
  mMaxY += dy;
}
void GlutApp::moveLeft() {
  double dx;
  dx = (1.0 - 0.9) * (mMaxX - mMinX) / 2.0;
  if (mMinX - dx >= -2.0) {
    mMinX -= dx;
    mMaxX -= dx;
  }
}
void GlutApp::moveRight() {
  double dx;
  dx = (1.0 - 0.9) * (mMaxX - mMinX) / 2.0;
  if (mMaxX + dx <= 2.0) {
    mMinX += dx;
    mMaxX += dx;
  }
}
void GlutApp::moveDown() {
  double dy;
  dy = (1.0 - 0.9) * (mMaxY - mMinY) / 2.0;
  if (mMinY - dy >= -2.0) {
    mMinY -= dy;
    mMaxY -= dy;
  }
}
void GlutApp::moveUp() {
  double dy;
  dy = (1.0 - 0.9) * (mMaxY - mMinY) / 2.0;
  if (mMaxY + dy <= 2.0) {
    mMinY += dy;
    mMaxY += dy;
  }
}
void GlutApp::setFractalMode(FractalMode mode) { mFractalMode = mode; }
void GlutApp::increaseMaxNumber() {
  if (mMaxNumber < 2048) {
    mMaxNumber *= 1.1;
  }
}
void GlutApp::decreaseMaxNumber() {
  if (mMaxNumber > 11) {
    mMaxNumber /= 1.1;
  }
}
void GlutApp::setAB(int x, int y) {
  mActionData.getGrid();
  ComplexFractal *f1 = dynamic_cast<ComplexFractal *>(&mActionData.getGrid());
  if (mFractalMode == M_MANDELBROT && f1 != 0) {
    mA = mMinX + x * f1->getDeltaX();
    mB = mMinY + y * f1->getDeltaY();
  }
}
void GlutApp::resetPlane() {
  mMinX = -2.0;
  mMaxX = 2.0;
  mMinY = -2.0;
  mMaxY = 2.0;
}
void GlutApp::createFractal() {
  if (mFractalMode == M_MANDELBROT) {
    selectMandelbrot();
  } else if (mFractalMode == M_JULIA) {
    selectJulia();
    juliaParameters(mA, mB);
  } else if (mFractalMode == M_COMPLEX) {
    selectComplexFractal();
  }
  configureGrid(mMaxNumber);
  fractalPlaneSize(mMinX, mMaxX, mMinY, mMaxY);
  fractalCalculate();
  gridApplyColorTable();
}

void GlutApp::increaseChannel(Color &color, int channel) {
  color.setChannel(channel, (color.getChannel(channel) + 10));
  if (color.getChannel(channel) > 255) {
    color.setChannel(channel, 255);
  }
  setColorTable();
  gridApplyColorTable();
}
void GlutApp::decreaseChannel(Color &color, int channel) {
  color.setChannel(channel, (color.getChannel(channel) - 10));
  if (color.getChannel(channel) < 0) {
    color.setChannel(channel, 0);
  }
  setColorTable();
  gridApplyColorTable();
}
Color &GlutApp::fetchColor() {
  if (mInteractionMode == IM_COLOR1) {
    return mColor1;
  } else if (mInteractionMode == IM_COLOR2) {
    return mColor2;
  } else if (mInteractionMode == IM_COLOR3) {
    return mColor3;
  } else {
    static Color color = Color();
    return color;
  }
}
void GlutApp::increaseRed() { increaseChannel(fetchColor(), 0); }
void GlutApp::decreaseRed() { decreaseChannel(fetchColor(), 0); }
void GlutApp::increaseGreen() { increaseChannel(fetchColor(), 1); }
void GlutApp::decreaseGreen() { decreaseChannel(fetchColor(), 1); }
void GlutApp::increaseBlue() { increaseChannel(fetchColor(), 2); }
void GlutApp::decreaseBlue() { decreaseChannel(fetchColor(), 2); }

void GlutApp::toggleHSVColor() {
  mHSVColor = !mHSVColor;
  setColorTable();
  gridApplyColorTable();
}
