

#include <iostream>
#include <fstream> // для роботи з файлами


int main() {
    std::cout << "Task 2\n";

    /*Задані ціле число K і набір ненульових цілих чисел.Вивести кількість чисел в наборі, менших за K.
        (Дані обробляються безпосередньо з файлу, масиви не застосовуються.
            Отримані вхідні дані та результати розрахунку виводяться на екран.)*/


    std::ifstream fin("input2.txt");
    // Відкриття файлу

    if (!fin.is_open())
    {
        std::cerr << "Помилка відкриття файлу!\n";
        return 1;
    }

    int K;
    fin >> K; // Зчитування числа K з файлу

    int countLessThanK = 0;
    int num;
    while (fin >> num) { // Читання чисел з файлу

        std::cout << num << ", ";

        if (num < K) 
        {
            countLessThanK++;
        }
        '\n';
    }

    std::cout << "Кількість чисел менших за " << K << ": " << countLessThanK << '\n';

    // Закрити файл
    fin.close();


    return 0;
}




