#include <iostream>
#define GL_SILENCE_DEPRECATION
#include<gl\glew.h>
#include<gl\freeglut.h>
#include<gl/glut.h>

void drawSupport() {
    for (int i = 0; i < 12; i++) {
        glColor3f(1, 1, 1);//Base Color
        float size = .5;//Ratio Size
        //For Each for Loop will create a row of the ghost Iterating down a row with each for loop.
        for (int i = 0; i < 10; i++) {
            glutSolidCube(size);
            glTranslatef(size, 0, 0);

        }
        glTranslatef(-11 * size, -size, 0);
        for (int i = 0; i < 12; i++) {
            if (i == 1 || i == 2 || i == 3 || i == 8 || i == 9 || i == 10) {
                glColor3f(0.5, .35, .05);
            }
            glutSolidCube(size);
            glTranslatef(size, 0, 0);
            glColor3f(1, 1, 1);
        }
        glTranslatef(-12 * size, -size, 0);
        for (int i = 0; i < 12; i++) {
            glutSolidCube(size);
            glTranslatef(size, 0, 0);
        }
        glTranslatef(-12 * size, -size, 0);
        for (int i = 0; i < 36; i++) {
            if (i == 1 || i == 2 || i == 3 || i == 8 || i == 9 || i == 10 || i == 13 || i == 14 || i == 15 || i == 20 || i == 21 || i == 22 || i == 25 || i == 26 || i == 27 || i == 32 || i == 33 || i == 34) {
                glColor3f(0, 0, 1);
            }
            glutSolidCube(size);
            glTranslatef(size, 0, 0);
            if (i == 11 || i == 23) {
                glTranslatef(-12 * size, -size, 0);
            }
            glColor3f(1, 1, 1);
        }
        glTranslatef(-12 * size, -size, 0);
        for (int i = 0; i < 12; i++) {
            glutSolidCube(size);
            glTranslatef(size, 0, 0);
        }
        glTranslatef(-12 * size, -size, 0);
        for (int i = 0; i < 12; i++) {
            glutSolidCube(size);
            glTranslatef(size, 0, 0);
        }
        glTranslatef(-12 * size, -size, 0);
        for (int i = 0; i < 12; i++) {
            if (i == 1 || i == 10) {
                glColor3f(1, 1, 0);
            }
            glutSolidCube(size);
            glTranslatef(size, 0, 0);
            glColor3f(1, 1, 1);
        }
        glTranslatef(-12 * size, -size, 0);
        for (int i = 0; i < 12; i++) {
            if (i == 1 || i == 10) {
                glColor3f(1, 1, 0);
            }
            glutSolidCube(size);
            glTranslatef(size, 0, 0);
            glColor3f(1, 1, 1);
        }
        glTranslatef(-12 * size, -size, 0);
        for (int i = 0; i < 12; i++) {
            if (i == 0 || i == 11) {
                glColor3f(1, 1, 1);
            }
            glutSolidCube(size);
            glTranslatef(size, 0, 0);
            glColor3f(1, 1, 0);
        }
        glColor3f(1, 1, 1);
        glTranslatef(-12 * size, -size, 0);
        for (int i = 0; i < 12; i++) {
            glutSolidCube(size);
            glTranslatef(size, 0, 0);
        }
        glTranslatef(-12 * size, -size, 0);
        for (int i = 0; i < 12; i++) {
            glutSolidCube(size);
            glTranslatef(size, 0, 0);
        }
        glTranslatef(-12 * size, -size, 0);
        for (int i = 0; i < 12; i++) {
            if (i == 0 || i == 1 || i == 2 || i == 5 || i == 6 || i == 9 | i == 10 || i == 11) {
                glutSolidCube(size);
            }
            glTranslatef(size, 0, 0);
        }

        glTranslatef(-11 * size, 13 * size, -size);
    }
}