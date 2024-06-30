#include <iostream>
#include <iomanip> 
#include <limits>
#define M 4
#define N 4


int main()
{


	//	5. Дана цілочисельна матриця розміру MхN.Знайти номер першого з її
	//	стовпців, що містить однакову кількість додатних і від’ємних елементів
	//	(нульові елементи матриці не враховуються).Якщо таких стовпців немає, то
	//	вивести 0.
	std::cout << "Завдання 5" << '\n';

	int matrix[M][N] = { {1, -1, 1, 1 }, {5, -7,- 7, 8}, {-9, 11, 11, 11}, {-13, -14, 11, -16} };
	int i = 0;
	int j = 0;
	int columnIndex = 0;
	bool foundColumn = false;

	for (j = 0; j < N; ++j)
	{
		int count = 0;// кількість від'ємних чисел  в стовпчику
		int count1 = 0;// кількість додатних чисел в стовпчику

		for (i = 0; i < M; ++i)
		{
			if (matrix[i][j]<0)
			{
				count++;
			}
			if (matrix[i][j] > 0)
			{
				count1++;
			}
		
		}
		
		if (count == count1 && count!= 0)
		{
			columnIndex = j + 1; // Номер стовпця, якщо знайдено
		foundColumn = true;
		break; // Вийти з циклу, якщо знайдено
	    }
	}


	if (foundColumn) {
		std::cout << "Номер першого стовпця, що містить однакову кількість додатних і від’ємних елементів: " << columnIndex << '\n';
	}
	else {
		std::cout << "0\n";
	}
	
	return 0;
}
