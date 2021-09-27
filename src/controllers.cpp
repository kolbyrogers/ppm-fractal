#include <iostream>
#include <map>
#include <string>
#include "image_menu.h"
#include "Image.h"
#include "PPM.h"

int assignment1(std::istream &is, std::ostream &os)
{
    ActionData action_data(is, os);
    return askQuestions3(action_data);
}

int assignment2(std::istream &is, std::ostream &os)
{
    ActionData action_data(is, os);
    diagonalQuadPattern(action_data);
    copyImage(action_data);
    drawAsciiImage(action_data);

    return 0;
}

int assignment3(std::istream &is, std::ostream &os)
{
    ActionData action_data(is, os);
    stripedDiagonalPattern(action_data);
    copyImage(action_data);
    writeUserImage(action_data);

    return 0;
}

int inquisitor(ActionData &action_data)
{
    return askInquisitorQuestions(action_data);
}

int simple_squares_ascii(std::istream &is, std::ostream &os)
{
    ActionData action_data(is, os);
    simpleSquaresPattern(action_data);
    copyImage(action_data);
    drawAsciiImage(action_data);

    return 0;
}

void showMenu(MenuData &menu_data, ActionData &action_data)
{
    // For each command that was added to MenuData via addAction(), displays one line of text to the output stream of the ActionData.
    // The lines are formatted like this: “command-name) command description”. See the ShowMenu() example
    std::vector<std::string> names = menu_data.getNames();
    for (int i = 0; i < names.size(); i++)
    {
        action_data.getOS() << names[i] << ") " << menu_data.getDescription(names[i]) << std::endl;
    }
}

void takeAction(const std::string &choice, MenuData &menu_data, ActionData &action_data)
{
    if (menu_data.getFunction(choice) != 0)
    {
        menu_data.getFunction(choice)(action_data);
    }
    else if (choice == "menu")
    {
        showMenu(menu_data, action_data);
    }
    else
    {
        std::cout << "Unknown action '" << choice << "'." << std::endl;
    }
}

void configureMenu(MenuData &menu_data)
{
    menu_data.addAction("draw-ascii", drawAsciiImage, "Write output image to terminal as ASCII art.");
    menu_data.addAction("write", writeUserImage, "Write output image to file.");
    menu_data.addAction("copy", copyImage, "Copy input image 1 to output image.");
    menu_data.addAction("read1", readUserImage1, "Read file into input image 1");
    menu_data.addAction("#", commentLine, "Comment to end of line.");
    menu_data.addAction("size", setSize, "Set the size of input image 1.");
    menu_data.addAction("max-color-value", setMaxColorValue, "Set the max color value of input image 1.");
    menu_data.addAction("channel", setChannel, "Set a channel value in input image 1.");
    menu_data.addAction("pixel", setPixel, "Set a pixel's 3 values in input image 1");
    menu_data.addAction("clear", clearAll, "Set all pixels to 0,0,0 in input image 1");
    menu_data.addAction("quit", quit, "Quit.");
}

int imageMenu(std::istream &is, std::ostream &os)
{
    ActionData action_data(is, os);
    MenuData menu_data;
    configureMenu(menu_data);
    showMenu(menu_data, action_data);
    while (!action_data.getDone() && action_data.getIS().good())
    {
        takeAction(getChoice(action_data), menu_data, action_data);
    }

    return 0;
}