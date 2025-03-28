#include <stdlib.h>   // standard definitions
#include <stdio.h>    // C I/O (for sprintf)
#include <math.h>     // standard definitions
#include <GL/freeglut.h> // FreeGLUT

double rotAngle = 10;  // rotation angle (BEWARE: Global)
double rotAngle1 = 10; // rotation angle (BEWARE: Global)

//------------------------------------------------------------------
// init
// Sets up some default OpenGL values.
//------------------------------------------------------------------
void init()
{
    glClearColor(0, 0, 0, 0); // background color
    glClearDepth(1.0);        // background depth value

    glEnable(GL_DEPTH_TEST);  // Enable depth testing

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 1000); // setup a perspective projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        0.0, 0.0, 5.0,  // eye position
        0.0, 0.0, 0.0,  // lookat position
        0.0, 1.0, 0.0   // up direction
    );
}

//------------------------------------------------------------------
// display callback function
// This is called each time application needs to redraw itself.
// Most of the OpenGL work is done through this function.
//------------------------------------------------------------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear buffers

    glPushMatrix(); // Save the current camera transform
    glRotated(rotAngle, 0, 1, 0);  // Rotate by rotAngle about y-axis
    glRotated(rotAngle1, 1, 0, 0); // Rotate by rotAngle about x-axis

    glEnable(GL_COLOR_MATERIAL); // Enable color for the object
    glColor3f(1.0, 0.1, 0.1);    // Reddish color
    glutSolidTeapot(1);          // Draw the teapot

    glPopMatrix();    // Restore the modelview matrix
    glFlush();        // Force OpenGL to render now
    glutSwapBuffers(); // Make the image visible
}

//------------------------------------------------------------------
// keyboard callback function
// This is called whenever a keyboard key is pressed.
//------------------------------------------------------------------
void keyboard(unsigned char k, int x, int y)
{
    switch (k)
    {
    case 'a':
        rotAngle += 5; // Increase rotation by 5 degrees
        break;
    case 'y':
        rotAngle1 += 5; // Increase rotation by 5 degrees
        break;
    case 'b':
        rotAngle1 -= 5; // Decrease rotation by 5 degrees
        break;
    case 'l':
        rotAngle -= 5; // Decrease rotation by 5 degrees
        break;
    case 'q':
        exit(0); // Exit the program
    }
    glutPostRedisplay(); // Redraw the scene
}

//-----------------------------------------------------------------
// main program
// Where everything begins.
//------------------------------------------------------------------
int main(int argc, char **argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB); // Set display mode
    glutInitWindowSize(800, 600); // Set window size
    glutCreateWindow("FreeGLUT Example"); // Create the window

    init(); // Call our own initialization function

    glutDisplayFunc(display);   // Register display function
    glutKeyboardFunc(keyboard); // Register keyboard function

    glutMainLoop(); // Enter the event loop
    return 0;
}

