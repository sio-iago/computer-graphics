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

#define scale 40.0

#define abs_x 30
#define abs_y 14

#define max_x scale*abs_x
#define max_y scale*abs_y


#include <iostream>


// Default values
GLfloat borderColor[] = { 0.0, 0.0, 0.0 };


// Zoom variables
int zoomTimes = 0;
GLfloat scalePercent = 0.1;


// Translation variables
int translationTimes = 0;
GLfloat translationAmount = 10.0;

static void redraw(void){
    
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluOrtho2D( 0, max_x, 0, max_y);
    
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glPushMatrix();
    
    
    // Draws the Table
    drawTable();

    /*  
        Draws the books
        FredID: F03040527
        Last five: 4 0 5 2 7
        Transposed: 4 1 5 2 7
    */
    
    std::string stack1[4] = {
        "Java Principles",
        "Python",
        "Java For Dummies",
        "C/C++ Basics"
    };
    
    std::string stack2[1] = {
        "Human Body Guide"
    };
    
    std::string stack3[5] = {
        "Macroeconomics",
        "Microeconomics",
        "Accounting",
        "Financial Business",
        "E-Commerce"
    };
    
    std::string stack4[2] = {
        "Physics I",
        "Chimestry IV"
    };
    
    std::string stack5[7] = {
        "Harry Potter",
        "Percy Jackson",
        "Hunger Games",
        "Paper Towns",
        "Alice",
        "7 Habbits",
        "OpenGL Guide"
    };
    
    drawBook(4, stack1, 0);
    drawBook(1, stack2, 1);
    drawBook(5, stack3, 2);
    drawBook(2, stack4, 3);
    drawBook(7, stack5, 4);
    
    glPopMatrix();
    
    glutSwapBuffers();
}

static void drawTable(void){
    
    GLfloat tableColor[] = { 0.6, 0.4, 0.12 };
    
    GLint leftFoot[4][2] = {
        {8,0} , {8,5} , {9,5} , {9,0}
    };
    
    GLint rightFoot[4][2] = {
        {20,0} , {20,5} , {21,5} , {21,0}
    };
    
    GLint tableTop[4][2] = {
        {2,5} , {2,6} , {28,6} , {28,5}
    };
    
    glClear (GL_COLOR_BUFFER_BIT);
    
    
    
    // Draws the left foot
    glColor3fv(tableColor);
    glBegin(GL_POLYGON);
    
    for(int i=0; i<4; i++)
    {
        glVertex2i(leftFoot[i][0]*scale , leftFoot[i][1]*scale);
    }
    
    glEnd();
    
    glColor3fv(borderColor);
    glBegin(GL_LINE_LOOP);
    
    for(int i=0; i<4; i++)
    {
        glVertex2i(leftFoot[i][0]*scale , leftFoot[i][1]*scale);
    }

    glEnd();
    
    // Draws the right foot
    glColor3fv(tableColor);
    glBegin(GL_POLYGON);
    
    for(int i=0; i<4; i++)
    {
        glVertex2i(rightFoot[i][0]*scale , rightFoot[i][1]*scale);
    }
    
    glEnd();

    glColor3fv(borderColor);
    glBegin(GL_LINE_LOOP);
    
    for(int i=0; i<4; i++)
    {
        glVertex2i(rightFoot[i][0]*scale , rightFoot[i][1]*scale);
    }
    
    glEnd();
    
    // Draws the table top
    glColor3fv(tableColor);
    glBegin(GL_POLYGON);
    
    for(int i=0; i<4; i++)
    {
        glVertex2i(tableTop[i][0]*scale , tableTop[i][1]*scale);
    }
    
    glEnd();
    
    glColor3fv(borderColor);
    glBegin(GL_LINE_LOOP);
    
    for(int i=0; i<4; i++)
    {
        glVertex2i(tableTop[i][0]*scale , tableTop[i][1]*scale);
    }
    
    glEnd();
    
}


