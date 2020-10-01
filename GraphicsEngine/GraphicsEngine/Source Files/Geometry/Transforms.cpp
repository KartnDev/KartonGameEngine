#include "Transforms.h"
#include "../Common/pchdr.h"
#include "../Math Utilities/matrix4x4.h"

constexpr float aCoef = WIDTH / HEIGHT;

Vector2d Ortho2D(Vector3d vec, float zFar, float zNear, float thetaFoV)
{
	float fVal = 1.0f / tanf(thetaFoV * 0.5f / 180.0f * 3.14159f);
	float qCoef = zFar / (zFar - zNear);

	float zPointed = vec.z * qCoef - zNear * qCoef;

	Vector2d res;
	res.x = aCoef * fVal * vec.x / zPointed;
	res.y = fVal * vec.y / zPointed;

	return res;
}

Triangle Ortho2DTris(Triangle triangle, float zFar, float zNear, float thetaFoV)
{
	float fFovRadian = 1.0f / tanf(thetaFoV * 0.5f / 180.0f * 3.14159f);

	Triangle res;

	matrix4x4 projMat;

	projMat.mat[0][0] = aCoef * fFovRadian;
	projMat.mat[1][1] = fFovRadian;
	projMat.mat[2][2] = zFar / (zFar - zNear);
	projMat.mat[3][2] = (-zFar * zNear) / (zFar - zNear);
	projMat.mat[2][3] = 1.0f;
	projMat.mat[3][3] = 0.0f;

	triangle.points[0]


	return res;
}

