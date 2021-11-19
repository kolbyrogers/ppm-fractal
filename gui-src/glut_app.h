#ifndef _GLUT_APP_H_
#define _GLUT_APP_H_

/*
 * These #ifdef clauses ensure that the glut library header
 * files will be found, regardless of your environment.
 * Don't change them.
 */
#ifdef _WIN32
  #include "glut.h"
#else
  #ifdef __APPLE__
    #include <GLUT/glut.h>
  #else
    #include <GL/glut.h>
  #endif
#endif

#include "GlutApp.h"

// glut_app.cpp
extern GlutApp *g_app_data; /* Application wide global data */
void initialize_app(int height, int width);

// glut_callback.cpp
void display_cb(void);
void keyboard_cb(unsigned char c, int x, int y);
void special_cb(int c, int x, int y);
void reshape_cb(int w, int h);
void mouse_cb(int mouse_button, int state, int x, int y);

// gl_draw.cpp
void DrawCircle(double x1, double y1, double radius);
void DrawRectangle(double x1, double y1, double x2, double y2);
void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
void DrawText(double x, double y, const char *string);

#endif /* _GLUT_APP_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
