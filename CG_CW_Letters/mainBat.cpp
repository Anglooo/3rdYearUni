////////////////////////////////////////////////////////////////
//
// Title: mainBat.cpp
// Author: Thomas Frow & Mark Calderwood
// Date:   30/10/13
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
#include "Draw_Animal.h"
#include "Draw_Body.h"
#include "Draw_Whole_Wing.h"
#include "Draw_Tail.h"
#include "Draw_Head.h"



//static double theta_stop1 = 270;
float pitch = 0.0f;
float yaw = 0.0f;
float pitch0, yaw0;
bool MousePressed;
int mouseX0, mouseY0;
bool rotating=false;



bool wingMove = false;
bool tailMove = false;

bool showWhole =  true;
bool showWing = false;
bool showBody = false;
bool showHead = false;
bool showTail = false;

double wingAngle = 0;
double tailAngle = 0;
double counter = 0.0;


void tailAnimationTrigger()
{
	if(tailMove == false)
	{
		tailMove = true;
		printf("Tail Triggered");		
	}
	else
	{
		tailMove = false;
	}	
}

void wingAnimationTrigger()
{
	if(wingMove == false)
	{
		wingMove = true;
		printf("Wing Triggered");
	}
	else
	{
		wingMove = false;
	}	
}

void showWholeTrigger()
{
	if(showWhole == false)
	{
		showWhole = true;
	}
	else
	{
		showWhole = false;
	}	
}

void showWingTrigger()
{
	if(showWing == false)
	{
		showWing = true;
	}
	else
	{
		showWing = false;
	}	
}

void showBodyTrigger()
{
	if(showBody == false)
	{
		showBody = true;
	}
	else
	{
		showBody = false;
	}	
}

void showTailTrigger()
{
	if(showTail == false)
	{
		showTail = true;
	}
	else
	{
		showTail = false;
	}	
}

void showHeadTrigger()
{
	if(showHead == false)
	{
		showHead = true;
	}
	else
	{
		showHead = false;
	}	
}




void drawAxesAndGridLines(bool x_y_display, bool y_z_display,  bool x_z_display)
{
	float offset;
	glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex3f(-20, 0, 0);					
		glVertex3f(+20, 0, 0);					
		glVertex3f( 0 ,-20, 0);				    	
		glVertex3f(	0, +20, 0);
		glVertex3f( 0, 0,-20);				    	
		glVertex3f(	0, 0, +20);

	glEnd();
	
	glLineStipple(1, 0xAAAA); //line style = fine dots
	glEnable(GL_LINE_STIPPLE);

	glBegin(GL_LINES);
		
		if (x_y_display) {glColor3f(0.0,0.7,0.7);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in x-y plane
			glVertex3f(-10.0, offset, 0.0);					// Top Left
			glVertex3f(+10.0, offset, 0.0);					// Top Right
			glVertex3f( offset,-10, 0.0);					// Bottom Right
			glVertex3f(	offset,+10.0, 0.0);					// Bottom Left
		}}

		if (y_z_display) {glColor3f(0.7,0.0,0.7);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in y-z plane
			glVertex3f( 0, offset, -10);					
			glVertex3f(	0, offset, 10.0);
			glVertex3f( 0, -10, offset);					
			glVertex3f(	0, 10, offset);
		}}

		if (x_z_display) {glColor3f(0.7,0.7,0.0);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in x-z plane
			glVertex3f( offset, 0, -10);					
			glVertex3f(	offset, 0, 10.0);
			glVertex3f( -10, 0, offset);					
			glVertex3f(	10, 0, offset);
		}}

	glEnd();
	glDisable(GL_LINE_STIPPLE);
}


void drawScene(int t)
{	
	counter = counter + 0.01;
	if(counter > 10)
	{
	counter = 0;	
	}
	
	if(wingMove == true)
	{
		wingAngle = cos(counter)*30;
	}
	else
	{
			wingAngle = 0;
	}
	
	if(tailMove == true)
	{
		tailAngle = cos(counter)*10;
	}
	else
	{
			tailAngle = 0;
	}
	
	
	if(showWhole == true)
	{
		drawAnimal(wingAngle,tailAngle);
		showWing = false;
		showTail = false;
		showBody = false;
		showHead = false;
	}
	
	if(showWing == true)
	{
		drawWholeWing(wingAngle);
		showWhole = false;
	}
	
	if(showHead == true)
	{
		glPushMatrix();
			glScalef(0.5, 0.5, 0.5);

			drawHead();
		glPopMatrix();
		
		showWhole = false;
	}
	
	if(showTail == true)
	{
		drawTail(tailAngle);
		showWhole = false;
	}
	
	if(showBody == true)
	{
		drawBody();
		showWhole = false;
	}
	
	glutPostRedisplay();
	glutTimerFunc(100,drawScene, 0);
}

