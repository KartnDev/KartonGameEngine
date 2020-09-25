#include "Graphing2D.h"

#include "../Common/FXTypes.h"

#ifdef USING_FAST_FLOAT
	#define GlVector2D glVertex2f
#endif

#ifndef USING_FAST_FLOAT
	#define GlVector2D glVertex2d
#endif

void DrawLine(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1)
{
	DrawLine(x0, y0, x1, y1, 1.0f, 1.0f, 1.0f, 1.0f);
}

void DrawLine(vector2d point1, vector2d point2)
{
	DrawLine(point1, point2, 1.0f, 1.0f, 1.0f, 1.0f);
}

void DrawLine(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, float alpha)
{
	DrawLine(x0, y0, x1, y1, 1.0f, 1.0f, 1.0f, alpha);
}


void DrawLine(vector2d point1, vector2d point2, float alpha)
{
	DrawLine(point1, point2, 1.0f, 1.0f, 1.0f, alpha);
}

void DrawLine(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, int red, int green, int blue, float alpha)
{
	glColor4f(red, green, blue, alpha);

	glBegin(GL_LINES);

	GlVector2D(x0, y0);
	GlVector2D(x1, y1);

	glEnd();
}

void DrawLine(vector2d point1, vector2d point2, int red, int green, int blue, float alpha)
{
	glColor4f(red, green, blue, alpha);

	glBegin(GL_LINES);

	GlVector2D(point1.x, point1.y);
	GlVector2D(point2.x, point2.y);

	glEnd();
}

void DrawTriangle(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, FloatFX x2, FloatFX y2)
{
	DrawTriangle(x0, y0, x1, y1, x2, y2, 1.0f, 1.0f, 1.0f, 1.0f);
}

void DrawTriangle(vector2d point1, vector2d point2, vector2d point3)
{
	DrawTriangle(point1, point2, point3, 1.0f, 1.0f, 1.0f, 1.0f);
}

void DrawTriangle(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, FloatFX x2, FloatFX y2, float alpha)
{
	DrawTriangle(x0, y0, x1, y1, x2, y2, 1.0f, 1.0f, 1.0f, alpha);
}

void DrawTriangle(vector2d point1, vector2d point2, vector2d point3, float alpha)
{
	DrawTriangle(point1, point2, point3, 1.0f, 1.0f, 1.0f, alpha);
}

void DrawTriangle(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, FloatFX x2, FloatFX y2, int red, int green, int blue, float alpha)
{
	glBegin(GL_LINES);

	glColor4f(red, green, blue, alpha);

	GlVector2D(x0, y0);
	GlVector2D(x1, y1);

	GlVector2D(x1, y1);
	GlVector2D(x2, y2);

	GlVector2D(x2, y2);
	GlVector2D(x0, y0);

	glEnd();
}

void DrawTriangle(vector2d point1, vector2d point2, vector2d point3, int red, int green, int blue, float alpha)
{
	glBegin(GL_LINES);

	glColor4f(red, green, blue, alpha);

	GlVector2D(point1.x, point1.y);
	GlVector2D(point2.x, point2.y);
	GlVector2D(point3.x, point3.y);

	glEnd();
}

void DrawTriangle(Triangle tri)
{
	glBegin(GL_LINES);

	glColor3f(tri.red, tri.green, tri.blue);

	GlVector2D(tri.points[1].x, tri.points[1].y);
	GlVector2D(tri.points[2].x, tri.points[2].x);
	GlVector2D(tri.points[3].x, tri.points[3].x);

	glEnd();
}

void FillTriangle(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, FloatFX x2, FloatFX y2)
{
	FillTriangle(x0, y0, x1, y1, x2, y2, 1.0f, 1.0f, 1.0f, 1.0f);
}

void FillTriangle(vector2d point1, vector2d point2, vector2d point3)
{
	FillTriangle(point1, point2, point3, 1.0f, 1.0f, 1.0f, 1.0f);
}

void FillTriangle(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, FloatFX x2, FloatFX y2, float alpha)
{
	FillTriangle(x0, y0, x1, y1, x2, y2, 1.0f, 1.0f, 1.0f, alpha);
}

void FillTriangle(vector2d point1, vector2d point2, vector2d point3, float alpha)
{
	FillTriangle(point1, point2, point3, 1.0f, 1.0f, 1.0f, alpha);
}

void FillTriangle(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, FloatFX x2, FloatFX y2, int red, int green, int blue, float alpha)
{
	glBegin(GL_TRIANGLES);

	glColor4f(red, green, blue, alpha);

	GlVector2D(x0, y0);
	GlVector2D(x1, y1);
	GlVector2D(x2, y2);

	glEnd();
}

void FillTriangle(vector2d point1, vector2d point2, vector2d point3, int red, int green, int blue, float alpha)
{
	glBegin(GL_TRIANGLES);

	glColor4f(red, green, blue, alpha);

	GlVector2D(point1.x, point1.y);
	GlVector2D(point2.x, point2.y);
	GlVector2D(point3.x, point3.y);

	glEnd();
}
