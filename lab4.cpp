#include <iostream>
#include <cmath>
double expo(double base, double exponent)
{
	if (exponent <= 0)
	{
		return 1;
	}
	return expo(base, --exponent) * base;
}

long double factorial (int number)
{
	if (number <= 1)
	{
		return 1;
	}
	return (number * factorial(--number));
}

int main()
{
	int V = (14328013 % 5) ? 14328013 % 5 : 5;
	std::cout << "Варіант:" << V;

	std::cout << "Task 1\n";
	/*1. Дано два цілих числа A і B(A < B).Знайти суму квадратів всіх цілих чисел
		від A до B включно.*/
	int A{};
	int B{};
	int A1{};
	int sum{0};
	std::cout << "Введіть ціле A (A<B):";
	std::cin >> A;
	std::cout << "Введіть ціле B (B>A):";
	std::cin >> B;
	for (int i{A}; i <=B; i++ )
	{	
		sum += i*i;
	}
	std::cout << "Сума квадратів цілих чисел від A до B:" << sum << '\n';
	

	std::cout << "Task 2\n";
	/*2. Дано ціле число (N> 0).Знайти добуток 1.1 · 1.2 · 1.3 · ... для N
			співмножників.*/
	int N{}; // ітерації
	double result{1}; // 
	std::cout << "Введіть значення N:";
	std::cin >> N;

	for (int i{ 1 }; i <= N; i++)
	{
		
		result *= (1 + i * 0.1);
		
	}
	std::cout << "Добуток =" <<  result << '\n';

	/////*3. Дано дійсне число A і ціле число N(> 0).Знайти значення виразу

	////	1 - A + A^2 - A^3 + ... + (–1)^N·A^N

	std::cout << "Task 3\n";
	float A2{};
	int N1 {};
	std::cout << "Введіть дійсне A:";
	std::cin >> A2;
	std::cout << "Введіть ціле N (N>0):";
	std::cin >> N1;
	float result1{0};
	for (int i{ 0 }; i <= N1; i++)
	{

		result1 += expo(-1, i) * expo(A2, i);
	}
	std::cout << "Результат:" << result1 << '\n';


		/*4. Дано дійсне число X і ціле число N(> 0).Знайти значення виразу

		1 – X^2/ (2!) + X^4/ (4!) – ... + (–1)^N·X^(2·N) / ((2·N)!)

		(N!= 1 · 2 · ... · N).Отримане число є наближеним значенням функції cos в
		точці X.*/

	std::cout << "Task 4:\n";
	float X{};
	int N10{};
	std::cout << "Введіть дійсне X:";
	std::cin >> X;
	std::cout << "Введіть ціле N:";
	std::cin >> N10;
	
	float result2{ 0 };
	for (int i{ 0 }; i <= N; i++)
	{
		result2 += expo(-1, i) * expo(X, 2 * i) / factorial(2 * i);
	}
	std::cout << "Результат:" << result2 << '\n';




		/*5. Дано ціле число N(> 0).Послідовність дійсних чисел АК визначається
		наступним чином :

	A1 = 1, A2 = 1, AK = K / (AK - 1 + AK - 2) для K = 3, 4, ....

		Вивести елементи A1, A2, ..., AN.*/

	std::cout << "Task 5:\n";

	int N28{};
	std::cout << "Введіть ціле N:";
	std::cin >> N28;

	double A93{ 1 };
	double A92{ 1 };
	std::cout << "A_1 = 1\n";
	std::cout << "A_2 = 1\n";
	for (int i (3); i <= N28; i++)
	{
		A92 += A93;
		A93 = A92 - A93;
		A92 -= A93;
		A92 = i / (A93 + A92);
		std::cout << "A_" << i << " = " << A92 << '\n';

	}
	
	return 0;

}