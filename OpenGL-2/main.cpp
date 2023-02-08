#include <windows.h>
#include <GL/glu.h>
#include<GL/gl.h>
#include <GL/glext.h>
#include<Gl/glut.h>
GLfloat A = 0;
void Spin()
{
    A = A + 0.005;
    if (A > 360)
        A = 0;
    glutPostRedisplay();
}
void MyInit()
{
    glClearColor(0, 0, 0, 1);
    glColor3f(1, 0, 0);
    glEnable(GL_DEPTH_TEST);
}
void Face(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[])
{
    glBegin(GL_POLYGON);
    glVertex3fv(A);
    glVertex3fv(B);
    glVertex3fv(C);
    glVertex3fv(D);

    glEnd();
}
void Cube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[],
          GLfloat V5[], GLfloat V6[], GLfloat V7[])
{
    glColor3f(1, 0, 0); // RGB
    Face(V0, V1, V2, V3);
    glColor3f(0, 1, 0);
    Face(V4, V5, V6, V7);
    glColor3f(0, 0, 1);
    Face(V0, V4, V7, V3);
    glColor3f(1, 1, 0);
    Face(V1, V5, V6, V2);
    glColor3f(1, 0, 1);
    Face(V3, V2, V6, V7);
    glColor3f(0, 1, 1);
    Face(V0, V1, V5, V4);
}
void Draw()
{
    GLfloat V[8][3] = {
        {-0.5, 0.5, 0.5},
        {0.5, 0.5, 0.5},
        {0.5, -0.5, 0.5},
        {-0.5, -0.5, 0.5},
        {-0.5, 0.5, -0.5},
        {0.5, 0.5, -0.5},
        {0.5, -0.5, -0.5},
        {-0.5, -0.5, -0.5}};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(A, 1, 1, 1);
    Cube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);
    glutSwapBuffers();
}
int main(int argC, char *argV[])
{
    glutInit(&argC, argV);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(200, 20);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    // glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Color Cube and Spin by sangam ");
    MyInit();
    glutDisplayFunc(Draw);
    glutIdleFunc(Spin);
    glutMainLoop();
    return 0;
}
