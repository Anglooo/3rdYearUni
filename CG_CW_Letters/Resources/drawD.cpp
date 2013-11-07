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
#include "drawD.h"



void drawD() 
{
	// Function to draw 3D curve 
	// depth = depth centred round z=0
	// r1 = inner radius
	// r2 = outer radius
	// theta_start = start angle in degrees measured from x-axis
	// theta_stop = similar 
	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glScalef(1.0, 1.0, 1.0);
	
	double depth = 1.0;
	double r1 = 1.5;
	double r2 = 2.0;
	double theta_start = 90.0;
	double theta_stop = 270.0;
	double theta_inc = 5.0;
	
	double x, y, x1, x2, y1, y2, z, thet, z_front, z_back;
	int i=0;
	double radius=1.5, c=3.14159/180.0;
	z_front=depth/2; z_back=-depth/2;
	
	// draw rear face (away from viewer)
	glColor3f(0.0,0.0,0.0);
	z=z_back;
	glBegin(GL_QUAD_STRIP);
	for(thet=theta_start; thet<=theta_stop;thet+=theta_inc) {
		x=cos(c*thet)*r2; y=sin(c*thet)*r2; glVertex3d(x,y,z);
		x=cos(c*thet)*r1; y=sin(c*thet)*r1; glVertex3d(x,y,z);
	}
	glEnd();

	// draw front face (closer to viewer)
	glColor3f(0.0,0.0,0.0);
	z=z_front;
	glBegin(GL_QUAD_STRIP);
	for(thet=theta_start; thet<=theta_stop;thet+=theta_inc)	{
		x=cos(c*thet)*r1; y=sin(c*thet)*r1; glVertex3d(x,y,z);
		x=cos(c*thet)*r2; y=sin(c*thet)*r2; glVertex3d(x,y,z);
	}
	glEnd();

	// draw upper face
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_QUAD_STRIP);
	for(thet=theta_start; thet<=theta_stop;thet+=theta_inc) {
		x=cos(c*thet)*r2; y=sin(c*thet)*r2;
		z=z_front; glVertex3d(x,y,z);
		z=z_back;  glVertex3d(x,y,z);
	}
	glEnd();

	// draw lower face
	glBegin(GL_QUAD_STRIP);
	for(thet=theta_start; thet<=theta_stop;thet+=theta_inc)	{
		x=cos(c*thet)*r1; y=sin(c*thet)*r1;
		z=z_back; glVertex3d(x,y,z);
		z=z_front; glVertex3d(x,y,z);
	}
	glEnd();

	// draw bottom end - Fixed by Tom Methven (31/08/2012)
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		x1=cos(c*theta_start)*r1; y1=sin(c*theta_start)*r1;
		x2=cos(c*theta_start)*r2; y2=sin(c*theta_start)*r2;

		glVertex3d(x1,y1,z_front);
		glVertex3d(x2,y2,z_front);
		glVertex3d(x2,y2,z_back);
		glVertex3d(x1,y1,z_back);
	glEnd();

	// draw top end
	glBegin(GL_POLYGON);
		x1=cos(c*theta_stop)*r1; y1=sin(c*theta_stop)*r1;
		x2=cos(c*theta_stop)*r2; y2=sin(c*theta_stop)*r2;

		glVertex3d(x1,y1,z_front);
		glVertex3d(x2,y2,z_front);
		glVertex3d(x2,y2,z_back);
		glVertex3d(x1,y1,z_back);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
			glTranslatef(-0.25, 0.0, 0.0);
			glRotatef(0.0, 0.0, 0.0, 1.0);
			glScalef(0.5, 4.0, 1.0);
			draw3DCube();
	glPopMatrix();
		
	

}
