#include "CommonMathPreHeader.h"


#ifndef GRAPHICS_ENGINE_MATRIX4X4_H
#define GRAPHICS_ENGINE_MATRIX4X4_H

namespace KtStd
{
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
		void InverseSelf();


		void TransposeSelf();
		matrix4x4& Transpose();

		void operator*=(const matrix4x4& rhs);
		void operator+=(const matrix4x4& rhs);
		void operator-=(const matrix4x4& rhs);

		matrix4x4 operator+(const matrix4x4& rhs);
		matrix4x4 operator-(const matrix4x4& rhs);
		matrix4x4 operator*(const matrix4x4& rhs);
	};
}

#endif 