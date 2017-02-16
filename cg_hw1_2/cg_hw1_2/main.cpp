//
//  main.cpp
//  cg_hw2
//
//  Created by Silva IO on 9/6/15.
//  Copyright (c) 2015 Silva IO. All rights reserved.
//

#include "main.h"

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#include <iostream>
#include <string.h>

#define max_x 200
#define max_y 30

using namespace std;

static void redraw(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0, max_x, 0, max_y);
    
    string name = "Iago Oliveira da Silva";
    
    char nameToWrite[name.size()+1];
    
    strcpy(nameToWrite, name.c_str());
    
    writeMyName(nameToWrite);
}

static void writeMyName(char *name)
{
    glClear (GL_COLOR_BUFFER_BIT);
    
    GLint size = (int) strlen(name);
    GLint xRaster, yRaster;

    // My Name
    glColor3f(0, 0, 0);
    
    xRaster = 10;
    yRaster = 10;
    
    
    for (GLint i=0; i<size; i++)
    {
        glRasterPos2i(xRaster, yRaster);
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, name[i]);
        
        xRaster += 8;
    }
    
    glFlush();
    
}


int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    
    glutInitWindowSize( max_x, max_y );
    glutCreateWindow("Full Name");
    
    glutDisplayFunc(redraw);
    
    glMatrixMode(GL_PROJECTION);
    
    glutMainLoop();

    
    return 0;
}
