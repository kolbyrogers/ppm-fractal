#include <iostream>
#include "image_menu.h"
#include "Image.h"

void diagonalQuadPattern( std::istream& is, std::ostream& os, Image& image ) {
    int height, width;

    height = getInteger(std::cin, std::cout, "Image height? ");
    width = getInteger(std::cin, std::cout, "Image width? ");
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
