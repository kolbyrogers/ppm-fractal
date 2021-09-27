#include <iostream>
#include "image_menu.h"

int main()
{
   ActionData action_data(std::cin, std::cout);
   return simple_squares_ascii(action_data);
}
