//	3. Для матриці К розміром NxM визначити та вивести на екран : 1) найменший
//	елемент для кожного рядка; 2) найбільший елемент для кожного стовпця.

#include <iostream>
#include <iomanip> 
#include <limits>
#define M 4
#define N 4

int main()
{
	std::cout << "Завдання 3" << '\n';

	int numbers1[M * N]; // вхідний набір чисел
	int matrix1[M][N];   // результуюча матриця

	int i = 0;
	int j = 0;

	// Ввід вхідного набору чисел
	std::cout << "Введіть " << M * N << " чисел:\n";
	for (int i = 0; i < M * N; ++i)
	{
		std::cin >> numbers1[i];

	}

	// Заповнення результуючої матриці
	int rowIndex = 0;
	for (int i = 0; i < M * N; ++i)
	{
		matrix1[rowIndex][j] = numbers1[i];
		++rowIndex;
		if (rowIndex == M) 
		{
			rowIndex = 0;
			++j;
			std::cout << '\n';
		}
	}

//вивід результуючої матриці
	std::cout << "Задана матриця: \n";
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << matrix1[i][j] << '\t';
		}
		std::cout << '\n';
	}



	// 1) Найменший елемент для кожного рядка
	std::cout << "Найменший елемент для кожного рядка:\n";
	for (int i = 0; i < N; ++i)
	{
		int minInRow = matrix1[i][0]; // Перший елемент у рядку
		for (int j = 1; j < M; ++j)
		{
			if (matrix1[i][j] < minInRow)
			{
				minInRow = matrix1[i][j];
			}
		}
		std::cout << "Рядок " << i + 1 << ": " << minInRow << '\n';
	}

	// 2) Найбільший елемент для кожного стовпця
	std::cout << "\nНайбільший елемент для кожного стовпця:\n";
	
	for (int j = 0; j < M; ++j)
	{
		int maxInCol = matrix1[0][j]; // Перший елемент у стовпці
		for (int i = 1; i < N; ++i)
		{
			if (matrix1[i][j] > maxInCol)
			{
				maxInCol = matrix1[i][j];
			}
		}

		std::cout << "Стовпець " << j + 1 << ": " << maxInCol << '\n';
	}
	return 0;
}