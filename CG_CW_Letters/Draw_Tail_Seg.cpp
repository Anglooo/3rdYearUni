////////////////////////////////////////////////////////////////
//
// Draw_Tail_Seg.cpp
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

void drawTailSeg() {

	glPushMatrix();
		//glRotatef(0, 0.0, 0.0, 1.0);
		//glTranslatef(-0.38, -0.7, 0.0);
		glScalef(0.25, 0.05, 0.5);
		drawT();
	glPopMatrix();
	
}
