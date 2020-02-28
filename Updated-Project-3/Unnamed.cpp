//
//  main.cpp
//  Project 1
//
//  Created by Clayton Johnsen on 2/6/20.
//  Copyright © 2020 Clayton C. Johnsen. All rights reserved.
//

//#include <GLUT/GLUT.h>  //this was for MAC OS X
#include <iostream>
#define GL_SILENCE_DEPRECATION
#include<gl\glew.h>
#include<gl\freeglut.h>
#include<gl/glut.h>


/*
 07FEB20 @ 0110
 Creating the arrays for each part and its location separately, but defined to begin with.
 
            *****NOTE TO PROFESSOR*****
 Not sure if this is better or not, please let me know if I fail to ask!
            ***************************

 07FEB20 @ 0116
                *****NOTE TO SELF*****
 Wondering if I should make all the cubes the same size.....at the moment I do not have the luxury of time so I will make them the same size for their respective parts, but if the updated version is allowed I will be able to add in more detail
                **********************
 
 07FEB20 @ 0159
 In realizing I could just use excel to meet the 16x16 requirements (which I won't be sure until I know afterwards), I made a 16x6 borded inside and out area.  I then took a screenshot using Alt+PrtScrn and pasted it into Paint.  I then started selecting different colors until I got what I wanted.
 
 Below are the colors and a link to the picture I can reference if I am away from my PC:
 https://drive.google.com/file/d/1FKQgEVJ8AVwi3Iy8er-Qx_8HMoj9sHun/view?usp=sharing
 
 COLORS (RGB):
    HOOD            17,17,17
    EYE             147,0,0
    NECKLACE        192,192,192
    PENDANT         72,196,210
    OUTFIT BASE     0,0,47
    OUTFIT LINER    212,175,55
    BELT            48,48,48
    BUCKLE          192,192,192
    HANDS (FLESH)   237,232,226
    MAHJI           32,255,255
    SHOES           81,40,0
 
                    *****NOTE*****
 Now, this information being here, for future thinking,
 I'm wondering if I should create the different arrays
 for each body area ensuring that the feet would be 3D
 by protruding when rotated and connected by referencing
 the first set in the array above it (essentially making
 sure they never break)
                    **************
 
 07FEB20 @ 0224
 Setting the colors as arrays which will make it easier
 to implement.
 
 07FEB20 @ 0233
 Setting the size of ALL cubes to be the same to get a
 baseline.  More detail to come in the updated version
 (again, if allowed).
 
 07FEB20 @ 1955
 Just finished tidying up the program after figuring out
 that sizeof(array) returns a byte, but
 sizeof(array)/sizeof(array[0]) returns the size of the
 array in int form.
 
 07FEB20 @ 2108
 Went piece-by-piece and discovered minor errors in my
 math.
 
 PROJECT 1, COMPLETE.
 */

double cube = 0.09;
/*
 keeping this around just in case ints become a thing somehow
int HOOD [3] = { 17,17,17 };
int EYE [3] = { 147,0,0 };
int NECKLACE [3] = { 192,192,192 };
int PENDANT [3] = { 72,196,210 };
int OUTFIT_BASE [3] = { 0,0,47 };
int OUTFIT_LINER [3] = { 212,175,55 };
int BELT [3] = { 48,48,48 };
int BUCKLE [3] = { 192,192,192 };
int HANDS [3] = { 237,232,226 };
int MAHJI [3] = { 32,255,255 };
int SHOES [3] = { 81,40,0 };
*/

