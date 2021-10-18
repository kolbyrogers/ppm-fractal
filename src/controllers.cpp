#include "Image.h"
#include "PPM.h"
#include "image_menu.h"
#include <iostream>
#include <map>
#include <string>

int assignment1(std::istream &is, std::ostream &os) {
  ActionData action_data(is, os);
  return askQuestions3(action_data);
}
int assignment2(std::istream &is, std::ostream &os) {
  ActionData action_data(is, os);
  diagonalQuadPattern(action_data);
  copyImage(action_data);
  drawAsciiImage(action_data);

  return 0;
}
int assignment3(std::istream &is, std::ostream &os) {
  ActionData action_data(is, os);
  stripedDiagonalPattern(action_data);
  copyImage(action_data);
  writeUserImage(action_data);

  return 0;
}
int inquisitor(ActionData &action_data) {
  return askInquisitorQuestions(action_data);
}
int simple_squares_ascii(std::istream &is, std::ostream &os) {
  ActionData action_data(is, os);
  simpleSquaresPattern(action_data);
  copyImage(action_data);
  drawAsciiImage(action_data);

  return 0;
}
void showMenu(MenuData &menu_data, ActionData &action_data) {
  std::vector<std::string> names = menu_data.getNames();
  for (std::vector<std::string>::iterator it = names.begin(); it != names.end();
       ++it) {
    action_data.getOS() << *it << ") " << menu_data.getDescription(*it)
                        << std::endl;
  }
}
void takeAction(const std::string &choice, MenuData &menu_data,
                ActionData &action_data) {
  if (menu_data.getFunction(choice) != 0) {
    menu_data.getFunction(choice)(action_data);
  } else if (choice == "menu") {
    showMenu(menu_data, action_data);
  } else {
    action_data.getOS() << "Unknown action '" << choice << "'." << std::endl;
  }
}
void configureMenu(MenuData &menu_data) {
  menu_data.addAction("draw-ascii", drawAsciiImage,
                      "Write output image to terminal as ASCII art.");
  menu_data.addAction("write", writeUserImage, "Write output image to file.");
  menu_data.addAction("copy", copyImage, "Copy input image 1 to output image.");
  menu_data.addAction("read1", readUserImage1, "Read file into input image 1.");
  menu_data.addAction("#", commentLine, "Comment to end of line.");
  menu_data.addAction("size", setSize, "Set the size of input image 1.");
  menu_data.addAction("max-color-value", setMaxColorValue,
                      "Set the max color value of input image 1.");
  menu_data.addAction("channel", setChannel,
                      "Set a channel value in input image 1.");
  menu_data.addAction("pixel", setPixel,
                      "Set a pixel's 3 values in input image 1.");
  menu_data.addAction("clear", clearAll,
                      "Set all pixels to 0,0,0 in input image 1.");
  menu_data.addAction("quit", quit, "Quit.");
  menu_data.addAction("read2", readUserImage2, "Read file into input image 2.");
  menu_data.addAction(
      "+", plus,
      "Set output image from sum of input image 1 and input image 2.");
  menu_data.addAction("+=", plusEquals,
                      "Set input image 1 by adding in input image 2.");
  menu_data.addAction(
      "-", minus,
      "Set output image from difference of input image 1 and input image 2.");
  menu_data.addAction("-=", minusEquals,
                      "Set input image 1 by subtracting input image 2.");
  menu_data.addAction(
      "*", times,
      "Set output image from input image 1 multiplied by a number.");
  menu_data.addAction("*=", timesEquals,
                      "Set input image 1 by multiplying by a number.");
  menu_data.addAction(
      "/", divide, "Set output image from input image 1 divided by a number.");
  menu_data.addAction("/=", divideEquals,
                      "Set input image 1 by dividing by a number.");
  menu_data.addAction(
      "red-gray", grayFromRed,
      "Set output image by grayscale from red on input image 1.");
  menu_data.addAction(
      "green-gray", grayFromGreen,
      "Set output image by grayscale from green on input image 1.");
  menu_data.addAction(
      "blue-gray", grayFromBlue,
      "Set output image by grayscale from blue on input image 1.");
  menu_data.addAction(
      "linear-gray", grayFromLinearColorimetric,
      "Set output image by linear colorimetric grayscale on input image 1.");
  menu_data.addAction("circle", drawCircle,
                      "Draw a circle shape in input image 1.");
  menu_data.addAction("box", drawBox, "Draw a box shape in input image 1.");
  menu_data.addAction("orange", orangeFilter,
                      "Set output image from orange filter on input image 1.");
  menu_data.addAction("square", drawSquare,
                      "Draw a square shape in input image 1.");
  menu_data.addAction("grid", configureGrid, "Configure the grid.");
  menu_data.addAction("grid-set", setGrid, "Set a single value in the grid.");
  menu_data.addAction("grid-apply", applyGrid,
                      "Use the grid values to set colors in the output image.");
}
int imageMenu(std::istream &is, std::ostream &os) {
  ActionData action_data(is, os);
  action_data.setGrid(new NumberGrid);
  MenuData menu_data;
  configureMenu(menu_data);
  while (!action_data.getDone() && action_data.getIS().good()) {
    takeAction(getChoice(action_data), menu_data, action_data);
  }
  return 0;
}
