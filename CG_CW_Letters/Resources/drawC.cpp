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
#include "drawC.h"
#include "3DCurve.h"

void drawC() 
{
	
	double depth = 1.0;
	double r1 = 1.5;
	double r2 = 2.0;
	double theta_start = 45.0;
	double theta_stop = 315.0;
	double theta_inc = 5.0;
	
	
	draw3Dcurve(depth, r1, r2, theta_start, theta_stop, theta_inc);
	
}