float HOOD [3] = { 17/255.0,17/255.0,17/255.0 };
float EYE [3] = { 147/255.0,0/255.0,0/255.0 };
float NECKLACE [3] = { 192/255.0,192/255.0,192/255.0 };
float PENDANT [3] = { 72/255.0,196/255.0,210/255.0 };
float OUTFIT_BASE [3] = { 0/255.0,0/255.0,47/255.0 };
float OUTFIT_LINER [3] = { 212/255.0,175/255.0,55/255.0 };
float BELT [3] = { 48/255.0,48/255.0,48/255.0 };
float BUCKLE [3] = { 192/255.0,192/255.0,192/255.0 };
float HANDS [3] = { 237/255.0,232/255.0,226/255.0 };
float MAHJI [3] = { 32/255.0,255/255.0,255/255.0 };
float SHOES [3] = { 81/255.0,40/255.0,0/255.0 };

/*
 these body arrays will work in this order when called:
        LEFT LEG
        RIGHT LEG
        GROIN
        TORSO
        LEFT ARM
        RIGHT ARM
        HEAD
 going up until it reaches its higher limit, then right
 once, and back down until it reaches its lower limit; repeat the process for each part starting in the bottom left
 */

//"head" contains the colors HOOD and EYE
float head [9][3] =
    {
        HOOD[0],HOOD[1],HOOD[2],
        HOOD[0],HOOD[1],HOOD[2],
        HOOD[0],HOOD[1],HOOD[2],
        HOOD[0],HOOD[1],HOOD[2],
        HOOD[0],HOOD[1],HOOD[2],
        HOOD[0],HOOD[1],HOOD[2],
        HOOD[0],HOOD[1],HOOD[2],
        HOOD[0],HOOD[1],HOOD[2],
        EYE[0],EYE[1],EYE[2]
    };
float headLoc [9][3] =
    {
        -.45,.54,0,//starting with hood, BOT-L going clockwise, ending with the eye
        0,.09,0,
        0,.09,0,
        .09,0,0,
        .09,0,0,
        0,-.09,0,
        0,-.09,0,
        -.09,0,0,
        0,.09,0//eye
    };

//"rightArm" contains the colors:
//  OUTFIT_BASE,OUTFIT_LINER,HANDS,MAHJIN
float rightArm [18][3] =
    {
        MAHJI[0],MAHJI[1],MAHJI[2],
        HANDS[0],HANDS[1],HANDS[2],
        MAHJI[0],MAHJI[1],MAHJI[2],
        HANDS[0],HANDS[1],HANDS[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2]
    };
float rightArmLoc [18][3] =
    {
        .81,-.18,0,//starting with hands, BOT-R
        -.09,0,0,
        0,.09,0,
        .09,0,0,
        0,.09,0,//begin outside of arm
        0,.09,0,
        0,.09,0,
        0,.09,0,
        0,.09,0,
        -.09,.09,0,//top corner of shoulder
        -.09,0,0,
        0,-.09,0,
        0,-.09,0,
        .09,.09,0,//begin inside of arm
        0,-.09,0,
        0,-.09,0,
        0,-.09,0,
        0,-.09,0
    };

//"leftArm" contains the colors:
//  OUTFIT_BASE,OUTFIT_LINER,HANDS,MAHJIN
float leftArm [18][3] =
    {
        MAHJI[0],MAHJI[1],MAHJI[2],
        HANDS[0],HANDS[1],HANDS[2],
        MAHJI[0],MAHJI[1],MAHJI[2],
        HANDS[0],HANDS[1],HANDS[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2]
    };
float leftArmLoc [18][3] =
    {
        -.63,-.63,0,//starting with hands, BOT-L
        .09,0,0,
        0,.09,0,
        -.09,0,0,
        0,.09,0,//begin outside of arm
        0,.09,0,
        0,.09,0,
        0,.09,0,
        0,.09,0,
        .09,.09,0,//top corner of shoulder
        .09,0,0,
        0,-.09,0,
        0,-.09,0,
        -.09,.09,0,//begin inside of arm
        0,-.09,0,
        0,-.09,0,
        0,-.09,0,
        0,-.09,0
    };