static void drawBook(int frednumber, std::string *names, int stackPosition){
    
    GLfloat booksize = 4.0f;
    
    GLfloat bookColors[5][3] = {
        {0.95,0.8,0.8},
        {0.8,0.95,0.8},
        {1.0,1.0,1.0},
        {0.8,0.8,0.95},
        {0.6,0.7,0.98}
    };
    
    GLfloat bookStackCoordinates[4][2] = {
        {4.0f , 6.0f},
        {4.0f , 7.0f},
        {4.0f + booksize , 7.0f},
        {4.0f + booksize , 6.0f}
    };
    
    // Draws the book
    for(int j=0; j<frednumber; j++)
    {
        glColor3fv(bookColors[j%5]);
     
        
        glPushMatrix();
        
        if(j == frednumber-1 && stackPosition == 0 && translationTimes > 0)
        {
            glTranslatef(translationTimes*translationAmount, 0.0, 0.0);
        }
        
        glBegin(GL_POLYGON);
        
        GLfloat scaledBook = 1.0;
        
        if(j == frednumber-1 && stackPosition == 0 && zoomTimes > 0)
        {
            scaledBook = 1.0f + (scalePercent * (float)zoomTimes);
        }
        
        glVertex2f(
                   (bookStackCoordinates[0][0]+1.0+(booksize*stackPosition))*scale ,
                   (bookStackCoordinates[0][1]+j)*scale
                   );
        
        glVertex2f(
                   (bookStackCoordinates[1][0]+1+(booksize*stackPosition))*scale ,
                   ((bookStackCoordinates[1][1]+j*scaledBook)*scale)
                   );
        
        glVertex2f(
                   (bookStackCoordinates[2][0]*scaledBook+1+(booksize*stackPosition))*scale ,
                   (bookStackCoordinates[2][1]+j*scaledBook)*scale
                   );
        
        glVertex2f(
                   (bookStackCoordinates[3][0]*scaledBook+1+(booksize*stackPosition))*scale ,
                   (bookStackCoordinates[3][1]+j)*scale
                   );
        
        glEnd();
        
        glPopMatrix();
    }
    
    
    glColor3fv(borderColor);
    
    
    
    for(int j=0; j<frednumber; j++)
    {
        glPushMatrix();
        
        if(j == frednumber-1 && stackPosition == 0 && translationTimes > 0)
        {
            glTranslatef(translationTimes*translationAmount, 0.0, 0.0);
        }
        
        glBegin(GL_LINE_LOOP);
        
        GLfloat scaledBook = 1.0;
        
        if(j == frednumber-1 && stackPosition == 0 && zoomTimes > 0)
        {
            scaledBook = 1.0f + (scalePercent * (float)zoomTimes);
        }
        
        glVertex2f(
                   (bookStackCoordinates[0][0]+1.0+(booksize*stackPosition))*scale ,
                   (bookStackCoordinates[0][1]+j)*scale
                   );
        
        glVertex2f(
                   (bookStackCoordinates[1][0]+1+(booksize*stackPosition))*scale ,
                   ((bookStackCoordinates[1][1]+j*scaledBook)*scale)
                   );
        
        glVertex2f(
                   (bookStackCoordinates[2][0]*scaledBook+1+(booksize*stackPosition))*scale ,
                   (bookStackCoordinates[2][1]+j*scaledBook)*scale
                   );
        
        glVertex2f(
                   (bookStackCoordinates[3][0]*scaledBook+1+(booksize*stackPosition))*scale ,
                   (bookStackCoordinates[3][1]+j)*scale
                   );
        
        glEnd();
        
        glPopMatrix();
        
    }
    
    
    // Draws the text
    
    for(int j=0; j<frednumber; j++)
    {
        
        glPushMatrix();
        
        if(j == frednumber-1 && stackPosition == 0 && translationTimes > 0)
        {
            glTranslatef(translationTimes*translationAmount, 0.0, 0.0);
        }
        
        GLfloat scaledBook = 2.0f;
        
        if(j == frednumber-1 && stackPosition == 0 && zoomTimes > 0)
        {
            scaledBook = 2.0f + (scalePercent * (float)zoomTimes);
        }
        
        // Gets the size and convert to char*
        unsigned long nameSize = names[j].size()+1;
        char nameToWrite[nameSize];
        
        std::string name = names[j];
        
        // Copies the chars from string to char*
        strcpy(nameToWrite, name.c_str());
        
        // Coordinates Orientation
        GLfloat xRaster = (4.2f+1.0f+stackPosition*booksize) * scale;
        GLfloat yRaster = (6.5f+j*(scaledBook/2.0f)) * scale;
        
        glColor3f(0, 0, 0);
        
        for (GLint i=0; i<nameSize; i++)
        {
            glRasterPos2f(xRaster, yRaster);
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, nameToWrite[i]);
            
            xRaster += 8.0f*(scaledBook/2.0f);
        }
        
        glPopMatrix();
        
    }
    
    
}



static void idle(void) {
    
}

static void keyboardInput(unsigned char key, int x, int y)
{
    if(key == 'z' || key == 'Z')
    {
        zoomTimes++;
    }
    
    if(key == 't' || key == 'T')
    {
        translationTimes++;
    }
    
    glutPostRedisplay();
}


int main(int argc, char * argv[])
{
    // Init GLUT
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    
    glutInitWindowSize( max_x, max_y );
    glutCreateWindow("Homework 4");
    
    // Draws the scene
    glutDisplayFunc(redraw);
    glutKeyboardFunc(keyboardInput);
    glutIdleFunc(idle);
    
    // Projection type
    glMatrixMode(GL_PROJECTION);
    gluPerspective(0, 1.0, 10.0, 200.0);
    
    // Starts GLUT
    glutMainLoop();
    
    return 0;
}
