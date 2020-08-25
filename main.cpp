#include <windows.h>
#include <GL/glut.h>


//Initialize OpenGL
void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, 40, 0, 40, 0, 20);

}

void drawLines()
{
    glEnd();
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE);
    glVertex3f(2.0, 4.0, 0.0);
    glVertex3f(10.0, 10.0, 0.0);
    glEnd();
    glFlush();
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(300,400);
    glutCreateWindow("Example");
    init();
    glutDisplayFunc(drawLines);
    glutMainLoop();
}
