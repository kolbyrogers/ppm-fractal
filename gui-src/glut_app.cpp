#include "glut_app.h"

/*
 * Application wide global data
 */
GlutApp *g_app_data = 0;
void initialize_app(int height, int width) {
  g_app_data = new GlutApp(height, width);
}
