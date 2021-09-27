#include <iostream>
#include "image_menu.h"
#include "ActionData.h"

std::string getString(ActionData &action_data, const std::string &prompt)
{
    std::string response;
    action_data.getOS() << prompt;
    action_data.getIS() >> response;
    return response;
}

int getInteger(ActionData &action_data, const std::string &prompt)
{
    int response;
    action_data.getOS() << prompt;
    action_data.getIS() >> response;
    return response;
}

double getDouble(ActionData &action_data, const std::string &prompt)
{
    double response;
    action_data.getOS() << prompt;
    action_data.getIS() >> response;
    return response;
}

int askQuestions3(ActionData &action_data)
{
    std::string color;
    int integer;
    double number;
    int i;

    color = getString(action_data, "What is your favorite color? ");
    integer = getInteger(action_data, "What is your favorite integer? ");
    number = getDouble(action_data, "What is your favorite number? ");
    for (i = 0; i < integer; i++)
    {
        action_data.getOS() << (i + 1) << " " << color << " " << number << std::endl;
    }
    return integer;
}

int askInquisitorQuestions(ActionData &action_data)
{
    std::string pokemon;
    int level;
    double health;
    pokemon = getString(action_data, "What is your most powerful Pokemon? ");
    level = getInteger(action_data, "What is its level? ");
    health = getDouble(action_data, "What is its health? ");
    action_data.getOS() << pokemon << " is level " << level << " and " << health << " HP." << std::endl;
    return level;
}

std::string getChoice(ActionData &action_data)
{
    return getString(action_data, "Choice? ");
}

void commentLine(ActionData &action_data)
{
    unsigned char byte;
    bool repeat = true;
    while (repeat == true)
    {
        action_data.getIS().read((char *)&byte, 1);
        if (!action_data.getIS().good() || byte == '\n')
        {
            repeat = false;
        }
    }
    return;
    // read from the input stream until the input stream has nothing to read,
    // or a newline character is read. Do not do anything with the characters read.
}

void quit(ActionData &action_data)
{
    action_data.setDone();
}
