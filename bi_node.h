#pragma once
struct BiNode 
{
    int data;          // Дані, які зберігаються в елементі списку
    BiNode* prev, * next;  // Вказівники на попередній і наступний елементи списку

    // Конструктор за замовчуванням
    BiNode() 
    {
        data = 0;
        prev = next = nullptr;
    }

    // Конструктор з параметром
    BiNode(int x) 
    {
        data = x;
        prev = next = nullptr;
    }
};
