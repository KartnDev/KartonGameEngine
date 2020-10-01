#include "Transforms.h"


namespace KtStd::Geometry
{
	constexpr float aCoef = (float)WIDTH / HEIGHT;

	Vector3d& MultiplyMatrixVector(const Vector3d& i, const Matrix4X4& m)
	{
		Vector3d res;

		res.x = i.x * m.mat[0][0] + i.y * m.mat[1][0] + i.z * m.mat[2][0] + m.mat[3][0];
		res.y = i.x * m.mat[0][1] + i.y * m.mat[1][1] + i.z * m.mat[2][1] + m.mat[3][1];
		res.z = i.x * m.mat[0][2] + i.y * m.mat[1][2] + i.z * m.mat[2][2] + m.mat[3][2];
		float w = i.x * m.mat[0][3] + i.y * m.mat[1][3] + i.z * m.mat[2][3] + m.mat[3][3];

		if (w != 0.0f)
		{
			res.x /= w; res.y /= w; res.z /= w;
		}

		return res;
	}

	Vector2d Ortho2D(Vector3d vec, float zFar, float zNear, float thetaFoV)
	{
		float fVal = 1.0f / tanf(1.5f);
		float qCoef = zFar / (zFar - zNear);

		float zPointed = vec.z * qCoef - zNear * qCoef;

		Vector2d res;
		res.x = aCoef * fVal * vec.x / zPointed;
		res.y = fVal * vec.y / zPointed;

		return res;
	}

	Triangle Ortho2DTris(Triangle triangle, float fFar, float fNear, float thetaFoV)
	{
		Triangle res;

		float fFovRad = 1.0f / tanf(1.5f);

		Matrix4X4 matProj;

		matProj.mat[0][0] = aCoef * fFovRad;
		matProj.mat[1][1] = fFovRad;
		matProj.mat[2][2] = fFar / (fFar - fNear);
		matProj.mat[3][2] = (-fFar * fNear) / (fFar - fNear);
		matProj.mat[2][3] = 1.0f;
		matProj.mat[3][3] = 0.0f;

		res.points[0] = MultiplyMatrixVector(triangle.points[0], matProj);
		res.points[1] = MultiplyMatrixVector(triangle.points[1], matProj);
		res.points[2] = MultiplyMatrixVector(triangle.points[2], matProj);


		return res;
	}

}