#include "ColorTable.h"
#include <iostream>
#include <random>
#include <vector>

// --- Color Class ---
Color::Color() : mRed(0), mGreen(0), mBlue(0) {}
Color::Color(const int &red, const int &green, const int &blue)
    : mRed(red), mGreen(green), mBlue(blue) {}

int Color::getRed() const { return mRed; }

int Color::getGreen() const { return mGreen; }

int Color::getBlue() const { return mBlue; }

int Color::getChannel(const int &channel) const {
  if (channel == 0) {
    return mRed;
  } else if (channel == 1) {
    return mGreen;
  } else if (channel == 2) {
    return mBlue;
  }
  return -1;
}
void Color::setRed(const int &value) {
  if (value >= 0) {
    mRed = value;
  }
}
void Color::setGreen(const int &value) {
  if (value >= 0) {
    mGreen = value;
  }
}
void Color::setBlue(const int &value) {
  if (value >= 0) {
    mBlue = value;
  }
}
void Color::setChannel(const int &channel, const int &value) {
  if (channel == 0) {
    setRed(value);
  } else if (channel == 1) {
    setGreen(value);
  } else if (channel == 2) {
    setBlue(value);
  }
}
void Color::invert(const int &max_color_value) {
  if (getRed() <= max_color_value && getGreen() <= max_color_value &&
      getBlue() <= max_color_value) {
    setRed(max_color_value - getRed());
    setGreen(max_color_value - getGreen());
    setBlue(max_color_value - getBlue());
  }
}
bool Color::operator==(const Color &rhs) const {
  return this->getChannel(0) == rhs.getChannel(0) &&
         this->getChannel(1) == rhs.getChannel(1) &&
         this->getChannel(2) == rhs.getChannel(2);
}
// support functions
std::ostream &operator<<(std::ostream &os, const Color &color) {
  os << color.getRed() << ":" << color.getGreen() << ":" << color.getBlue();
  return os;
}

// --- ColorTable Class ---
ColorTable::ColorTable(const int &num_color) : mColors(num_color) {}

int ColorTable::getNumberOfColors() const { return mColors.size(); }

void ColorTable::setNumberOfColors(const int &num_color) {
  mColors.resize(num_color);
}
const Color &ColorTable::operator[](const int &i) const {
  if (i >= getNumberOfColors() || i < 0) {
    static Color ec(-1, -1, -1);
    static Color c(-1, -1, -1);
    c = ec;
    return c;
  } else {
    return mColors[i];
  }
}
Color &ColorTable::operator[](const int &i) {
  if (i >= getNumberOfColors() || i < 0) {
    static Color ec(-1, -1, -1);
    static Color c(-1, -1, -1);
    c = ec;
    return c;
  } else {
    return mColors[i];
  }
}
void ColorTable::setRandomColor(const int &max_color_value,
                                const int &position) {
  if (position < getNumberOfColors() && max_color_value >= 0 && position >= 0) {
    int rRed = (std::rand() % (max_color_value + 1));
    int rGreen = (std::rand() % (max_color_value + 1));
    int rBlue = (std::rand() % (max_color_value + 1));
    mColors[position].setRed(rRed);
    mColors[position].setGreen(rGreen);
    mColors[position].setBlue(rBlue);
  }
}
double ColorTable::gradientSlope(const double y1, const double y2,
                                 const double x1, const double x2) const {
  return (y2 - y1) / (x2 - x1);
}
double ColorTable::gradientValue(const double y1, const double x1,
                                 const double slope, const double x) const {
  return y1 + (x - x1) * slope;
  // Calculate the y-value along the gradient from point (x1,y1) to the point
  // at position x.
}
void ColorTable::insertGradient(const Color &color1, const Color &color2,
                                const int &position1, const int &position2) {
  if (position1 < position2 && position1 < getNumberOfColors() &&
      position2 < getNumberOfColors() && position1 >= 0 && position2 >= 0) {
    for (int i = position1; i <= position2; ++i) {
      for (int channel = 0; channel < 3; ++channel) {
        int value1 = color1.getChannel(channel);
        int value2 = color2.getChannel(channel);
        double slope = gradientSlope(value1, value2, position1, position2);
        double newVal = gradientValue(value1, position1, slope, i);
        mColors[i].setChannel(channel, newVal);
      }
    }
  }
}
int ColorTable::getMaxChannelValue() const {
  int max = 0;
  for (int i = 0; i < getNumberOfColors(); ++i) {

    for (int channel = 0; channel < 3; ++channel) {
      int tmp = max;
      mColors[i].getChannel(channel) > max
          ? max = mColors[i].getChannel(channel)
          : max = tmp;
    }
  }
  return max;
}
