#include <iostream>
#include <fstream>
#include <ios>
#include "image_menu.h"

void drawAsciiImage(ActionData &action_data)
{
    int height = action_data.getInputImage1().getHeight();
    int width = action_data.getInputImage1().getWidth();
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int r = action_data.getInputImage1().getChannel(row, column, 0);
            int g = action_data.getInputImage1().getChannel(row, column, 1);
            int b = action_data.getInputImage1().getChannel(row, column, 2);
            double strength = (r + g + b) / 765.0;
            if (strength >= 1.0)
            {
                action_data.getOS() << "@";
            }
            else if (strength >= 0.9)
            {
                action_data.getOS() << "#";
            }
            else if (strength >= 0.8)
            {
                action_data.getOS() << "%";
            }
            else if (strength >= 0.7)
            {
                action_data.getOS() << "*";
            }
            else if (strength >= 0.6)
            {
                action_data.getOS() << "|";
            }
            else if (strength >= 0.5)
            {
                action_data.getOS() << "+";
            }
            else if (strength >= 0.4)
            {
                action_data.getOS() << ";";
            }
            else if (strength >= 0.3)
            {
                action_data.getOS() << "~";
            }
            else if (strength >= 0.2)
            {
                action_data.getOS() << "-";
            }
            else if (strength >= 0.1)
            {
                action_data.getOS() << ".";
            }
            else if (strength >= 0.0)
            {
                action_data.getOS() << " ";
            }
            // >= 1.0 -> @, >= 0.9 -> #, >= 0.8 -> %, >= 0.7 -> *, >= 0.6 -> |,
            // >= 0.5 -> +, >= 0.4 -> ;, >= 0.3 -> ~, >= 0.2 -> -, >= 0.1 -> ., >= 0.0 -> Space
        }
        action_data.getOS() << std::endl;
    }
}

void writeUserImage(ActionData &action_data)
{
    std::string filename;
    filename = getString(action_data, "Output filename? ");
    std::ofstream file(filename, std::ios::binary); // opens the output file in binary mode
    action_data.getInputImage1().writeStream(file); // writes the PPM object to the file’s stream (using writeStream)
    file.close();                                   // closes the file stream
}

void copyImage(ActionData &action_data)
{
    action_data.getOutputImage() = action_data.getInputImage1();
}

void readUserImage1(ActionData &action_data)
{
    std::string filename = getString(action_data, "Input filename? ");
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << filename << " could not be opened." << std::endl;
    }
    else
    {
        action_data.getInputImage1().readStream(file);
        file.close();
    }
}