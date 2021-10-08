#include <iostream>
#include "image_menu.h"
#include "PPM.h"

PPM::PPM()
    : Image(), mMaxCV(1)
{
}
PPM::PPM(const int &height, const int &width)
    : Image(height, width), mMaxCV(1)
{
}
int PPM::getMaxColorValue() const
{
    return mMaxCV;
}
bool PPM::valueValid(const int &value) const
{
    return (value >= 0 && value <= mMaxCV);
}
void PPM::setMaxColorValue(const int &max_color_value)
{
    if (max_color_value <= 255 && max_color_value >= 1)
    {
        mMaxCV = max_color_value;
    }
}
void PPM::setChannel(const int &row, const int &column, const int &channel, const int &value)
{
    if (valueValid(value))
    {
        Image::setChannel(row, column, channel, value);
    }
}
void PPM::setPixel(const int &row, const int &column, const int &red, const int &green, const int &blue)
{
    setChannel(row, column, 0, red);
    setChannel(row, column, 1, green);
    setChannel(row, column, 2, blue);
}
void PPM::writeStream(std::ostream &os) const
{
    os << "P6 " << getWidth() << " " << getHeight() << " " << getMaxColorValue() << "\n";
    for (int row = 0; row < getHeight(); row++)
    {
        for (int column = 0; column < getWidth(); column++)
        {
            for (int channel = 0; channel < 3; channel++)
            {
                unsigned char byte = getChannel(row, column, channel);
                os.write((char *)&byte, 1);
            }
        }
    }
}
void PPM::readStream(std::istream &is)
{
    std::string p6;
    int width;
    int height;
    int max;
    unsigned char byte;
    is >> p6 >> width >> height >> max;
    setWidth(width);
    setHeight(height);
    setMaxColorValue(max);
    is.read((char *)&byte, 1); // dumps the newline character
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            for (int channel = 0; channel < 3; channel++)
            {
                is.read((char *)&byte, 1);
                setChannel(row, column, channel, byte);
            }
        }
    }
}

bool PPM::operator==(const PPM &rhs) const
{
    return (getHeight() * getWidth()) == (rhs.getHeight() * rhs.getWidth());
}

bool PPM::operator!=(const PPM &rhs) const
{
    return (getHeight() * getWidth()) != (rhs.getHeight() * rhs.getWidth());
}

