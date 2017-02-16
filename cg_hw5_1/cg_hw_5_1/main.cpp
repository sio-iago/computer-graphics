//
//  main.cpp
//  cg_hw_5_1
//
//  Created by Silva IO on 11/10/15.
//  Copyright © 2015 Silva IO. All rights reserved.
//

#include "main.h"

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif


void init(void) {
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    glMatrixMode (GL_MODELVIEW);
    gluLookAt (x0, y0, z0, xref, yref, zref, Vx, Vy, Vz);
    
    glMatrixMode (GL_PROJECTION);
    glFrustum (xwMin, xwMax, ywMin, ywMax, dnear, dfar);
    
}

void drawCube(void)
{
    glPolygonMode (GL_FRONT, GL_FILL);
    glPolygonMode (GL_BACK, GL_LINE);
    
    glBegin(GL_QUADS);
    
    // Bottom face
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex3f(50.0f, 0.0f,  50.0f);
    glVertex3f(0.0f, 0.0f,  50.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0f, 0.0f, 0.0f);

    // Back face
    glColor3f(0.12f, 1.0f, 0.0f);
    glVertex3f(50.0f, 50.0f, 50.0f);
    glVertex3f(0.0f, 50.0f, 50.0f);
    glVertex3f(0.0f,  50.0f, 50.0f);
    glVertex3f(50.0f,  50.0f, 0.0f);

    // Right Face
    glColor3f(0.7f, 0.67f, 0.0f);
    glVertex3f(50.0f,  50.0f, 0.0f);
    glVertex3f(50.0f,  50.0f,  50.0f);
    glVertex3f(50.0f, 0.0f,  50.0f);
    glVertex3f(50.0f, 0.0f, 0.0f);

    // Left Face
    glColor3f(0.85f, 0.12f, 0.36f);
    glVertex3f(0.0f,  50.0f,  50.0f);
    glVertex3f(0.0f,  50.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f,  50.0f);

    
    // Top Face
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(50.0f, 50.0f, 0.0f);
    glVertex3f(0.0f, 50.0f, 0.0f);
    glVertex3f(0.0f, 50.0f,  50.0f);
    glVertex3f(50.0f, 50.0f,  50.0f);

    // Front face
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(50.0f,  50.0f, 50.0f);
    glVertex3f(0.0f,  50.0f, 50.0f);
    glVertex3f(0.0f, 0.0f, 50.0f);
    glVertex3f(50.0f, 0.0f, 50.0f);
    
    glEnd();
}




void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode (GL_MODELVIEW);
    
    glPushMatrix();
    glTranslatef(30.0f, -40.0f, -90.0f);
    glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
    drawCube();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-90.0f, -40.0f, 30.0f);
    glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
    drawCube();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-320.0f, 300.0f, -250.0f);
    drawCube();
    glPopMatrix();
    
    glFlush();
}


void reshape(GLsizei w, GLsizei h)
{
    glViewport (0, 0, w, h);
    
    winWidth = w;
    winHeight = h;
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Homework 5.1");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    init();

    glutMainLoop();
    return 0;
}
