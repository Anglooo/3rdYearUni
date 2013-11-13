////////////////////////////////////////////////////////////////
//
// Draw_Wing_Pt1.cpp To draw Wing part 1
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
#include "Resources/drawT.h"
#include "Resources/drawF.h"


void drawWingPt1() {

glTranslatef(0.0, 0.0, 0.0);
glRotatef(90, 0.0, 0.0, 1.0);
glScalef(1, 1, 1);

glPushMatrix();

	glPushMatrix();//top half
		
		//transformations to whole graphic.
		glTranslatef(0.075, 0, 0.0);
		glRotatef(0.0, 0.0, 0.0, 0.0);
		glScalef(0.2, 0.2, 0.2);

		float x = 0.0;

		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;	

		glPopMatrix();

		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;	

		glPopMatrix();


		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;	

		glPopMatrix();	

		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;	

		glPopMatrix();

		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;

		glPopMatrix();

		glPushMatrix();//T

			glTranslatef(x+0.1, 0.65, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 0.6, 1.0);
			drawT();
			x = x + 1.5;	

		glPopMatrix();

	glPopMatrix();
	//BREAK HERE --------------------------------------------------------------------
	glPushMatrix();
		
		//transformations to whole graphic.
		glTranslatef(1.95, 0.4, 0.0);
		glRotatef(240, 0.0, 0.0, 1.0);
		glScalef(0.2, 0.2, 0.2);

		 x = 0.0;

		glPushMatrix();//T

			glTranslatef(x+0.1, 0.65, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 0.6, 1.0);
			drawT();
			x = x + 1.5;	

		glPopMatrix();

		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;

		glPopMatrix();

		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;

		glPopMatrix();

		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;

		glPopMatrix();

		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;	

		glPopMatrix();

	glPopMatrix();
	//BREAK HERE ---------------------------------------------------------------------------------------
	glPushMatrix();
		
		//transformations to whole graphic.
		glTranslatef(1.95, 0.4, 0.0);
		glRotatef(240, 0.0, 0.0, 1.0);
		glScalef(0.2, 0.2, 0.2);

		 x = 0.0;

		glPushMatrix();//T

			glTranslatef(x+0.1, 0.65, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 0.6, 1.0);
			drawT();
			x = x + 1.5;	

		glPopMatrix();

		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;

		glPopMatrix();

		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;

		glPopMatrix();

		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;

		glPopMatrix();

		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;	

		glPopMatrix();

	glPopMatrix();
		//BREAK HERE --------------------------------------------------------------------
		glPushMatrix();
		
		//transformations to whole graphic.
		glTranslatef(0.5, -1, 0.0);
		glRotatef(180, 0.0, 0.0, 1.0);
		glScalef(0.2, 0.2, 0.2);

		 x = 0.0;


		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			//glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;

		glPopMatrix();

		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;

		glPopMatrix();

		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;

		glPopMatrix();

		glPushMatrix();//T

			glTranslatef(x, 0, 0.0);
			glRotatef(0, 0.0, 0.0, 1.0);
			glScalef(1.0, 1.0, 1.0);
			drawT();
			x = x + 1.5;	

		glPopMatrix();

	glPopMatrix();

glPopMatrix();
}
