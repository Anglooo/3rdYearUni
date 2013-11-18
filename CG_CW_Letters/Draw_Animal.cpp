////////////////////////////////////////////////////////////////
//
// Draw_Animal.cpp To draw an Animal
// 
// Author: Thomas Frow
// Date:   25/09/2013
//
///////////////////////////////////////////////////////////////

#ifdef __APPLE__
#    include <GLUT/glut.h>
#    include <OpenGL/OpenGL.h>
#elif defined _WIN32 || defined _WIN64
#    include <GL/glut.h>
#	 include "stdafx.h"
#elif __gnu_linux__
#    include <GL/glut.h>
#endif

#include <math.h>
#include <stdio.h>
#include "Resources/cube.h"
#include "Draw_Body.h"
#include "Draw_Whole_Wing.h"


void drawAnimal() {
glPushMatrix();
	glTranslatef(0.85, 0.0, 0.0);
	//glRotatef(0, 0.0, 0.0, 1.0);
	glScalef(0.5, 0.5, 0.5);
	drawWholeWing();	
glPopMatrix();
glPushMatrix();
	glTranslatef(-0.85, 0.0, 0.0);
	glRotatef(180, 0.0, 0.0, 1.0);
	glScalef(0.5, 0.5, 0.5);
	drawWholeWing();	
glPopMatrix();
glPushMatrix();
	glTranslatef(0, 0.0, 0.0);
	//glRotatef(0, 0.0, 0.0, 1.0);
	glScalef(0.3, 0.3, 0.3);
	drawBody();	
glPopMatrix();
}
