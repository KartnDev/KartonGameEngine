#include "../Common/FXTypes.h"
#include "vector3d.h"
#include <xmmintrin.h>
#include <immintrin.h>
#include <iostream>


struct matrix3x3
{
	FloatFX mat[3][3];
	__m128 row[3];


	void MatMul(const matrix3x3& rhs);
	void MatMulVector(const matrix3x3& rhs);

	void MatAdd(const matrix3x3& rhs);

	void ScalarMul(FloatFX rhs);
	void operator+=(FloatFX rhs);

	FloatFX Det() const;

	matrix3x3& Inverse() const;

	void operator*=(const matrix3x3& rhs);
	void operator*=(const vector3d& rhs);

	void operator/=(const matrix3x3& rhs);
	void operator/=(const vector3d& rhs);

	void operator+=(const matrix3x3& rhs);
	void operator+=(const vector3d& rhs);

	void operator-=(const matrix3x3& rhs);
	void operator-=(const vector3d& rhs);

	matrix3x3 operator+(const matrix3x3& rhs);
	matrix3x3 operator+(const vector3d& rhs);

	matrix3x3 operator-(const matrix3x3& rhs);
	matrix3x3 operator-(const vector3d& rhs);

	matrix3x3 operator*(const matrix3x3& rhs);
	matrix3x3 operator*(const vector3d& rhs);

	matrix3x3 operator/(const matrix3x3& rhs);
	matrix3x3 operator/(const vector3d& rhs);
};

