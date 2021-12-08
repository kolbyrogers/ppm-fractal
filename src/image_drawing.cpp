#include "JuliaSet.h"
#include "image_menu.h"
#include <cmath>
#include <iostream>

void diagonalQuadPattern(ActionData &action_data) {
  int height, width;
  height = getInteger(action_data, "Image height? ");
  width = getInteger(action_data, "Image width? ");
  action_data.getInputImage1().setHeight(height);
  action_data.getInputImage1().setWidth(width);
  action_data.getInputImage1().setMaxColorValue(255);
  for (int row = 0; row < height; row++) {
    for (int column = 0; column < width; column++) {
      // set red channel in top half to 0 and bottom half to 255
      if (row < height / 2) {
        action_data.getInputImage1().setChannel(row, column, 0, 0);
      } else if (row >= height / 2) {
        action_data.getInputImage1().setChannel(row, column, 0, 255);
      }
      // set blue channel in left half to 0 and right half to 255
      if (column < width / 2) {
        action_data.getInputImage1().setChannel(row, column, 2, 0);
      } else if (column >= width / 2) {
        action_data.getInputImage1().setChannel(row, column, 2, 255);
      }
      // set green channel based on calculation
      action_data.getInputImage1().setChannel(row, column, 1,
                                              (2 * row + 2 * column) % 256);
    }
  }
}
void stripedDiagonalPattern(ActionData &action_data) {
  int height, width, maxCV;
  height = getInteger(action_data, "Image height? ");
  width = getInteger(action_data, "Image width? ");
  action_data.getInputImage1().setHeight(height);
  action_data.getInputImage1().setWidth(width);
  maxCV = (height + width) / 3;
  if (maxCV > 255) {
    maxCV = 255;
  }
  action_data.getInputImage1().setMaxColorValue(maxCV);
  for (int row = 0; row < action_data.getInputImage1().getHeight(); row++) {
    for (int column = 0; column < action_data.getInputImage1().getWidth();
         column++) {
      if (row < height / 2) {
        action_data.getInputImage1().setChannel(row, column, 0, 0);
      } else if (row >= height / 2 && (row % 3) == 0) {
        action_data.getInputImage1().setChannel(row, column, 0, 0);
      } else if (row >= height / 2 && (row % 3) != 0) {
        action_data.getInputImage1().setChannel(
            row, column, 0, action_data.getInputImage1().getMaxColorValue());
      }
      action_data.getInputImage1().setChannel(
          row, column, 1,
          (row + action_data.getInputImage1().getWidth() - column - 1) %
              (action_data.getInputImage1().getMaxColorValue() + 1));
      if (column < row) {
        action_data.getInputImage1().setChannel(row, column, 2, 0);
      } else {
        action_data.getInputImage1().setChannel(
            row, column, 2, action_data.getInputImage1().getMaxColorValue());
      }
    }
  }
}
void simpleSquaresPattern(ActionData &action_data) {
  int size;
  size = getInteger(action_data, "Image size? ");
  action_data.getInputImage1().setHeight(size);
  action_data.getInputImage1().setWidth(size);
  for (int row = 0; row < action_data.getInputImage1().getHeight(); row++) {
    for (int column = 0; column < action_data.getInputImage1().getWidth();
         column++) {
      if (row < action_data.getInputImage1().getHeight() / 2) {
        action_data.getInputImage1().setChannel(row, column, 0, 127);
      } else if (row >= action_data.getInputImage1().getHeight() / 2) {
        action_data.getInputImage1().setChannel(row, column, 0, 255);
      }
      if (column < action_data.getInputImage1().getWidth() / 2) {
        action_data.getInputImage1().setChannel(row, column, 1, 0);
      } else if (column >= action_data.getInputImage1().getWidth() / 2) {
        action_data.getInputImage1().setChannel(row, column, 1, 255);
      }
      action_data.getInputImage1().setChannel(row, column, 2, 255);
    }
  }
}

