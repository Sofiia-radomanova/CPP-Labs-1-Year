#include <iostream>
#include <cmath>


int sumRange (int A, int B) // 1 Task
{
	if (A>B)
	{
		return 0;
	}
	int sum{0};
	for (int i{ A }; i <= B; i++)
	{
		sum += i;
	}
	return sum;
}


bool isSquare(int K) // 2 Task
{
	return !(std::sqrt(K) - static_cast<int> (std::sqrt(K))); //static_cast<int> перетворення типу значення на ціле
}

void аddLeftDigit(int D, int& K) //3 task
{
	for (int i{ K }; i > 0; i /= 10)
	{
	D *= 10;
	}
	K += D;
}


void swap(int& x, int& y)
{
	x += y;
	y = x - y;
	x -= y;
}

// Swapping numbers without temporary variable
	// n1 += n2
	// n2 = n1 - n2
	// n1 -= n2
void shiftLeft3(int& A, int& B, int& C)
{
	swap(B, C);
	swap(A, B);
}

char f(char a, char b)//Task 5
{

	return a * a + b * b;

}

long f(long a, long b) 
{

	return a * a + b * b;

}

double f(double a, double b)
{

	return a * a + b * b;

}



//int f(int a) { 
//return a * a + b * b; 
//} 
int f(int a, int b = 10)
{

	return a * a + b * b;

}



template <typename T>

T f(const T a, const T b) 
{

	return a * a + b * b;

}

int main()
{

	int V = ((3 + 6) % 5) ? (3 + 6) % 5 : 5;
	std::cout << "Варіант:" << V << '\n';


	/*1. Описати функцію sumRange(A, B) цілого типу, що знаходить суму всіх цілих
		чисел від A до B включно(A і B – цілі).Якщо A > B, то функція повертає 0. За
		допомогою цієї функції знайдіть суми чисел від X до Y і від Y до Z(X, Y, Z
			задає користувач).*/

	std::cout << "Task 1\n";
	int x{};
	int y{};
	int z{};
	std::cout << "Введіть ціле X:";
	std::cin >> x;
	std::cout << "Введіть ціле Y:";
	std::cin >> y;
	std::cout << "Введіть ціле Z:";
	std::cin >> z;

	std::cout << "Сума від Х до Y:" << sumRange(x, y) << '\n';
	std::cout << "Сума від Y до Z:" << sumRange(y, z) << '\n';

	/*2. Описати функцію іsSquare(K) логічного типу, яка повертає true, якщо цілий
		параметр K(К > 0) є квадратом деякого цілого числа, і false у протилежному
		випадку.За допомогою цієї функції знайти кількість квадратів у наборі з 10
		цілих додатних чисел.*/

	std::cout << "Task 2\n";

	int count{ 0 };
	for (int i{ 1 }; i <= 10; i++)
	{
		std::cout << std::boolalpha << i << " " << isSquare(i) << '\n'; //boolalpha виводить true/false
		count += isSquare(i);
	}
	std::cout << "кількість квадратів у наборі з 10 цілих додатних чисел:" << count << '\n';


	/*3. Описати функцію аddLeftDigit(D, K), додаючи до запису цілого додатного
		числа K зліва цифру D(D – вхідний параметр цілого типу, що лежить у
			діапазоні 1–9, K – параметр цілого типу, що є одночасно вхідним та вихідним).
		За допомогою цієї функції послідовно додайте до заданого числа K цифри D1
		і D2, виводячи результат кожного додавання на екран.*/

	std::cout << "Task 3\n";

	int D1{};
	int D2{};
	int K{};

	std::cout << "Введіть ціле K:\n";
	std::cin >> K;
	std::cout << "Введіть ціле D1:\n";
	std::cin >> D1;
	std::cout << "Введіть ціле D2:\n";
	std::cin >> D2;

	аddLeftDigit(D1, K);
	std::cout << K << '\n';
	аddLeftDigit(D2, K);
	std::cout << K << '\n';

	///*4. Описати функцію shiftLeft3(A, B, C), яка виконує лівий циклічний зсув :
	//значення A переходить в B, значення B – в C, значення C – в A(A, B, C – дійсні
	//	параметри, що є одночасно вхідними та вихідними).За допомогою цієї функції
	//	виконайте лівий циклічний зсув для двох наборів з трьох чисел : (A1, B1, C1) та
	//	(A2, B2, C2).

	// Swapping numbers without temporary variable
	// n1 += n2
	// n2 = n1 - n2
	// n1 -= n2

	std::cout << "Task 4 \n";
	int A1{};
	int B1{};
	int C1{};
	int A2{};
	int B2{};
	int C2{};

	std::cout << "Введіть ціле A1: ";
	std::cin >> A1;
	std::cout << "Введіть ціле B1: ";
	std::cin >> B1;
	std::cout << "Введіть ціле C1: ";
	std::cin >> C1;
	std::cout << "Введіть ціле A2: ";
	std::cin >> A2;
	std::cout << "Введіть ціле B2: ";
	std::cin >> B2;
	std::cout << "Введіть ціле C2: ";
	std::cin >> C2;

	shiftLeft3(A1, B1, C1);
	shiftLeft3(A2, B2, C2);

	std::cout << A1 << "," << B1 << "," << C1 << '\n';
	std::cout << A2 << "," << B2 << "," << C2 << '\n';

	/*5. Описати перевантажені функції та функцію - шаблон(див.завдання 3 до
		лабораторної роботи) для знаходження суми квадратів двох заданих чисел.*/
	std::cout << "Task 5\n";
	std::cout << "char:" << f('x', 'y') << '\n';
	std::cout << "long:" << f(56, -24) << '\n';
	std::cout << "double:" << f(4.3, 12.5) << '\n';
	std::cout << "За замовченням:" << f(5) << '\n';
	std::cout << "template Long:" << f<long>(17, -3) << '\n';
	std::cout << "template Char:" << f<char>('s', 'p') << '\n';
	std::cout << "template Double:" << f<double>(2.5, 3.5) << '\n';

	return 0;

}
