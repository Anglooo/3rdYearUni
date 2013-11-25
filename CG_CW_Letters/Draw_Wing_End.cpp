////////////////////////////////////////////////////////////////
//
// drawF.cpp To draw an F
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
#include "Draw_Wing_Pt1.h"
#include "Draw_Wing_Pt2.h"


void drawWingEnd(float wingAngle) {
glPushMatrix();
glRotatef(wingAngle, 0.0, 1.0, 0.0);
	glPushMatrix();
		glTranslatef(0.5, 0.0, 0.0);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.5, 0.7, 4);
		drawWingPt1();	
	glPopMatrix();
glPopMatrix();

glPushMatrix();
glRotatef(wingAngle, 0.0, 1.0, 0.0);
	glPushMatrix();
		glTranslatef(1.0, 0.0, 0.0);
		glScalef(1, 1, 1);
		drawWingPt2();
	glPopMatrix();
glPopMatrix();

}
