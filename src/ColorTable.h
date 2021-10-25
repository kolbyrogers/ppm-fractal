#ifndef _COLORTABLE_H_
#define _COLORTABLE_H_

#include <iostream>
#include <vector>

class Color {
public:
  Color();
  Color(const int &red, const int &green, const int &blue);
  int getRed() const;
  int getGreen() const;
  int getBlue() const;
  int getChannel(const int &channel) const;
  void setRed(const int &value);
  void setGreen(const int &value);
  void setBlue(const int &value);
  void setChannel(const int &channel, const int &value);
  void invert(const int &max_color_value);
  bool operator==(const Color &rhs) const;

private:
  int mRed;
  int mGreen;
  int mBlue;
};
std::ostream &operator<<(std::ostream &os, const Color &color);

class ColorTable {
public:
  ColorTable(const int &num_color);
  int getNumberOfColors() const;
  void setNumberOfColors(const int &num_color);
  const Color &operator[](const int &i) const;
  Color &operator[](const int &i);
  void setRandomColor(const int &max_color_value, const int &position);
  double gradientSlope(const double y1, const double y2, const double x1,
                       const double x2) const;
  double gradientValue(const double y1, const double x1, const double slope,
                       const double x) const;
  void insertGradient(const Color &color1, const Color &color2,
                      const int &position1, const int &position2);
  int getMaxChannelValue() const;

private:
  std::vector<Color> mColors;
};

#endif /* COLORTABLE_H */
