#include <GL/glut.h>
#include "Graphics3D.h"
#include "../Geometry/Triangle.h"

namespace KtStd::Graphics
{
	void DrawTriangle3D(const Triangle& triangle)
	{
		glBegin(GL_TRIANGLES);

		glColor3f(triangle.red, triangle.green, triangle.blue);


		GlVector3D(triangle.points[0].x, triangle.points[0].y, triangle.points[0].z);
		GlVector3D(triangle.points[1].x, triangle.points[1].y, triangle.points[1].z);
		GlVector3D(triangle.points[2].x, triangle.points[2].y, triangle.points[2].z);

		glEnd();

	}
}