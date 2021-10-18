#include "image_menu.h"
#include <iostream>

int main() {
  ActionData action_data(std::cin, std::cout);
  return simple_squares_ascii(action_data);
}
