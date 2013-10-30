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
#include "cube.h"


void drawF() {

	//Draw top 'arm' of F
	glPushMatrix();
		glTranslatef(0.75,1.25,0);
		//glRotatef(0,0,0);
		glScalef(2,0.5,0.5);
		draw3DCube();
	glPopMatrix();
	//Draw bottom 'arm' of F
	glPushMatrix();
		glTranslatef(0.75,0,0);
		//glRotatef(0,0,0);
		glScalef(2,0.5,0.5);
		draw3DCube();
	glPopMatrix();
	//Draw bottom cube
	glPushMatrix();
		glTranslatef(0.00,0,0);
		//glRotatef(1,90,0,0);
		glScalef(0.5,3,0.5);
		draw3DCube();
	glPopMatrix();
	
}
