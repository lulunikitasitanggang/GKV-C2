#include <GL/glut.h>
#include <iostream>
#include "imageloader.h"

GLuint textureId;

GLuint loadTexture(const char* filename) {
    Image* image = loadBMP(filename);
    if (!image) {
        std::cerr << "Gagal memuat gambar!" << std::endl;
        exit(1);
    }

    GLuint texId;
    glGenTextures(1, &texId);
    glBindTexture(GL_TEXTURE_2D, texId);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    delete image;
    return texId;
}

void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    textureId = loadTexture("bg1.bmp");

    glEnable(GL_COLOR_MATERIAL);
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / h, 1.0, 200.0);
}

void drawCube() {
    glBindTexture(GL_TEXTURE_2D, textureId);
    glBegin(GL_QUADS);

    // DEPAN
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1,  1);
    glTexCoord2f(1.0, 0.0); glVertex3f( 1, -1,  1);
    glTexCoord2f(1.0, 1.0); glVertex3f( 1,  1,  1);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1,  1,  1);

    // BELAKANG
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1.0, 1.0); glVertex3f(-1,  1, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f( 1,  1, -1);
    glTexCoord2f(0.0, 0.0); glVertex3f( 1, -1, -1);

    // KIRI
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1,  1);
    glTexCoord2f(1.0, 1.0); glVertex3f(-1,  1,  1);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1,  1, -1);

    // KANAN
    glTexCoord2f(1.0, 0.0); glVertex3f(1, -1, -1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1,  1, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f(1,  1,  1);
    glTexCoord2f(0.0, 0.0); glVertex3f(1, -1,  1);

    // ATAS
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, -1);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, 1,  1);
    glTexCoord2f(1.0, 0.0); glVertex3f( 1, 1,  1);
    glTexCoord2f(1.0, 1.0); glVertex3f( 1, 1, -1);

    // BAWAH
    glTexCoord2f(1.0, 1.0); glVertex3f(-1, -1, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f( 1, -1, -1);
    glTexCoord2f(0.0, 0.0); glVertex3f( 1, -1,  1);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1,  1);

    glEnd();
}

float angle = 0.0;

void update(int value) {
    angle += 1.0f;
    if (angle > 360) angle -= 360;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -5.0);
    glRotatef(angle, 1.0, 1.0, 0.0);

    drawCube();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Kubus Bertekstur");

    initRendering();
    glutDisplayFunc(drawScene);
    glutReshapeFunc(handleResize);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}

