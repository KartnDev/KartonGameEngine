#include "CommonMathPreHeader.h"



struct matrix4x4
{
	FloatFX mat[4][4];

	void MatMul(const matrix4x4& rhs);

	void MatAdd(const matrix4x4& rhs);
	void MatSub(const matrix4x4& rhs);

	void ScalarMul(FloatFX scalar);
	void ScalarAdd(FloatFX scalar);
	void operator+=(FloatFX rhs);
	void operator*=(FloatFX rhs);

	inline FloatFX Det() const;

	matrix4x4& Inverse() const;

	void operator*=(const matrix4x4& rhs);
	void operator+=(const matrix4x4& rhs);
	void operator-=(const matrix4x4& rhs);

	matrix4x4 operator+(const matrix4x4& rhs);
	matrix4x4 operator-(const matrix4x4& rhs);
	matrix4x4 operator*(const matrix4x4& rhs);


};