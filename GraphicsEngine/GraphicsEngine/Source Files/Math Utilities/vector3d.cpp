#include "Vector3d.h"

namespace KtStd
{
	Vector3d::Vector3d()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 1.0f;
	}

	Vector3d::Vector3d(FloatFX x, FloatFX y, FloatFX z, FloatFX w = 1.0f)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	inline FloatFX Vector3d::Length() const
	{
		return sqrtf(x * x + y * y + z * z);
	}

	void Vector3d::Normailize()
	{
		*this /= Length();
	}

	inline bool Vector3d::Equals(const Vector3d& other) const
	{
		return this->x == other.x && this->y == other.y && this->z == other.z;
	}

	inline bool Vector3d::operator==(const Vector3d& other) const
	{
		return Equals(other);
	}

	inline FloatFX Vector3d::Dot(const Vector3d& rhs) const
	{
		return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
	}

	void Vector3d::MultiplyMatrixVector(matrix4x4& m)
	{

		this->x = this->x * m.mat[0][0] + this->y * m.mat[1][0] + this->z * m.mat[2][0] + m.mat[3][0];
		this->y = this->x * m.mat[0][1] + this->y * m.mat[1][1] + this->z * m.mat[2][1] + m.mat[3][1];
		this->z = this->x * m.mat[0][2] + this->y * m.mat[1][2] + this->z * m.mat[2][2] + m.mat[3][2];
		const float w = this->x * m.mat[0][3] + this->y * m.mat[1][3] + this->z * m.mat[2][3] + m.mat[3][3];

		if (w != 0.0f)
		{
			this->x /= w; this->y /= w; this->z /= w;
		}

	}

	Vector3d Vector3d::Cross(const Vector3d& rhs) const
	{
		return Vector3d(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
	}

	void Vector3d::MultiplyByScalar(FloatFX scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
	}

	void Vector3d::operator*=(FloatFX scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
	}

	void Vector3d::operator/=(FloatFX scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
	}

	void Vector3d::DivideByScalar(FloatFX scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
	}


	void Vector3d::AddScalar(const Vector3d& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
	}

	void Vector3d::operator+=(const Vector3d& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
	}

	void Vector3d::SubScalar(const Vector3d& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
	}

	void Vector3d::operator-=(const Vector3d& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
	}

	Vector3d Vector3d::operator+(const Vector3d& rhs) const
	{
		return Vector3d(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	Vector3d Vector3d::operator-(const Vector3d& rhs) const
	{
		return Vector3d(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	Vector3d Vector3d::operator*(const FloatFX scalar) const
	{
		return Vector3d(x * scalar, y * scalar, z * scalar);
	}

	Vector3d Vector3d::operator/(const FloatFX scalar) const
	{
		return Vector3d(x / scalar, y / scalar, z / scalar);
	}

}