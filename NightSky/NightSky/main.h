//
//  main.h
//  NightSky
//
//  Created by Silva IO on 10/31/15.
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

#include <cmath>

#define PI 3.14159

#define z 1.0f

#define window_x 1000
#define window_y 500

#define popup_x 388
#define popup_y 45

#define FRAME_TIME 50
#define SPEED 0.25 // 0.25 is the ideal

#define numberOfObjects 30
#define object_not_found -1

#define starSize 2.5f
#define starCollisionBox 4.0f

// Popup Globals
bool isPopupOpened = false;
double skyPositionWhenClicked = 0.0f;
int popupObjectIndex = object_not_found;
GLdouble popupColor[3] = {0.1f, 0.5f, 0.1f};

// Animation globals
GLdouble skyTranslation = 0.0f;

// Space Objects Globals
typedef struct space_object
{
    GLdouble coordinates[2];
    GLdouble radius;
    GLdouble collisionBox;
    
    GLdouble color[3];
    
    const char* name;
    const char* details;
};

space_object *space_objects = new space_object[numberOfObjects];


// Functions
void init(void);
void display(void);
void reshape(void);
void mouseHandler(int button, int state, int x, int y);
void keyboardHandler(unsigned char key, int x, int y);
void idleHandler(void);
void timerFunction(int value);

void drawScene(int n);
int hasObject(int x, int y);
void drawPopup(void);



// Header common functions
void drawSpaceObject(GLdouble radius)
{
    glBegin(GL_TRIANGLE_FAN);
    
    for (GLdouble i=0; i <= 2*PI; i+=0.2f)
    {
        glVertex2f(cos(i)*radius,sin(i)*radius);
    }
    
    glEnd();
}

