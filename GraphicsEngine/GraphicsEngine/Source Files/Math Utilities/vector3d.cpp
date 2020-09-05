#include "vector3d.h"

vector3d::vector3d()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 1.0f;
}

vector3d::vector3d(FloatFX x, FloatFX y, FloatFX z, FloatFX w = 1.0f)
{
	x = x;
	y = y;
	z = z;
	w = w;
}

inline FloatFX vector3d::Length() const
{
	return sqrtf(x * x + y * y + z * z);
}

void vector3d::Normailize()
{
	*this /= Length();
}

inline bool vector3d::Equals(const vector3d& other) const
{
	return this->x == other.x && this->y == other.y && this->z == other.z;
}

inline bool vector3d::operator==(const vector3d& other) const
{
	return Equals(other);
}

inline FloatFX vector3d::Dot(const vector3d & rhs)
{
	return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
}

vector3d vector3d::Cross(const vector3d & rhs)
{
	return vector3d(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
}

void vector3d::MultiplyByScalar(FloatFX scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

void vector3d::operator*=(FloatFX scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

void vector3d::operator/=(FloatFX scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
}

void vector3d::DivideByScalar(FloatFX scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
}


void vector3d::AddScalar(const vector3d & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
}

void vector3d::operator+=(const vector3d & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
}

void vector3d::SubScalar(const vector3d & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
}

void vector3d::operator-=(const vector3d & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
}

vector3d vector3d::operator+(const vector3d & rhs)
{
	return vector3d(x + rhs.x, y + rhs.y, z + rhs.z);
}

vector3d vector3d::operator-(const vector3d & rhs)
{
	return vector3d(x - rhs.x, y - rhs.y, z - rhs.z);
}

vector3d vector3d::operator*(const FloatFX scalar)
{
	return vector3d(x * scalar, y * scalar, z * scalar);
}

vector3d vector3d::operator/(const FloatFX scalar)
{
	return vector3d(x / scalar, y / scalar, z / scalar);
}