//"torso" contains the colors:
//  OUTFIT_BASE,OUTFIT_LINER,NECKLACE,PENDANT,BELT,BUCKLE
float torso [30][3] =
    {
        BELT[0],BELT[1],BELT[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        NECKLACE[0],NECKLACE[1],NECKLACE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        NECKLACE[0],NECKLACE[1],NECKLACE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        BELT[0],BELT[1],BELT[2],
        BUCKLE[0],BUCKLE[1],BUCKLE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        NECKLACE[0],NECKLACE[1],NECKLACE[2],
        PENDANT[0],PENDANT[1],PENDANT[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        NECKLACE[0],NECKLACE[1],NECKLACE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        BELT[0],BELT[1],BELT[2],
        BELT[0],BELT[1],BELT[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        NECKLACE[0],NECKLACE[1],NECKLACE[2]
    };
float torsoLoc [30][3] =
    {
        -.18,.18,0, //beginning with left side of belt going up (COL-1)
        0,.09,0,
        0,.09,0,
        0,.09,0,
        0,.09,0,
        0,.09,0,
        .09,0,0,//going down COL-2
        0,-.09,0,
        0,-.09,0,
        0,-.09,0,
        0,-.09,0,
        0,-.09,0,
        .09,0,0,//going up COL-3
        0,.09,0,
        0,.09,0,
        0,.09,0,
        0,.09,0,
        0,.09,0,
        .09,0,0,//going down COL-4
        0,-.09,0,
        0,-.09,0,
        0,-.09,0,
        0,-.09,0,
        0,-.09,0,
        .09,0,0,//going up COL-5
        0,.09,0,
        0,.09,0,
        0,.09,0,
        0,.09,0,
        0,.09,0
    };

//"groin" contains the color OUTFIT_BASE
float groin [2][3] =
    {
        OUTFIT_BASE[0], OUTFIT_BASE[1], OUTFIT_BASE[2],
        OUTFIT_BASE[0], OUTFIT_BASE[1], OUTFIT_BASE[2]
    };
float groinLoc [2][3] =
    {
        .09,.45,0,//top half
        0,-.09,0 //bottom half
    };

//"rightLeg" contains the colors:
//  OUTFIT_BASE,OUTFIT_LINER,SHOES
float rightLeg [16][3] =
    {
        SHOES[0],SHOES[1],SHOES[2],
        SHOES[0],SHOES[1],SHOES[2],
        SHOES[0],SHOES[1],SHOES[2],
        SHOES[0],SHOES[1],SHOES[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2]
    };
float rightLegLoc [16][3] =
    {
        -.27,-.09,.09,//front right shoe
        .09,0,0,//front left shoe
        0,0,-.09,//back left shoe (left side of R-heel)
        -.09,0,0,//back right shoe (right side of R-heel)
        0,.09,0,//begin outside of right leg
        0,.09,0,
        0,.09,0,
        0,.09,0,
        0,.09,0,
        0,.09,0,
        .09,0,0,//begin inside of right leg
        0,-.09,0,
        0,-.09,0,
        0,-.09,0,
        0,-.09,0,
        0,-.09,0
    };

//"leftLeg" contains the colors:
//  OUTFIT_BASE,OUTFIT_LINER,SHOES
float leftLeg [16][3] =
    {
        SHOES[0],SHOES[1],SHOES[2],
        SHOES[0],SHOES[1],SHOES[2],
        SHOES[0],SHOES[1],SHOES[2],
        SHOES[0],SHOES[1],SHOES[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_LINER[0],OUTFIT_LINER[1],OUTFIT_LINER[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2],
        OUTFIT_BASE[0],OUTFIT_BASE[1],OUTFIT_BASE[2]
    };
float leftLegLoc [16][3] =
    {
        .18,.09,.09,//front left shoe !!!!!!! [currently .09 off the ground to show full character] !!!!!!!
        -.09,0,0,//front right shoe
        0,0,-.09,//back right shoe (right side of L-heel)
        .09,0,0,//back left shoe (left side of L-heel)
        0,.09,0,//begin outside of left leg
        0,.09,0,
        0,.09,0,
        0,.09,0,
        0,.09,0,
        0,.09,0,
        -.09,0,0,//begin inside of left leg
        0,-.09,0,
        0,-.09,0,
        0,-.09,0,
        0,-.09,0,
        0,-.09,0
    };

void buildUnnamed(){

    glTranslatef(0,-1,0);//sets the center of where the building of Unnamed begins
    
    //LEFT LEG FOR-LOOP
    for (int i = 0; i<16;i++){
        //SET COLOR FIRST
        glColor3f(leftLeg[i][0], leftLeg[i][1], leftLeg[i][2]);
        //MOVE INTO POSITION
        glTranslatef(leftLegLoc[i][0], leftLegLoc[i][1], leftLegLoc[i][2]);
        //CREATE CUBE
        glutSolidCube(cube);
    }

    //RIGHT LEG FOR-LOOP
    for (int i=0; i<16; i++){
        //SET COLOR
        glColor3f(rightLeg[i][0], rightLeg[i][1], rightLeg[i][2]);
        //MOVE INTO POSITION
        glTranslatef(rightLegLoc[i][0], rightLegLoc[i][1], rightLegLoc[i][2]);
        //CREATE CUBE
        glutSolidCube(cube);
    }
    
    //GROIN FOR-LOOP
    for (int i=0; i<2; i++){
        //SET COLOR
        glColor3f(groin[i][0], groin[i][1], groin[i][2]);
        //MOVE INTO POSITION
        glTranslatef(groinLoc[i][0], groinLoc[i][1], groinLoc[i][2]);
        //CREATE CUBE
        glutSolidCube(cube);
    }
    
    //TORSO FOR-LOOP
    for (int i=0; i<30; i++){
        //SET COLOR
        glColor3f(torso[i][0], torso[i][1], torso[i][2]);
        //MOVE INTO POSITION
        glTranslatef(torsoLoc[i][0], torsoLoc[i][1], torsoLoc[i][2]);
        //CREATE CUBE
        glutSolidCube(cube);
    }

    //LEFT ARM FOR-LOOP
    for (int i=0; i<18; i++){
        //SET COLOR
        glColor3f(leftArm[i][0], leftArm[i][1], leftArm[i][2]);
        //MOVE INTO POSITION
        glTranslatef(leftArmLoc[i][0], leftArmLoc[i][1], leftArmLoc[i][2]);
        //CREATE CUBE
        glutSolidCube(cube);
    }

    //RIGHT ARM FOR-LOOP
    for (int i=0; i<18; i++){
        //SET COLOR
        glColor3f(rightArm[i][0], rightArm[i][1], rightArm[i][2]);
        //MOVE INTO POSITION
        glTranslatef(rightArmLoc[i][0], rightArmLoc[i][1], rightArmLoc[i][2]);
        //CREATE CUBE
        glutSolidCube(cube);
    }

    //HEAD FOR-LOOP
    for (int i=0; i<9; i++){
        //SET COLOR
        glColor3f(head[i][0], head[i][1], head[i][2]);
        //MOVE INTO POSITION
        glTranslatef(headLoc[i][0], headLoc[i][1], headLoc[i][2]);
        //CREATE CUBE
        glutSolidCube(cube);
    }
    
}


/*
 06FEB20 @ 2353
 Thinking it will be best to just create separate methods
 to create things as then it narrows my field to a
 method instead of jumbled amongst of bunch of things
 within the <<display()>> method.
 
 This method will call upon the <<buildUnnamed()>> method to
 receive the data to build the character in a for-loop.
*/


void displayUnnamed(){
    //needed to stop getting finicky background; source: Brandon Schmick
    glClear(GL_COLOR_BUFFER_BIT);

    //calls the method to unite all methods under one banner!
    buildUnnamed();

    glFlush();
}
/*
int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutCreateWindow("Unnamed");
    glutDisplayFunc(displayUnnamed);
    glutMainLoop();

return 0;
}*/
