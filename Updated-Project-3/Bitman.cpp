//
//  Bitman.cpp
//  Code Testing
//
//  Created by Brandon Schmick on 2/26/20.
//  Copyright © 2020 Brandon Schmick. All rights reserved.
//

//#include "Bitman.h"
#include <iostream>
#define GL_SILENCE_DEPRECATION
#include<gl\glew.h>
#include<gl\freeglut.h>
#include<gl/glut.h>

//#include <GLUT/GLUT.h>
GLfloat sizeBitman = .5; //Universal Size Ration
int angleBitman = 0; //Global rotation angleBitman
void displayBitman(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Clear Screen
    glLoadIdentity();//Adjust for animation
    glRotatef(angleBitman, 0, 1, 0);//Rotate around Y axis
    glTranslatef(-2.5*sizeBitman,4*sizeBitman,0);//Adjust window for sizeBitman
    //Make the Upper Bulbs
    glColor3f(0, .5, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(-sizeBitman, -sizeBitman, 0);
    //Second Layer
    for(int i = 0; i < 3; i++){
        glutSolidCube(sizeBitman);
        glTranslatef(sizeBitman, 0, 0);
    }
    glTranslatef(0, -sizeBitman, 0);
    //Third Layer
    for(int i = 0; i < 5; i++){
        glutSolidCube(sizeBitman);
        glTranslatef(-sizeBitman, 0, 0);
    }
    //reset for second bulb
    glTranslatef(8*sizeBitman, 2*sizeBitman, 0);
    glutSolidCube(sizeBitman);
       glTranslatef(-sizeBitman, -sizeBitman, 0);
       for(int i = 0; i < 3; i++){
           glutSolidCube(sizeBitman);
           glTranslatef(sizeBitman, 0, 0);
       }
       glTranslatef(0, -sizeBitman, 0);
       for(int i = 0; i < 5; i++){
           glutSolidCube(sizeBitman);
           glTranslatef(-sizeBitman, 0, 0);
       }

    //Create Body
    glTranslatef(-4*sizeBitman , -sizeBitman, 0);
    glColor3f(0.5,0,.8 );
    //Create layout of main body piece
    for(int i = 0; i < 10; i++){
        glutSolidCube(sizeBitman);
        glTranslatef(sizeBitman, 0, 0);
    }
    glTranslatef(-sizeBitman,-sizeBitman,0);
    for(int i = 2; i < 12; i++){
        if(i == 3 || i == 4 || i == 9|| i == 10 ){
            glColor3f(.5,0,0);//Red eyes
        }
        glutSolidCube(sizeBitman);
        glTranslatef(-sizeBitman, 0, 0);
        glColor3f(0.5, 0, .8);
    }
    glTranslatef(sizeBitman, -sizeBitman, 0);
    glColor3f(.5,0,.8 );
    for(int i = 0; i < 10; i++){
        if(i == 1 || i == 8){
            glColor3f(.5,0,0);//Red Eyes
        }
        if(i == 2 || i == 7){
            glColor3f(1,1,1);//Pupils
        }
        glutSolidCube(sizeBitman);
        glTranslatef(sizeBitman, 0, 0);
        glColor3f(0.5, 0, .8 );
    }
    glTranslatef(-sizeBitman, -sizeBitman, 0);
    for(int i = 0; i < 10; i++){
        glutSolidCube(sizeBitman);
        glTranslatef(-sizeBitman,0,0);
        glColor3f(0.5,0,.8);
    }
    //Left Leg
    glTranslatef(sizeBitman, -sizeBitman, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(sizeBitman, 0, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(0, -sizeBitman, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(-sizeBitman, 0, 0);
    glutSolidCube(sizeBitman);
    //Right Leg
    glTranslatef(8*sizeBitman,0,0);
    glutSolidCube(sizeBitman);
    glTranslatef(sizeBitman, 0, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(0, sizeBitman, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(-sizeBitman, 0, 0);
    glutSolidCube(sizeBitman);
    glFlush();
    }
void displayBitman2(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glRotatef(angleBitman, 0, 1, 0);
        glTranslatef(-1.25*sizeBitman,4*sizeBitman,0);//Adjust for centering on screen across all three animations.
        //Make the Bulbs
        glColor3f(0, .5, 0);
        glutSolidCube(sizeBitman);
        glTranslatef(-sizeBitman, -sizeBitman, 0);

        for(int i = 0; i < 3; i++){
            glutSolidCube(sizeBitman);
            glTranslatef(sizeBitman, 0, 0);
        }
        glTranslatef(0, -sizeBitman, 0);
        for(int i = 0; i < 5; i++){
            glutSolidCube(sizeBitman);
            glTranslatef(-sizeBitman, 0, 0);
        }
        glColor3f(0.5,0,.8 );
        glTranslatef(-sizeBitman, -sizeBitman, 0);
        //Creates the body
        for(int i = 0; i < 36; i++){
            glutSolidCube(sizeBitman);
            glTranslatef(sizeBitman, 0, 0);
            if(i == 8 || i == 17 || i == 26){
                glTranslatef(-9*sizeBitman, -sizeBitman, 0);
            }
        }
        //Creates Front Leg
        glTranslatef(-sizeBitman, -sizeBitman, 0);
        glutSolidCube(sizeBitman);
        glTranslatef(-sizeBitman, 0, 0);
        glutSolidCube(sizeBitman);
        
        glTranslatef(0, -sizeBitman, 0);
        glutSolidCube(sizeBitman);
        glTranslatef(sizeBitman, 0, 0);
        glutSolidCube(sizeBitman);
        //Create Back Leg
        glTranslatef(-6*sizeBitman, 2*sizeBitman, 0);
        glTranslatef(-sizeBitman, -sizeBitman, 0);
        glutSolidCube(sizeBitman);
        glTranslatef(-sizeBitman, 0, 0);
        glutSolidCube(sizeBitman);
        
        glTranslatef(0, -sizeBitman, 0);
        glutSolidCube(sizeBitman);
        glTranslatef(sizeBitman, 0, 0);
        glutSolidCube(sizeBitman);
        
        glFlush();
    }
void displayBitman3(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(angleBitman, 0, 1, 0);
    glTranslatef(-1.25*sizeBitman,4*sizeBitman,0);//Adjust for centering
    //Make the Bulb
    glColor3f(0, .5, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(-sizeBitman, -sizeBitman, 0);
    for(int i = 0; i < 3; i++){
        glutSolidCube(sizeBitman);
        glTranslatef(sizeBitman, 0, 0);
    }
    glTranslatef(0, -sizeBitman, 0);
    for(int i = 0; i < 5; i++){
        glutSolidCube(sizeBitman);
        glTranslatef(-sizeBitman, 0, 0);
    }
    glColor3f(0.5,0,.8 );
    glTranslatef(-sizeBitman, -sizeBitman, 0);
    //Creates the body.
    for(int i = 0; i < 36; i++){
        glutSolidCube(sizeBitman);
        glTranslatef(sizeBitman, 0, 0);
        if(i == 8 || i == 17 || i == 26){
            glTranslatef(-9*sizeBitman, -sizeBitman, 0);
        }
    }
    //Legs
    glTranslatef(-sizeBitman, -sizeBitman, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(-sizeBitman, 0, 0);
    glutSolidCube(sizeBitman);

    glTranslatef(0, -sizeBitman, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(sizeBitman, 0, 0);
    glutSolidCube(sizeBitman);

    glTranslatef(-6*sizeBitman, 2*sizeBitman, 0);
    glTranslatef(-sizeBitman, -sizeBitman, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(-sizeBitman, 0, 0);
    glutSolidCube(sizeBitman);

    glTranslatef(0, -sizeBitman, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(sizeBitman, 0, 0);
    glutSolidCube(sizeBitman);

    glTranslatef(3*sizeBitman, 9*sizeBitman, 0);//return to top
    //Smoke coming out of back
    glColor3f(.75, .75, .75);
    glutSolidCube(sizeBitman);
    glTranslatef(-sizeBitman, sizeBitman, 0);
    for(int i =0; i<3; i++){
        glutSolidCube(sizeBitman);
        glTranslatef(sizeBitman, 0, 0);
    }
    glTranslatef(-4*sizeBitman, sizeBitman, 0);
    for(int i =0; i<5; i++){
        glutSolidCube(sizeBitman);
        glTranslatef(sizeBitman, 0, 0);
    }
        glFlush();
    }

void displayBitman4() {
    GLfloat sizeBitman = 1; //Universal Size Rations
    glRotatef(angleBitman, 0, 1, 0);//Rotate around Y axis
    //Make the Upper Bulbs
    glColor3f(0, .5, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(-sizeBitman, -sizeBitman, 0);
    //Second Layer
    for (int i = 0; i < 3; i++) {
        glutSolidCube(sizeBitman);
        glTranslatef(sizeBitman, 0, 0);
    }
    glTranslatef(0, -sizeBitman, 0);
    //Third Layer
    for (int i = 0; i < 5; i++) {
        glutSolidCube(sizeBitman);
        glTranslatef(-sizeBitman, 0, 0);
    }
    //reset for second bulb
    glTranslatef(8 * sizeBitman, 2 * sizeBitman, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(-sizeBitman, -sizeBitman, 0);
    for (int i = 0; i < 3; i++) {
        glutSolidCube(sizeBitman);
        glTranslatef(sizeBitman, 0, 0);
    }
    glTranslatef(0, -sizeBitman, 0);
    for (int i = 0; i < 5; i++) {
        glutSolidCube(sizeBitman);
        glTranslatef(-sizeBitman, 0, 0);
    }

    //Create Body
    glTranslatef(-4 * sizeBitman, -sizeBitman, 0);
    glColor3f(0.5, 0, .8);
    //Create layout of main body piece
    for (int i = 0; i < 10; i++) {
        glutSolidCube(sizeBitman);
        glTranslatef(sizeBitman, 0, 0);
    }
    glTranslatef(-sizeBitman, -sizeBitman, 0);
    for (int i = 2; i < 12; i++) {
        if (i == 3 || i == 4 || i == 9 || i == 10) {
            glColor3f(.5, 0, 0);//Red eyes
        }
        glutSolidCube(sizeBitman);
        glTranslatef(-sizeBitman, 0, 0);
        glColor3f(0.5, 0, .8);
    }
    glTranslatef(sizeBitman, -sizeBitman, 0);
    glColor3f(.5, 0, .8);
    for (int i = 0; i < 10; i++) {
        if (i == 1 || i == 8) {
            glColor3f(.5, 0, 0);//Red Eyes
        }
        if (i == 2 || i == 7) {
            glColor3f(1, 1, 1);//Pupils
        }
        glutSolidCube(sizeBitman);
        glTranslatef(sizeBitman, 0, 0);
        glColor3f(0.5, 0, .8);
    }
    glTranslatef(-sizeBitman, -sizeBitman, 0);
    for (int i = 0; i < 10; i++) {
        glutSolidCube(sizeBitman);
        glTranslatef(-sizeBitman, 0, 0);
        glColor3f(0.5, 0, .8);
    }
    //Left Leg
    glTranslatef(sizeBitman, -sizeBitman, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(sizeBitman, 0, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(0, -sizeBitman, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(-sizeBitman, 0, 0);
    glutSolidCube(sizeBitman);
    //Right Leg
    glTranslatef(8 * sizeBitman, 0, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(sizeBitman, 0, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(0, sizeBitman, 0);
    glutSolidCube(sizeBitman);
    glTranslatef(-sizeBitman, 0, 0);
    glutSolidCube(sizeBitman);
}
/*void init(){
    glMatrixMode(GL_PROJECTION);
    glOrtho(-5,5,-5,5,-5,5);//Set Window from -5 to 5 on XYZ
    glMatrixMode(GL_MODELVIEW);
}*/
void idleBitman(void){ //new part, an idle function, runs when nothing else is happening
    angleBitman++; //Increment the angleBitman
    angleBitman %=360; // keep angleBitman between 0-360
    glutPostRedisplay();
}
void timerFunctionBitman(int value){
    if(value == 0){
        glutDisplayFunc(displayBitman);
        glutIdleFunc(idleBitman);
        glutTimerFunc(5000, timerFunctionBitman, 1);
    }
    if(value == 1){
        glutDisplayFunc(displayBitman2);
        glutIdleFunc(idleBitman);
        glutTimerFunc(5000, timerFunctionBitman, 2);
    }
    if(value == 2){
        glutDisplayFunc(displayBitman3);
        glutIdleFunc(idleBitman);
        glutTimerFunc(5000, timerFunctionBitman, 0);
    }
}
/*int main(int argc,  char * argv[]) {
    glutInit(&argc, argv);
    glutCreateWindow("BitMan");
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(displayBitman);
    glutIdleFunc(idle);
    glutTimerFunc(5000, timerFunction, 1);
    init();
    glutMainLoop();
    return 0;
}*/

 
