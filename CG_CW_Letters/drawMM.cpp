////////////////////////////////////////////////////////////////
//
// Model for D
// 
// Author: Mark Calderwood
// Date:   18/09/2013
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
#include "drawMM.h"



void drawMM() 
{
	glPushMatrix();
			glTranslatef(-1.31, 0.0, 0.0);
			glRotatef(0.0, 0.0, 0.0, 1.0);
			glScalef(0.5, 4.0, 1.0);
			draw3DCube();
	glPopMatrix();
	
	glPushMatrix();
			glTranslatef(1.31, 0.0, 0.0);
			glRotatef(0.0, 0.0, 0.0, 1.0);
			glScalef(0.5, 4.0, 1.0);
			draw3DCube();
	glPopMatrix();
	
	glPushMatrix();
			glTranslatef(-0.54, 1.13, 0.0);
			glRotatef(45.0, 0.0, 0.0, 1.0);
			glScalef(0.5, 2.0, 1.0);
			draw3DCube();
	glPopMatrix();
	
	glPushMatrix();
			glTranslatef(0.54, 1.13, 0.0);
			glRotatef(135.0, 0.0, 0.0, 1.0);
			glScalef(0.5, 2.0, 1.0);
			draw3DCube();
	glPopMatrix();
		
	

}
