//
//  main.cpp
//  NightSky
//
//  Created by Silva IO on 10/31/15.
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

#include <iostream>

using namespace std;


const GLdouble skyColor[3] = { 0.05f, 0.05f, 0.18f };

void init(void)
{
    setupSpaceObjects();
}

void display(void)
{
    glClearColor(skyColor[0], skyColor[1], skyColor[2], 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D( 0, window_x, 0, window_y);
    
    // Multisampling
    glEnable(GL_MULTISAMPLE);
    glEnable( GL_POLYGON_SMOOTH );
    glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // Scene drawing
    glPushMatrix();
    glTranslated(-skyTranslation, 0.0f, 0.0f);
    
    drawScene(numberOfObjects);
    
    glPopMatrix();
    
    // Popup drawing
    drawPopup();
    
    glutSwapBuffers();
    
}

void reshape(int x, int y)
{
    glutReshapeWindow(window_x, window_y);
}


void drawScene(int n)
{
    for(int i=0; i<n; i++)
    {
        GLdouble x = space_objects[i].coordinates[0];
        GLdouble y = space_objects[i].coordinates[1];
        
        if(x - skyTranslation < 0)
        {
            x = x + window_x;
        }
        
        GLdouble* color = space_objects[i].color;
        
        
        glPushMatrix();
        glTranslatef(x,y,0.0);
        
        GLdouble radius = space_objects[i].radius;
        
        glColor3dv(color);
        
        drawSpaceObject(radius);
        
        
        glPopMatrix();
    }
}

void mouseHandler(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT && state == GLUT_DOWN)
    {
        /*
         (window_y - y) because the glut given y is the position
         from top-bottom and the openGL drawing is bottom-up.
         */
        int obj = hasObject(x, window_y-y);
        
        if(obj != object_not_found)
        {
            isPopupOpened = true;
            popupObjectIndex = obj;
            skyPositionWhenClicked = skyTranslation;
        }
        else
        {
            isPopupOpened = false;
        }
    }
}

void idleHandler(void)
{
    
}

void keyboardHandler(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'q': { exit(0); }
        case 'Q': { exit(0); }
    }
}

void timerFunction(int value)
{
    if(skyTranslation > window_x - SPEED)
        skyTranslation = 0.0f;
    else
        skyTranslation += SPEED;
    
    glutPostRedisplay();
    glutTimerFunc(FRAME_TIME, timerFunction, value);
}


int hasObject(int x, int y)
{
    for(int i=0; i<numberOfObjects; i++)
    {
        double objX = space_objects[i].coordinates[0] - skyTranslation;
        
        if(objX < 0)
        {
            objX = objX + window_x;
        }
        
        double objY = space_objects[i].coordinates[1];
        double collisionRadius = space_objects[i].collisionBox;
        
        double mouseX = (double) x;
        double mouseY = (double) y;
        
        if((mouseX >= objX - collisionRadius) && (mouseX <= objX + collisionRadius) &&
           (mouseY >= objY - collisionRadius) && (mouseY <= objY + collisionRadius))
        {
            return i;
        }
    }
    
    return object_not_found;
}

void drawPopup(void)
{
    if(isPopupOpened)
    {
        double margin = 2.0f;
        glColor3dv(popupColor);
        
        GLdouble popupX = space_objects[popupObjectIndex].coordinates[0] - skyPositionWhenClicked;
        GLdouble popupY = space_objects[popupObjectIndex].coordinates[1];

        if(popupX < 0)
        {
            popupX = window_x + popupX;
        }
        
        if((popupX + popup_x) >= window_x)
        {
            popupX = window_x - popup_x - margin;
        }
        if((popupY + popup_y) >= window_y)
        {
            popupY = window_y - popup_y - margin;
        }
        
        glPushMatrix();
        glTranslated(popupX, popupY, 0.0);
        
        glBegin(GL_POLYGON);
        
        glVertex2d(0.0f+margin, 0.0f+margin);
        glVertex2d(0.0f+margin, popup_y);
        glVertex2d(popup_x, popup_y);
        glVertex2d(popup_x, 0.0f+margin);
        
        glEnd();
        
        // Title and description
        glColor3f(1.0f, 1.0f, 1.0f);
        
        double xRaster = 3 * margin;
        double yRaster = popup_y - 10 - 2 * margin;
        
        const char *title = space_objects[popupObjectIndex].name;
        const char *details = space_objects[popupObjectIndex].details;
        
        unsigned int titleSize = strlen(title);
        unsigned int detailsSize = strlen(details);
        
        // Title
        for (GLint i=0; i<titleSize; i++)
        {
            glRasterPos2i(xRaster, yRaster);
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, title[i]);
            
            xRaster += 8;
        }
        
        // Draw the line under the title
        glColor3f(0.2f,0.8f,0.2f);
        glLineWidth(0.1f);
        
        yRaster -= 5;
        
        glBegin(GL_LINE_LOOP);
        
        glVertex2d(2.0f, yRaster);
        glVertex2d(popup_x, yRaster);
        
        glEnd();
        
        // Description
        xRaster = 3 * margin;
        yRaster = popup_y - 32 - 2 * margin;
        
        glColor3f(1.0f, 1.0f, 1.0f);
        
        for (GLint i=0; i<detailsSize; i++)
        {
            glRasterPos2i(xRaster, yRaster);
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, details[i]);
            
            xRaster += 8;
        }
        
        
        
        glPopMatrix();
    }
}

int main (int argc, char **argv)
{
    
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_MULTISAMPLE);
    
    glutInitWindowSize(window_x, window_y);
    glutCreateWindow("Night Sky");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseHandler);
    glutKeyboardFunc(keyboardHandler);
    glutIdleFunc(idleHandler);
    glutTimerFunc((int)FRAME_TIME, timerFunction, 0);
    
    init();
    
    glutMainLoop();
    
    return 0;
    
}
