#include <iostream>
#include <string>
#include "Image.h"

std::string getString( std::istream& is, std::ostream& os, const std::string& prompt );

int getInteger( std::istream& is, std::ostream& os, const std::string& prompt );

double getDouble( std::istream& is, std::ostream& os, const std::string& prompt );

int askQuestions3(std::istream& is, std::ostream& os);

int assignment1( std::istream& is, std::ostream& os );

void drawAsciiImage( std::istream& is, std::ostream& os, const Image& image );

void diagonalQuadPattern( std::istream& is, std::ostream& os, Image& image );

int assignment2( std::istream& is, std::ostream& os );
