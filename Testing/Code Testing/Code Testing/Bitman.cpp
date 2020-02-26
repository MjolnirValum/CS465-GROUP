//
//  Bitman.cpp
//  Code Testing
//
//  Created by Brandon Schmick on 2/26/20.
//  Copyright © 2020 Brandon Schmick. All rights reserved.
//

#include "Bitman.hpp"
#include <iostream>
#define GL_SILENCE_DEPRECATION
#include<GLUT/GLUT.h>
GLfloat size = .5; //Universal Size Ration
int angle = 0; //Global rotation angle
void displayBitman(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Clear Screen
    glLoadIdentity();//Adjust for animation
    glRotatef(angle, 0, 1, 0);//Rotate around Y axis
    glTranslatef(-2.5*size,4*size,0);//Adjust window for size
    //Make the Upper Bulbs
    glColor3f(0, .5, 0);
    glutSolidCube(size);
    glTranslatef(-size, -size, 0);
    //Second Layer
    for(int i = 0; i < 3; i++){
        glutSolidCube(size);
        glTranslatef(size, 0, 0);
    }
    glTranslatef(0, -size, 0);
    //Third Layer
    for(int i = 0; i < 5; i++){
        glutSolidCube(size);
        glTranslatef(-size, 0, 0);
    }
    //reset for second bulb
    glTranslatef(8*size, 2*size, 0);
    glutSolidCube(size);
       glTranslatef(-size, -size, 0);
       for(int i = 0; i < 3; i++){
           glutSolidCube(size);
           glTranslatef(size, 0, 0);
       }
       glTranslatef(0, -size, 0);
       for(int i = 0; i < 5; i++){
           glutSolidCube(size);
           glTranslatef(-size, 0, 0);
       }

    //Create Body
    glTranslatef(-4*size , -size, 0);
    glColor3f(0.5,0,.8 );
    //Create layout of main body piece
    for(int i = 0; i < 10; i++){
        glutSolidCube(size);
        glTranslatef(size, 0, 0);
    }
    glTranslatef(-size,-size,0);
    for(int i = 2; i < 12; i++){
        if(i == 3 || i == 4 || i == 9|| i == 10 ){
            glColor3f(.5,0,0);//Red eyes
        }
        glutSolidCube(size);
        glTranslatef(-size, 0, 0);
        glColor3f(0.5, 0, .8);
    }
    glTranslatef(size, -size, 0);
    glColor3f(.5,0,.8 );
    for(int i = 0; i < 10; i++){
        if(i == 1 || i == 8){
            glColor3f(.5,0,0);//Red Eyes
        }
        if(i == 2 || i == 7){
            glColor3f(1,1,1);//Pupils
        }
        glutSolidCube(size);
        glTranslatef(size, 0, 0);
        glColor3f(0.5, 0, .8 );
    }
    glTranslatef(-size, -size, 0);
    for(int i = 0; i < 10; i++){
        glutSolidCube(size);
        glTranslatef(-size,0,0);
        glColor3f(0.5,0,.8);
    }
    //Left Leg
    glTranslatef(size, -size, 0);
    glutSolidCube(size);
    glTranslatef(size, 0, 0);
    glutSolidCube(size);
    glTranslatef(0, -size, 0);
    glutSolidCube(size);
    glTranslatef(-size, 0, 0);
    glutSolidCube(size);
    //Right Leg
    glTranslatef(8*size,0,0);
    glutSolidCube(size);
    glTranslatef(size, 0, 0);
    glutSolidCube(size);
    glTranslatef(0, size, 0);
    glutSolidCube(size);
    glTranslatef(-size, 0, 0);
    glutSolidCube(size);
    glFlush();
    }
