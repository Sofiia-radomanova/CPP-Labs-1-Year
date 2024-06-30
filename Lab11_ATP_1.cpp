#include <iostream>
#include "Stack.h"

using namespace std;


void T1()
{
    // Створення трьох стеків: T, even та odd
    Stack T, even, odd;
    int t;

    //1 
    cout << "How many numbers do you want to input in stack? "; 
    cin >> t;
    int a;

    // Введення чисел у стек T
    for (int i = 0; i < t; i++)
    {
        cout << "Number: "; 
        cin >> a;
        T.push(a);
    }

    // Виведення стеку T
    cout << "\nYour stack:\n";
    T.view();

    //2 
    cout << "\nDivision by even/odd:\n";
    Node* temp = T.Top;

    // Поділ на парні та непарні числа та додавання їх у відповідні стеки
    while (temp)
    {
        if (!(temp->data % 2))
            even.push(temp->data);
        else
            odd.push(temp->data);
        temp = temp->next;
    }

    // Виведення парних та непарних чисел
    cout << "Even: "; even.view();
    cout << "Odd: "; odd.view();

    //3 
    cout << "1 - Adding or 2 - Deleting?" << endl; 
    cin >> t;

    switch (t)
    {

    case 1:
        cout << "\nHow many numbers do you want to input? "; 
        cin >> t;

        // Додавання нових чисел у відповідні стеки
        for (int i = 0; i < t; i++)
        {
            cout << "Number: "; 
            cin >> a;
            if (!(a % 2))
                even.push(a);
            else
                odd.push(a);
        }
        break;

    case 2:
        cout << "1 - Even stack, 2 - Odd stack"; cin >> a;
        cout << "\nHow many numbers do you want to delete?" << endl;
        cin >> t;

        // Видалення елементів з відповідного стеку
        for (int i = 0; i < t; i++) 
        {
            if (a % 2)
            {
                if (!even.empty())
                    even.pop();
                else
                    break;
            }

            else
            {
                if (!odd.empty())
                    odd.pop();
                else
                    break;
            }
        }
    }

    // Виведення змінених стеків
    cout << "\nAfter changing:\n";
    cout << "Even: "; even.view();
    cout << "Odd: "; odd.view();

    //4 
    // Об'єднання стеків even та odd, та виведення результату
    even.push(odd);
    cout << "\nYour final stack:\n";
    even.view();
}


int main()
{
    // Виклик функції для роботи зі стеками
    T1();

    return 0;
}
