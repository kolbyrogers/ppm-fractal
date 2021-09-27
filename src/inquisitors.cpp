#include <iostream>
#include "image_menu.h"

int main()
{
    ActionData action_data(std::cin, std::cout);
    return inquisitor(action_data);
}