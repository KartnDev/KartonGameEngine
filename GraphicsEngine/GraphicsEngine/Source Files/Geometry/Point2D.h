#pragma once
#include "../Common/FXTypes.h"

namespace KtStd::Geometry
{
	struct Point2D
	{
		FloatFX x, y;
		Point2D(FloatFX x, FloatFX y);
		Point2D();
	};
}