/*
    CS465G, Spring 2020
    "Been through the desert lab"
    Code sourced from Dr. Ehrlich
    Original source believed to be from OpenGL SuperBible (Wright, Lipchak, Haemel, 4th ed)
 */

#include <math.h>
#include <iostream>
#include <gl\glew.h>
#include <gl\freeglut.h>
#include <gl/GL.h>

#define GL_SILENCE_DEPRECATION
#define PI 3.14159265

// camera movement states: rotations
bool lookUp;
bool lookDown;
bool lookLeft;
bool lookRight;
// camera movement states: translation
bool walkForward;
bool walkBackward;
bool strafeLeft;
bool strafeRight;
// camera state in the model
float xCameraLocation;
float yCameraLocation;
float zCameraLocation;
float yRotationAngle;
float zRotationAngle;
float xRotationAngle;

float forwardMovement = 1.0f;

// Called to draw scene
void display(void)
{
	GLfloat horizontalMovement=1;
	GLfloat verticalMovement=0;
	horizontalMovement=cos(xRotationAngle*PI/180);
	verticalMovement=-sin(xRotationAngle*PI/180);

	// Reset Model view matrix stack
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
    // rotatte and translate camera
	glRotatef(-xRotationAngle, 1, 0, 0);
	glRotatef(yRotationAngle, 0, 1, 0);
	glTranslatef(-xCameraLocation, -yCameraLocation, -zCameraLocation);

    // initial camera position
	glTranslatef(0,-0.50,-10);
	
    // draw both sides of polygons, fill them in
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT);
    
    // draw the coordinate axes
	glColor3f(0,0,0);
	glLineWidth(2);
	glBegin(GL_LINES);
		//x
		glColor3f(1,0,0);
		glVertex3f(-10,0,0);
		glVertex3f(10,0,0);
		
		//y
		glColor3f(0,1,0);
		glVertex3f(0,-10,0);
		glVertex3f(0,10,0);

		//z
		glColor3f(0,0,1);
		glVertex3f(0,0,-10);
		glVertex3f(0,0,10);
	glEnd();
	
	// draw the desert
	glColor3ub(250, 223, 173);
	glBegin(GL_QUADS);
		for (int i=-100;i<=100;i+=10)
			for (int j=-100;j<=100;j+=10)
			{
				glVertex3f(i+10,0,j);
				glVertex3f(i,0,j);
				glVertex3f(i,0,j+10);
				glVertex3f(i+10,0,j+10);
			}
	glEnd();


	// draw the pyramid
	glColor3ub(210, 180, 140);
	glBegin(GL_TRIANGLES);
		glVertex3f(0,5,0);
		glVertex3f(-5,0,-5);
		glVertex3f(5,0,-5);

		glVertex3f(0,5,0);
		glVertex3f(-5,0,-5);
		glVertex3f(-5,0,5);

		glVertex3f(0,5,0);
		glVertex3f(-5,0,5);
		glVertex3f(5,0,5);

		glVertex3f(0,5,0);
		glVertex3f(5,0,5);
		glVertex3f(5,0,-5);
	glEnd();

	glutSwapBuffers();
}

void timerFunction(int value)
    {
		 // Redraw the scene with new coordinates
		glutPostRedisplay();
        // recall this function after 16 ms
        // note, the last argument indicates that the variable value will be passed the int 1
        // you can have multiple timer functions and use
        // this int to determine which one needs to be processed
		glutTimerFunc(16,timerFunction, 1);
    }

// set up rendering context
void init(void)
{
	lookUp=false;
	lookDown=false;
	lookLeft=false;
	lookRight=false;
	walkForward=false;
	walkBackward=false;
	strafeLeft=false;
	strafeRight=false;
	yRotationAngle=0;
	xRotationAngle=0;
	zRotationAngle=0;

	//turn culling on -> don't draw surfaces that point away from us
	glEnable(GL_CULL_FACE);

	//turn depth test on
	glEnable(GL_DEPTH_TEST);

	// White background
	glClearColor(0.0f,0.0f, 0.0f, 1.0f );

	// Set color shading model to smooth (not really an issue here)
	glShadeModel(GL_SMOOTH);

	
}

// update the view based on the current screen size
// we will cover this later
void changeSize(int w, int h)
	{
	//GLfloat nRange = 100.0f;

	// Prevent a divide by zero
	if(h == 0)
		h = 1;

	// Set Viewport to window dimensions
    glViewport(0, 0, w, h);

	// Reset projection matrix stack
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
    GLfloat fAspect = (GLfloat)w / (GLfloat)h;
	gluPerspective(45,fAspect,0.1,1000);
	
	// Reset Model view matrix stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	
	}

// Respond to arrow keys by moving the camera frame of reference
void specialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		xRotationAngle++;
		break;
	case GLUT_KEY_DOWN:
		xRotationAngle--;
		break;
	case GLUT_KEY_LEFT:
		yRotationAngle--;
		break;
	case GLUT_KEY_RIGHT:
		yRotationAngle++;
		break;
	default:
		break;
	}
	// Refresh the Window
	glutPostRedisplay();
}


// handle keyboard entry
void keyboardFunc(unsigned char key, int x, int y)
{
    // horizontal and vertical movement
	float VM = (sin(xRotationAngle*PI / 180.0)*forwardMovement);
	float HM = (cos(xRotationAngle*PI / 180.0)*forwardMovement);

    // change in x, y, z due to this movement and camera angle
	float dX = sin(yRotationAngle*PI / 180.0) * HM;
	float dZ = -cos(yRotationAngle * PI / 180.0) * HM;
	float dY = VM;
    // a and d require y component of movement as well
	float dXSide = 0;
	float dZSide = 0;
	float dYSide = 0;

	switch (key)
	{
	case 'w':
		xCameraLocation += dX;
		yCameraLocation += dY;
		zCameraLocation += dZ;
		break;
	case 's':
		xCameraLocation -= dX;
		yCameraLocation -= dY;
		zCameraLocation -= dZ;
		break;
	case 'a':
		dXSide = sin((yRotationAngle - 90)*PI / 180.0) * 1;
		dZSide = -cos((yRotationAngle - 90) * PI / 180.0) * 1;
		dYSide = 0;
		xCameraLocation += dXSide;
		yCameraLocation += dYSide;
		zCameraLocation += dZSide;
		break;
	case 'd':
		dXSide = sin((yRotationAngle + 90)*PI / 180.0) * 1;
		dZSide = -cos((yRotationAngle + 90) * PI / 180.0) * 1;
		dYSide = 0;
		xCameraLocation += dXSide;
		yCameraLocation += dYSide;
		zCameraLocation += dZSide;
		break;
    // exit on escape key
	case 27:
		exit(0);
		break;
	default:
		break;
	}

}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500); 
 	glutCreateWindow("Been through the desert lab...");
	glutReshapeFunc(changeSize);
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboardFunc);

	glutTimerFunc(16, timerFunction, 1);
	init();
	
	glutMainLoop();
    
    return 0;
}

