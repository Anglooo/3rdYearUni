////////////////////////////////////////////////////////////////
//
// Draw_Tail.cpp: To draw the tail
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
#include "Draw_Tail_Seg.h"
 

void drawTail(double tailAngle) {
	
glPushMatrix();

	glPushMatrix();
	glRotatef(tailAngle , 1.0, 0.0, 0.0);		
		glPushMatrix();
			glTranslatef(-0.40, -0.0, 0.0);
			drawTailSeg();
		glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glRotatef(tailAngle, 1.0, 0.0, 0.0);	
		glPushMatrix();
			glTranslatef(-0.40, -0.08, 0.0);
			//glScalef(0.8, 1,1);
			drawTailSeg();
		glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(tailAngle, 1.0, 0.0, 0.0);	
		glPushMatrix();
			glTranslatef(-0.40, -0.16, 0.0);
			//glScalef(0.8, 1,1);
			drawTailSeg();
		glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(tailAngle, 1.0, 0.0, 0.0);
		glPushMatrix();
			glTranslatef(-0.40, -0.24, 0.0);
			drawTailSeg();
		glPopMatrix();
		
	glPopMatrix();
	
glPopMatrix();
	
		
}
