////////////////////////////////////////////////////////////////
//
// Draw_Body.cpp To draw a Body
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
#include "Resources/drawMM.h"
#include "Resources/drawT.h"
#include "Resources/drawM.h"
#include "Resources/drawF.h"

void drawBody() {

	glPushMatrix();
		glRotatef(0, 0.0, 0.0, 1.0);
		glScalef(1.0, 1.0, 1.0);
		drawMM();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(1.25, 0.0, 0.0);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(1.0, 1.0, 1.0);
		drawM();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-1.5, 0.5, 0.0);
		glRotatef(0, 0.0, 0.0, 1.0);
		glScalef(1.0, 1.0, 1.0);
		drawT();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(1.5, -0.5, 0.0);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(1.0, 1.0, 1.0);
		drawT();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.2, -0.5, 0.0);
		glRotatef(180, 0.0, 1.0, 0.0);
		glScalef(1.0, 1.0, 1.0);
		drawF();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0, -0.5, 0.0);
		//glRotatef(0.0,0.0, 0.0, 1.0);
		glScalef(1.0, 0.9, 1.0);
		drawF();
	glPopMatrix();
}
