
#include <iostream>
#include <vector>
#include <cmath>


//2. Заданий масив А дійсних з К елементів(К та елементи масиву вводяться
//	користувачем).Вивести на екран масив А та новий сформований масив В, в
//	якому записані ті елементи з масиву А, що округлюються до меншого цілого,
//	в порядку їх слідування.

int main()
{
	std::cout << "Task 2\n";
		
		std::vector<float> A; 
		int K; //кількість елементів в масиві
		float x; //значення
		std::cout << "Enter K count of elements: ";
		std::cin >> K;

		std::cout << "Enter the elements:";
		for (int i = 0; i < K; i++) 
		{
			std::cin >> x; //введення значень кожного елемента
			A.push_back(x);
		}



		std::cout << "Initial array A: ";
		for (int i = 0; i < A.size(); i++)
		{ //виведення на екран
			std::cout << A[i] << "  ";
		}
		
		std::vector<float> B;
		 

		for (std::vector<float>::iterator it = A.begin(); it != A.end(); it++) //ініціалізація ітератора , завдяки ітератору проходимо від 1 до останнього 
		{
			float integer = round(*it); // округлення до цілого;
			if (*it > integer)
			{
				B.push_back(*it);
			}
		}

		std::cout << "\nInitial array B: ";
		for (int i = 0; i < B.size(); i++)
		{ //виведення на екран
			std::cout << B[i] << "  ";
		}

}
