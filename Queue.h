#pragma once
#include <iostream>

// Оголошення структури для вузла списку
struct Node
{
	int data;       // Дані вузла
	Node* next;     // Вказівник на наступний вузол
	Node() { data = 0; next = nullptr; } // Конструктор за замовчуванням
	Node(int x) { data = x; next = nullptr; } // Конструктор з параметром //ДАБЛ
};




// Додає елемент в кінець черги
Node* enque(Node* T, int x)
{
    Node* newNode = new Node(x); // Створюємо новий вузол

    // Якщо черга порожня, встановлюємо початок черги
    if (!T)
    {
        return newNode;
    }

    // Інакше, шукаємо кінець черги
    Node* temp = T;
    while (temp->next)
    {
        temp = temp->next;
    }

    // Додаємо новий елемент в кінець черги
    temp->next = newNode;
    return T;
}

// Видаляє перший елемент з черги
Node* deque(Node* H)
{
    // Якщо черга порожня, повертаємо nullptr
    if (!H)
    {
        return nullptr;
    }

    Node* temp = H->next; // Зберігаємо посилання на другий елемент
    delete H; // Видаляємо перший елемент
    return temp; // Повертаємо новий початок черги
}

// Повертає значення першого елемента черги
int first(Node* H)
{
    // Якщо черга порожня, повертаємо -1 
    if (!H)
    {
        return -1;
    }
    return H->data; // Повертаємо значення першого елемента
}

// Повертає значення останнього елемента черги
int last(Node* T)
{
    // Якщо черга порожня, повертаємо -1 
    if (!T)
    {
        return -1;
    }
    // Шукаємо кінець черги
    while (T->next)
    {
        T = T->next;
    }
    return T->data; // Повертаємо значення останнього елемента
}

// Перевіряє, чи черга порожня
bool empty(Node* H)
{
    return H == nullptr; // Черга порожня, якщо початок черги nullptr
}

// Виводить на екран елементи черги
void view(Node* H)
{
    // Якщо черга порожня, виводимо повідомлення
    if (!H)
    {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    // Виводимо елементи черги
    std::cout << "Queue: ";
    while (H)
    {
        std::cout << H->data << " ";
        H = H->next;
    }
    std::cout << std::endl;
}

// Очищує чергу і повертає nullptr
Node* clear(Node* H)
{
    // Видаляємо всі елементи черги
    while (H)
    {
        Node* temp = H;
        H = H->next;
        delete temp;
    }
    return nullptr; // Повертаємо nullptr
}

