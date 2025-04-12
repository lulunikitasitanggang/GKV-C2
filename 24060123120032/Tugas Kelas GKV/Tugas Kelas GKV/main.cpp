#include <GL/glut.h>

int projectionMode = 0;

void drawCuboid(float width, float height, float depth) {
    glPushMatrix();
    glScalef(width, height, depth);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawFloor(float width, float depth) {
    glPushMatrix();
    glTranslatef(0.0f, -1.6f, 0.0f);
    glDisable(GL_LIGHTING);
    glColor3f(0.3f, 0.3f, 0.3f);
    glScalef(width, 0.05f, depth);
    glutSolidCube(1.0);
    glEnable(GL_LIGHTING);
    glPopMatrix();
}

void drawCabinet() {
    glColor3f(0.55f, 0.27f, 0.07f); // Warna kayu coklat

    // Badan lemari
    drawCuboid(2.0, 3.0, 1.0);

    // Pintu kiri
    glPushMatrix();
    glTranslatef(-0.5, 0.0, 0.51);
    drawCuboid(0.95, 2.9, 0.05);
    glPopMatrix();

    // Pintu kanan
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.51);
    drawCuboid(0.95, 2.9, 0.05);
    glPopMatrix();

    // Pegangan kiri
    glColor3f(0.2f, 0.2f, 0.2f);
    glPushMatrix();
    glTranslatef(-0.25, 0.0, 0.56);
    drawCuboid(0.05, 0.2, 0.05);
    glPopMatrix();

    // Pegangan kanan
    glPushMatrix();
    glTranslatef(0.25, 0.0, 0.56);
    drawCuboid(0.05, 0.2, 0.05);
    glPopMatrix();

    // Garis pemisah, bingkai, dan tepi lemari
    glColor3f(0.1f, 0.05f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-0.02f, -1.45f, 0.531f);
    glVertex3f( 0.02f, -1.45f, 0.531f);
    glVertex3f( 0.02f,  1.45f, 0.531f);
    glVertex3f(-0.02f,  1.45f, 0.531f);
    glEnd();

    // Garis horizontal atas dan bawah depan
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, 1.45f, 0.531f);
    glVertex3f( 1.0f, 1.45f, 0.531f);
    glVertex3f( 1.0f, 1.48f, 0.531f);
    glVertex3f(-1.0f, 1.48f, 0.531f);

    glVertex3f(-1.0f, -1.45f, 0.531f);
    glVertex3f( 1.0f, -1.45f, 0.531f);
    glVertex3f( 1.0f, -1.48f, 0.531f);
    glVertex3f(-1.0f, -1.48f, 0.531f);
    glEnd();

    // Garis sudut dan tepi lemari
    glColor3f(0.05f, 0.02f, 0.01f);
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, -1.5f, 0.5f);
    glVertex3f(-0.98f, -1.5f, 0.5f);
    glVertex3f(-0.98f, 1.5f, 0.5f);
    glVertex3f(-1.0f, 1.5f, 0.5f);

    glVertex3f(1.0f, -1.5f, 0.5f);
    glVertex3f(0.98f, -1.5f, 0.5f);
    glVertex3f(0.98f, 1.5f, 0.5f);
    glVertex3f(1.0f, 1.5f, 0.5f);

    glVertex3f(-1.0f, 1.5f, 0.5f);
    glVertex3f(1.0f, 1.5f, 0.5f);
    glVertex3f(1.0f, 1.48f, 0.5f);
    glVertex3f(-1.0f, 1.48f, 0.5f);

    glVertex3f(-1.0f, -1.5f, 0.5f);
    glVertex3f(1.0f, -1.5f, 0.5f);
    glVertex3f(1.0f, -1.48f, 0.5f);
    glVertex3f(-1.0f, -1.48f, 0.5f);
    glEnd();
}

void setCamera() {
    switch (projectionMode) {
        case 0: gluLookAt(3.0, 3.0, 6.0,   0.0, 1.5, 0.0,   0.0, 1.0, 0.0); break; // Default

        // Orthographic
        case 1: gluLookAt(0.0, 0.0, 5.0,   0.0, 0.0, 0.0,   0.0, 1.0, 0.0); break; // Front View (benar)
        case 2: gluLookAt(0.0, 0.0, -5.0,  0.0, 0.0, 0.0,   0.0, 1.0, 0.0); break; // Back View
        case 3: gluLookAt(5.0, 0.0, 0.0,   0.0, 0.0, 0.0,   0.0, 1.0, 0.0); break; // Side (Right)
        case 4: gluLookAt(0.0, 5.0, 0.0,   0.0, 0.0, 0.0,   0.0, 0.0, -1.0); break; // Plan (Top)
        case 5: gluLookAt(3.0, 3.0, 3.0,   0.0, 0.0, 0.0,   0.0, 1.0, 0.0); break; // Isometric
        case 6: gluLookAt(4.0, 2.5, 3.0,   0.0, 0.0, 0.0,   0.0, 1.0, 0.0); break; // Dimetric
        case 7: gluLookAt(5.0, 2.0, 2.5,   0.0, 0.0, 0.0,   0.0, 1.0, 0.0); break; // Trimetric

        // Perspective
        case 8: gluLookAt(5.0, 2.0, 5.0,   0.0, 0.0, 0.0,   0.0, 1.0, 0.0); break; // 1 titik hilang
        case 9: gluLookAt(5.0, 5.0, 5.0,   0.0, 0.0, 0.0,   0.0, 1.0, 0.0); break; // 2 titik hilang
        case 10: gluLookAt(7.0, 7.0, 7.0,  0.0, 0.0, 0.0,   0.0, 1.0, 0.0); break; // 3 titik hilang dengan lebih extreme

    }
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (projectionMode >= 1 && projectionMode <= 7)
        glOrtho(-3, 3, -3, 3, -10, 10);
    else
        gluPerspective(60.0, (float)w/h, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int, int) {
    switch (key) {
        case '0': projectionMode = 0; break;
        case '1': projectionMode = 1; break;
        case '2': projectionMode = 2; break;
        case '3': projectionMode = 3; break;
        case '4': projectionMode = 4; break;
        case '5': projectionMode = 5; break;
        case '6': projectionMode = 6; break;
        case '7': projectionMode = 7; break;
        case '8': projectionMode = 8; break;
        case '9': projectionMode = 9; break;
        case 'q': projectionMode = 10; break;
        case 27: exit(0); break; // ESC to exit
    }
    glutPostRedisplay();
}

const char* getProjectionLabel() {
    switch (projectionMode) {
        case 1: return "Orthographic - Front View";
        case 2: return "Orthographic - Back View";
        case 3: return "Orthographic - Side View";
        case 4: return "Orthographic - Plan View";
        case 5: return "Orthographic - Isometric View";
        case 6: return "Orthographic - Dimetric View";
        case 7: return "Orthographic - Trimetric View";
        case 8: return "Perspective - 1 titik hilang";
        case 9: return "Perspective - 2 titik hilang";
        case 10: return "Perspective - 3 titik hilang";
        default: return "Default View";
    }
}

void drawText(float x, float y, const char* text) {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_LIGHTING);
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; ++c)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    glEnable(GL_LIGHTING);

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    setCamera();

    drawCabinet();
    drawFloor(5.0f, 3.0f);

    // Tampilkan label proyeksi di layar
    drawText(10, 570, getProjectionLabel());

    glutSwapBuffers();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_pos[] = {2.0, 4.0, 2.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Lemari Kayu - Proyeksi GKV");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

