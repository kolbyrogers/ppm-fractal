#include <iostream>
#include "image_menu.h"
#include "Image.h"

void drawAsciiImage( std::istream& is, std::ostream& os, const Image& image ) {
    int height = image.getHeight();
    int width = image.getWidth();
    int max = height * width * 3;
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            int r = image.getChannel(row, column, 0);
            int g = image.getChannel(row, column, 1);
            int b = image.getChannel(row, column, 2);
            double strength = (r + g + b) / 765.0;
            if (strength >= 1.0) {
                std::cout << "@";
            } else if (strength >= 0.9) {
                std::cout << "#";
            } else if (strength >= 0.8) {
                std::cout << "%";
            } else if (strength >= 0.7) {
                std::cout << "*";
            } else if (strength >= 0.6) {
                std::cout << "|";
            } else if (strength >= 0.5) {
                std::cout << "+";
            } else if (strength >= 0.4) {
                std::cout << ";";
            } else if (strength >= 0.3) {
                std::cout << "~";
            } else if (strength >= 0.2) {
                std::cout << "-";
            } else if (strength >= 0.1) {
                std::cout << ".";
            } else if (strength >= 0.0) {
                std::cout << " ";
            }
            // >= 1.0 -> @, >= 0.9 -> #, >= 0.8 -> %, >= 0.7 -> *, >= 0.6 -> |, 
            // >= 0.5 -> +, >= 0.4 -> ;, >= 0.3 -> ~, >= 0.2 -> -, >= 0.1 -> ., >= 0.0 -> Space
        }
        std::cout << std::endl;
    }
}
