#include <GL/glut.h>
#include "../Math Utilities/vector2d.h"
#include "../Geometry/Triangle.h"
#include "../Common/FXTypes.h"



void DrawLine(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1);
void DrawLine(Vector2d point1, Vector2d point2);

void DrawLine(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, float alpha);
void DrawLine(Vector2d point1, Vector2d point2, float alpha);

void DrawLine(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, int red, int green, int blue, float alpha);
void DrawLine(Vector2d point1, Vector2d point2, int red, int green, int blue, float alpha);


void DrawTriangle(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, FloatFX x2, FloatFX y2);
void DrawTriangle(Vector2d point1, Vector2d point2, Vector2d point3);
	 
void DrawTriangle(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, FloatFX x2, FloatFX y2, float alpha);
void DrawTriangle(Vector2d point1, Vector2d point2, Vector2d point3, float alpha);
	 
void DrawTriangle(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, FloatFX x2, FloatFX y2, int red, int green, int blue, float alpha);
void DrawTriangle(Vector2d point1, Vector2d point2, Vector2d point3, int red, int green, int blue, float alpha);

void DrawTriangle(Triangle triangle);

void FillTriangle(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, FloatFX x2, FloatFX y2);
void FillTriangle(Vector2d point1, Vector2d point2, Vector2d point3);

void FillTriangle(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, FloatFX x2, FloatFX y2, float alpha);
void FillTriangle(Vector2d point1, Vector2d point2, Vector2d point3, float alpha);

void FillTriangle(FloatFX x0, FloatFX y0, FloatFX x1, FloatFX y1, FloatFX x2, FloatFX y2, int red, int green, int blue, float alpha);
void FillTriangle(Vector2d point1, Vector2d point2, Vector2d point3, int red, int green, int blue, float alpha);