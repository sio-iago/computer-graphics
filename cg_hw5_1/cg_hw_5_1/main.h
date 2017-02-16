//
//  main.h
//  cg_hw_5_1
//
//  Created by Silva IO on 11/10/15.
//  Copyright © 2015 Silva IO. All rights reserved.
//

#ifndef main_h
#define main_h

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define PI 3.1415926535



/* Globals */
GLint winWidth = 600, winHeight = 600;   //  Initial display-window size.

GLfloat x0 = 100.0, y0 = 50.0, z0 = 50;  //  Viewing-coordinate origin.
GLfloat xref = 50.0, yref = 50.0, zref = 0.0;  //  Look-at point.
GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0;          //  View up vector.

/*  Set coordinate limits for the clipping window:  */
GLfloat xwMin = -40.0, ywMin = -60.0, xwMax = 40.0, ywMax = 60.0;

/*  Set positions for near and far clipping planes:  */
GLfloat dnear = 25.0, dfar = 500.0;

/* OpenGL Functions */
void init(void);
void display(void);
void reshape(GLsizei w, GLsizei h);

void drawCube(void);


#endif /* main_h */
