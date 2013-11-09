////////////////////////////////////////////////////////////////
//
// Draw_Wing_Pt2.cpp To draw the second part of the wing.
// 
// Author: Thomas Frow
// Date:   25/09/2013
//
////////////////////////////////////////////////////////////////

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
#include "Resources/drawC.h"
#include "Resources/drawD.h"


void drawWingPt2() {

glPushMatrix();

	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glScalef(1.0, 1.0, 1.0);

	glPushMatrix();//Big D

		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(0.0, 0.0, 0.0, 0.0);
		glScalef(0.6, 1.0, 0.5);
		drawD();

	glPopMatrix();

	glPushMatrix();//Top Left D

		glTranslatef(-0.3, -1.6, 0.0);
		glRotatef(180, 1.0, 0.0, 0.0);
		glRotatef(50, 0.0, 0.0, 1.0);
		glScalef(0.3, 0.3, 0.5);
		drawD();

	glPopMatrix();

	glPushMatrix();// Top Right D

		glTranslatef(-0.175, -1.6, 0.0);
		glRotatef(180, 1.0, 0.0, 0.0);
		glRotatef(53, 0.0, 0.0, 1.0);
		glScalef(0.3, 0.3, 0.5);
		drawD();

	glPopMatrix();

	glPushMatrix(); //Bottom Left D

		glTranslatef(-0.3, 1.6, 0.0);
		glRotatef(50, 0.0, 0.0, 1.0);
		glScalef(0.3, 0.3, 0.5);
		drawD();

	glPopMatrix();

	glPushMatrix(); //Bottom Right D

		glTranslatef(-0.175, 1.6, 0.0);
		glRotatef(53, 0.0, 0.0, 1.0);
		glScalef(0.3, 0.3, 0.5);
		drawD();

	glPopMatrix();

	
glPopMatrix();
	
}
