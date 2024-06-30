#include <iostream>
#include <cmath>


int main()
{

	int V{ (9 % 5) ? 20 % 5 : 5 };

	std::cout << "Радоманова Софія АнД-11, Варіант: " << V << '\n';
	std::cout << "\nTask 1\n";
	//1. Дано додатні числа A, B, C. На прямокутнику розміру A х B розмістити
	//максимально можливу кількість квадратів зі стороною C(без накладання).
	//Знайти кількість квадратів, розміщених на прямокутнику.Операції множення
	//і ділення не використовувати.

	float A{};
	std::cout << "Введіть A:\n";
	std::cin >> A;
	float B{};
	std::cout << "Введіть B:\n";
	std::cin >> B;
	float C{};
	std::cout << "Введіть C:\n";
	std::cin >> C;
	float i{0};
	float B_tmp{};
	if (C > 0 && A > 0 && B > 0)
	{
		if (C <= A && C <= B)
		{
			while (A >= C)
			{
				A -= C;
				B_tmp = B;
				while (B_tmp >= C)
				{
					B_tmp -= C;
					i++;
				}

			}
			std::cout << "кількість квадратиків:" << i << '\n';
		}
		else
		{
			std::cout << "жодного квадратика";
		}
	}
	else
	{
		std::cout << "Незадовільні значення";
	}

	//Дано ціле число N(N > 1).Знайти найбільше ціле число K, при якому
   //виконується нерівність 3^K < N.
	std::cout << "\nTask 2\n";
	float N{};
	float K{};

	std::cout << "Вставте N:";
	std::cin >> N;
	if (N > 1)
	{
		K = 0;
		do
		{
			K++;
		} while (pow(3, K) < N);
		std::cout << "K=" << K - 1;
	}
	else
		std::cout << "N не задовольняє умові\n";

	//3. Дано ціле число N (N > 1). Вивести найменше із цілих чисел K, для яких сума
	//1 + 2 + ... + K буде більше або дорівнює N, і саму цю суму.
	std::cout << "\n Task 3\n";

	float S = {};
	float P = {};
	float sum{};
	std::cout << "Введіть N (N>1):\n";
	std::cin >> S;
	if (S > 1)
	{
		P = 1;
		sum = 1;
		while (sum < S)
		{
			P++;
			sum = sum + P;
		}
		std::cout << "K=" << P << '\n' << "Сума=" << sum;
	}
	else
		std::cout << "N не задовольняє умові\n";

	//4. Дано ціле числа N (N > 0) та М (0 ≤ M ≤ 9). За допомогою операцій ділення
	//і остачі від ділення змінити значення числа N видаливши з запису цього числа
	//	цифри M.Наприклад, N = 125354, M = 5, отримуємо 1234; для N = 333, M = 3
	//	маємо отримати 0.

	std::cout <<"\n Task 4\n";
	int N1{};
	int M1{};
	int newN{ 0 };
	
	while (true)
	{
		std::cout << "0 < N =";
		std::cin >> N1;
		std::cout << "0 <= M <= 9=";
		std::cin >> M1;
			if (N1<= 0 || M1< 0 || M1>= 9)
			{
				std::cerr << "Помилка!\n";
			
			}
			break;
	}
	int i1{1 };
	while (N1 >0)
	{
		int digit{ N1 % 10}; 
		if (digit!= M1)
		{
			newN = newN + digit * i1;
		}
		N1= N1/ 10;
		i1 *= 10;
		
	}
	std::cout << newN << '\n';

	/* 5. Дано ціле число N (N > 1), що є числом Фібоначчі: N = Fk Послідовність
	чисел Фібоначчі Fk визначається наступним чином :
	F1 = 1, F2 = 1, Fk = Fk−2 + Fk−1, де k = 3, 4, ....
		Знайти ціле число K - порядковий номер числа Фібоначчі N.*/

	std::cout << "Task 5\n";
	int Fn{  };
	
	while (true)
	{
		std::cout << "Введіть число Фібоначчі (N>1) \n";
		std::cin >> Fn;
		if (Fn <= 1)
		{
			std::cout << "Помилка: N <= 1.\n";
			continue;
		}
		break;
	}

	int F1{ 1 };
	int F2{ 2 };
	int K3{ 2 };
	int temp{};

	while (F2 < Fn)
	{
		temp = F2;
		F2 = F1 + F2;
		F1 = temp;
		K3+= 1;
	}
	std::cout << "K=" << K3<< '\n';

	return 0;
}
