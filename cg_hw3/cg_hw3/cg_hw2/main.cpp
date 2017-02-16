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

#define margin_x 60
#define margin_y 40

#define max_x 900
#define max_y 600

#define graph_y_max 5


#include <iostream>
#include <cmath>


// Default values
GLfloat borderColor[] = { 0.0, 0.0, 0.0 };

static double lineWidth = 0.0;

static void redraw(void){
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0, max_x, 0, max_y);
    
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    
    drawMainGraphLines(10, 500, 10, 100);
    
    drawLines(lineWidth);
    
    glFlush();
}


static void drawXAxisLabels(int y, int x_inputs)
{
    glColor3f(0.0, 0.0, 0.0);
    
    // To scale the output we have to make sure
    // the draw will follow the max_x (x size of the window)
    // and also give us the space (margin_x) to draw
    // the labels

    GLint xSpacing = floor(((double)max_x - 2*margin_x)/((double)x_inputs)) - ceil(((double)2*margin_x)/((double)x_inputs)) ;
    
    // So we have to set the initial position to fit the xSpacing
    // and also the margin left
    GLint xRaster = margin_x + 0.5*xSpacing;
    
    // Cursor y position, where 12 is the padding y
    GLint yRaster = 12;
    
    for(int i=1; i<=x_inputs; i++)
    {
        char *number = new char;
        sprintf(number,"%d",i);
        
        int numberSize = sizeof(number)/sizeof(CHAR_BIT);
        
        for (GLint j=0; j<numberSize; j++)
        {
            glRasterPos2i(xRaster, yRaster);
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, number[j]);
            
            xRaster += 8;
        }
        
        // First part: we are just walking through the xSpacing
        // scale.
        // Second part: make sure it'll not be considering the
        // space walked to draw the numbers.
        xRaster += xSpacing - 8*numberSize;
    }
}

static void drawYAxisLabels(int y, int y_scale)
{
    glColor3f(0.0, 0.0, 0.0);
    
    // Cursor y position. We need to add the margin_y since it'll be upper the y
    GLint yRaster = margin_y;
    
    for(int i=0; i<=y; i+=y_scale)
    {
        char *number = new char;
        sprintf(number,"%d",i);
        
        // Cursor x position, where 4 is the padding x
        GLint xRaster = 4;
        
        int numberSize = sizeof(number)/sizeof(CHAR_BIT);
        for (GLint j=0; j<=numberSize; j++)
        {
            glRasterPos2i(xRaster, yRaster);
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, number[j]);
            
            xRaster += 8;
        }
        
        // Where 13 is the font height
        yRaster += y_scale;
        
    }
}

static void drawMainGraphLines(int x, int y, int x_inputs, int y_scale)
{
    drawXAxisLabels(x, x_inputs);
    drawYAxisLabels(y, y_scale);

    GLint xLine[2][2] = {
        { 0 + margin_x , 0 + margin_y } ,
        { max_x - 3*margin_x , 0 + margin_y}
    };
    
    GLint yLine[2][2] = {
        { 0 + margin_x , 0 + margin_y } ,
        { 0 + margin_x , max_y - margin_y}
    };
    
    glColor3f(0.0, 0.0, 0.0);

    // X draw
    glBegin(GL_LINE_STRIP);
    glVertex2iv(xLine[0]);
    glVertex2iv(xLine[1]);
    glEnd();
    
    // Y draw
    glBegin(GL_LINE_STRIP);
    glVertex2iv(yLine[0]);
    glVertex2iv(yLine[1]);
    glEnd();
    
    // Drawing sublines
    
    //Drawing the (y = n) lines
    glColor3f(0.8, 0.8, 0.8);
    
    for(int i=y_scale ; i<=y; i+= y_scale)
    {
        glBegin(GL_LINE_STRIP);
        
        glVertex2i(( 0 + margin_x ), (i + margin_y));
        glVertex2i(( max_x - 3*margin_x ), (i + margin_y));
        
        glEnd();
    }
    
    // Drawing the (x = n) lines
    
    // Scale conversion (same as drawXAxisLabels)
//    GLint xSpacing = floor(((double)max_x - 3*margin_x)/ ((double)x_inputs)) - ceil(((double)margin_x)/((double)x_inputs)) ;
//    
//    for(int i=1; i<x_inputs; i++)
//    {
//        glBegin(GL_LINE_STRIP);
//        
//        glVertex2i(( i*xSpacing + margin_x ), (0 + margin_y)+1);
//        glVertex2i(( i*xSpacing + margin_x ), (max_y - margin_y)+1);
//        
//        glEnd();
//    }
    
}

