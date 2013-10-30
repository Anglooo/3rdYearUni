////////////////////////////////////////////////////////////////
//
// Model for D
// 
// Author: Mark Calderwood
// Date:   18/09/2013
//
////////////////////////////////////////////////////////////////

//#include "stdafx.h" //Only required for windows
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "drawM.h"
#include "cube.h"


void drawM() 
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
