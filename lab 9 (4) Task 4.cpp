#include <vector>
#include <iostream>


//4. Заданий масив А, що містить впорядковані за спаданням цілі числа(числа
//	можуть повторюватися).Видалити з масиву елементи, що повторюються,
//	залишивши їх останнє входження.Перед непарними елементів вставити задане
//	користувачем число К.Вивести на екран поточний розмір, ємність та
//	максимальний розмір вектора до видалення елементів, після видалення та
//	після вставки.


int main()
{
	int K;
	std::cout << "Task 4";
	std::vector<int> A = { 5, 5, 4, 4, 3, 3, 2, 2, 1, 1, 0, 0 };

	std::cout << std::endl << "Initial array: ";
	for (int i = 0; i < A.size(); ++i) 
	{ //вивід на екран
		std::cout << A[i] << " ";
	}

	std::cout << "\nEnter the K:";
	std::cin >> K;


	std::cout << std::endl << "Vector size before deleting: " << A.size();
	std::cout << std::endl << "Vector capacity before deleting:" << A.capacity();
	std::cout << std::endl << "Vector max size before deleting:" << A.max_size();
	


	for (int i = 0; i < A.size() - 1; i++) //стирання елементів  що повторюються
	{
		if (!(A[i] > A[i + 1]))
		{
			A.erase(A.begin() + i);
			i--;
		}
	}

	std::cout <<  "\nInitial array: ";
	for (int i = 0; i < A.size(); ++i)
	{ //вивід на екран
		std::cout << A[i] << " ";
	}
	std::cout << std::endl << "Vector size after deleting: " << A.size();
	std::cout << std::endl << "Vector capacity after deleting:" << A.capacity();
	std::cout << std::endl << "Vector max size after deleting:" << A.max_size();
	

	for (int i = 0; i < A.size(); i++) 
	{
		if (A[i] % 2==1) 
		{
			A.insert(A.begin() + i, K); 
			i++; 
		}
	}
	std::cout  << "\nInitial array: ";
	for (int i = 0; i < A.size(); ++i)
	{ //вивід на екран
		std::cout << A[i] << " ";
	}
	std::cout << std::endl << "Vector size after inserting: " << A.size();
	std::cout << std::endl << "Vector capacity after inserting:" << A.capacity();
	std::cout << std::endl << "Vector max size after inserting:" << A.max_size();



}


