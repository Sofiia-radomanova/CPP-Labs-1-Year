#pragma once
#include <iostream>
#include "bi_node.h"

// Функція для отримання вказівника на останній елемент в списку
BiNode* get_back(BiNode* F);

// Функція для додавання нового значення х в кінець списку
BiNode* push_back(BiNode* F, int x);

// Функція для додавання нового значення х на початок списку
BiNode* push_front(BiNode* F, int x);

// Функція для додавання нового значення х перед елементом node
BiNode* insert(BiNode* F, int x, BiNode* node);

// Функція для додавання нового значення х після елемента node
BiNode* insert(BiNode* F, BiNode* node, int x);

// Функція для видалення елементу node зі списку
BiNode* remove(BiNode* F, BiNode* node);

// Функція для виведення списку у прямому порядку
void forward_view(BiNode* F);

// Функція для виведення списку у зворотному порядку
void reverse_view(BiNode* F);

// Функція для очищення списку
BiNode* clear(BiNode* F);

// Функція для пошуку елементу з заданим значенням key у списку
BiNode* find(BiNode* F, int key);

// Функція для міняє в списку місцями елементи n1 та n2
BiNode* swap(BiNode* n1, BiNode* n2);

// Функція для сортування елементів списку методом прямого вибору
BiNode* sort(BiNode* F);