void displayBitman2(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glRotatef(angle, 0, 1, 0);
        glTranslatef(-1.25*size,4*size,0);//Adjust for centering on screen across all three animations.
        //Make the Bulbs
        glColor3f(0, .5, 0);
        glutSolidCube(size);
        glTranslatef(-size, -size, 0);

        for(int i = 0; i < 3; i++){
            glutSolidCube(size);
            glTranslatef(size, 0, 0);
        }
        glTranslatef(0, -size, 0);
        for(int i = 0; i < 5; i++){
            glutSolidCube(size);
            glTranslatef(-size, 0, 0);
        }
        glColor3f(0.5,0,.8 );
        glTranslatef(-size, -size, 0);
        //Creates the body
        for(int i = 0; i < 36; i++){
            glutSolidCube(size);
            glTranslatef(size, 0, 0);
            if(i == 8 || i == 17 || i == 26){
                glTranslatef(-9*size, -size, 0);
            }
        }
        //Creates Front Leg
        glTranslatef(-size, -size, 0);
        glutSolidCube(size);
        glTranslatef(-size, 0, 0);
        glutSolidCube(size);
        
        glTranslatef(0, -size, 0);
        glutSolidCube(size);
        glTranslatef(size, 0, 0);
        glutSolidCube(size);
        //Create Back Leg
        glTranslatef(-6*size, 2*size, 0);
        glTranslatef(-size, -size, 0);
        glutSolidCube(size);
        glTranslatef(-size, 0, 0);
        glutSolidCube(size);
        
        glTranslatef(0, -size, 0);
        glutSolidCube(size);
        glTranslatef(size, 0, 0);
        glutSolidCube(size);
        
        glFlush();
    }
void displayBitman3(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(angle, 0, 1, 0);
    glTranslatef(-1.25*size,4*size,0);//Adjust for centering
    //Make the Bulb
    glColor3f(0, .5, 0);
    glutSolidCube(size);
    glTranslatef(-size, -size, 0);
    for(int i = 0; i < 3; i++){
        glutSolidCube(size);
        glTranslatef(size, 0, 0);
    }
    glTranslatef(0, -size, 0);
    for(int i = 0; i < 5; i++){
        glutSolidCube(size);
        glTranslatef(-size, 0, 0);
    }
    glColor3f(0.5,0,.8 );
    glTranslatef(-size, -size, 0);
    //Creates the body.
    for(int i = 0; i < 36; i++){
        glutSolidCube(size);
        glTranslatef(size, 0, 0);
        if(i == 8 || i == 17 || i == 26){
            glTranslatef(-9*size, -size, 0);
        }
    }
    //Legs
    glTranslatef(-size, -size, 0);
    glutSolidCube(size);
    glTranslatef(-size, 0, 0);
    glutSolidCube(size);

    glTranslatef(0, -size, 0);
    glutSolidCube(size);
    glTranslatef(size, 0, 0);
    glutSolidCube(size);

    glTranslatef(-6*size, 2*size, 0);
    glTranslatef(-size, -size, 0);
    glutSolidCube(size);
    glTranslatef(-size, 0, 0);
    glutSolidCube(size);

    glTranslatef(0, -size, 0);
    glutSolidCube(size);
    glTranslatef(size, 0, 0);
    glutSolidCube(size);

    glTranslatef(3*size, 9*size, 0);//return to top
    //Smoke coming out of back
    glColor3f(.75, .75, .75);
    glutSolidCube(size);
    glTranslatef(-size, size, 0);
    for(int i =0; i<3; i++){
        glutSolidCube(size);
        glTranslatef(size, 0, 0);
    }
    glTranslatef(-4*size, size, 0);
    for(int i =0; i<5; i++){
        glutSolidCube(size);
        glTranslatef(size, 0, 0);
    }
        glFlush();
    }
void init(){
    glMatrixMode(GL_PROJECTION);
    glOrtho(-5,5,-5,5,-5,5);//Set Window from -5 to 5 on XYZ
    glMatrixMode(GL_MODELVIEW);
}
void idle(void){ //new part, an idle function, runs when nothing else is happening
    angle++; //Increment the angle
    angle %=360; // keep angle between 0-360
    glutPostRedisplay();
}
void timerFunction(int value){
    if(value == 0){
        glutDisplayFunc(displayBitman);
        glutIdleFunc(idle);
        glutTimerFunc(5000, timerFunction, 1);
    }
    if(value == 1){
        glutDisplayFunc(displayBitman2);
        glutIdleFunc(idle);
        glutTimerFunc(5000, timerFunction, 2);
    }
    if(value == 2){
        glutDisplayFunc(displayBitman3);
        glutIdleFunc(idle);
        glutTimerFunc(5000, timerFunction, 0);
    }
}
int main(int argc,  char * argv[]) {
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
}

 
