#include <iostream>
#include "image_menu.h"
#include "Image.h"

Image::Image() {
    height = 0;
    width = 0;
    std::vector<int> imageVector(height * width * 3);
}
Image::Image(const int& heightIn, const int& widthIn) {
    setHeight(heightIn);
    setWidth(widthIn);
    std::vector<int> imageVector(height * width * 3);
}
int Image::getHeight() const {
    return height;
}
int Image::getWidth() const {
    return width;
}
bool Image::indexValid( const int& row, const int& column, const int& channel ) const {
    // Checks if row column and channel are within the legal limits. 
    // Returns true if they all are, false otherwise.
    if (row >= getHeight() || row < 0 || column >= getWidth() || column < 0 || channel > 2 || channel < 0) {
        return false;
    }
    return true;
}
int Image::index( const int& row, const int& column, const int& channel ) const {
    return (row * width * 3) + (column * 3) + channel;
}
int Image::getChannel( const int& row, const int& column, const int& channel ) const {
    if (indexValid(row, column, channel))
    {
        return imageVector[index(row, column, channel)];
    } else {
        return -1;
    }
}
void Image::setHeight(const int& heightIn) {
    if (heightIn >= 0) {
        height = heightIn;
        imageVector.resize(height * width * 3);
    }
}
void Image::setWidth(const int& widthIn) {
    if (widthIn >= 0) {
        width = widthIn;
        imageVector.resize(height * width * 3);
    }
}
void Image::setChannel( const int& row, const int& column, const int& channel, const int& value ) {
    if (indexValid(row, column, channel)) {
        imageVector[index(row, column, channel)] = value;
    }
}
