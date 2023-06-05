// Вариант 4;
// Решение СЛАУ методом простых итераций;
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


void PrintMatrix(double* ptr[], const unsigned char SIZE_R, const unsigned char SIZE_C)
{
	for (int i = 0; i < SIZE_R; i++) {
		for (int j = 0; j < SIZE_C; j++) {
			cout << setw(9) << ptr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int main()
{
	const unsigned char SIZE = 5;

	double matrix[][SIZE + 1] = { {38.0, -8.0, 9.0, -4.0, 8.0, 43.0},
								{-1.0, 21.0, -5.0, 0.0, -2.0, 26.0},
								{-1.0, -7.0, 15.0, 1.0, -4.0, 12.0},
								{6.0, 6.0, -3.0, 25.0, 1.0, 70.0},
								{-8.0, 5.0, 6.0, 1.0, 28.0, 32.0} };
	double result[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };

	// создание массива указателей массива matrix
	double* ptr[SIZE]{};
	for (int i = 0; i < SIZE; i++)
		ptr[i] = matrix[i];

	// вывод матрицы в консоль;
	PrintMatrix(ptr, SIZE, SIZE + 1);

	double new[] ;
	x01 = x02 = x03 = 0.0;







	return 0;
}
