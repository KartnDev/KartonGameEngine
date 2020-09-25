#pragma once
#include "../Common/pchdr.h"


struct Vector3d
{
	FloatFX x, y, z, w;

	Vector3d();
	Vector3d(FloatFX x, FloatFX y, FloatFX z, FloatFX w);

	inline FloatFX Length() const;
	void Normailize();

	inline bool Equals(const Vector3d& rhs) const;
	inline bool operator==(const Vector3d& rhs) const;

	inline FloatFX Dot(const Vector3d& rhs);
	Vector3d Cross(const Vector3d& rhs);

	void MultiplyByScalar(FloatFX scalar);
	void operator/= (FloatFX scalar);

	void DivideByScalar(FloatFX scalar);
	void operator*= (FloatFX scalar);

	void AddScalar(const Vector3d& rhs);
	void operator+= (const Vector3d& rhs);

	void SubScalar(const Vector3d& rhs);
	void operator-= (const Vector3d& rhs);

	Vector3d operator+(const Vector3d& rhs);
	Vector3d operator-(const Vector3d& rhs);
	Vector3d operator*(const FloatFX scalar);
	Vector3d operator/(const FloatFX scalar);
	
};