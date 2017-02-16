//
//  main.cpp
//  cg_hw5_2
//
//  Created by Silva IO on 11/10/15.
//  Copyright © 2015 Silva IO. All rights reserved.
//
#include "main.h"

#include <stdio.h>
#include <stdlib.h>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif



/*  Create checkerboard texture  */
void makeCheckImageRed(void)
{
    int i, j, c;
    
    for (i = 0; i < checkImageHeight; i++) {
        for (j = 0; j < checkImageWidth; j++) {
            c = ((((i&0x8)==0)^((j&0x8))==0))*255;
            checkImageRed[i][j][0] = (GLubyte) 120 | c;
            checkImageRed[i][j][1] = (GLubyte) c;
            checkImageRed[i][j][2] = (GLubyte) c;
            checkImageRed[i][j][3] = (GLubyte) 255;
        }
    }
}

void makeCheckImageBlue(void)
{
    int i, j, c;
    
    for (i = 0; i < checkImageHeight; i++) {
        for (j = 0; j < checkImageWidth; j++) {
            c = ((((i&0x8)==0)^((j&0x8))==0))*255;
            checkImageBlue[i][j][0] = (GLubyte) c;
            checkImageBlue[i][j][1] = (GLubyte) c;
            checkImageBlue[i][j][2] = (GLubyte) 120 | c;
            checkImageBlue[i][j][3] = (GLubyte) 255;
        }
    }
}

void makeCheckImageGreen(void)
{
    int i, j, c;
    
    for (i = 0; i < checkImageHeight; i++) {
        for (j = 0; j < checkImageWidth; j++) {
            c = ((((i&0x8)==0)^((j&0x8))==0))*255;
            checkImageGreen[i][j][0] = (GLubyte) c;
            checkImageGreen[i][j][1] = (GLubyte) 120 | c;
            checkImageGreen[i][j][2] = (GLubyte) c;
            checkImageGreen[i][j][3] = (GLubyte) 255;
        }
    }
}



void drawCheckboard(void)
{
    glBegin(GL_QUADS);
    
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
    
    glEnd();
}

void drawScene(void)
{
    // Smaller One
    glBindTexture(GL_TEXTURE_2D, texGreenName);
    
    glLoadIdentity();
    glPushMatrix();
    
    glTranslatef(0.0f, 0.002f, -6.0f);
    glPushMatrix(); // Translate
    
    glRotatef(-25.0f, 1.0f, 0.0f, 0.0f);
    glPushMatrix(); // Rotate
    
    glScalef(1.0f, 1.0f, 1.0f);
    glPushMatrix(); // Scale
    
    drawCheckboard();
    
    glPopMatrix(); // Scale
    glPopMatrix(); // Rotate
    glPopMatrix(); // Translate
    glPopMatrix(); // Identity
    
    
    // Middle One
    glBindTexture(GL_TEXTURE_2D, texBlueName);
    
    glLoadIdentity();
    glPushMatrix();
    
    glTranslatef(0.0f, 0.001f, -6.0f);
    glPushMatrix(); // Translate
    
    glRotatef(-25.0f, 1.0f, 0.0f, 0.0f);
    glPushMatrix(); // Rotate
    
    glScalef(2.0f, 1.0f, 1.0f);
    glPushMatrix(); // Scale
    
    drawCheckboard();
    
    glPopMatrix(); // Scale
    glPopMatrix(); // Rotate
    glPopMatrix(); // Translate
    glPopMatrix(); // Identity
    
    
    // Bigger One
    glBindTexture(GL_TEXTURE_2D, texRedName);
    
    glLoadIdentity();
    glPushMatrix();
    
    glTranslatef(0.0f, 0.0f, -6.0f);
    glPushMatrix(); // Translate
    
    glRotatef(-25.0f, 1.0f, 0.0f, 0.0f);
    glPushMatrix(); // Rotate
    
    glScalef(3.0f, 1.0f, 1.0f);
    glPushMatrix(); // Scale
    
    drawCheckboard();
    
    glPopMatrix(); // Scale
    glPopMatrix(); // Rotate
    glPopMatrix(); // Translate
    glPopMatrix(); // Identity
}

void drawSceneTopDown(void)
{
    // Bigger One
    glBindTexture(GL_TEXTURE_2D, texRedName);
    
    glLoadIdentity();
    glPushMatrix();
    
    glTranslatef(0.0f, -1.0f, -6.0f);
    glPushMatrix(); // Translate
    
    glRotatef(-50.0f, 1.0f, 0.0f, 0.0f);
    glPushMatrix(); // Rotate
    
    glScalef(3.0f, 1.0f, 1.0f);
    glPushMatrix(); // Scale
    
    drawCheckboard();
    
    glPopMatrix(); // Scale
    glPopMatrix(); // Rotate
    glPopMatrix(); // Translate
    glPopMatrix(); // Identity
    
    
    // Middle One
    glBindTexture(GL_TEXTURE_2D, texBlueName);
    
    glLoadIdentity();
    glPushMatrix();
    
    glTranslatef(0.0f, 0.0f, -6.0f);
    glPushMatrix(); // Translate
    
    glRotatef(-50.0f, 1.0f, 0.0f, 0.0f);
    glPushMatrix(); // Rotate
    
    glScalef(2.0f, 1.0f, 1.0f);
    glPushMatrix(); // Scale
    
    drawCheckboard();
    
    glPopMatrix(); // Scale
    glPopMatrix(); // Rotate
    glPopMatrix(); // Translate
    glPopMatrix(); // Identity
    
    
    // Smaller One
    glBindTexture(GL_TEXTURE_2D, texGreenName);
    
    glLoadIdentity();
    glPushMatrix();
    
    glTranslatef(0.0f, 1.0f, -6.0f);
    glPushMatrix(); // Translate
    
    glRotatef(-50.0f, 1.0f, 0.0f, 0.0f);
    glPushMatrix(); // Rotate
    
    glScalef(1.0f, 1.0f, 1.0f);
    glPushMatrix(); // Scale
    
    drawCheckboard();
    
    glPopMatrix(); // Scale
    glPopMatrix(); // Rotate
    glPopMatrix(); // Translate
    glPopMatrix(); // Identity
    
}

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    makeCheckImageRed();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    
    // Red checkboard
    glGenTextures(1, &texRedName);
    glBindTexture(GL_TEXTURE_2D, texRedName);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                    GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                 checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 checkImageRed);
    
    // Blue checkboard
    makeCheckImageBlue();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    
    glGenTextures(1, &texBlueName);
    glBindTexture(GL_TEXTURE_2D, texBlueName);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                    GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                 checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 checkImageBlue);
    
    // Green checkboard
    makeCheckImageGreen();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    
    glGenTextures(1, &texGreenName);
    glBindTexture(GL_TEXTURE_2D, texGreenName);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                    GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                 checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 checkImageGreen);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    
    drawSceneTopDown();
    //drawScene();
    
    glFlush();
    glDisable(GL_TEXTURE_2D);
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.6);
}

void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Homework 5.2");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0; 
}