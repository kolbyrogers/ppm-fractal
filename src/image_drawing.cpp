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
    int height, width, maxCV, greenValue;

    height = getInteger(is, os, "Image height? ");
    width = getInteger(is, os, "Image width? ");
    p.setHeight(height);
    p.setWidth(width);

    maxCV = (height + width) / 3;
    if (maxCV > 255) {
        maxCV = 255;
    }
    p.setMaxColorValue(maxCV);

    for (int row = 0; row < p.getHeight(); row++) {
        for (int column = 0; column < p.getWidth(); column++) {
            // If a pixel is in the top half of the image, sets the red channel of the pixel to 0.
            // If a pixel is in the bottom half of the image and the row number is a multiple of 3, sets the red channel of the pixel to 0.
            // If a pixel is in the bottom half of the image, and the row number is not a multiple of 3, sets the red channel to the maximum color value.
            if (row < height / 2) {
                p.setChannel(row, column, 0, 0);
            } else if (row >= height / 2 && (row % 3) == 0) {
                p.setChannel(row, column, 0, 0);
            } else if (row >= height / 2 && (row % 3) != 0) {
                p.setChannel(row, column, 0, p.getMaxColorValue());
            }
            // Sets the green channel of a pixel to the remainder of (row + width - column - 1) divided by one more than the maximum color value.
            p.setChannel(row, column, 1, (row + p.getWidth() - column - 1) % (p.getMaxColorValue() + 1));
            // Sets the blue channel of a pixel to 0 if the column number is less than the row. Otherwise, sets the blue channel to the maximum color value.
            if (column < row) {
                p.setChannel(row, column, 2, 0);
            } else {
                p.setChannel(row, column, 2, p.getMaxColorValue());
            }   
        }
    }
}