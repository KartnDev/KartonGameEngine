#pragma once
#include "../Common/pchdr.h"
#include "../Math Utilities/matrix4x4.h"
#include "../Math Utilities/vector2d.h"
#include "Triangle.h"


using namespace KtStd::Math;
using namespace KtStd::Geometry;

namespace KtStd::Geometry
{
	Vector2d& Ortho2D(const Vector3d& vec, float zFar, float zNear, float thetaFoV);
	Triangle& Ortho2DTris(const Triangle& triangle, float ZFar, float ZNear, float thetaFoV);

	Triangle& RotateByZ(Triangle& triangle, float theta);
	Triangle& RotateByY(Triangle& triangle, float theta);
	Triangle& RotateByX(Triangle& triangle, float theta);

}