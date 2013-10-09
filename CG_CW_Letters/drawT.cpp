////////////////////////////////////////////////////////////////
//
// drawT.cpp To draw a T
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

