#include "Math Utilities/matrix3x3.h"

inline __m256 twolincomb_AVX_8(__m256 A01, const matrix3x3 &B)
{
	__m256 result;
	result = _mm256_mul_ps(_mm256_shuffle_ps(A01, A01, 0x00), _mm256_broadcast_ps(&B.row[0]));
	result = _mm256_add_ps(result, _mm256_mul_ps(_mm256_shuffle_ps(A01, A01, 0x55), _mm256_broadcast_ps(&B.row[1])));
	result = _mm256_add_ps(result, _mm256_mul_ps(_mm256_shuffle_ps(A01, A01, 0xaa), _mm256_broadcast_ps(&B.row[2])));
	return result;
}


void matmult_AVX_8(matrix3x3 &out, const matrix3x3 &A, const matrix3x3 &B)
{
	_mm256_zeroupper();
	__m256 A01 = _mm256_loadu_ps(&A.mat[0][0]);
	__m256 A23 = _mm256_loadu_ps(&A.mat[2][0]);

	__m256 out01x = twolincomb_AVX_8(A01, B);
	__m256 out23x = twolincomb_AVX_8(A23, B);

	_mm256_storeu_ps(&out.mat[0][0], out01x);
	_mm256_storeu_ps(&out.mat[2][0], out23x);
}

static float randf()
{
	// assumes VC++ rand()
	return rand() % 10;
}

static void randmat(matrix3x3 &M)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			M.mat[i][j] = randf();
}

void print_matrix(matrix3x3 &M)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << M.mat[i][j] << ", ";
		}
		std::cout << std::endl;
	}
}

void M3x3_SSE(float *A, float *B, float *C) {
	__m128 row1 = _mm_load_ps(&B[0]);
	__m128 row2 = _mm_load_ps(&B[3]);
	__m128 row3 = _mm_load_ps(&B[6]);
	for (int i = 0; i < 3; i++) {
		__m128 brod1 = _mm_set1_ps(A[3 * i + 0]);
		__m128 brod2 = _mm_set1_ps(A[3 * i + 1]);
		__m128 brod3 = _mm_set1_ps(A[3 * i + 2]);
		__m128 row = _mm_add_ps (_mm_add_ps(_mm_mul_ps(brod1, row1), _mm_mul_ps(brod2, row2)), _mm_mul_ps(brod3, row3));
		_mm_store_ps(&C[3 * i], row);
	}
}


#define print_line std::cout << "=======================================\n" << std::endl;


int main()
{
	matrix3x3 a, b, res;

	randmat(a);
	randmat(b);

	std::cout << "Matrix A: " << std::endl;
	print_matrix(a);
	print_line
	std::cout << "Matrix B: " << std::endl;
	print_matrix(a);
	print_line
	M3x3_SSE(a.mat[0], b.mat[0], res.mat[0]);

	std::cout << "Result: " << std::endl;
	print_matrix(res);
	print_line


	return 0;
}