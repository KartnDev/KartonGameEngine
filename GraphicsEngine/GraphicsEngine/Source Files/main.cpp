#include <GL/glut.h>

#include "GraphicsFlow/GraphicsPipeline.h"

#define WIN_X 0
#define WIN_Y 0

using namespace KtStd::Graphics;

void init(void) {

	glClearColor(0, 0, 0, 0);

	glViewport(WIN_X, WIN_Y, WIDTH, HEIGHT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(WIN_X, WIDTH, WIN_Y, HEIGHT, 1, -1);
	//gluOrtho2D(WIN_X, WIDTH, WIN_Y, HEIGHT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}



void CallBackWindow(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	FramePipelineFlow();

	glFlush();
}



int main(int argc, char**argv) 
{

	glutInit(&argc, argv);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutCreateWindow("Example");

	init();
	InitPipelining();

	glutDisplayFunc(CallBackWindow);
	glutMainLoop();

}