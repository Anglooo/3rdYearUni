#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "drawC.h"
#include "drawD.h"
#include "drawM.h"
#include "cube.h"

//static double theta_stop1 = 270;
float pitch = 0.0f;
float yaw = 0.0f;
float pitch0, yaw0;
bool MousePressed;
int mouseX0, mouseY0;
bool rotating=false;
double counter = 0.0;

void draw3DCube();
void draw3dMC();
void draw3dD();
void draw3dCD();
void draw3dMCD();

void drawAxesAndGridLines(bool x_y_display, bool y_z_display,  bool x_z_display)
{
	glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex3f(-20, 0, 0);					
		glVertex3f(+20, 0, 0);					
		glVertex3f( 0 ,-20, 0);				    	
		glVertex3f(	0, +20, 0);
		glVertex3f( 0, 0,-20);				    	
		glVertex3f(	0, 0, +20);

	glEnd();
}

void draw3dD(){

	glRotatef(sin(counter)*-30, 1.0, 0.0, 0.0);
	drawD();

}

void draw3dCD(){

	//shuffle along the x-axis
	glTranslatef(3.5, 0.0, 0.0);
	//add another rotation
	glRotatef(sin(counter)*30, 1.0, 0.0, 0.0);
	//add rotation to matrix
	glPushMatrix();
		//draw the C
		drawC();
		//add any current transformations to the matrix
		glPushMatrix();
			glTranslatef(1.5,0,0);
			drawD();
		glPopMatrix();

	glPopMatrix();

}

void draw3dMCD(){

	//Apply scaling and rotation to entire model.
	glScalef(0.5, 0.5, 0.5);
	glRotatef(sin(counter)*20, 1.0, 0.0, 0.0);

	drawM();
	//add to the matrix
	glPushMatrix();

	draw3dCD();

	glPopMatrix();
}



void drawScene(int t)
{
	counter = counter + 0.001;
	
	draw3dMCD();
	
	glutPostRedisplay();
	
	glutTimerFunc(10, drawScene, 0);
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
	case 'i': case 'I':
		//theta_stop1+=10;
	break;
	case 'd': case 'D':
		//theta_stop1-=10;
	break;
	case 'r': 
		rotating= !rotating;
		rotateView(rotating);
	break;
	case 'R':
        resetView();
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
	//glutKeyboardFunc(keyboardCallBack);

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
	printf("Key \"R\" - Reset the View.\n");

	glutMainLoop();

	return 0;
}
