////////////////////////////////////////////////////////////////
//
// drawF.cpp To draw an F
// 
// Author: Thomas Frow
// Date:   25/09/2013
//
////////////////////////////////////////////////////////////////

//#include "stdafx.h" //Only required for windows
#include <stdlib.h>

//#include <GL/glut.h> //required for linux
#include <math.h>
#include <stdio.h>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>//only required for mac
//#include "drawT.h"
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
		glTranslatef(0,0,0);
		//glRotatef(1,90,0,0);
		glScalef(0.5,3,0.5);
		draw3DCube();
	glPopMatrix();
}
