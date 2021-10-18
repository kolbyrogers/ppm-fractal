#include "image_menu.h"
#include <iostream>

int main() {
  ActionData action_data(std::cin, std::cout);
  return inquisitor(action_data);
}
