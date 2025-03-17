/**************************
 * Includes
 *
 **************************/

#include <windows.h>
#include <gl/gl.h>
#include <GL/glut.h>
#include <math.h>

void drawCircle(float cx, float cy, float r, float innerR, float innerG, float innerB) {
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10) {
        float theta = i * 3.14159265359 / 180;
        glVertex2f(cx + r * cos(theta), cy + r * sin(theta));
    }
    glEnd();
    
    glColor3f(innerR, innerG, innerB);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10) {
        float theta = i * 3.14159265359 / 180;
        glVertex2f(cx + (r * 0.4) * cos(theta), cy + (r * 0.4) * sin(theta));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    // Langit
    glColor3f(0.6f, 0.8f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1, 1);
    glVertex2f(1, 1);
    glVertex2f(1, 0.3);
    glVertex2f(-1, 0.3);
    glEnd();
    
    // Tanah
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1, 0.3);
    glVertex2f(1, 0.3);
    glVertex2f(1, -1);
    glVertex2f(-1, -1);
    glEnd();
    
    // Gunung
    glColor3f(0.5f, 0.3f, 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.9f, 0.3f);
    glVertex2f(-0.2f, 0.8f);
    glVertex2f(0.3f, 0.3f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(0.8f, 0.8f);
    glVertex2f(1.2f, 0.3f);
    glEnd();
    
    // Matahari
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10) {
        float theta = i * 3.14159265359 / 180;
        glVertex2f(0.4f + 0.12f * cos(theta), 0.7f + 0.12f * sin(theta));
    }
    glEnd();
    
    // Jalan
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2f(-1, -0.2);
    glVertex2f(1, -0.1);
    glVertex2f(1, -0.5);
    glVertex2f(-1, -0.6);
    glEnd();
    
    // Garis Jalan
    glColor3f(1, 1, 1);
    for (float x = -0.9; x < 1.0; x += 0.3) {
        glBegin(GL_QUADS);
        glVertex2f(x, -0.35);
        glVertex2f(x + 0.1, -0.32);
        glVertex2f(x + 0.1, -0.35);
        glVertex2f(x, -0.38);
        glEnd();
    }
    
    // Mobil
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.25f, -0.25f);
    glVertex2f(0.25f, -0.25f);
    glVertex2f(0.25f, -0.1f);
    glVertex2f(-0.25f, -0.1f);
    glEnd();
    
    // Atap Mobil diperlebar
    glBegin(GL_QUADS);
    glVertex2f(-0.23f, -0.1f);
    glVertex2f(0.23f, -0.1f);
    glVertex2f(0.18f, 0.05f);
    glVertex2f(-0.18f, 0.05f);
    glEnd();
    
    // Jendela Mobil (dua jendela)
    glColor3f(0.7f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.15f, -0.1f);
    glVertex2f(0.0f, -0.1f);
    glVertex2f(0.0f, 0.02f);
    glVertex2f(-0.15f, 0.02f);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(0.05f, -0.1f);
    glVertex2f(0.15f, -0.1f);
    glVertex2f(0.15f, 0.02f);
    glVertex2f(0.05f, 0.02f);
    glEnd();
    
    // Lampu Sen (menyatu dengan mobil, persegi panjang)
    glColor3f(1.0f, 0.6f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.23f, -0.15f);
    glVertex2f(0.27f, -0.15f);
    glVertex2f(0.27f, -0.2f);
    glVertex2f(0.23f, -0.2f);
    glEnd();
    
    // Roda Mobil
    drawCircle(-0.15f, -0.27f, 0.05f, 1.0f, 1.0f, 1.0f);
    drawCircle(0.15f, -0.27f, 0.05f, 1.0f, 1.0f, 1.0f);
    
    glutSwapBuffers();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil di Pegunungan");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
