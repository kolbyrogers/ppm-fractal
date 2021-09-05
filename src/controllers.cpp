#include <iostream>
#include "image_menu.h"
#include "Image.h"

int assignment1(std::istream& is, std::ostream& os) {
    int q3;

    q3 = askQuestions3(std::cin, std::cout);
    return q3;
}

int assignment2(std::istream& is, std::ostream& os) {
    Image image;
    diagonalQuadPattern(is, os, image);  
    drawAsciiImage(is, os, image);

    return 0; 
}