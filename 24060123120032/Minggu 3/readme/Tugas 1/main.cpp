/**************************
 * Includes
 *
 **************************/

#include <windows.h>
#include <gl/gl.h>


#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898

void DrawCircle(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
        int num_segments = 100; // Jumlah segmen untuk membuat lingkaran halus
        for (int i = 0; i < num_segments; i++) {
            float angle = 2.0f * PI * i / num_segments;
            float x = cos(angle) * 0.5; // Radius 0.5
            float y = sin(angle) * 0.5;
            glVertex2f(x, y);
        }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lingkaran");
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Latar belakang hitam
    gluOrtho2D(-1, 1, -1, 1); // Menyesuaikan koordinat tampilan
    
    glutDisplayFunc(DrawCircle);
    glutMainLoop();
    return 0;
}

