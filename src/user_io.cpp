#include <iostream>
#include "image_menu.h"

std::string getString(std::istream &is, std::ostream &os, const std::string &prompt)
{
    std::string response;
    os << prompt;
    is >> response;
    return response;
}

int getInteger(std::istream &is, std::ostream &os, const std::string &prompt)
{
    int response;
    os << prompt;
    is >> response;
    return response;
}

double getDouble(std::istream &is, std::ostream &os, const std::string &prompt)
{
    double response;
    os << prompt;
    is >> response;
    return response;
}
int askQuestions3(std::istream &is, std::ostream &os)
{
    std::string color;
    int integer;
    double number;
    int i;

    color = getString(is, os, "What is your favorite color? ");
    integer = getInteger(is, os, "What is your favorite integer? ");
    number = getDouble(is, os, "What is your favorite number? ");
    // for i in range(integer):
    //     print(i + 1, color, number)
    for (i = 0; i < integer; i++)
    {
        os << (i + 1) << " " << color << " " << number << std::endl;
    }
    return integer;
}

int askInquisitorQuestions(std::istream &is, std::ostream &os)
{
    std::string pokemon;
    int level;
    double health;
    pokemon = getString(is, os, "What is your most powerful Pokemon? ");
    level = getInteger(is, os, "What is its level? ");
    health = getDouble(is, os, "What is its health? ");
    os << pokemon << " is level " << level << " and " << health << " HP." << std::endl;
    return level;
}