#pragma once
#define GL_SILENCE_DEPRECATION
#include <gl\glew.h>
#include <gl\freeglut.h>
#include <gl/glut.h>
const double ROW = -.4; // Variable that sets the x-row value.

//int angle = 0;

void displayGhost() {

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