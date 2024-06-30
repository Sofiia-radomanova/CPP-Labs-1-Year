
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


int main()
{

	std::cout << "Task 4\n";

	//4. Задані ціле число K, а також K наборів ненульових цілих чисел.Кожен набір
	//містить не менше двох елементів, ознакою його завершення є число 0. Знайти
	//кількість наборів, елементи яких зростають або зменшуються.
	
	//(Дані обробляються безпосередньо з файлу, масиви не застосовуються.
	//	Структура файлу аналогічна до задачі 3.
	//	Отримані вхідні дані та результати розрахунку виводяться на екран.)


	std::ifstream fin("input4.txt");


	if (!fin.is_open())
	{
		std::cerr << "Помилка відкриття файлу!\n";
		return 1;
	}

	int K;
	fin >> K; // Зчитування числа K з файлу
    int count = 0; // Лічильник кількості наборів зростаючих або зменшуючих послідовностей

    for (int i = 0; i <= K; i++)
    {
        int prev, current;
        fin >> prev >> current; // Читаємо перші два числа
        if (prev == 0 || current == 0) 
        {
            continue; // Пропускаємо набори з менше ніж двома елементами
        }

        bool isIncreasing = current > prev;
        bool isValid = true;

        while (current != 0) 
        {
            prev = current;
            fin >> current;
            if (current == 0)
            {
                break;
            }
            if ((isIncreasing && current <= prev) || (!isIncreasing && current >= prev))
            {
                isValid = false;
                break;
            }
        }

        if (isValid) 
        {
            count++;
        }
    }

    std::cout << "Кількість наборів зростаючих або зменшуючих послідовностей: " << count << '\n';

    fin.close();



	return 0;
}