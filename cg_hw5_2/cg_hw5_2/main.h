//
//  main.h
//  cg_hw5_2
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

/* Angle definitions */
#define PI 3.141527

/*  Create checkerboard texture  */
#define checkImageWidth 64
#define checkImageHeight 64
static GLubyte checkImageRed[checkImageHeight][checkImageWidth][4];
static GLubyte checkImageBlue[checkImageHeight][checkImageWidth][4];
static GLubyte checkImageGreen[checkImageHeight][checkImageWidth][4];

static GLuint texRedName;
static GLuint texBlueName;
static GLuint texGreenName;

void makeCheckImageRed(void);
void makeCheckImageBlue(void);
void makeCheckImageGreen(void);

/* OpenGL Functions */
void init(void);
void display(void);
void reshape(int w, int h);
void keyboard (unsigned char key, int x, int y);

void drawCheckboard(void);
void drawScene(void);


#endif /* main_h */
