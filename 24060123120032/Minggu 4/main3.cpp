#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

static int shoulder = 0, shoulderY = 0, elbow = 0, wrist = 0;
static int finger[5] = {0, 0, 0, 0, 0};

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    // Posisikan kamera agar objek terlihat lebih jelas
    glTranslatef(0.0, 0.0, -5.0);

    // Rotasi bahu ke arah pelihat (kamera)
    glRotatef((GLfloat)shoulderY, 0.0, 1.0, 0.0); 

    // Posisi awal bahu
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    // Bahu
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Siku
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Pergelangan tangan
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.3, 0.8);
    glutWireCube(1.0);
    glPopMatrix();

    // Jari-jari
    float fingerPositions[5][2] = {{0.5, 0.2}, {0.5, 0.1}, {0.5, 0.0}, {0.5, -0.1}, {0.5, -0.2}};
    for (int i = 0; i < 5; i++) {
        glPushMatrix();
        glTranslatef(fingerPositions[i][0], fingerPositions[i][1], 0.2);
        glRotatef((GLfloat)finger[i], 0.0, 0.0, 1.0);
        glScalef(0.5, 0.1, 0.1);
        glutWireCube(1.0);
        glPopMatrix();
    }

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    if (h == 0 || w == 0) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLdouble)w / (GLdouble)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;
        case 'a': shoulderY = (shoulderY + 5) % 360; break; // Putar bahu ke kiri (menghadap kamera)
        case 'd': shoulderY = (shoulderY - 5) % 360; break; // Putar bahu ke kanan
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;
        case 'w': wrist = (wrist + 5) % 360; break;
        case 'W': wrist = (wrist - 5) % 360; break;
        case '1': finger[0] = (finger[0] + 5) % 360; break;
        case '!': finger[0] = (finger[0] - 5) % 360; break;
        case '2': finger[1] = (finger[1] + 5) % 360; break;
        case '@': finger[1] = (finger[1] - 5) % 360; break;
        case '3': finger[2] = (finger[2] + 5) % 360; break;
        case '#': finger[2] = (finger[2] - 5) % 360; break;
        case '4': finger[3] = (finger[3] + 5) % 360; break;
        case '$': finger[3] = (finger[3] - 5) % 360; break;
        case '5': finger[4] = (finger[4] + 5) % 360; break;
        case '%': finger[4] = (finger[4] - 5) % 360; break;
        case 27: exit(0); break;
        default: break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lengan dengan Telapak Tangan dan Jari");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

