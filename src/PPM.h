#ifndef _PPM_H_
#define _PPM_H_
#include "Image.h"
#include <iostream>

class PPM : public Image
{
public:
    // Constructors
    PPM();
    PPM(const int &height, const int &width);

    // Methods
    int getMaxColorValue() const;
    bool valueValid(const int &value) const;
    void setMaxColorValue(const int &max_color_value);
    void setChannel(const int &row, const int &column, const int &channel, const int &value);
    void setPixel(const int &row, const int &column, const int &red, const int &green, const int &blue);
    void writeStream(std::ostream &os) const;
    void readStream(std::istream &is);

    // Operators
    bool operator==(const PPM &rhs) const;
    bool operator!=(const PPM &rhs) const;
    bool operator<(const PPM &rhs) const;
    bool operator<=(const PPM &rhs) const;
    bool operator>(const PPM &rhs) const;
    bool operator>=(const PPM &rhs) const;
    PPM &operator+=(const PPM &rhs);
    PPM &operator-=(const PPM &rhs);
    PPM &operator*=(const double &rhs);
    PPM &operator/=(const double &rhs);
    PPM operator+(const PPM &rhs) const;
    PPM operator-(const PPM &rhs) const;
    PPM operator*(const double &rhs) const;
    PPM operator/(const double &rhs) const;

private:
    // Data members
    int mMaxCV;
};

#endif