////////////////////////////////////////////////////////////////
//
// drawT.cpp To draw a T
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
#include "cube.h"
#include "drawT.h"


void drawT() {
	glPushMatrix();
	glTranslatef(1.5,0,0);
	//Draw top cube
	glPushMatrix();
		glTranslatef(0,1.25,0);
		//glRotatef(0,0,0);
		glScalef(3,0.5,0.5);
		draw3DCube();
	glPopMatrix();
	//Draw bottom cube
	glPushMatrix();
		glTranslatef(0,0,0);
		//glRotatef(1,90,0,0);
		glScalef(0.5,3,0.5);
		draw3DCube();
	glPopMatrix();
	glPopMatrix();
}

