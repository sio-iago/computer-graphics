//
//  main.cpp
//  cg_hw1
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

#define max_x 570
#define max_y 150


static void redraw(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0, max_x, 0, max_y);
    
    drawFredonia();
}

static void drawFredonia(void)
{
    
    glClear (GL_COLOR_BUFFER_BIT);
    
    
    // F
    glColor3f(0, 0, 0);
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2i(10, 10);
    glVertex2i(10, 140);
    glVertex2i(70, 140);
    glVertex2i(70, 120);
    glVertex2i(30, 120);
    glVertex2i(30, 100);
    glVertex2i(70, 100);
    glVertex2i(70, 80);
    glVertex2i(30, 80);
    glVertex2i(30, 10);
    
    glEnd();
    // End F
    
    
    // R
    glColor3f(0, 0, 1);
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2i(80, 10);
    glVertex2i(80, 140);
    glVertex2i(140, 140);
    glVertex2i(140, 80);
    glVertex2i(110, 80);
    glVertex2i(140, 10);
    glVertex2i(120, 10);
    glVertex2i(95, 80);
    glVertex2i(95, 10);
    
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2i(95, 130);
    glVertex2i(130, 130);
    glVertex2i(130, 100);
    glVertex2i(95, 100);
    
    glEnd();
    // End R
    
    // E
    glColor3f(0, 1, 0);
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2i(160, 10);
    glVertex2i(160, 140);
    glVertex2i(220, 140);
    glVertex2i(220, 110);
    glVertex2i(180, 110);
    glVertex2i(180, 90);
    glVertex2i(220, 90);
    glVertex2i(220, 65);
    glVertex2i(180, 65);
    glVertex2i(180, 40);
    glVertex2i(220, 40);
    glVertex2i(220, 10);
    
    glEnd();
    // End E
    
    // D
    glColor3f(0.9, 0.7, 0);
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2i(230, 10);
    glVertex2i(230, 140);
    glVertex2i(270, 140);
    glVertex2i(290, 120);
    glVertex2i(290, 40);
    glVertex2i(270, 10);
    
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2i(240, 20);
    glVertex2i(240, 130);
    glVertex2i(260, 130);
    glVertex2i(280, 110);
    glVertex2i(280, 50);
    glVertex2i(260, 20);
    
    glEnd();
    // End D
    
    // O
    glColor3f(0.9, 0.7, 1.0);
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2i(320, 10);
    glVertex2i(300, 40);
    glVertex2i(300, 110);
    glVertex2i(320, 140);
    glVertex2i(340, 140);
    glVertex2i(360, 110);
    glVertex2i(360, 40);
    glVertex2i(340, 10);
    
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2i(325, 20);
    glVertex2i(310, 40);
    glVertex2i(310, 100);
    glVertex2i(325, 120);
    glVertex2i(335, 120);
    glVertex2i(350, 100);
    glVertex2i(350, 40);
    glVertex2i(335, 20);
    
    glEnd();
    // End O
    
    // N
    glColor3f(0.9, 0.1, 0.3);
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2i(370, 10);
    glVertex2i(370, 140);
    glVertex2i(390, 140);
    glVertex2i(430, 30);
    glVertex2i(430, 140);
    glVertex2i(450, 140);
    glVertex2i(450, 10);
    glVertex2i(425, 10);
    glVertex2i(385, 120);
    glVertex2i(385, 10);
    
    glEnd();
    // End N
    
    // I
    glColor3f(0.6, 0.6, 0.6);
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2i(470, 10);
    glVertex2i(470, 140);
    glVertex2i(490, 140);
    glVertex2i(490, 10);
    
    glEnd();
    // End I
    
    // A
    glColor3f(1.0, 0.2, 0.85);
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2i(500, 10);
    glVertex2i(530, 140);
    glVertex2i(560, 10);
    glVertex2i(550, 10);
    glVertex2i(540, 50);
    glVertex2i(520, 50);
    glVertex2i(510, 10);
    
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    
    glVertex2i(520, 60);
    glVertex2i(530, 110);
    glVertex2i(540, 60);
    
    glEnd();
    // End A
    
    
    glFlush();
    
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    
    glutInitWindowSize( max_x, max_y );
    glutCreateWindow("Fredonia");
    
    glutDisplayFunc(redraw);
    
    glMatrixMode(GL_PROJECTION);
    
    gluPerspective(0, 1.0, 10.0, 200.0);
    
    glutMainLoop();
    
    return 0;
}
