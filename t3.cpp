﻿// Вариант 4;
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
		cout << endl << endl;
	}
	cout << endl;
}


int main()
{
	double eps = 0.00001;
	const unsigned char SIZE = 5;

	double matrix[][SIZE + 1] = { {38.0, -8.0, 9.0, -4.0, 8.0 },
								{-1.0, 21.0, -5.0, 0.0, -2.0 },
								{-1.0, -7.0, 15.0, 1.0, -4.0 },
								{6.0, 6.0, -3.0, 25.0, 1.0 },
								{-8.0, 5.0, 6.0, 1.0, 28.0 } };
	double free_terms[SIZE] = { 43.0, 26.0, 12.0, 70.0, 32.0 };
	double result[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
	double result2[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
	double temp[SIZE] = { 43.0, 26.0, 12.0, 70.0, 32.0 };

	// создание массива указателей массива matrix
	double* ptr[SIZE]{};
	for (int i = 0; i < SIZE; i++)
		ptr[i] = matrix[i];

	// вывод матрицы в консоль;
	PrintMatrix(ptr, SIZE, SIZE);

	// вывод свободных членов в консоль;
	cout << "Free Terms:\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << free_terms[i] << '\t';
	}
	cout << endl << endl;


///////////////////////////////////////////////////////////////////////////////////
	// расчет новых значенй матрицы result;
	int k = 0;
	while (k != -1)
	{
		k += 1;
		// вычисления;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = SIZE - 1; j >= 0; j--)
			{
				if (i != j)
				{
					temp[i] -= matrix[i][j] * result[j];
				}
			}
			temp[i] /= matrix[i][i];
			result[i] = temp[i];
		}

		// вывод промежуточного результата в консоль;
		cout << k+1 << ") " << "Interim result:\n";
		for (int i = 0; i < SIZE; i++)
		{
			cout << "x" << i+1 << " = " << result[i] << endl;
		}
		cout << endl << endl;

		// присваивание временной переменной снова значения матрицы свободных членов;
		for (int i = 0; i < SIZE; i++)
		{
			temp[i] = free_terms[i];
		}

		// проверка на eps;
		if (abs(result[k-1] - result2[k-1]) > eps)
		{
			for (int i = 0; i < SIZE; i++)
			{
				result2[i] = result[i];
			}
		}
		// выход из wbrkf while и вывод результатов в консоль;
		else {
			k = -1;
			cout << "Result:\n";

			for (int i = 0; i < SIZE; i++)
			{
				cout << "x" << i+1 << " = " << result[i] << endl;
			}
		}
	}
///////////////////////////////////////////////////////////////////////////////////


	return 0;
}


