#include "Point3D.h"


namespace KtStd::Geometry
{
	Point3D::Point3D(FloatFX x, FloatFX y, FloatFX z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Point3D::Point3D()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}
}