#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <math.h>
#include <iostream>
#define PI 3.14159265
double size = 20000000;
int angle = 360;
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
void drawBitman(){
    GLfloat size = 1; //Universal Size Rations
        glRotatef(angle, 0, 1, 0);//Rotate around Y axis
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
}
void drawSupport(){
    glColor3f(1, 1, 1);
    float size =1;
    glTranslatef(-5*size, 5*size, 0);
    glutSolidCube(2*size);
    for(int i = 0; i < 5; i++){
        glutSolidCube(2*size);
        glTranslatef(2*size, 0, 0);
    }
    glTranslatef(-10*size, -2*size, 0);
    glutSolidCube(2*size);
    glTranslatef(0, -2*size, 0);
    glutSolidCube(2*size);
    glTranslatef(0, -2*size, 0);
    glutSolidCube(2*size);
    glTranslatef(0, -2*size, 0);
    glutSolidCube(2*size);
    for(int i = 0; i < 5; i++){
        glTranslatef(2*size, 0, 0);
        if(i == 0 || i==2 || i ==4){
            glColor3f(0, 1, 0);
        }
        glutSolidCube(2*size);
        glColor3f(1, 1, 1);
    }
    for(int i =0; i<4;i++){
        glTranslatef(0, 2*size, 0);
        if(i == 0 || i == 2){
            glColor3f(1, 0, 0);
            glTranslatef(4*size, 0, 0);
            glutSolidCube(2*size);
            glColor3f(1, 0, 1);
            glTranslatef(-2*size, 0, 0);
            glutSolidCube(2*size);
            glColor3f(0, 1, 1);
            glTranslatef(-2*size, 0, 0);
            glutSolidCube(2*size);
            
        }
        if(i == 2){
            glTranslatef(-2*size, 0, 0);
            glColor3f(0, 0, 1);
            glutSolidCube(2*size);
            glTranslatef(2*size, 0, 0);
            
        }
        glutSolidCube(2*size);
        glColor3f(1, 1, 1);
    }


    
}
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
    glTranslatef(5, 8, -20);
    drawBitman();
    glTranslatef(-20, 3, 0);
    drawSupport();
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
    float HM = (cos(xRotationAngle*PI / 180.0)*forwardMovement);

    // change in x, y, z due to this movement and camera angle
    float dX = sin(yRotationAngle*PI / 180.0) * HM;
    float dZ = -cos(yRotationAngle * PI / 180.0) * HM;
    // a and d require y component of movement as well
    float dXSide = 0;
    float dZSide = 0;

    switch (key)
    {
    case 'w':
        xCameraLocation += dX;
        zCameraLocation += dZ;
        break;
    case 's':
        xCameraLocation -= dX;
        zCameraLocation -= dZ;
        break;
    case 'a':
        dXSide = sin((yRotationAngle - 90)*PI / 180.0) * 1;
        dZSide = -cos((yRotationAngle - 90) * PI / 180.0) * 1;
        xCameraLocation += dXSide;
        zCameraLocation += dZSide;
        break;
    case 'd':
        dXSide = sin((yRotationAngle + 90)*PI / 180.0) * 1;
        dZSide = -cos((yRotationAngle + 90) * PI / 180.0) * 1;
        xCameraLocation += dXSide;
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