bool PPM::operator<(const PPM &rhs) const
{
    return (getHeight() * getWidth()) < (rhs.getHeight() * rhs.getWidth());
}
bool PPM::operator<=(const PPM &rhs) const
{
    return (getHeight() * getWidth()) <= (rhs.getHeight() * rhs.getWidth());
}
bool PPM::operator>(const PPM &rhs) const
{

    return (getHeight() * getWidth()) > (rhs.getHeight() * rhs.getWidth());
}
bool PPM::operator>=(const PPM &rhs) const
{
    return (getHeight() * getWidth()) >= (rhs.getHeight() * rhs.getWidth());
}
PPM &PPM::operator+=(const PPM &rhs)
{
    int mcv = getMaxColorValue();
    for (int row = 0; row < getHeight(); row++)
    {
        for (int col = 0; col < getWidth(); col++)
        {
            int red = (getChannel(row, col, 0) + rhs.getChannel(row, col, 0));
            red = red > mcv ? mcv : red;
            int green = (getChannel(row, col, 1) + rhs.getChannel(row, col, 1));
            green = green > mcv ? mcv : green;
            int blue = (getChannel(row, col, 2) + rhs.getChannel(row, col, 2));
            blue = blue > mcv ? mcv : blue;
            setChannel(row, col, 0, red);
            setChannel(row, col, 1, green);
            setChannel(row, col, 2, blue);
        }
    }
    return *this;
}
PPM &PPM::operator-=(const PPM &rhs)
{
    for (int row = 0; row < getHeight(); row++)
    {
        for (int col = 0; col < getWidth(); col++)
        {
            int red = (getChannel(row, col, 0) - rhs.getChannel(row, col, 0));
            red = red < 0 ? 0 : red;
            int green = (getChannel(row, col, 1) - rhs.getChannel(row, col, 1));
            green = green < 0 ? 0 : green;
            int blue = (getChannel(row, col, 2) - rhs.getChannel(row, col, 2));
            blue = blue < 0 ? 0 : blue;
            setChannel(row, col, 0, red);
            setChannel(row, col, 1, green);
            setChannel(row, col, 2, blue);
        }
    }
    return *this;
}
PPM &PPM::operator*=(const double &rhs)
{
    int mcv = getMaxColorValue();
    for (int row = 0; row < getHeight(); row++)
    {
        for (int col = 0; col < getWidth(); col++)
        {
            int red = (getChannel(row, col, 0) * rhs);
            red = red > mcv ? mcv : red;
            red = red < 0 ? 0 : red;
            int green = (getChannel(row, col, 1) * rhs);
            green = green > mcv ? mcv : green;
            green = green < 0 ? 0 : green;
            int blue = (getChannel(row, col, 2) * rhs);
            blue = blue > mcv ? mcv : blue;
            blue = blue < 0 ? 0 : blue;
            setChannel(row, col, 0, red);
            setChannel(row, col, 1, green);
            setChannel(row, col, 2, blue);
        }
    }
    return *this;
}
PPM &PPM::operator/=(const double &rhs)
{
    int mcv = getMaxColorValue();
    for (int row = 0; row < getHeight(); row++)
    {
        for (int col = 0; col < getWidth(); col++)
        {
            int red = (getChannel(row, col, 0) / rhs);
            red = red > mcv ? mcv : red;
            red = red < 0 ? 0 : red;
            int green = (getChannel(row, col, 1) / rhs);
            green = green > mcv ? mcv : green;
            green = green < 0 ? 0 : green;
            int blue = (getChannel(row, col, 2) / rhs);
            blue = blue > mcv ? mcv : blue;
            blue = blue < 0 ? 0 : blue;
            setChannel(row, col, 0, red);
            setChannel(row, col, 1, green);
            setChannel(row, col, 2, blue);
        }
    }
    return *this;
}
PPM PPM::operator+(const PPM &rhs) const
{
    PPM newObject(getHeight(), getWidth());
    int mcv = getMaxColorValue();
    newObject.setMaxColorValue(mcv);
    for (int row = 0; row < getHeight(); row++)
    {
        for (int col = 0; col < getWidth(); col++)
        {
            int red = (getChannel(row, col, 0) + rhs.getChannel(row, col, 0));
            red = red > mcv ? mcv : red;
            int green = (getChannel(row, col, 1) + rhs.getChannel(row, col, 1));
            green = green > mcv ? mcv : green;
            int blue = (getChannel(row, col, 2) + rhs.getChannel(row, col, 2));
            blue = blue > mcv ? mcv : blue;
            newObject.setChannel(row, col, 0, red);
            newObject.setChannel(row, col, 1, green);
            newObject.setChannel(row, col, 2, blue);
        }
    }
    return newObject;
}
PPM PPM::operator-(const PPM &rhs) const
{
    PPM newObject(getHeight(), getWidth());
    int mcv = getMaxColorValue();
    newObject.setMaxColorValue(mcv);
    for (int row = 0; row < getHeight(); row++)
    {
        for (int col = 0; col < getWidth(); col++)
        {
            int red = (getChannel(row, col, 0) - rhs.getChannel(row, col, 0));
            red = red < 0 ? 0 : red;
            int green = (getChannel(row, col, 1) - rhs.getChannel(row, col, 1));
            green = green < 0 ? 0 : green;
            int blue = (getChannel(row, col, 2) - rhs.getChannel(row, col, 2));
            blue = blue < 0 ? 0 : blue;
            newObject.setChannel(row, col, 0, red);
            newObject.setChannel(row, col, 1, green);
            newObject.setChannel(row, col, 2, blue);
        }
    }
    return newObject;
}

