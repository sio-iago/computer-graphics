#include "main.h"

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define window_x 500
#define window_y 500

GLdouble radius=1;


void init(void)
{
    // Multisampling
    glEnable(GL_MULTISAMPLE);
    glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
    
    // Enable the lights
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    
    glShadeModel (GL_SMOOTH);
    
    glEnable(GL_NORMALIZE);
    
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
}

void display(void)
{
    
    glMatrixMode(GL_MODELVIEW);

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glOrtho( 0.0, 1.0, 0.0, 1.0, -1.0, 1.0 ); // Create the drawing space
    
    spotlight();
    drawSphere();
    
    
    glFlush();

}

void drawSphere(void)
{
    glLoadIdentity();
    
    // Material Properties
    GLfloat mat_specular[3] = { 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[1] = { 50.0 };
    
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    
    // traslate z = -8.0
    glTranslatef(0.0,0.0,-8.0);
    
    glColor3f(9.0, 0.98, 0.81);
    glNormal3f(0.0, 0.0, 1.0);
    
    // drawing the sphere.
    glutSolidSphere(radius,80,40);

}

void spotlight(void)
{
    glLoadIdentity();
    
    
    
    GLfloat ambientColor[4] = {0.05, 0.05, 0.05, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
    
    
    // Room light
    GLfloat lightColor0[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat lightPos0[4] = {-20.0, 15.0, -45.0, 1.0};

    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    
    
    // Spotlight
//    GLfloat spotDir[4] = { 0.0, 0.0, 0.0 };
//    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDir);
//    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 100.0);
//    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.0);
    
}

void reshape(int x, int y)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluPerspective(40.0,1.0,1.0,21.0);
    
    glutReshapeWindow(window_x, window_y);
    
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
    
    glutInitWindowSize(window_x, window_y);
    glutCreateWindow("Homework 4");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    init();
    
    
    glutMainLoop();
    return 0;
}