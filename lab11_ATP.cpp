

#include <iostream>
#include "Node.h"


//    Для реалізації стека написати функції :
// Node * push(Node * T, int x) – додає нове значення х до вершини стека
//T і повертає нове значення для T;
// Node* pop(Node* T) – видаляє значення з вершини стека і повертає
//нове значення для T;
// int top(Node* T) – повертає значення, що знаходиться на вершині T;
// void view(Node* T) – виводить на екран поточний вміст стека(увага!
//    елементи стеку зазвичай виводяться у порядку зворотному до їх
//    введення користувачем);
// bool empty(Node* T) – повертає «істину», якщо стек порожній;
// Node* T clear(Node* T) – очищує стек і повертає значення Т = nullptr.
//




// Додає нове значення х до вершини стека T і повертає нове значення для T;
Node* push(Node* T, int x) 
{
    Node* newNode = new Node(x);// Створюємо новий елемент
    newNode->next = T;//отримуємо значення поля next об'єкта, на який вказує вказівник newNode. Встановлюємо вказівник на T елемент
    return newNode;
}

// Видаляє значення з вершини стека і повертає нове значення для T;
Node* pop(Node* T) 
{
    if (T == nullptr) 
    {
        std::cout << "Stack is empty. Cannot pop." << std::endl;
        return nullptr;
    }
    Node* temp = T;// Тимчасовий вказівник на вершину стека
    T = T->next;// отримуємо значення поля next об'єкта, на який вказує вказівник T.Переміщаємо вершину на наступний елемент
    delete temp;// Видаляємо попередню вершину
    return T;
}

// Повертає значення, що знаходиться на вершині стека T
int top(Node* T) 
{
    if (T == nullptr)
    {
        std::cout << "Stack is empty. No top element." << std::endl;
        return -1; // Повертаємо якусь спеціальну помилкову значення
    }
    return T->data;
}

// Виводить на екран поточний вміст стека (у зворотньому порядку до їх введення)
void view(Node* T)
{
    std::cout << "Stack contents: ";
    while (T != nullptr)
    {
        std::cout << T->data << " ";
        T = T->next;
    }
    std::cout << std::endl;
}

// Перевіряє, чи є стек T порожнім
bool empty(Node* T) 
{
    return T == nullptr;
}

// Очищає стек і повертає значення T = nullptr
Node* clear(Node* T) 
{
    while (T != nullptr)
    {
        Node* temp = T;
        T = T->next;
        delete temp;
    }
    return nullptr;
}




int main() 
{

    //Node* T = nullptr; // Ініціалізуємо стек як порожній

    //// Додаємо елементи в стек
    //T = push(T, 1);
    //T = push(T, 2);
    //T = push(T, 3);
    //T = push(T, 4);
    //T = push(T, 5);

                    Stack originalStack;

                    // Додаємо елементи в оригінальний стек
                    originalStack.push(1);
                    originalStack.push(2);
                    originalStack.push(3);
                    originalStack.push(4);
                    originalStack.push(5);

                    Stack evenStack;
                    Stack oddStack;

                    // Розділяємо стек на парні та непарні числа, виводимо їх
                    originalStack.splitEvenOdd(evenStack, oddStack);
   
                    std::cout << "Even stack contents: \n";
                    evenStack.viewStack();
                    std::cout << "Odd stack contents: \n";
                    oddStack.viewStack();


                    std::cout << "Even stack after removal: \n";
                    evenStack.removeFromStack();
                    evenStack.viewStack();
                    std::cout << "Odd stack after removal: \n";
                    oddStack.removeFromStack();
                    oddStack.viewStack();

                   /* Stack unitedStack;
                    std::cout << "United stack: \n";
                    mergeStacks(evenStack, oddStack, unitedStack);
                    unitedStack.viewStack();*/



    //// Виводимо вміст стека
    //view(T);

    //// Перевіряємо, чи стек порожній
    //if (!empty(T)) 
    //{
    //    // Виводимо верхній елемент
    //    std::cout << "Top element: " << top(T) << std::endl;
    //}

    //// Видаляємо верхній елемент
    //T = pop(T);

    //// Виводимо оновлений вміст стека
    //view(T);

    //// Очищаємо стек
    //T = clear(T);

    //// Перевіряємо, чи стек порожній після очищення
    //if (empty(T))
    //{
    //    std::cout << "Stack is empty after clearing." << std::endl;
    //}

    return 0;
}




