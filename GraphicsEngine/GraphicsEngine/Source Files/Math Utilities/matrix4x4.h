#pragma once

#include "CommonMathPreHeader.h"


namespace KtStd::Math
{
	struct Matrix4X4
	{
		FloatFX mat[4][4];

		void MatMul(const Matrix4X4& rhs);

		void MatAdd(const Matrix4X4& rhs);
		void MatSub(const Matrix4X4& rhs);

		void ScalarMul(FloatFX scalar);
		void ScalarAdd(FloatFX scalar);
		void operator+=(FloatFX rhs);
		void operator*=(FloatFX rhs);

		inline FloatFX Det() const;

		Matrix4X4& Inverse() const;
		void InverseSelf();


		void TransposeSelf();
		Matrix4X4& Transpose();

		void operator*=(const Matrix4X4& rhs);
		void operator+=(const Matrix4X4& rhs);
		void operator-=(const Matrix4X4& rhs);

		Matrix4X4 operator+(const Matrix4X4& rhs);
		Matrix4X4 operator-(const Matrix4X4& rhs);
		Matrix4X4 operator*(const Matrix4X4& rhs);
	};
}



