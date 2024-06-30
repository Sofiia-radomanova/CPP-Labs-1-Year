
//	2. Для матриці Н розміром RxQ обчислити та вивести на екран суму непарних
//	елементів, значення яких належить інтервалу[a, b].


#include <iostream>
#include <iomanip> 
#include <limits>
#define R 4
#define Q 6


int main()
{


	std::cout << "Завдання 2" << '\n';
	int a;
	int b;
	int sum{};
	std::cout << "Початок проміжку: ";
	std::cin >> a;
	std::cout << "Кінець проміжку: ";
	std::cin >> b;

	int H[R][Q] = { };
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < Q; j++) {
			std::cout << "H[" << i << "][" << j << "]: ";
			std::cin >> H[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < Q; j++) {
			if (H[i][j] >= a && H[i][j] <= b && H[i][j] % 2 != 0) {
				sum += H[i][j];
			}
		}
	}
	std::cout << "Сума непарних елементів матриці H, що належать інтервалу [" << a << ", " << b << "]: " << sum << '\n';
	return 0;
}