//
//  main.h
//  cg_hw2
//
//  Created by Silva IO on 9/22/15.
//  Copyright © 2015 Silva IO. All rights reserved.
//

#ifndef main_h
#define main_h

#include <iostream>

/* Functions called by GLUT */
static void redraw(void);
static void keyboardInput(unsigned char key, int x, int y);
static void idle(void);

/* Subfunctions */
static void drawTable(void);
static void drawBook(int frednumber, std::string *names, int stackPosition);
static void zoom(void);

#endif /* main_h */