//Mouse Controls
void idleCallBack (){
	yaw=yaw+.25;
    glutPostRedisplay();
}

void rotateView(bool r){
	rotating = r;
	if (r) glutIdleFunc(idleCallBack); else glutIdleFunc(NULL);
}

void resetView(){
	rotateView(false); //Stop view rotation
	yaw=pitch=0;
}

void executeViewControl (float y, float p){
	glRotatef(y, 0.0f, 1.0f, 0.0f); //yaw about y-axis
    glRotatef(p, 1.0f, 0.0f, 0.0f); //pitch about x-axis 
}

void mouseClickCallBack(int button, int state, int x, int y) {
	//Called on button press or release
    switch (state)
    {
		case GLUT_DOWN:
			MousePressed = true;
			rotateView(false);
			pitch0 = pitch; yaw0 = yaw;
			mouseX0 = x; mouseY0 = y;
			break;
		default:
		case GLUT_UP:
			MousePressed = false;
			//rotateView(true);
			break;
    }
} 

void mouseMotionCallBack(int x, int y) 
{
	// Called when the Mouse is moved with left button down
    pitch = pitch0 + (y - mouseY0);
    yaw = yaw0 + (x - mouseX0);
	glutPostRedisplay();
} 

void reshapeCallBack(int w, int h) 
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	if (w == 0 || h == 0) return;
    if (w <= h) glOrtho(-3.0, 3.0, -3.0 * (GLfloat) h / (GLfloat) w, 3.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else        glOrtho(-3.0 * (GLfloat) w / (GLfloat) h, 3.0 * (GLfloat) w / (GLfloat) h, -3.0, 3.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

//======================================================
// KEYBOARD CALLBACK ROUTINE 
//======================================================
void keyboardCallBack(unsigned char key, int x, int y) {
	printf("Keyboard call back: key=%c, x=%d, y=%d\n", key, x, y);
	switch(key)
	{
	case 'b': case 'B':
		glPolygonMode(GL_BACK,GL_FILL);
	break;
	case 'f': case 'F':
		glPolygonMode(GL_FRONT,GL_FILL);
	break;
	case 'l': case 'L':
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	break;
	case 'r': 
		rotating= !rotating;
		rotateView(rotating);
	break;
	case 'R':
        resetView();
	break;
	case 'w':
        wingAnimationTrigger();
        printf("triggered Wing Animation");
	break;
	case 't':
        tailAnimationTrigger();
        printf("triggered Tail Animation");
	break;
	case 'T':
        showTailTrigger();
        printf("showing tail");
	break;
	case 'H':
        showHeadTrigger();
        printf("showing head");
	break;
	case 'W':
        showWingTrigger();
        printf("showing Wing");
	break;
	case 'p':
        showWholeTrigger();
        printf("Showing Whole Animal");
	break;
	

	default:
		printf("Press b - back fill; f - front fill; l - line; i - increment; or d - decrement; r - rotate; R - reset view\n");
	}

	glutPostRedisplay();
}
//Display Call Back
void displayCallBack()	
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	executeViewControl (yaw, pitch);
	drawAxesAndGridLines(true, true, true);
	
	drawScene(0);
	
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
   // Allow cmd line arguments to be passed to the glut
	glutInit(&argc, argv);

	// Create and name window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Need both double buffering and z buffer
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Example 8.1 - 3D Curve Example");

	// Add Display & Mouse CallBacks
	glutReshapeFunc(reshapeCallBack);
	glutDisplayFunc(displayCallBack);
	glutIdleFunc(NULL); // Starts the Idle Function as having no routine attached to it. This is modified in rotateView()
	glutMouseFunc(mouseClickCallBack);
    glutMotionFunc(mouseMotionCallBack);
	glutKeyboardFunc(keyboardCallBack);

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0,0.0,0.0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */

	// Print Application Usage
	printf("Program Controls:\n");
	printf("Left Mouse Button & Drag - Changes the View.\n");
	printf("Key \"b\" - Back Fill.\n");
	printf("Key \"f\" - Front Fill.\n");
	printf("Key \"l\" - Wire Frame/Line Fill.\n");
	printf("Key \"i\" - Increment Sections of Curve.\n");
	printf("Key \"d\" - Decrement Sections of Curve.\n");
	printf("Key \"r\" - Automated Rotation.\n");
	printf("Key \"w\" - Start and stop the wing animation\n");
	printf("Key \"t\" - Start and stop the tail animation.\n");
	printf("Key \"p\" - Show the whole animal\n");
	printf("Key \"T\" - Show just the tail\n");
	printf("Key \"H\" - Show just the head\n");
	printf("Key \"W\" - Show just the wing\n");
	printf("Key \"B\" - Show just the body\n");

	glutMainLoop();

	return 0;
}
