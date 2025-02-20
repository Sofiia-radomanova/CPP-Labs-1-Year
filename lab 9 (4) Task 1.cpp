﻿
#include <iostream>
#include <vector>



int main()
{
	std::cout << "Радоманова Софія АнД-11, варіант:";
	int V = ((20 +5) % 5) ? (20 + 5) % 5 : 5;
	std::cout << V;

	
	std::cout << "\nTask 1\n";

	/*1. Заданий масив А цілих чисел(елементи масиву задати під час опису у списку
		ініціалізації).Визначити кількість ділянок(серій), на яких елементи масиву
		мають однакові значення.Вивести на екран масив, його поточний розмір а
		також отриману кількість ділянок(серій).*/

	std::vector<int> A = { 1, 2, 19, 5, 6, 10, 11,  23,  42, 24,  7, 1 };
	std::cout << "Initial array: ";
	for (int i = 0; i < A.size(); i++)
	{ //вивід на екран
		std::cout << A[i] << " ";
	}
	std::cout << '\n' << "Vector size: " << A.size() << '\n';

	int prev;
	int count = 0;
	for (std::vector<int>::iterator i = A.begin(); i != A.end()-1; i++) //ініціалізація ітератора , завдяки ітератору проходимо від 1 до останнього 
	{
		if (*i == *(i + 1)) // Якщо значення елементу = значенню наступного елементу 
		{
			if (prev != *(i + 1)) // Якщо значення попереднього елементу не дорівнює значенню наступного
			{
			count++;
			}
		}
		prev = *i;
	}
	std::cout << "Kількість ділянок(серій)" << count;


}

