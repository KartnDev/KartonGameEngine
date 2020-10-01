#include "Matrix4X4.h"

#define MAT_COLS 4
#define MAT_ROWS 4

namespace KtStd::Math
{
	void m4x4_AVX(float* A, float* B, float* C)
	{
		__m256 row1 = _mm256_load_ps(&B[0]);
		__m256 row2 = _mm256_load_ps(&B[4]);
		__m256 row3 = _mm256_load_ps(&B[8]);
		__m256 row4 = _mm256_load_ps(&B[12]);
		for (int i = 0; i < 4; i++)
		{
			__m256 brod1 = _mm256_set1_ps(A[4 * i + 0]);
			__m256 brod2 = _mm256_set1_ps(A[4 * i + 1]);
			__m256 brod3 = _mm256_set1_ps(A[4 * i + 2]);
			__m256 brod4 = _mm256_set1_ps(A[4 * i + 3]);
			__m256 row = _mm256_add_ps(
				_mm256_add_ps(_mm256_mul_ps(brod1, row1), _mm256_mul_ps(brod2, row2)), _mm256_add_ps(_mm256_mul_ps(brod3, row3), _mm256_mul_ps(brod4, row4)));
			_mm256_store_ps(&C[4 * i], row);

		}
	}

	void Matrix4X4::MatMul(const Matrix4X4& rhs)
	{
		Matrix4X4 res;

		m4x4_AVX(this->mat[0], const_cast<float*>(rhs.mat[0]), res.mat[0]);

		*this = res;
	}

	void Matrix4X4::MatAdd(const Matrix4X4& rhs)
	{
		for (size_t i = 0; i < MAT_ROWS; i++)
		{
			for (size_t j = 0; j < MAT_COLS; j++)
			{
				this->mat[i][j] += rhs.mat[i][j];
			}
		}
	}

	void Matrix4X4::MatSub(const Matrix4X4& rhs)
	{
		for (size_t i = 0; i < MAT_ROWS; i++)
		{
			for (size_t j = 0; j < MAT_COLS; j++)
			{
				this->mat[i][j] -= rhs.mat[i][j];
			}
		}
	}

	void Matrix4X4::ScalarMul(FloatFX scalar)
	{
		for (size_t i = 0; i < MAT_ROWS; i++)
		{
			for (size_t j = 0; j < MAT_COLS; j++)
			{
				this->mat[i][j] *= scalar;
			}
		}
	}

	void Matrix4X4::ScalarAdd(FloatFX scalar)
	{
		for (size_t i = 0; i < MAT_ROWS; i++)
		{
			for (size_t j = 0; j < MAT_COLS; j++)
			{
				this->mat[i][j] += scalar;
			}
		}
	}

	void Matrix4X4::operator+=(FloatFX rhs)
	{
		ScalarAdd(rhs);
	}

	void Matrix4X4::operator*=(FloatFX rhs)
	{
		ScalarMul(rhs);
	}

	inline FloatFX Matrix4X4::Det() const
	{
		return FloatFX();
	}

	Matrix4X4& Matrix4X4::Inverse() const
	{
		Matrix4X4 res;

		return res;
	}

	void Matrix4X4::InverseSelf()
	{
	}

	void Matrix4X4::TransposeSelf()
	{
	}

	Matrix4X4& Matrix4X4::Transpose()
	{
		Matrix4X4 res;

		return res;
	}

	void Matrix4X4::operator*=(const Matrix4X4& rhs)
	{
		MatMul(rhs);
	}

	void Matrix4X4::operator+=(const Matrix4X4& rhs)
	{
		MatAdd(rhs);
	}

	void Matrix4X4::operator-=(const Matrix4X4& rhs)
	{
		MatSub(rhs);
	}

	Matrix4X4 Matrix4X4::operator+(const Matrix4X4& rhs)
	{
		Matrix4X4 result;

		for (size_t i = 0; i < MAT_ROWS; i++)
		{
			for (size_t j = 0; j < MAT_COLS; j++)
			{
				result.mat[i][j] = this->mat[i][j] + rhs.mat[i][j];
			}
		}

		return result;
	}

	Matrix4X4 Matrix4X4::operator-(const Matrix4X4& rhs)
	{
		Matrix4X4 result;

		for (size_t i = 0; i < MAT_ROWS; i++)
		{
			for (size_t j = 0; j < MAT_COLS; j++)
			{
				result.mat[i][j] = this->mat[i][j] - rhs.mat[i][j];
			}
		}

		return result;
	}

	Matrix4X4 Matrix4X4::operator*(const Matrix4X4& rhs)
	{
		Matrix4X4 res;

		m4x4_AVX(this->mat[0], const_cast<float*>(rhs.mat[0]), res.mat[0]);

		return res;
	}

}