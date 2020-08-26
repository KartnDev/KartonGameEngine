#include <math.h>
#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>


void DrawTriangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, float r, float g, float b)
{
    glBegin(GL_TRIANGLES);

    glColor3f(r, g, b);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);

    glEnd();
}




void init2D(float r, float g, float b)
{
    glClearColor(r,g,b,0.0);
    glMatrixMode (GL_PROJECTION);
    glOrtho(0, 640, 480, 0, -1, 1);
}

void display(void)
{
    glClearColor(0,0,0,0);

    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = -100; i < 200; i+=30)
    {
        DrawTriangle(300.0 + i,  210.0 + i, 340.0 + i, 215.0 + i, 320.0 + i, 250.0 + i, 0.5, 100 + i/10, 100 + i/ 5);
    }


    glFlush();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("points and lines");
    init2D(0.0,0.0,0.0);
    glutDisplayFunc(display);
    glutMainLoop();
}