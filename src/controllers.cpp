#include <iostream>
#include "image_menu.h"
#include "Image.h"

int assignment1(std::istream& is, std::ostream& os) {
    int q3 = askQuestions3(is, os);
    
    return q3;
}

int assignment2(std::istream& is, std::ostream& os) {
    Image image;
    diagonalQuadPattern(is, os, image);  
    drawAsciiImage(is, os, image);

    return 0; 
}