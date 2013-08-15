#include <stdio.h>
#include <stdlib.h>
#include "GL/glut.h"

#define H 300
#define W H
#define ESC 0x1B

int r = 1, g = 1, b = 1, mousex, mousey, mousexx, mouseyy, draw;

void init (void) {
  glClearColor (0, 0, 0, 0);
  glClear (GL_COLOR_BUFFER_BIT);
}

void display (void) {
  if (draw) glBegin (GL_LINE_STRIP);
    glColor3f (r, g, b);
    glVertex2f (mousexx, mouseyy); glVertex2f (mousex, mousey); 
  glEnd ();
  printf ("displayed %d %d\n", mousex, mousey);
  glFlush ();
}

void reshape (int w, int h) {
  glViewport (0, 0, w, h);
  glLoadIdentity ();
  glOrtho (0, w, 0, h, -1, 1);
}

void trackmouse (int x, int y) {
  int vp[4]; glGetIntegerv (GL_VIEWPORT, vp);
  mousexx = mousex, mouseyy = mousey;
  mousex = x; mousey = vp[3] -y;
  glutPostRedisplay ();
}

void mouse (int button, int state, int x, int y) {
  int vp[4]; glGetIntegerv (GL_VIEWPORT, vp); y = vp[3] - y;
  printf ("mouse %d %d %d %d\n", button, state, x, y);
  if (draw = state == GLUT_DOWN, draw) {
    mousexx = mousex = x;
    mouseyy = mousey = y;
  }
}

void keyboard (unsigned char key, int x, int y) {
  (void) x; (void) y;
  if (key == ESC) exit (EXIT_SUCCESS);
  if (key == '$') glClear (GL_COLOR_BUFFER_BIT), glutPostRedisplay ();
  if (key == '{') r ^= 1;
  if (key == '}') g ^= 1;
  if (key == '(') b ^= 1;
  if (key == '=') r = g = b = 0;
}

int main (int argc, char **argv) {
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (W, H);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc (display);
  glutReshapeFunc (reshape);
  glutMouseFunc (mouse);
  glutKeyboardFunc (keyboard);
  glutMotionFunc (trackmouse);
  glutMainLoop ();
  exit (EXIT_FAILURE);
}
