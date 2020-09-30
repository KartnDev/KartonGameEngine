#include "Transforms.h"
#include "../Common/pchdr.h"

constexpr float aCoef = WIDTH / HEIGHT;

Vector2d Ortho2D(Vector3d vec, int zFar, int zNear, float thetaFoV)
{
	float fVal = 1.0f / tanf(thetaFoV / 2);
	float qCoef = static_cast<float>(zFar) / (zFar - zNear);

	float zPointed = vec.z * qCoef - zNear * qCoef;

	Vector2d res;
	res.x = aCoef * fVal * vec.x / zPointed;
	res.y = fVal * vec.y / zPointed;

	return res;
}

Triangle Ortho2DTris(Triangle triangle, int zFar, int zNear, float thetaFoV)
{
	Triangle res;

	auto v1 = Ortho2D(triangle.points[0], zFar, zNear, thetaFoV);
	res.points[0].x = v1.x;
	res.points[0].y = v1.y;

	v1 = Ortho2D(triangle.points[1], zFar, zNear, thetaFoV);
	res.points[1].x = v1.x;
	res.points[1].y = v1.y;
	
	v1 = Ortho2D(triangle.points[2], zFar, zNear, thetaFoV);
	res.points[2].x = v1.x;
	res.points[2].y = v1.y;

	return res;
}

