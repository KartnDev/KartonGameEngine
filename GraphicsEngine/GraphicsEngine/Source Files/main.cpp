#include "Math Utilities/matrix3x3.h"
#include <ctime>



void randmat(matrix3x3 &M)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			M.mat[i][j] =  (rand() % 10);
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



#define print_line std::cout << "=======================================\n" << std::endl;


int main()
{
	srand((unsigned)time(NULL));

	matrix3x3 a, b, res;

	randmat(a);

	randmat(b);

	std::cout << "Matrix A: " << std::endl;
	print_matrix(a);
	print_line
	std::cout << "Matrix B: " << std::endl;
	print_matrix(b);
	print_line
	a.MatMul(b);

	std::cout << "Result: " << std::endl;
	print_matrix(res);
	print_line


	return 0;
}