#include "Vector3d.h"

namespace KtStd::Math
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