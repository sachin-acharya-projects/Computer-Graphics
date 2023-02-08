#include <windows.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>

void init()
{
    glClearColor(0, 0, 0, 1);
    glColor3f(0, 0, 1);
}
void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(25);
    glBegin(GL_POINTS);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(-0.5, -0.5);
    glEnd();
    glFlush();
}
int main(int argC, char *argV[])
{
    glutInit(&argC, argV);
    glutInitWindowPosition(100, 150);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Basic OpenGL Program");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
