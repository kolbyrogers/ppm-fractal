#include "glut_app.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display_cb(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  g_app_data->display();
  glutSwapBuffers();
}

// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard_cb(unsigned char c, int x, int y) {
  (void)x;
  (void)y;
  // just for demonstration purposes
  std::cout << "key: " << (int)c << std::endl;
  switch (c) {
  case 'q':
  case 27: // escape character means to quit the program
    exit(0);
    break;
  case 'J':
    g_app_data->createJulia();
    break;
  case 'j':
    g_app_data->createJulia2();
    break;
  case 'M':
    g_app_data->createMandelbrot();
    break;
  case 'm':
    g_app_data->createMandelbrot2();
    break;
  case 'C':
    g_app_data->createComplexFractal();
    break;
  case 'c':
    g_app_data->createComplexFractal2();
    break;
  default:
    return; // if we don't care, return without glutPostRedisplay()
  }

  glutPostRedisplay(); // tell glut to call display() as soon as possible.
}

void special_cb(int c, int x, int y) {
  (void)x;
  (void)y;
  // just for demonstration purposes
  std::cout << "special key: " << (int)c << std::endl;
  switch (c) {
  case GLUT_KEY_UP:
    break;
  case GLUT_KEY_DOWN:
    break;
  case GLUT_KEY_LEFT:
    break;
  case GLUT_KEY_RIGHT:
    break;
  default:
    return; // if we don't care, return without glutPostRedisplay()
  }
  glutPostRedisplay(); // tell glut to call display() as soon as possible.
}

// This callback function gets called by the Glut
// system whenever the window is resized by the user.
void reshape_cb(int w, int h) {
  // Reset our global variables to the new width and height.
  g_app_data->setSize(h, w);

  // all of the gl*() function calls below are part of the openGL
  // library, not our code.

  // Set the pixel resolution of the final picture (Screen coordinates).
  glViewport(0, 0, w, h);

  // Set the projection mode to 2D orthographic, and set the world coordinates:
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, 0, h);
  glMatrixMode(GL_MODELVIEW);
}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse_cb(int mouse_button, int state, int x, int y) {
  // translate pixel coordinates to display coordinates
  int xdisplay = x;
  int ydisplay = g_app_data->getHeight() - y;
  if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    std::cout << "Left Mouse Down. @" << xdisplay << "," << ydisplay
              << std::endl;
  }
  if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
    std::cout << "Left Mouse Up. @" << xdisplay << "," << ydisplay << std::endl;
  }
  if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
    std::cout << "Middle Mouse Down. @" << xdisplay << "," << ydisplay
              << std::endl;
  }
  if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) {
    std::cout << "Middle Mouse Up. @" << xdisplay << "," << ydisplay
              << std::endl;
  }
  glutPostRedisplay();
}
