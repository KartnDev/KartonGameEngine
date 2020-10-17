#include "Point2D.h"

namespace KtStd::Geometry
{
	Point2D::Point2D(FloatFX x, FloatFX y)
	{
		this->x = x;
		this->y = y;
	}

	Point2D::Point2D()
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}
}