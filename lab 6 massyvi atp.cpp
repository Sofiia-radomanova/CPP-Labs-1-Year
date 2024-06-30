// lab 6 massyvi atp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#define N 5

//#define R 5

int main()

{
	int SecretCode = 2;
	int V = ((20 + SecretCode) % 5) ? (20 + SecretCode) % 5 : 5;
	std::cout << "АнД - 11, Радоманова Софія, Варіант:" << V << '\n';
	/*1. Дано цілочисельну константу N (> 0). Сформувати і вивести цілочисельний
	*масив розміру N, що містить ступені двійки від першого до N : 2, 4, 8, 16, ...*/
	
std::cout << "Task 1\n";


int Mas [N];
int i = 1;
for (int i = 1; i < N; i++)
{
	Mas[i] = (std::pow(2, i));
	std::cout << "A [" << i << "]: " << Mas[i] << '\n';
}


	/*	2. Для введення задано цілочисельний масив розміру N.Вивести всі парні
		числа, що містяться в даному масиві, в порядку спадання їх індексів, а також
		їх кількість К.
		*/

std::cout << "Task 2\n";

	
	for (int i = 0; i < N; i++)
	{
		std:: cout << "Mas[" << i << "]: ";
		std:: cin >> Mas[i];
	}

	int Number{0};
	for (int i = N - 1; i >= 0; i--)
	{
		if(Mas[i]%2 == 0 )
		{
			std::cout << "Mas[" << i << "]: " << Mas[i] << " ";
			Number++;
		}
		std::cout << '\n';
	}
	std::cout << "Кількість парних чисел:" << Number << '\n';


	/*3. Для введення задано цілочисельний масив А розміру N і ціле число К(1 ≤ K
			≤ N).Вивести елементи масиву з порядковими номерами, що є кратними до K :
	АК, A2К, А3К, ... Оператор умови не використовувати.
		*/
	std::cout << "Task 3\n";

	for (int i = 0; i < N; i++)
	{
		std::cout << "Mas[" << i << "]: ";
		std::cin >> Mas[i];
	}

	int K{};
	std::cout << "Введіть число К:";
	std::cin >> K;

	for (int i = K ; i < N; i += K) {
		std::cout << "A[" << i << "]: " << Mas[i];
	}

	/*Під час розв’язку задач 4 та 5 потрібно використати явну ініціалізацію
		елементів масиву.
		4. Дано масив ненульових цілих чисел розміру N.Перевірити, чи утворюють
		його елементи геометричну прогресію.Якщо утворюють, то вивести
		знаменник прогресії, якщо ні – вивести 0.*/
	
	std::cout << "\nTask 4\n";
	int Mas1[N] = { 50, 100, 200, 4000, 800 };
	double L{};
	bool T = true;

	for (int i = 0; i < N; i++)
	{
		std::cout << "Mas[" << i << "]: " << Mas1[i] << '\n';
	}

	for (i = 0; i <N-1; i++)
	{
		 L = (Mas1[i+1]) / Mas1[i];
		 if (Mas1[i] * L != Mas1[i + 1])
		 {
			 T = false;
			 break;
		 }
		 
	}
	if (T==1)
	{
		std::cout<< "знаменник прогресії:"<< L;
	}
	else
	{
		std::cout << "Це не геометрична прогресія\n";
	}


		
		/*5. Дано масив розміру N.Знайти номери тих елементів масиву, які більше свого
		лівого сусіда, і кількість таких елементів.Знайдені номера виводити в порядку
		їх зменшення.*/

	std::cout << "\nTask 5\n";
	int Mas2[N] = { 296, 3, 849, 65, 17};

	for (int i = 0; i < N; i++)
	{
		std::cout << "Mas[" << i << "]: " << Mas2[i] << '\n';
	}

	int number_el{};
	for (int i = N - 1; i > 0; i--)
	{
		if (Mas2[i] > Mas2[i-1])
		{
			std::cout << i << ", ";
			number_el++;
		}
		
	}

	std::cout << "Кількість елементів: " << number_el;

	return 0;
}