void drawLines(double lineWidth)
{
    // Scale conversion (same as drawXAxisLabels)
    GLint xSpacing = floor(((double)max_x - 3*margin_x)/ ((double)10)) - ceil(((double)margin_x)/((double)10)) ;

    
    int dataTableA[10] =  {
        318, 324, 315, 282, 157,
        219, 236, 184, 249, 446
    };
    
    GLfloat colorA[3] = {
        0.1,0.1, 0.70
    };
    
    int dataTableB[10] =  {
        420, 342, 324, 310, 262,
        185, 190, 196, 217, 240
    };
    
    GLfloat colorB[3] = {
        0.84,0.2, 0.2
    };
    
    int dataTableC[10] =  {
        210, 208, 218, 237, 267,
        272, 290, 350, 383, 422
    };
    
    GLfloat colorC[3] = {
        0.6,0.95, 0.6
    };
    
    
    // Line weight
    glLineWidth(lineWidth);
    
    // Antialiasing configuration
    glEnable( GL_LINE_SMOOTH );
    glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // Data A
    glColor3fv(colorA);
    
    glBegin(GL_LINE_STRIP);
    
    for(int i=1; i<=10; i++)
    {
        GLint xCoord = ((GLint)i * xSpacing) + 0.5*margin_x;
        GLint yCoord = ((GLint)dataTableA[i-1]) + margin_y;
        
        glVertex2i(xCoord,yCoord);
    }
    
    glEnd();
    
    // Data B
    glColor3fv(colorB);
    
    glBegin(GL_LINE_STRIP);
    
    for(int i=1; i<=10; i++)
    {
        GLint xCoord = ((GLint)i * xSpacing) + 0.5*margin_x;
        GLint yCoord = ((GLint)dataTableB[i-1]) + margin_y;
        
        glVertex2i(xCoord,yCoord);
    }
    
    glEnd();
    
    // Data C
    glColor3fv(colorC);
    
    glBegin(GL_LINE_STRIP);
    
    for(int i=1; i<=10; i++)
    {
        GLint xCoord = ((GLint)i * xSpacing) + 0.5*margin_x;
        GLint yCoord = ((GLint)dataTableC[i-1]) + margin_y;
        
        glVertex2i(xCoord,yCoord);
    }
    
    glEnd();
    
    
    // Disable antialiasing
    glDisable( GL_LINE_SMOOTH );
    glDisable(GL_BLEND);
    
    
    // Label A
    std::string labelA = "Data A";
    
    // Gets the size of the label to convert to *char
    unsigned long labelASize = labelA.size()+1;
    char labelAToWrite[labelASize];
    
    // Copies the chars from string to char*
    strcpy(labelAToWrite, labelA.c_str());
    
    // Label B
    std::string labelB = "Data B";
    
    unsigned long labelBSize = labelB.size()+1;
    char labelBToWrite[labelBSize];
    
    strcpy(labelBToWrite, labelB.c_str());
    
    // Label C
    std::string labelC = "Data C";
    
    unsigned long labelCSize = labelC.size()+1;
    char labelCToWrite[labelCSize];
    
    strcpy(labelCToWrite, labelC.c_str());
    
    
    
    // Legend drawing
    GLint xRaster = 0;
    GLint yRaster = 0;
    
    // Calculating the y center of the window
    GLint yCenterCoord = max_y / 2;
    // The spacing between the legend params
    GLint spacing = 30;
    
    // The X coord will be used as the following:
    // lineSize: 20 px
    // x = max_x + lineSize - 2 * margin_x
    GLint lineSize = 40;
    GLint xLegendDefault = max_x + lineSize - 2 * margin_x;
    
    // To make sure the labels will be centered:
    // A => yCenterCoord + 30
    // B => yCenterCoord
    // C => yCenterCoord - 30
    
    // Label A
    glColor3f(0.0,0.0,0.0);
    
    xRaster = xLegendDefault;
    yRaster = yCenterCoord + 30;
    for (GLint j = 0; j<labelASize; j++)
    {
        glRasterPos2i(xRaster, yRaster);
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, labelA[j]);
        
        xRaster += 8;

    }
    
    glColor3fv(colorA);
    glBegin(GL_LINE_STRIP);
    
    glVertex2i(xLegendDefault-lineSize, yCenterCoord+35);
    glVertex2i(xLegendDefault-10, yCenterCoord+35);
    
    glEnd();
    
    
    // Label B
    glColor3f(0.0,0.0,0.0);
    
    xRaster = xLegendDefault;
    yRaster = yCenterCoord;
    for (GLint j = 0; j<labelASize; j++)
    {
        glRasterPos2i(xRaster, yRaster);
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, labelB[j]);
        
        xRaster += 8;
        
    }
    
    glColor3fv(colorB);
    glBegin(GL_LINE_STRIP);
    
    glVertex2i(xLegendDefault-lineSize, yCenterCoord+5);
    glVertex2i(xLegendDefault-10, yCenterCoord+5);
    
    glEnd();
    
    
    
    // Label C
    glColor3f(0.0,0.0,0.0);
    
    xRaster = xLegendDefault;
    yRaster = yCenterCoord - 30;
    for (GLint j = 0; j<labelASize; j++)
    {
        glRasterPos2i(xRaster, yRaster);
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, labelC[j]);
        
        xRaster += 8;
    }

    glColor3fv(colorC);
    glBegin(GL_LINE_STRIP);
    
    glVertex2i(xLegendDefault-lineSize, yCenterCoord-25);
    glVertex2i(xLegendDefault-10, yCenterCoord-25);
    
    glEnd();
    
}

int main(int argc, char * argv[])
{
    while(lineWidth<1.0)
    {
        std::cout << "What size of line do you want? (It must least 1.0 or more)" << std::endl;
        std::cin >> lineWidth;
        
        if(!std::cin)
        {
            std::cin.clear();
            while (std::cin.get() != '\n'){/*Wait to clear the buffer*/}
            std::cout << "You must type a number" << std::endl;
        }
        
        if(lineWidth<1.0)
            std::cout << "You must type a number greater or equals to 1.0" << std::endl;
    }
    
    // Init GLUT
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    
    glutInitWindowSize( max_x, max_y );
    glutCreateWindow("Homework 3");
    
    // Draws the scene
    glutDisplayFunc(redraw);
    
    // Projection type
    glMatrixMode(GL_PROJECTION);
    gluPerspective(0, 1.0, 10.0, 200.0);
    
    // Starts GLUT
    glutMainLoop();
    
    return 0;
}
