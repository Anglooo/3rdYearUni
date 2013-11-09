////////////////////////////////////////////////////////////////
//
// Draw_Wing_Pt1.cpp To draw Wing part 1
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
#include "Resources/drawT.h"
#include "Resources/drawF.h"


void drawWingPt1() {
glPushMatrix();
	
	//transformations to whole graphic.
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glScalef(0.5, 0.5, 0.5);

	glPushMatrix();//Big D

		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(0.0, 0.0, 0.0, 0.0);
		glScalef(1.0, 1.0, 1.0);
		drawT();

	glPopMatrix();
	
glPopMatrix();
}
