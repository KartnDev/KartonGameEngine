#include <GL/glut.h>
#include <Windows.h>
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
float theta = 0.0f;


void CallBackWindow(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	FramePipelineFlow(theta);

	glFlush();

}
void process_Normal_Keys(int key, int x, int y)
{
	switch (key)
	{
	case 27:  break;
	case 100: theta += 0.1; break;
	}
	CallBackWindow();
}


int main(int argc, char**argv) 
{

	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);



	glutInit(&argc, argv);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutCreateWindow("Example");

	init();
	InitPipelining();

	glutDisplayFunc(CallBackWindow);
	glutSpecialFunc(process_Normal_Keys);
	glutMainLoop();
	
}

