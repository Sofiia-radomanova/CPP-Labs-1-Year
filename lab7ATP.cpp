#include <iostream>
#include <iomanip>
#include <limits>
#define M 6
#define N 4

int main()
{
    int V = ((20 + 8) % 6) ? (20 + 8) % 6 : 6;
    std::cout << "Варіант: " << V << '\n';

    // 1. Заданий набір з М чисел.Сформувати матрицю розміру MхN, у якій в
    // кожному стовпці містяться всі числа з вхідного набору(в тому ж порядку).

    std::cout << "Завдання 1\n";

    int numbers[M];     // вхідний набір чисел (тепер потрібно ввести лише один стовпчик)
    int matrix[M][N];   // результуюча матриця

    // Ввід вхідного набору чисел
    std::cout << "Введіть " << M << " чисел для першого стовпчика:\n";
    for (int i = 0; i < M; ++i)
    {
        std::cin >> numbers[i];
    }

    // Заповнення результуючої матриці
    for (int j = 0; j < N; ++j)
    { // по стовпцях
        for (int i = 0; i < M; ++i)
        { // по рядках
            matrix[i][j] = numbers[i];
        }
    }

    // Вивід результуючої матриці
    std::cout << "Результуюча матриця " << M << "x" << N << ":\n";
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