void setSize(ActionData &action_data) {
  int height, width;
  height = getInteger(action_data, "Height? ");
  width = getInteger(action_data, "Width? ");
  action_data.getInputImage1().setHeight(height);
  action_data.getInputImage1().setWidth(width);
}
void setMaxColorValue(ActionData &action_data) {
  int max = getInteger(action_data, "Max color value? ");
  action_data.getInputImage1().setMaxColorValue(max);
}
void setChannel(ActionData &action_data) {
  int row, column, channel, value;
  row = getInteger(action_data, "Row? ");
  column = getInteger(action_data, "Column? ");
  channel = getInteger(action_data, "Channel? ");
  value = getInteger(action_data, "Value? ");
  action_data.getInputImage1().setChannel(row, column, channel, value);
}
void setPixel(ActionData &action_data) {
  int row, column, red, green, blue;
  row = getInteger(action_data, "Row? ");
  column = getInteger(action_data, "Column? ");
  red = getInteger(action_data, "Red? ");
  green = getInteger(action_data, "Green? ");
  blue = getInteger(action_data, "Blue? ");
  action_data.getInputImage1().setPixel(row, column, red, green, blue);
}
void clearAll(ActionData &action_data) {
  for (int row = 0; row < action_data.getInputImage1().getHeight(); row++) {
    for (int column = 0; column < action_data.getInputImage1().getWidth();
         column++) {
      action_data.getInputImage1().setPixel(row, column, 0, 0, 0);
    }
  }
}

void drawCircle(ActionData &action_data) {
  int centerRow = getInteger(action_data, "Center Row? ");
  int centerCol = getInteger(action_data, "Center Column? ");
  int radius = getInteger(action_data, "Radius? ");
  int red = getInteger(action_data, "Red? ");
  int green = getInteger(action_data, "Green? ");
  int blue = getInteger(action_data, "Blue? ");
  for (int row = 0; row < action_data.getInputImage1().getHeight(); row++) {
    for (int col = 0; col < action_data.getInputImage1().getWidth(); col++) {
      int rowDif = row - centerRow;
      int colDif = col - centerCol;
      double distance = std::sqrt((rowDif * rowDif) + (colDif * colDif));
      if (distance <= radius) {
        action_data.getInputImage1().setPixel(row, col, red, green, blue);
      }
    }
  }
}
void drawBox(ActionData &action_data) {
  int tRow = getInteger(action_data, "Top Row? ");
  int lCol = getInteger(action_data, "Left Column? ");
  int bRow = getInteger(action_data, "Bottom Row? ");
  int rCol = getInteger(action_data, "Right Column? ");
  int red = getInteger(action_data, "Red? ");
  int green = getInteger(action_data, "Green? ");
  int blue = getInteger(action_data, "Blue? ");
  for (int row = tRow; row <= bRow; row++) {
    for (int col = lCol; col <= rCol; col++) {
      action_data.getInputImage1().setPixel(row, col, red, green, blue);
    }
  }
}
void drawSquare(ActionData &action_data) {
  int row = getInteger(action_data, "Row? ");
  int col = getInteger(action_data, "Column? ");
  int size = getInteger(action_data, "Size? ");
  int red = getInteger(action_data, "Red? ");
  int green = getInteger(action_data, "Green? ");
  int blue = getInteger(action_data, "Blue? ");
  int tRow = row - (size / 2);
  int bRow = row + (size / 2);
  int lCol = col - (size / 2);
  int rCol = col + (size / 2);
  for (int row = tRow; row <= bRow; row++) {
    for (int col = lCol; col <= rCol; col++) {
      action_data.getInputImage1().setPixel(row, col, red, green, blue);
    }
  }
}

// Number Grid
void configureGrid(ActionData &action_data) {
  int height = getInteger(action_data, "Grid Height? ");
  int width = getInteger(action_data, "Grid Width? ");
  int max = getInteger(action_data, "Grid Max Value? ");
  action_data.getGrid().setGridSize(height, width);
  action_data.getGrid().setMaxNumber(max);
}
void setGrid(ActionData &action_data) {
  int row = getInteger(action_data, "Grid Row? ");
  int col = getInteger(action_data, "Grid Column? ");
  int val = getInteger(action_data, "Grid Value? ");
  action_data.getGrid().setNumber(row, col, val);
}
void applyGrid(ActionData &action_data) {
  action_data.getGrid().setPPM(action_data.getOutputImage());
}

