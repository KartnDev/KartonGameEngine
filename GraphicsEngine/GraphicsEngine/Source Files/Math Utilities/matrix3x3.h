#pragma once
#include "CommonMathPreHeader.h"


namespace KtStd
{
	struct matrix3x3
	{
		FloatFX mat[3][3];

		void MatMul(const matrix3x3& rhs);

		void MatAdd(const matrix3x3& rhs);
		void MatSub(const matrix3x3& rhs);

		void ScalarMul(FloatFX scalar);
		void ScalarAdd(FloatFX scalar);
		void operator+=(FloatFX rhs);
		void operator*=(FloatFX rhs);

		void TransposeSelf();
		matrix3x3& Transpose();


		inline FloatFX Det() const;

		matrix3x3& Inverse() const;
		void InverseSelf();

		void operator*=(const matrix3x3& rhs);
		void operator+=(const matrix3x3& rhs);
		void operator-=(const matrix3x3& rhs);

		matrix3x3& operator+(const matrix3x3& rhs);
		matrix3x3& operator-(const matrix3x3& rhs);
		matrix3x3& operator*(const matrix3x3& rhs);
	};
}
