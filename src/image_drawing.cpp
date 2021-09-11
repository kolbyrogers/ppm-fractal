#include <iostream>
#include "image_menu.h"

void diagonalQuadPattern( std::istream& is, std::ostream& os, Image& image ) {
    int height, width;

    height = getInteger(is, os, "Image height? ");
    width = getInteger(is, os, "Image width? ");
    image.setHeight(height);
    image.setWidth(width);

    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            // set red channel in top half to 0 and bottom half to 255
            if (row < height / 2) {
                image.setChannel(row, column, 0, 0);
            } else if (row >= height / 2) {
                image.setChannel(row, column, 0, 255);
            }
            // set blue channel in left half to 0 and right half to 255
            if (column < width / 2) {
                image.setChannel(row, column, 2, 0);
            } else if (column >= width / 2) {
                image.setChannel(row, column, 2, 255);
            }
            // set green channel based on calculation
            image.setChannel(row, column, 1, (2*row + 2*column) % 256);
        }
    }
}

void stripedDiagonalPattern( std::istream& is, std::ostream& os, PPM& p ) {
    int height, width, maxCV;
    height = getInteger(is, os, "Image height? ");
    width = getInteger(is, os, "Image width? ");
    
    p.setHeight(height);
    p.setWidth(width);
    maxCV = (height + width) / 3;
    if (maxCV > 255) {
        maxCV = 255;
    }
    p.setMaxColorValue(maxCV);
    os << "Test" << std::endl;
    for (int row = 0; row < p.getHeight(); row++) {
        for (int column = 0; column < p.getWidth(); column++) {
            for (int channel = 0; channel < 3; channel++) {
                /*If a pixel is in the top half of the image, sets the red channel of the pixel to 0. If a pixel is in the bottom half of the image and the row number is a multiple of 3, sets the red channel of the pixel to 0. If a pixel is in the bottom half of the image, and the row number is not a multiple of 3, sets the red channel to the maximum color value.
                Sets the green channel of a pixel to the remainder of (row + width - column - 1) divided by one more than the maximum color value. Read that sentence carefully to get the math correct.
                Sets the blue channel of a pixel to 0 if the column number is less than the row. Otherwise, sets the blue channel to the maximum color value. */
                if (channel == 0){
                    if (row < (p.getHeight() / 2)) {
                        p.setChannel(row, column, channel, 0);
                    } else if (row >= (p.getHeight() / 2) && (row % 3 == 0)) {
                        p.setChannel(row, column, channel, 0);
                    } else if (row >= (p.getHeight() / 2) && (row % 3 != 0)) {
                        p.setChannel(row, column, channel, p.getMaxColorValue());
                    }
                } else if (channel == 1) {
                    p.setChannel(row, column, channel, (row + width - column - 1) % (p.getMaxColorValue() + 1));
                } else if (channel == 2) {
                    if (column < row) {
                        p.setChannel(row, column, channel, 0);
                    } else (p.setChannel(row, column, channel, p.getMaxColorValue()));
                }
            }
        }
    } os << "test2" << std::endl;
}