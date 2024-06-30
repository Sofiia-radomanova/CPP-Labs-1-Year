#include <iostream>
#include "Queue.h"
#include <fstream>

using namespace std;

void T2()
{
    // Створення трьох черг: T, even та odd
    Node* T = nullptr, * even = nullptr, * odd = nullptr;
    int t; //кількість чисел в черзі

    //1 
    cout << "How many numbers do you want to input in a queue? ";
    cin >> t;
    int a;

    // Введення чисел у чергу T
    for (int i = 0; i < t; i++)
    {
        cout << "Number: ";
        cin >> a;
        T = enque(T, a);
    }

    // Виведення черги T
    cout << "\nYour queue:\n";
    view(T);

    //2 
    cout << "\nDivision by even/odd:\n";

    // Перевірка чи черга порожня
    if (!empty(T))
    {
        Node* temp = T; //створення покажчика temp, який вказує на об'єкт, на який вказує покажчик T.

        // Поділ на парні та непарні числа та додавання їх у відповідні черги
        while (temp)
        {
            if (!(temp->data % 2))
                even = enque(even, temp->data);
            else
                odd = enque(odd, temp->data);
            temp = temp->next;
        }
    }

    // Виведення парних та непарних чисел
    cout << "Even "; view(even);
    cout << "Odd "; view(odd);

    //3 
    cout << "1 - Adding or 2 - Deleting?" << std::endl;
    cin >> t;

    switch (t)
    {
    case 1:
        cout << "\nHow many numbers do you want to input? ";
        cin >> t;

        // Додавання нових чисел у відповідні черги
        for (int i = 0; i < t; i++)
        {
            cout << "Number: ";
            cin >> a;
            if (!(a % 2))
                even = enque(even, a);
            else
                odd = enque(odd, a);
        }
        break;

    case 2:
        cout << "1 - Even queue, 2 - Odd queue";
        cin >> a;
        cout << "\nHow many numbers do you want to delete?" << endl;
        cin >> t;

        // Видалення елементів з відповідної черги
        for (int i = 0; i < t; i++)
        {
            if (a % 2)
            {
                if (!empty(even))
                    even = deque(even);
                else
                    break;
            }
            else
            {
                if (!empty(odd))
                    odd = deque(odd);
                else
                    break;
            }
        }
    }

    // Виведення змінених черг
    cout << "\nAfter changing:\n";
    cout << "Even "; view(even);
    cout << "Odd "; view(odd);

    //4 
   // Об'єднання черг even та odd, та виведення результату
    while (!empty(odd)) 
    {
        even = enque(even, first(odd)); // Додаємо значення першого елемента черги odd у чергу even
        odd = deque(odd); // Видаляємо перший елемент черги odd
    }

    cout << "\nYour final ";
    view(even);

}











int main()
{

    cout << "Task 2\n";
    
    T2();


    
    return 0;
}















/*
bool checkOrder(Node* conveyor, int K)
{
    // Черга для складу
    Node* warehouse = nullptr;

    // Виконання кроків накопичувача
    while (!empty(conveyor) || !empty(warehouse))
    {
        if (!empty(conveyor) && (empty(warehouse) || first(conveyor) < first(warehouse)))
        {
            // Переміщення контейнера зі стрічки в цех В
            warehouse = enque(warehouse, first(conveyor));
            conveyor = deque(conveyor);
        }
        else if (!empty(warehouse) && (empty(conveyor) || first(warehouse) < first(conveyor)))
        {
            // Переміщення контейнера зі складу в цех В
            warehouse = deque(warehouse);
        }
        else
        {
            // Переміщення контейнера зі стрічки в склад
            warehouse = enque(warehouse, first(conveyor));
            conveyor = deque(conveyor);
        }

    }

    // Перевірка чи впорядковані контейнери в цеху В
    double prevPriority = -1;
    while (!empty(warehouse))
    {
        double priority = first(warehouse);
        warehouse = deque(warehouse);

        if (priority < prevPriority) // Якщо поточний пріоритет менший за попередній
            return false; // Контейнери не впорядковані

        prevPriority = priority;
    }
    std::cout << "Warehouse state after step:\n";
    view(warehouse);

    // Після завершення перевірки впорядкованості виведення стану складу
    std::cout << "Warehouse state after checking order:\n";
    view(warehouse);
    return true; // Всі контейнери впорядковані
}


cout << "Task 3\n";

ifstream inputFile("input.txt"); // Відкриття вхідного файлу для зчитування
ofstream outputFile("output.txt"); // Відкриття вихідного файлу для запису

// Перевірка, чи вдалося відкрити вхідний файл
if (!inputFile.is_open()) {
    cout << "Unable to open input file\n";
    return 1;
}

// Перевірка, чи вдалося відкрити вихідний файл
if (!outputFile.is_open()) {
    cout << "Unable to open output file\n";
    return 1; // Припиняємо виконання програми, оскільки не вдається відкрити файл
}

// Перевірка, чи вдалося записати вихідний файл
if (!outputFile) {
    cout << "Error writing to output file\n";
    return 1; // Припиняємо виконання програми, оскільки не вдається записати в файл
}


int N; // Кількість тестів
inputFile >> N; // Зчитування кількості тестів з файлу

// Цикл обробки кожного тесту
for (int i = 0; i < N; ++i)
{
    int K; // Кількість контейнерів у поточному тесті
    inputFile >> K; // Зчитування кількості контейнерів для поточного тесту

    // Створення черги для стрічки контейнерів
    Node* conveyor = nullptr;

    // Зчитування контейнерів у стрічку
    for (int j = 0; j < K; ++j)
    {
        double priority;
        inputFile >> priority;
        conveyor = enque(conveyor, priority); // Додаємо контейнер з пріоритетом у чергу стрічки
    }

    // Виклик функції, яка перевіряє впорядкування контейнерів
    bool result = checkOrder(conveyor, K);

    // Виведення результату у вихідний файл
    outputFile << result << endl;


}

inputFile.close(); // Закриття вхідного файлу
outputFile.close(); // Закриття вихідного файлу

*/