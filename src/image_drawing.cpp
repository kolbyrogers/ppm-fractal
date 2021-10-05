#include <iostream>
#include "image_menu.h"
#include <cmath>

void diagonalQuadPattern(ActionData &action_data)
{
    int height, width;
    height = getInteger(action_data, "Image height? ");
    width = getInteger(action_data, "Image width? ");
    action_data.getInputImage1().setHeight(height);
    action_data.getInputImage1().setWidth(width);
    action_data.getInputImage1().setMaxColorValue(255);
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            // set red channel in top half to 0 and bottom half to 255
            if (row < height / 2)
            {
                action_data.getInputImage1().setChannel(row, column, 0, 0);
            }
            else if (row >= height / 2)
            {
                action_data.getInputImage1().setChannel(row, column, 0, 255);
            }
            // set blue channel in left half to 0 and right half to 255
            if (column < width / 2)
            {
                action_data.getInputImage1().setChannel(row, column, 2, 0);
            }
            else if (column >= width / 2)
            {
                action_data.getInputImage1().setChannel(row, column, 2, 255);
            }
            // set green channel based on calculation
            action_data.getInputImage1().setChannel(row, column, 1, (2 * row + 2 * column) % 256);
        }
    }
}

void stripedDiagonalPattern(ActionData &action_data)
{
    int height, width, maxCV;
    height = getInteger(action_data, "Image height? ");
    width = getInteger(action_data, "Image width? ");
    action_data.getInputImage1().setHeight(height);
    action_data.getInputImage1().setWidth(width);
    maxCV = (height + width) / 3;
    if (maxCV > 255)
    {
        maxCV = 255;
    }
    action_data.getInputImage1().setMaxColorValue(maxCV);
    for (int row = 0; row < action_data.getInputImage1().getHeight(); row++)
    {
        for (int column = 0; column < action_data.getInputImage1().getWidth(); column++)
        {
            // If a pixel is in the top half of the image, sets the red channel of the pixel to 0.
            // If a pixel is in the bottom half of the image and the row number is a multiple of 3, sets the red channel of the pixel to 0.
            // If a pixel is in the bottom half of the image, and the row number is not a multiple of 3, sets the red channel to the maximum color value.
            if (row < height / 2)
            {
                action_data.getInputImage1().setChannel(row, column, 0, 0);
            }
            else if (row >= height / 2 && (row % 3) == 0)
            {
                action_data.getInputImage1().setChannel(row, column, 0, 0);
            }
            else if (row >= height / 2 && (row % 3) != 0)
            {
                action_data.getInputImage1().setChannel(row, column, 0, action_data.getInputImage1().getMaxColorValue());
            }
            // Sets the green channel of a pixel to the remainder of (row + width - column - 1) divided by one more than the maximum color value.
            action_data.getInputImage1().setChannel(row, column, 1, (row + action_data.getInputImage1().getWidth() - column - 1) % (action_data.getInputImage1().getMaxColorValue() + 1));
            // Sets the blue channel of a pixel to 0 if the column number is less than the row. Otherwise, sets the blue channel to the maximum color value.
            if (column < row)
            {
                action_data.getInputImage1().setChannel(row, column, 2, 0);
            }
            else
            {
                action_data.getInputImage1().setChannel(row, column, 2, action_data.getInputImage1().getMaxColorValue());
            }
        }
    }
}

void simpleSquaresPattern(ActionData &action_data)
{
    int size;
    size = getInteger(action_data, "Image size? ");
    action_data.getInputImage1().setHeight(size);
    action_data.getInputImage1().setWidth(size);
    for (int row = 0; row < action_data.getInputImage1().getHeight(); row++)
    {
        for (int column = 0; column < action_data.getInputImage1().getWidth(); column++)
        {
            // set red channel in top half to 127 and bottom half to 255
            if (row < action_data.getInputImage1().getHeight() / 2)
            {
                action_data.getInputImage1().setChannel(row, column, 0, 127);
            }
            else if (row >= action_data.getInputImage1().getHeight() / 2)
            {
                action_data.getInputImage1().setChannel(row, column, 0, 255);
            }
            // set green channel in left half to 0 and right half to 255
            if (column < action_data.getInputImage1().getWidth() / 2)
            {
                action_data.getInputImage1().setChannel(row, column, 1, 0);
            }
            else if (column >= action_data.getInputImage1().getWidth() / 2)
            {
                action_data.getInputImage1().setChannel(row, column, 1, 255);
            }
            // set blue channel
            action_data.getInputImage1().setChannel(row, column, 2, 255);
        }
    }
}

void setSize(ActionData &action_data)
{
    int height, width;
    height = getInteger(action_data, "Height? ");
    width = getInteger(action_data, "Width? ");
    action_data.getInputImage1().setHeight(height);
    action_data.getInputImage1().setWidth(width);
}
void setMaxColorValue(ActionData &action_data)
{
    int max = getInteger(action_data, "Max color value? ");
    action_data.getInputImage1().setMaxColorValue(max);
}
void setChannel(ActionData &action_data)
{
    int row, column, channel, value;
    row = getInteger(action_data, "Row? ");
    column = getInteger(action_data, "Column? ");
    channel = getInteger(action_data, "Channel? ");
    value = getInteger(action_data, "Value? ");
    action_data.getInputImage1().setChannel(row, column, channel, value);
}
void setPixel(ActionData &action_data)
{
    int row, column, red, green, blue;
    row = getInteger(action_data, "Row? ");
    column = getInteger(action_data, "Column? ");
    red = getInteger(action_data, "Red? ");
    green = getInteger(action_data, "Green? ");
    blue = getInteger(action_data, "Blue? ");
    action_data.getInputImage1().setPixel(row, column, red, green, blue);
}
void clearAll(ActionData &action_data)
{
    for (int row = 0; row < action_data.getInputImage1().getHeight(); row++)
    {
        for (int column = 0; column < action_data.getInputImage1().getWidth(); column++)
        {
            action_data.getInputImage1().setPixel(row, column, 0, 0, 0);
        }
    }
}

void drawCircle(ActionData &action_data)
{
    int centerRow = getInteger(action_data, "Center Row? ");
    int centerCol = getInteger(action_data, "Center Column? ");
    int radius = getInteger(action_data, "Radius? ");
    int red = getInteger(action_data, "Red? ");
    int green = getInteger(action_data, "Green? ");
    int blue = getInteger(action_data, "Blue ");
    for (int row = 0; row < action_data.getInputImage1().getHeight(); row++)
    {
        for (int col = 0; col < action_data.getInputImage1().getWidth(); col++)
        {
            int rowDif = row - centerRow;
            int colDif = col - centerCol;
            double distance = std::sqrt((rowDif * rowDif) + (colDif * colDif));
            if (distance <= radius)
            {
                action_data.getInputImage1().setPixel(row, col, red, green, blue);
            }
        }
    }
}
void drawBox(ActionData &action_data)
{
    int tRow = getInteger(action_data, "Top Row? ");
    int lCol = getInteger(action_data, "Left Column? ");
    int bRow = getInteger(action_data, "Bottom Row? ");
    int rCol = getInteger(action_data, "Right Column? ");
    int red = getInteger(action_data, "Red? ");
    int green = getInteger(action_data, "Green? ");
    int blue = getInteger(action_data, "Blue ");
    for (int row = tRow; row < bRow; row++)
    {
        for (int col = lCol; col < rCol; col++)
        {
            action_data.getInputImage1().setPixel(row, col, red, green, blue);
        }
    }
}