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
 

void drawTail() {
	
	glPushMatrix();
		//glRotatef(0, 0.0, 0.0, 1.0);
		glTranslatef(-0.40, -0.7, 0.0);
		//glScalef(0.8, 1,1);
		drawTailSeg();
	glPopMatrix();
	
	glPushMatrix();
		//glRotatef(0, 0.0, 0.0, 1.0);
		glTranslatef(-0.40, -0.75, 0.0);
		//glScalef(0.8, 1,1);
		drawTailSeg();
	glPopMatrix();
	
	glPushMatrix();
		//glRotatef(0, 0.0, 0.0, 1.0);
		glTranslatef(-0.40, -0.8, 0.0);
		//glScalef(0.8, 1,1);
		drawTailSeg();
	glPopMatrix();
	
	glPushMatrix();
		//glRotatef(0, 0.0, 0.0, 1.0);
		glTranslatef(-0.40, -0.85, 0.0);
		//glScalef(0.8, 1,1);
		drawTailSeg();
	glPopMatrix();


	
		
}
