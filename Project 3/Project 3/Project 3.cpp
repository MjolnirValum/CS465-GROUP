
#include <iostream>
//Rian Cervantes
#include <gl\glew.h>
#include <gl/glut.h>
#include <gl\freeglut.h>
#include <gl\GL.h>

//#include <GLUT/GLUT.h>  // for Mac
#define GL_SILENCE_DEPRECATION
const double ROW = -.4; // Variable that sets the x-row value.

int angle = 0;

void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();



	double x = ROW;
	//16x16 Space is created with these For loops although only the spaces that require cubes are filled in. 
	//3 spaces are purposefully left "blank" on each side to leave room for animation for when the ghost will go Angry
	for (int i = 0; i < 16; i++) {
		//the x value is started at -.4. if i is not in IF loop, x value has .05 added to the value. This moves the point of drawing the cube over.
		if (i == 4 || i == 5 || i == 7 || i == 8 || i == 10 || i == 11) {
			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, -.5, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);

			x = x + 0.05; //After hitting one of the i values the loop adds .05 to x value and checks for next i value. 
		}
		else {
			x = x + .05; //if i value is not hit in IF loop, x value add .05 without drawing the cube. 
		}
	}

	x = ROW; // resets X row value to -.4
	for (int i = 0; i < 16; i++) {
		if (i == 4 || i == 5 || i == 7 || i == 8 || i == 10 || i == 11) {


			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, -.45, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);
			x = x + 0.05;

		}
		else {
			x = x + .05;
		}
	}

	x = ROW;
	for (int i = 0; i < 16; i++) {
		//Creates a solid white line at 4,5,6,7,8,9,10,11. 
		if (i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 11) {
			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, -.4, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);

			x = x + .05;
		}
		else {

			x = x + .05;
		}
	}

	x = ROW;
	for (int i = 0; i < 16; i++) {
		if (i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 11) {

			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, -.35, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);

			x = x + .05;
		}
		else {

			x = x + .05;
		}
	}

	x = ROW;
	//This For loop creates the bottom of the mouth and uses a Yellow color. 
	for (int i = 0; i < 16; i++) {
		if (i == 4 || i == 11) {

			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, -.3, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);

			x = x + .05;
		}
		else if (i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10) {

			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, -.3, 0);
			glColor3f(1, 1, 0);
			glutSolidCube(.05);

			x = x + .05;

		}

		else {
			x = x + .05;
		}
	}

	x = ROW;
	for (int i = 0; i < 16; i++) {
		if (i == 4 || i == 6 || i == 7 || i == 8 || i == 9 || i == 11) {

			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, -.25, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);

			x = x + .05;
		}
		else if (i == 5 || i == 10) {

			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, -.25, 0);
			glColor3f(1, 1, 0);
			glutSolidCube(.05);

			x = x + .05;

		}

		else {
			x = x + .05;
		}
	}

	x = ROW;
	for (int i = 0; i < 16; i++) {
		if (i == 4 || i == 6 || i == 7 || i == 8 || i == 9 || i == 11) {

			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, -.2, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);

			x = x + .05;
		}
		else if (i == 5 || i == 10) {

			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, -.2, 0);
			glColor3f(1, 1, 0);
			glutSolidCube(.05);

			x = x + .05;

		}

		else {
			x = x + .05;
		}
	}

	x = ROW;
	for (int i = 0; i < 16; i++) {
		if (i == 4 || i == 6 || i == 7 || i == 8 || i == 9 || i == 11) {

			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, -.15, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);

			x = x + .05;
		}
		else if (i == 5 || i == 10) {

			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, -.15, 0);
			glColor3f(1, 1, 0);
			glutSolidCube(.05);

			x = x + .05;

		}

		else {
			x = x + .05;
		}
	}

	x = ROW;
	for (int i = 0; i < 16; i++) {
		if (i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 11) {
			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, -.1, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);

			x = x + .05;
		}
		else {

			x = x + .05;
		}
	}

	x = ROW;
	for (int i = 0; i < 16; i++) {
		if (i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 11) {
			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, -.05, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);

			x = x + .05;
		}
		else {

			x = x + .05;
		}
	}

	x = ROW;
	//Creates the start of the Blue eyes of the ghost that will go Red during animation. 
	for (int i = 0; i < 16; i++) {
		if (i == 4 || i == 7 || i == 8 || i == 11) {
			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, 0, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);

			x = x + .05;
		}
		else if (i == 5 || i == 6 || i == 9 || i == 10) {
			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, 0, 0);
			glColor3f(0, .5, 1);
			glutSolidCube(.05);

			x = x + .05;
		}

		else {
			x = x + .05;
		}
	}

	x = ROW;
	for (int i = 0; i < 16; i++) {
		if (i == 4 || i == 7 || i == 8 || i == 11) {
			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, .05, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);

			x = x + .05;
		}
		else if (i == 5 || i == 6 || i == 9 || i == 10) {
			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, .05, 0);
			glColor3f(0, .5, 1);
			glutSolidCube(.05);

			x = x + .05;
		}

		else {
			x = x + .05;
		}
	}

	x = ROW;
	for (int i = 0; i < 16; i++) {
		if (i == 4 || i == 7 || i == 8 || i == 11) {
			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, .1, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);

			x = x + .05;
		}
		else if (i == 5 || i == 6 || i == 9 || i == 10) {
			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, .1, 0);
			glColor3f(0, .5, 1);
			glutSolidCube(.05);

			x = x + .05;

		}

		else {
			x = x + .05;
		}
	}

	x = ROW;
	for (int i = 0; i < 16; i++) {
		if (i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 11) {
			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, .15, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);

			x = x + .05;
		}
		else {

			x = x + .05;
		}
	}

	x = ROW;
	//Creates the Brown colored eyebrows 
	for (int i = 0; i < 16; i++) {
		if (i == 4 || i == 7 || i == 8 || i == 11) {
			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, .2, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);

			x = x + .05;
		}
		else if (i == 5 || i == 6 || i == 9 || i == 10) {
			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, .2, 0);
			glColor3f(0.5, .35, .05);
			glutSolidCube(.05);

			x = x + .05;

		}

		else {
			x = x + .05;
		}
	}

	x = ROW;
	for (int i = 0; i < 16; i++) {
		if (i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10) {
			glLoadIdentity();
			glRotatef(angle, 0, 1, 0);
			glTranslatef(x, .25, 0);
			glColor3f(1, 1, 1);
			glutSolidCube(.05);

			x = x + .05;
		}
		else {

			x = x + .05;
		}
	}


	glutSwapBuffers();
}
void idle() {
	angle++;
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("GhostFriend");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glEnable(GL_DEPTH);
	glutMainLoop();
	return 0;

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