// Initialize the objects
void setupSpaceObjects(void)
{
    // Object 0
    space_objects[0].name = "Moon";
    space_objects[0].details = "The Moon is Earth's only natural satellite.";
    space_objects[0].coordinates[0] = 650.0f;
    space_objects[0].coordinates[1] = 250.0f;
    space_objects[0].radius = 25.0f;
    space_objects[0].collisionBox = 24.0f;
    space_objects[0].color[0] = 1.0f;
    space_objects[0].color[1] = 1.0f;
    space_objects[0].color[2] = 1.0f;
    
    
    // Object 1
    space_objects[1].name = "Venus";
    space_objects[1].details = "Venus is the second planet from the Sun.";
    space_objects[1].coordinates[0] = 540.0f;
    space_objects[1].coordinates[1] = 330.0f;
    space_objects[1].radius = 4.0f;
    space_objects[1].collisionBox = 4.0f;
    space_objects[1].color[0] = 1.00f;
    space_objects[1].color[1] = 0.98f;
    space_objects[1].color[2] = 0.92f;
    
    // Object 2
    space_objects[2].name = "Mars";
    space_objects[2].details = "Mars is the fourth planet from the Sun.";
    space_objects[2].coordinates[0] = 530.0f;
    space_objects[2].coordinates[1] = 336.0f;
    space_objects[2].radius = 1.8f;
    space_objects[2].collisionBox = 2.5f;
    space_objects[2].color[0] = 1.00f;
    space_objects[2].color[1] = 0.98f;
    space_objects[2].color[2] = 0.92f;
    
    
    // Object 3
    space_objects[3].name = "Jupiter";
    space_objects[3].details = "Jupiter is the fifth planet from the Sun.";
    space_objects[3].coordinates[0] = 560.0f;
    space_objects[3].coordinates[1] = 390.0f;
    space_objects[3].radius = 3.5f;
    space_objects[3].collisionBox = 3.5f;
    space_objects[3].color[0] = 1.0f;
    space_objects[3].color[1] = 1.0f;
    space_objects[3].color[2] = 1.0f;
    
    
    // Object 4
    space_objects[4].name = "Denebola";
    space_objects[4].details = "Denebola is in the zodiac constellation of Leo.";
    space_objects[4].coordinates[0] = 440.0f;
    space_objects[4].coordinates[1] = 370.0f;
    space_objects[4].radius = starSize;
    space_objects[4].collisionBox = starCollisionBox;
    space_objects[4].color[0] = 1.0f;
    space_objects[4].color[1] = 1.0f;
    space_objects[4].color[2] = 1.0f;
    
    
    //----- Crux Constellation -----//
    // Object 5
    space_objects[5].name = "Gamma Crucis";
    space_objects[5].details = "Gamma Crucis, often called Gacrux.";
    space_objects[5].coordinates[0] = 200.0f;
    space_objects[5].coordinates[1] = 440.0f;
    space_objects[5].radius = starSize;
    space_objects[5].collisionBox = starCollisionBox;
    space_objects[5].color[0] = 1.0f;
    space_objects[5].color[1] = 1.0f;
    space_objects[5].color[2] = 1.0f;
    
    // Object 6
    space_objects[6].name = "Delta Crucis";
    space_objects[6].details = "Delta Crucis is called Pálida in Portuguese.";
    space_objects[6].coordinates[0] = 245.0f;
    space_objects[6].coordinates[1] = 410.0f;
    space_objects[6].radius = starSize;
    space_objects[6].collisionBox = starCollisionBox;
    space_objects[6].color[0] = 1.0f;
    space_objects[6].color[1] = 1.0f;
    space_objects[6].color[2] = 1.0f;
    
    
    // Object 7
    space_objects[7].name = "Epsilon Crucis";
    space_objects[7].details = "Epsilon Crucis is a Class K3III star.";
    space_objects[7].coordinates[0] = 223.0f;
    space_objects[7].coordinates[1] = 376.0f;
    space_objects[7].radius = starSize;
    space_objects[7].collisionBox = starCollisionBox;
    space_objects[7].color[0] = 1.0f;
    space_objects[7].color[1] = 1.0f;
    space_objects[7].color[2] = 1.0f;
    
    // Object 8
    space_objects[8].name = "Mu Crucis";
    space_objects[8].details = "Mu Crucis is a wide binary of class B stars.";
    space_objects[8].coordinates[0] = 212.0f;
    space_objects[8].coordinates[1] = 320.0f;
    space_objects[8].radius = starSize;
    space_objects[8].collisionBox = starCollisionBox;
    space_objects[8].color[0] = 1.0f;
    space_objects[8].color[1] = 1.0f;
    space_objects[8].color[2] = 1.0f;
    
    // Object 9
    space_objects[9].name = "Kappa Crucis";
    space_objects[9].details = "Kappa Crucis is a star in star cluster NGC 4755.";
    space_objects[9].coordinates[0] = 165.0f;
    space_objects[9].coordinates[1] = 398.0f;
    space_objects[9].radius = starSize;
    space_objects[9].collisionBox = starCollisionBox;
    space_objects[9].color[0] = 1.0f;
    space_objects[9].color[1] = 1.0f;
    space_objects[9].color[2] = 1.0f;
    
    //----- Other Objects -----//
    // Object 10
    space_objects[10].name = "Rigel";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[10].coordinates[0] = 345.0f;
    space_objects[10].coordinates[1] = 198.0f;
    space_objects[10].radius = starSize;
    space_objects[10].collisionBox = starCollisionBox;
    space_objects[10].color[0] = 1.0f;
    space_objects[10].color[1] = 1.0f;
    space_objects[10].color[2] = 1.0f;
    
    // Object 11
    space_objects[11].name = "Alpha Persei";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[11].coordinates[0] = 430.0f;
    space_objects[11].coordinates[1] = 80.0f;
    space_objects[11].radius = starSize;
    space_objects[11].collisionBox = starCollisionBox;
    space_objects[11].color[0] = 1.0f;
    space_objects[11].color[1] = 1.0f;
    space_objects[11].color[2] = 1.0f;
    
    // Object 12
    space_objects[12].name = "Saturn";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[12].coordinates[0] = 480.0f;
    space_objects[12].coordinates[1] = 400.0f;
    space_objects[12].radius = starSize;
    space_objects[12].collisionBox = starCollisionBox;
    space_objects[12].color[0] = 1.0f;
    space_objects[12].color[1] = 1.0f;
    space_objects[12].color[2] = 1.0f;
    
    // Object 13
    space_objects[13].name = "Beta Ceti";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[13].coordinates[0] = 580.0f;
    space_objects[13].coordinates[1] = 158.0f;
    space_objects[13].radius = starSize;
    space_objects[13].collisionBox = starCollisionBox;
    space_objects[13].color[0] = 1.0f;
    space_objects[13].color[1] = 1.0f;
    space_objects[13].color[2] = 1.0f;
    
    // Object 14
    space_objects[14].name = "Canopus";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[14].coordinates[0] = 700.0f;
    space_objects[14].coordinates[1] = 170.0f;
    space_objects[14].radius = starSize;
    space_objects[14].collisionBox = starCollisionBox;
    space_objects[14].color[0] = 1.0f;
    space_objects[14].color[1] = 1.0f;
    space_objects[14].color[2] = 1.0f;
    
    // Object 15
    space_objects[15].name = "Deneb";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[15].coordinates[0] = 65.0f;
    space_objects[15].coordinates[1] = 285.0f;
    space_objects[15].radius = starSize;
    space_objects[15].collisionBox = starCollisionBox;
    space_objects[15].color[0] = 1.0f;
    space_objects[15].color[1] = 1.0f;
    space_objects[15].color[2] = 1.0f;
    
    // Object 16
    space_objects[16].name = "Vega";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[16].coordinates[0] = 148.0f;
    space_objects[16].coordinates[1] = 235.0f;
    space_objects[16].radius = starSize;
    space_objects[16].collisionBox = starCollisionBox;
    space_objects[16].color[0] = 1.0f;
    space_objects[16].color[1] = 1.0f;
    space_objects[16].color[2] = 1.0f;
    
    // Object 17
    space_objects[17].name = "Altair";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[17].coordinates[0] = 100.0f;
    space_objects[17].coordinates[1] = 100.0f;
    space_objects[17].radius = starSize;
    space_objects[17].collisionBox = starCollisionBox;
    space_objects[17].color[0] = 1.0f;
    space_objects[17].color[1] = 1.0f;
    space_objects[17].color[2] = 1.0f;
    
    // Object 18
    space_objects[18].name = "Aldebaran";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[18].coordinates[0] = 805.0f;
    space_objects[18].coordinates[1] = 325.0f;
    space_objects[18].radius = starSize;
    space_objects[18].collisionBox = starCollisionBox;
    space_objects[18].color[0] = 1.0f;
    space_objects[18].color[1] = 1.0f;
    space_objects[18].color[2] = 1.0f;
    
    // Object 19
    space_objects[19].name = "Alpha Centauri";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[19].coordinates[0] = 65.0f;
    space_objects[19].coordinates[1] = 48.0f;
    space_objects[19].radius = starSize;
    space_objects[19].collisionBox = starCollisionBox;
    space_objects[19].color[0] = 1.0f;
    space_objects[19].color[1] = 1.0f;
    space_objects[19].color[2] = 1.0f;
    
    // Object 20
    space_objects[20].name = "Alkaid";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[20].coordinates[0] = 770.0f;
    space_objects[20].coordinates[1] = 232.0f;
    space_objects[20].radius = starSize;
    space_objects[20].collisionBox = starCollisionBox;
    space_objects[20].color[0] = 1.0f;
    space_objects[20].color[1] = 1.0f;
    space_objects[20].color[2] = 1.0f;
    
    // Object 21
    space_objects[21].name = "Mizar";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[21].coordinates[0] = 810.0f;
    space_objects[21].coordinates[1] = 255.0f;
    space_objects[21].radius = starSize;
    space_objects[21].collisionBox = starCollisionBox;
    space_objects[21].color[0] = 1.0f;
    space_objects[21].color[1] = 1.0f;
    space_objects[21].color[2] = 1.0f;
    
    // Object 22
    space_objects[22].name = "Alioth";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[22].coordinates[0] = 850.0f;
    space_objects[22].coordinates[1] = 227.0f;
    space_objects[22].radius = starSize;
    space_objects[22].collisionBox = starCollisionBox;
    space_objects[22].color[0] = 1.0f;
    space_objects[22].color[1] = 1.0f;
    space_objects[22].color[2] = 1.0f;
    
    // Object 23
    space_objects[23].name = "Megrez";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[23].coordinates[0] = 891.0f;
    space_objects[23].coordinates[1] = 202.0f;
    space_objects[23].radius = starSize;
    space_objects[23].collisionBox = starCollisionBox;
    space_objects[23].color[0] = 1.0f;
    space_objects[23].color[1] = 1.0f;
    space_objects[23].color[2] = 1.0f;
    
    // Object 24
    space_objects[24].name = "Dubhe";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[24].coordinates[0] = 951.0f;
    space_objects[24].coordinates[1] = 208.0f;
    space_objects[24].radius = starSize;
    space_objects[24].collisionBox = starCollisionBox;
    space_objects[24].color[0] = 1.0f;
    space_objects[24].color[1] = 1.0f;
    space_objects[24].color[2] = 1.0f;
    
    // Object 25
    space_objects[19].name = "El Kophrah";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[19].coordinates[0] = 865.0f;
    space_objects[19].coordinates[1] = 122.0f;
    space_objects[19].radius = starSize;
    space_objects[19].collisionBox = starCollisionBox;
    space_objects[19].color[0] = 1.0f;
    space_objects[19].color[1] = 1.0f;
    space_objects[19].color[2] = 1.0f;
    
    // Object 26
    space_objects[26].name = "Alpha Pegasi";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[26].coordinates[0] = 248.0f;
    space_objects[26].coordinates[1] = 134.0f;
    space_objects[26].radius = starSize;
    space_objects[26].collisionBox = starCollisionBox;
    space_objects[26].color[0] = 1.0f;
    space_objects[26].color[1] = 1.0f;
    space_objects[26].color[2] = 1.0f;
    
    // Object 27
    space_objects[27].name = "Arcturus";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[27].coordinates[0] = 940.0f;
    space_objects[27].coordinates[1] = 430.0f;
    space_objects[27].radius = starSize;
    space_objects[27].collisionBox = starCollisionBox;
    space_objects[27].color[0] = 1.0f;
    space_objects[27].color[1] = 1.0f;
    space_objects[27].color[2] = 1.0f;
    
    // Object 28
    space_objects[28].name = "Hamal";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[28].coordinates[0] = 690.0f;
    space_objects[28].coordinates[1] = 420.0f;
    space_objects[28].radius = starSize;
    space_objects[28].collisionBox = starCollisionBox;
    space_objects[28].color[0] = 1.0f;
    space_objects[28].color[1] = 1.0f;
    space_objects[28].color[2] = 1.0f;
    
    // Object 29
    space_objects[29].name = "Sigma Sagitarii";
    space_objects[1].details = "A star out of the solar system.";
    space_objects[29].coordinates[0] = 645.0f;
    space_objects[29].coordinates[1] = 62.0f;
    space_objects[29].radius = starSize;
    space_objects[29].collisionBox = starCollisionBox;
    space_objects[29].color[0] = 1.0f;
    space_objects[29].color[1] = 1.0f;
    space_objects[29].color[2] = 1.0f;
}


#endif /* main_h */
