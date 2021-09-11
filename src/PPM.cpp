#include <iostream>
#include "image_menu.h"
#include "PPM.h"

PPM::PPM()
    : Image(), mMaxCV(1) {
}
PPM::PPM( const int& height, const int& width )
    : Image(height, width), mMaxCV(1) {
}
int PPM::getMaxColorValue() const {
    return mMaxCV;
}
bool PPM::valueValid(const int& value) const {
    return (value >= 0 && value <= mMaxCV);
}
void PPM::setMaxColorValue( const int& max_color_value ){
    if (max_color_value <= 255 && max_color_value >= 1) {
        mMaxCV = max_color_value;
    }
}
void PPM::setChannel(const int& row, const int& column, const int& channel, const int& value) {
    if (valueValid(value)) {
       Image::setChannel(row, column, channel, value);
    }
}
void PPM::setPixel(const int& row, const int& column, const int& red, const int& green, const int& blue) {
    setChannel(row, column, 0, red);
    setChannel(row, column, 1, green);
    setChannel(row, column, 2, blue);
}
void PPM::writeStream(std::ostream& os) const {
    // The first line of data is ASCII text, and the rest is binary data.
    os << "P6 " << getWidth() << " " << getHeight() << " " << getMaxColorValue() << "\n";
    for (int row = 0; row < getHeight(); row++) {
        for (int column = 0; column < getWidth(); column++) {
            for (int channel = 0; channel < 3; channel++) {
                unsigned char byte = getChannel(row, column, channel);
                os.write((char *) &byte, 1);
            }
        }
    }
}