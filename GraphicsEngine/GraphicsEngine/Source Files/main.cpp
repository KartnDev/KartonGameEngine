#include "Math Utilities/matrix4x4.h"
#include <ctime>



void randmat44(matrix4x4 &M)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			M.mat[i][j] = (rand() % 10);
}


void print_matrix44(matrix4x4 &M)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
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

	matrix4x4 a, b;

	randmat44(a);

	randmat44(b);

	std::cout << "Matrix A: " << std::endl;
	print_matrix44(a);
	print_line
	std::cout << "Matrix B: " << std::endl;
	print_matrix44(b);
	print_line
	a.MatMul(b);
	

	std::cout << "Result: " << std::endl;
	print_line
	print_matrix44(a);

	return 0;
}