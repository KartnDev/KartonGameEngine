#include "matrix4x4.h"

void m4x4_AVX(float *A, float *B, float *C) 
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
			_mm256_add_ps(_mm256_mul_ps(brod1, row1), _mm256_mul_ps(brod2, row2)), _mm256_add_ps(_mm256_mul_ps(brod3, row3),_mm256_mul_ps(brod4, row4)));
		_mm256_store_ps(&C[4 * i], row);
		
	}
}

void matrix4x4::MatMul(const matrix4x4 & rhs)
{
	matrix4x4 res;

	m4x4_AVX(this->mat[0], const_cast<float*>(rhs.mat[0]), res.mat[0]);

	*this = res;
}

void matrix4x4::MatAdd(const matrix4x4 & rhs)
{

}

void matrix4x4::MatSub(const matrix4x4 & rhs)
{
}

void matrix4x4::ScalarMul(FloatFX scalar)
{
}

void matrix4x4::ScalarAdd(FloatFX scalar)
{
}

inline FloatFX matrix4x4::Det() const
{
	return FloatFX();
}

