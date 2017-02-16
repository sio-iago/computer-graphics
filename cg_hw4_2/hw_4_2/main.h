//
//  main.h
//  hw_4_2
//
//  Created by Silva IO on 10/29/15.
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

void init(void);
void display(void);
void drawSphere(void);
void spotlight(void);

#endif /* main_h */
