#include "glut_app.h"

int main(int argc, char **argv)
{
  int height = 500;
  int width = 700;
  initialize_app(height, width);

  // all glut*() functions are part of the glut library, not our code.
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(g_app_data->getWidth(), g_app_data->getHeight());
  glutInitWindowPosition(50, 50);

  glutCreateWindow("Shapes");

  // register event handlers
  glutDisplayFunc(display_cb);
  glutKeyboardFunc(keyboard_cb);
  glutSpecialFunc(special_cb);
  glutReshapeFunc(reshape_cb);
  glutMouseFunc(mouse_cb);

  glColor3d(0,0,0);         // forground color
  glClearColor(1, 1, 1, 0); // background color

  glutMainLoop();
  return 0;
}