// Color Table
void setColorTableSize(ActionData &action_data) {
  int size = getInteger(action_data, "Size? ");
  action_data.getTable().setNumberOfColors(size);
}
void setColor(ActionData &action_data) {
  int position = getInteger(action_data, "Position? ");
  int red = getInteger(action_data, "Red? ");
  int green = getInteger(action_data, "Green? ");
  int blue = getInteger(action_data, "Blue? ");
  action_data.getTable()[position].setRed(red);
  action_data.getTable()[position].setGreen(green);
  action_data.getTable()[position].setBlue(blue);
}
void setRandomColor(ActionData &action_data) {
  int position = getInteger(action_data, "Position? ");
  action_data.getTable().setRandomColor(255, position);
}
void setColorGradient(ActionData &action_data) {
  int p1 = getInteger(action_data, "First position? ");
  int fRed = getInteger(action_data, "First red? ");
  int fGreen = getInteger(action_data, "First green? ");
  int fBlue = getInteger(action_data, "First blue? ");
  int p2 = getInteger(action_data, "Second position? ");
  int sRed = getInteger(action_data, "Second red? ");
  int sGreen = getInteger(action_data, "Second green? ");
  int sBlue = getInteger(action_data, "Second blue? ");
  Color c1;
  Color c2;
  c1.setRed(fRed);
  c1.setGreen(fGreen);
  c1.setBlue(fBlue);
  c2.setRed(sRed);
  c2.setGreen(sGreen);
  c2.setBlue(sBlue);
  action_data.getTable().insertGradient(c1, c2, p1, p2);
}
void applyGridColorTable(ActionData &action_data) {
  action_data.getGrid().setPPM(action_data.getOutputImage(),
                               action_data.getTable());
}

// ComplexFractal
void setFractalPlaneSize(ActionData &action_data) {
  double min_x = getDouble(action_data, "Min X? ");
  double max_x = getDouble(action_data, "Max X? ");
  double min_y = getDouble(action_data, "Min Y? ");
  double max_y = getDouble(action_data, "Max Y? ");
  ComplexFractal *f1 = dynamic_cast<ComplexFractal *>(&action_data.getGrid());
  if (f1 != 0) {
    f1->setPlaneSize(min_x, max_x, min_y, max_y);
  } else {
    std::cout << "Not a ComplexFractal object. Can't set the plane size.";
  }
}
void calculateFractal(ActionData &action_data) {
  action_data.getGrid().calculateAllNumbers();
}

// Julia Set
void setJuliaParameters(ActionData &action_data) {
  double a = getDouble(action_data, "Parameter a? ");
  double b = getDouble(action_data, "Parameter b? ");
  JuliaSet *j1 = dynamic_cast<JuliaSet *>(&action_data.getGrid());
  if (j1 != 0) {
    j1->setParameters(a, b);
  } else {
    std::cout << "Not a JuliaSet object. Can't set parameters.";
  }
}

// Threaded Grid
void calculateFractalSingleThread(ActionData &action_data) {
  action_data.getGrid().NumberGrid::calculateAllNumbers();
}

// Final Exam
void setHueSaturationValueGradient(ActionData &action_data) {
  int p1 = getInteger(action_data, "First position? ");
  double fHue = getInteger(action_data, "First hue? ");
  double fSaturation = getInteger(action_data, "First saturation? ");
  double fValue = getInteger(action_data, "First value? ");
  int p2 = getInteger(action_data, "Second position? ");
  double sHue = getInteger(action_data, "Second hue? ");
  double sSaturation = getInteger(action_data, "Second saturation? ");
  double sValue = getInteger(action_data, "Second value? ");
  Color c1;
  Color c2;
  c1.setFromHSV(fHue, fSaturation, fValue);
  c2.setFromHSV(sHue, sSaturation, sValue);
  action_data.getTable().insertHueSaturationValueGradient(c1, c2, p1, p2);
}
