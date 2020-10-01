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

	Vector2d& Ortho2D(const Vector3d& vec, float zFar, float zNear, float thetaFoV)
	{
		float fVal = 1.0f / tanf(1.50f);
		float qCoef = zFar / (zFar - zNear);

		float zPointed = vec.z * qCoef - zNear * qCoef;

		Vector2d res;
		res.x = aCoef * fVal * vec.x / zPointed;
		res.y = fVal * vec.y / zPointed;

		return res;
	}

	Triangle& Ortho2DTris(const Triangle& triangle, float ZFar, float ZNear, float thetaFoV)
	{
		Triangle res;

		auto p0 = Ortho2D(triangle.points[0], ZFar, ZNear, thetaFoV);
		res.points[0].x = p0.x;
		res.points[0].y = p0.y;

		auto p1 = Ortho2D(triangle.points[1], ZFar, ZNear, thetaFoV);
		res.points[1].x = p1.x;
		res.points[1].y = p1.y;

		auto p2 = Ortho2D(triangle.points[2], ZFar, ZNear, thetaFoV);
		res.points[2].x = p2.x;
		res.points[2].y = p2.y;

		return res;
	}

	Triangle& RotateByZ(Triangle& triangle, float theta)
	{
		Matrix4X4 matRotZ{};

		Triangle res;

		matRotZ.mat[0][0] = cosf(theta);
		matRotZ.mat[0][1] = sinf(theta);
		matRotZ.mat[1][0] = -sinf(theta);
		matRotZ.mat[1][1] = cosf(theta);
		matRotZ.mat[2][2] = 1;
		matRotZ.mat[3][3] = 1;

		res.points[0] = MultiplyMatrixVector(triangle.points[0], matRotZ);
		res.points[1] = MultiplyMatrixVector(triangle.points[1], matRotZ);
		res.points[2] = MultiplyMatrixVector(triangle.points[2], matRotZ);

		return res;
	}

	Triangle& RotateByY(Triangle& triangle, float theta)
	{
		Matrix4X4 matRotY{};
		Triangle res;

		matRotY.mat[0][0] = cosf(theta);
		matRotY.mat[0][2] = sinf(theta);
		matRotY.mat[1][1] = 1;
		matRotY.mat[2][0] = -sinf(theta);
		matRotY.mat[2][2] = cosf(theta);
		matRotY.mat[3][3] = 1;

		res.points[0] = MultiplyMatrixVector(triangle.points[0], matRotY);
		res.points[1] = MultiplyMatrixVector(triangle.points[1], matRotY);
		res.points[2] = MultiplyMatrixVector(triangle.points[2], matRotY);

		return res;
	}

	Triangle& RotateByX(Triangle& triangle, float theta)
	{
		Matrix4X4 matRotX{};

		Triangle res;

		matRotX.mat[0][0] = 1;
		matRotX.mat[1][1] = cosf(theta);
		matRotX.mat[1][2] = sinf(theta);
		matRotX.mat[2][1] = -sinf(theta);
		matRotX.mat[2][2] = cosf(theta);
		matRotX.mat[3][3] = 1;

		res.points[0] = MultiplyMatrixVector(triangle.points[0], matRotX);
		res.points[1] = MultiplyMatrixVector(triangle.points[1], matRotX);
		res.points[2] = MultiplyMatrixVector(triangle.points[2], matRotX);

		return res;
	}
}
