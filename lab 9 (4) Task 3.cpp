#include <iostream>
#include <vector>
#include <cstdlib> // Для використання функції rand
#include <ctime>  
#include <iomanip> 

//3. З використанням генератора випадкових величин утворити масив А
//(кількість елементів масиву та діапазон значень для елементів задає
//	користувач).Реалізувати зсув елементів масиву вліво на К позицій(К задає
//		користувач).Зсув реалізувати двома способами : 1) поступово рухаючи
//		елементи масиву; 2) з використанням методів класу вектор.Елементи, що
//		“витискаються” з масиву втрачаються.


// Функція для зсуву елементів масиву вліво на К позицій
void var1(std::vector<int>& A, int k)
{
    for (int i = 0; i < A.size(); i++)
    {
        if ((i + k) < A.size())
        {
            A[i] = A[i + k];
        }
        else
        {
            A[i] = 0;
        }
    }

    if (A[0] == 0)
    {
        for (int i = 0; i < A.size(); i++)
        {
            A[i] = 0;
        }
    }
}

// Функція для зсуву елементів масиву вліво на К позицій з використанням методів класу вектор
void var2(std::vector<int>& A, int k)
{
    int t = A.size() - k;
    if (k >= A.size())
    {
        A.assign(A.size(), 0);
    }
    else
    {
        A.erase(A.begin(), A.begin() + k);
        if (k)
        {
            A.insert(A.begin() + t, k, 0);
        }
    }
}

int main()
{
    srand(time(NULL));
    int number;
    int t, a, b, k;


    std::cout << "Enter the method (1-array, 2-vector) " << std::endl;
    std::cin >> number;

    std::cout << "Input array size: " << std::endl;
    std::cin >> t;

    std::cout << "Input range of values: " << std::endl;
    std::cin >> a >> b;

    std::cout << "Input the number by which you want to shift " << std::endl;
    std::cin >> k;

    std::vector<int> A;

    for (int i = 0; i < t; i++)
    {
        A.push_back(a + rand() % (b + 1));
    }

    std::cout << std::endl << "Array A: " << std::endl;
    for (int i = 0; i < t; i++)
    {
        std::cout << A[i] << " ";
    }


    switch (number)
    {
    case 1: var1(A, k);

        std::cout << std::endl << "Shifted array A: " << std::endl;
        for (int i = 0; i < A.size(); i++)
        {
            std::cout << A[i] << " ";
        }
        break;

    case 2:  
        var2(A, k);

        std::cout << std::endl << "Shifted array A: " << std::endl;
        for (int i = 0; i < A.size(); i++)
        {
            std::cout << A[i] << " ";
        }
        break;
    }


    return 0;
}
