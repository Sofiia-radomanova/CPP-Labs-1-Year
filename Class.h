#pragma once
#include <iostream>
#include "Node.h"

// Клас для стека
class Stack
{
private:
    Node* top; // Вказівник на вершину стека

public:
    Stack() : top(nullptr) {}

    // Додати елемент до вершини стека
    void push(int value)
    {
        Node* newNode = new Node(value); // Створюємо новий елемент
        newNode->next = top; //отримуємо значення поля next об'єкта, на який вказує вказівник newNode. Встановлюємо вказівник на наступний елемент на поточну вершину
        top = newNode; // Оновлюємо вершину стека
    }

    // Видалити елемент з вершини стека
    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }
        Node* temp = top; // Тимчасовий вказівник на вершину стека
        top = top->next; // отримуємо значення поля next об'єкта, на який вказує вказівник top.Переміщаємо вершину на наступний елемент
        delete temp; // Видаляємо попередню вершину
    }

    // Перевірка на порожність стека
    bool isEmpty() const
    {
        return top == nullptr;
    }


    // Розділити стек на два окремих стека: парні та непарні числа (для перевірки додаткової)
    void splitEvenOdd(Stack& evenStack, Stack& oddStack)
    {
        Node* current = top;
        while (current != nullptr)
        {
            if (current->data % 2 == 0)
                evenStack.push(current->data);
            else
                oddStack.push(current->data);
            current = current->next;
        }
    }

};


