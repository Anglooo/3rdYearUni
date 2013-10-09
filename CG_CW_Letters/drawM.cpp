////////////////////////////////////////////////////////////////
//
// drawM.cpp To draw an M
// 
// Author: Thomas Frow
// Date:   25/09/2013
//
////////////////////////////////////////////////////////////////

//#include "stdafx.h" //Only required for windows
#include <stdlib.h>

//#include <GL/glut.h> //required for linux/Windows
#include <math.h>
#include <stdio.h>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>//only required for mac
#include "cube.h"


void drawM() {

glPushMatrix();

glTranslatef(1.25,0,0);
	//Draw left vertical of M.
	glPushMatrix();
		glTranslatef(-1.25,0,0);
		//glRotatef(1,90,0,0);
		glScalef(0.5,3,0.5);
		draw3DCube();
	glPopMatrix();
	//left diagonal
	glPushMatrix();
		glTranslatef(-0.65,0.80,0);
		glRotatef(45,0,0,1);
		glScalef(0.5,1.5,0.5);
		draw3DCube();
	glPopMatrix();
	//right diagonal
	glPushMatrix();
		glTranslatef(0.5,0.65,0);
		glRotatef(135,0,0,1);
		glScalef(0.5,1.9,0.5);
		draw3DCube();
	glPopMatrix();
	
	//Draw right vertical of M.
	glPushMatrix();
		glTranslatef(1.25,0,0);
		//glRotatef(1,90,0,0);
		glScalef(0.5,3,0.5);
		draw3DCube();
	glPopMatrix();
	
glPopMatrix();
	
}
