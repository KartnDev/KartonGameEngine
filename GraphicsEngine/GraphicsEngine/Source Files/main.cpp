#include <GL/glut.h>
#include "GraphicsFlow/Graphing2D.h"


#define WIN_X 0
#define WIN_Y 0

#define WIDTH 640
#define HEIGHT 480

void init(void) {
	glClearColor(0, 0, 0, 0);

	glViewport(WIN_X, WIN_Y, WIDTH, HEIGHT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//glOrtho(WIN_X, WIDTH, WIN_Y, HEIGHT, 1, -1);
	gluOrtho2D(WIN_X, WIDTH, WIN_Y, HEIGHT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}



void CallBackWindow(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	DrawTriangle(100.0f, 100.0f, 200.0f, 400.0f, 500.0f, 450.0f);

	//drawLines(100, 100, 400, 400);
	
	glFlush();
}


int main(int argc, char**argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutCreateWindow("Example");
	init();
	glutDisplayFunc(CallBackWindow);
	glutMainLoop();
}