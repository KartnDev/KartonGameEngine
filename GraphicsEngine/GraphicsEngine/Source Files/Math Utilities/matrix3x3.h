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
	void MatMulVector(const vector3d& rhs);

	void MatAdd(const matrix3x3& rhs);
	void MatSub(const matrix3x3& rhs);

	void ScalarMul(FloatFX scalar);
	void ScalarAdd(FloatFX scalar);
	void operator+=(FloatFX rhs);
	void operator*=(FloatFX rhs);

	inline FloatFX Det() const;

	matrix3x3& Inverse() const;

	void operator*=(const matrix3x3& rhs);
	void operator*=(const vector3d& rhs);
	void operator+=(const matrix3x3& rhs);
	void operator-=(const matrix3x3& rhs);

	matrix3x3 operator+(const matrix3x3& rhs);
	matrix3x3 operator-(const matrix3x3& rhs);
	matrix3x3 operator*(const matrix3x3& rhs);
	matrix3x3 operator*(const vector3d& rhs);

};

