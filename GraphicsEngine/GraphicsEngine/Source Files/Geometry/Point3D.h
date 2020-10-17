#pragma once
#include "../Common/FXTypes.h"

namespace KtStd::Geometry
{
	struct Point3D
	{
		FloatFX x, y, z;
		Point3D(FloatFX x, FloatFX y, FloatFX z);
		Point3D();
	};
}