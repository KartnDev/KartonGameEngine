#pragma once
#include "../Math Utilities/vector3d.h"

using namespace KtStd::Math;

namespace KtStd::Geometry
{
	struct Triangle
	{
		Vector3d points[3];
		unsigned char red = 255;
		unsigned char green = 255;
		unsigned char blue = 255;

		Vector3d& GetNormal();
	};
}