PPM PPM::operator*(const double &rhs) const
{
    PPM newObject(getHeight(), getWidth());
    int mcv = getMaxColorValue();
    newObject.setMaxColorValue(mcv);
    for (int row = 0; row < getHeight(); row++)
    {
        for (int col = 0; col < getWidth(); col++)
        {
            int red = (getChannel(row, col, 0) * rhs);
            red = red > mcv ? mcv : red;
            red = red < 0 ? 0 : red;
            int green = (getChannel(row, col, 1) * rhs);
            green = green > mcv ? mcv : green;
            green = green < 0 ? 0 : green;
            int blue = (getChannel(row, col, 2) * rhs);
            blue = blue > mcv ? mcv : blue;
            blue = blue < 0 ? 0 : blue;
            newObject.setChannel(row, col, 0, red);
            newObject.setChannel(row, col, 1, green);
            newObject.setChannel(row, col, 2, blue);
        }
    }
    return newObject;
}

PPM PPM::operator/(const double &rhs) const
{
    PPM newObject(getHeight(), getWidth());
    int mcv = getMaxColorValue();
    newObject.setMaxColorValue(mcv);
    for (int row = 0; row < getHeight(); row++)
    {
        for (int col = 0; col < getWidth(); col++)
        {
            int red = (getChannel(row, col, 0) / rhs);
            red = red > mcv ? mcv : red;
            red = red < 0 ? 0 : red;
            int green = (getChannel(row, col, 1) / rhs);
            green = green > mcv ? mcv : green;
            green = green < 0 ? 0 : green;
            int blue = (getChannel(row, col, 2) / rhs);
            blue = blue > mcv ? mcv : blue;
            blue = blue < 0 ? 0 : blue;
            newObject.setChannel(row, col, 0, red);
            newObject.setChannel(row, col, 1, green);
            newObject.setChannel(row, col, 2, blue);
        }
    }
    return newObject;
}

void PPM::grayFromChannel(PPM &dst, const int &src_channel) const
{
    int height = getHeight();
    int width = getWidth();
    int mcv = getMaxColorValue();
    dst.setHeight(height);
    dst.setWidth(width);
    dst.setMaxColorValue(mcv);
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int value = getChannel(row, col, src_channel);
            dst.setChannel(row, col, 0, value);
            dst.setChannel(row, col, 1, value);
            dst.setChannel(row, col, 2, value);
        }
    }
}

void PPM::grayFromRed(PPM &dst) const
{
    grayFromChannel(dst, 0);
}
void PPM::grayFromGreen(PPM &dst) const
{
    grayFromChannel(dst, 1);
}
void PPM::grayFromBlue(PPM &dst) const
{
    grayFromChannel(dst, 2);
}
double PPM::linearColorimetricPixelValue(const int &row, const int &column) const
{
    // brightness = 0.2126*red + 0.7152*green + 0.0722*blue.
    return (0.2126 * getChannel(row, column, 0)) + (0.7152 * getChannel(row, column, 1)) + (0.0722 * getChannel(row, column, 2));
}

void PPM::grayFromLinearColorimetric(PPM &dst) const
{
    int height = getHeight();
    int width = getWidth();
    int mcv = getMaxColorValue();
    dst.setHeight(height);
    dst.setWidth(width);
    dst.setMaxColorValue(mcv);

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            double value = linearColorimetricPixelValue(row, col);
            dst.setChannel(row, col, 0, value);
            dst.setChannel(row, col, 1, value);
            dst.setChannel(row, col, 2, value);
        }
    }
}
void PPM::orangeFilter(PPM& dst) const {
	int height = getHeight();
	int width = getWidth();
	int mcv = getMaxColorValue();
	dst.setHeight(height);
	dst.setWidth(width);
	dst.setMaxColorValue(mcv);

	for (int row = 0; row < height; row++)
    {
       for (int col = 0; col < width; col++)
        {
			int old_red = getChannel(row, col, 0);
			int old_green = getChannel(row, col, 1);
			int old_blue = getChannel(row, col, 2);

            int new_red = 2 * (2 * old_red + old_green) / 3;
            new_red = new_red > mcv ? mcv : new_red;
            int new_green = 2 * (2 * old_red + old_green) / 6;
            new_green = new_green > mcv ? mcv : new_green;
			int new_blue = old_blue / 2;
            new_blue = new_blue > mcv ? mcv : new_blue;
			dst.setChannel(row, col, 0, new_red);
			dst.setChannel(row, col, 1, new_green);
			dst.setChannel(row, col, 2, new_blue);
        }
    }	
}
