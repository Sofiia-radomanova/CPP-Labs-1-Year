#include <iostream>
#include <cmath>
#include <Windows.h>


double log_b(double base, double x)
{
	return (std::log(x) / std::log(base));
}


int main()
{
	SetConsoleOutputCP(1251);

	int V{ (20 % 5) ? 20 % 5 : 5 };

	std::cout << "Радоманова Софія АнД-11, Варіант: " << V << '\n';
	std::cout << "\nTask 1\n";


	int x{};
	std::cout << "Enter x: ";
	std::cin >> x;

	int y{};
	std::cout << "Enter y: ";
	std::cin >> y;


	if (x > 0 && x <= 9 && x != 1)
	{
		y = (log_b(x, 10) / std::fabs(std::pow(x, 2)) + 3);
		std::cout << "y = " << y << '\n';
	}
	else
	{
		if (x == 1)
		{
			std::cout << "Function is not defined.\n";
		}
		else
		{
			y = std::exp(std::pow(x, 3));
		}
		std::cout << "y = " << y << '\n';
	}

	///////////////////////
	// Task 2
	std::cout << "\nTask 2\n";

	double x_c	{2};
	double y_c	{0};
	double R	{std::pow(x_c, 2) + std::pow(y_c, 2)};

	double x_u {};
	std::cout << "Enter x: ";
	std::cin >> x_u;

	double y_u {};
	std::cout << "Enter y: ";
	std::cin >> y_u;

	double distance_cu{ std::sqrt(std::pow((x_u - x_c), 2) + std::pow((y_u - y_c), 2)) };

	if (R < distance_cu && x_u < 4 && x_u > -4 && y_u < 4 && y_u > -4)
	{
		std::cout << "Точка з координатами (" << x_u << ", " << y_u << ") потрапляє у задану область.\n";
	}
	else
	{
		std::cout << "Точка з координатами (" << x_u << ", " << y_u << ") не потрапляє у задану область.\n";
	}

	/////////////
	// Task 3
	/*
	Задані три змінні цілого типу А, В, С. Якщо хоча б одна
	з них парна, то замінити кожну змінну на середнє значення двох інших, інакше кожну змінну зменшити вдвічі.
	*/
	std::cout << "\nTask 3\n";

	int A{};
	std::cout << "Enter A: ";
	std::cin >> A;

	int B{};
	std::cout << "Enter B: ";
	std::cin >> B;

	int C{};
	std::cout << "Enter C: ";
	std::cin >> C;

	if (!(A % 2) || !(B % 2) || !(C % 2))
	{
		int temp_A{ A };
		int temp_B{ B };

		A = (temp_B + C) / 2;
		B = (temp_A + C) / 2;
		C = (temp_B + temp_A) / 2;
	}
	else
	{
		A /= 2;
		B /= 2;
		C /= 2;
	}
	std::cout << "A=" << A << " B=" << B << " C=" << C << '\n';
	// true && false = false
	// true && true = true
	// true || false = true
	// false || false = false
	///4. Елементи рівностороннього трикутника пронумеровані в такий спосіб: 1 –
        //сторона a, 2 - радіус r вписаного кола, 3 - радіус R описаного кола, 4 – площа
		//S.Дано номер одного з цих елементів(ціле число в діапазоні 1 - 4) і його
		//значення(дійсне число).Вивести значення інших елементів даного трикутника
		//(в тому ж порядку). 
		//  S=a2 sqrt3 / 4  
	//R=a/sqrt3
	//r=a/2sqrt3

	std::cout << "\n Task 4 \n" ;
	int X; 
	double Y;
	std::cout << "Enter X (1-4)  \n";
	std::cin >> X;
	std::cout << " Enter Y \n ";
	std::cin >> Y;
		if (X<=0 || X>4 || y<0 ) 
		{
			std::cout << "Function is not defined.\n";
		}
		else
		{
			switch (X)
			{
			case 1:
				std::cout << "a= " << Y << '\n';
				std::cout << "r =" << Y / (2 * sqrt(3)) << '\n';
				std::cout << "R =" << Y / sqrt(3) << '\n';
				std::cout << "S= " << Y * Y * sqrt(3) / 4 << '\n';
				break;
			case 2:
				std::cout << "a= " << Y * 2 * std::sqrt(3) << '\n';
				std::cout << "r =" << Y << '\n';
				std::cout << "R =" << Y * 2 << '\n';
				std::cout << "S= " << Y * Y * 3 * std::sqrt(3) << '\n';
				break;
			case 3:
				std::cout << "a= " << Y * std::sqrt(3) << '\n';
				std::cout << "r =" << Y / 2 << '\n';
				std::cout << "R =" << Y << '\n';
				std::cout << "S= " << (Y * Y * 3 * std::sqrt(3)) / 4 << '\n';
				break;
			case 4:
				std::cout << "a= " << std::sqrt(Y * 4 / std::sqrt(3)) << '\n';
				std::cout << "r =" << std::sqrt(Y / (3 * std::sqrt(3))) << '\n';
				std::cout << "R =" << 2 * std::sqrt(Y / (3 * std::sqrt(3))) << '\n';
				std::cout << "S= " << Y << '\n';
				break;
			}
		}

	std::cout << "\n Task 5 \n";
	//Задане ціле К, що визначає номер кольору у веселці. Вивести на екран
	//повідомлення, чи є цей колір теплим чи холодним.
	int K;
	std::cout << "Enter the color (1-red, 7-violet)  \n";
	std::cin >> K; '\n';
	if (K < 0 || K > 7)
	 {
		std::cout << "unavailable";
	 }
	else
	{
		switch (K)
		{
		case 1: case 2: case 3: std::cout << "Warm \n";
		break;

		case 4: case 5: case 6: case 7: std::cout << "Cold \n";
		break;
		}
	}



	return 0;
}

