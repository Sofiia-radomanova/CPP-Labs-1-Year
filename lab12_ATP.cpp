#include <iostream>
#include "bilist.h"

//F  покажчик на початок списку
// Функція для отримання вказівника на останній елемент в списку
BiNode* get_back(BiNode* F)
{
    // Перевірка на пустий список
    if (!F)
        return nullptr;

    // Пошук останнього елемента
    while (F->next != nullptr)
    {
        F = F->next;
    }
    return F;
}

// Функція для додавання нового значення х в кінець списку
BiNode* push_back(BiNode* F, int x)
{
    BiNode* newNode = new BiNode(x);
    // Перевірка на пустий список
    if (!F)
    {
        F = newNode;
    }
    else
    {
        // Знаходження останнього елемента і додавання нового вузла
        BiNode* lastNode = get_back(F);
        lastNode->next = newNode;
        newNode->prev = lastNode;
    }
    return F;
}

// Функція для додавання нового значення х на початок списку
BiNode* push_front(BiNode* F, int x)
{
    BiNode* newNode = new BiNode(x);
    // Перевірка на пустий список
    if (!F)
    {
        F = newNode;
    }
    else
    {
        // Додавання нового вузла на початок списку
        newNode->next = F;
        F->prev = newNode;
        F = newNode;
    }
    return F;
}

// Функція для додавання нового значення х перед елементом node
BiNode* insert(BiNode* F, int x, BiNode* node)
{
    // Перевірка на пустий список або наявність вузла
    if (!F)
        return nullptr;
    BiNode* newNode = new BiNode(x);
    // Оновлення вказівників
    newNode->prev = node->prev; //присвоєння вказівнику prev нового вузла значення, яке зберігається у вказівнику prev вузла node
    newNode->next = node;//встановлюється вказівник next нового вузла на вузол node
    if (node->prev)
        node->prev->next = newNode;
    node->prev = newNode;
    // Оновлення початкового вказівника, якщо вставляється перед першим вузлом
    if (F == node)
        F = newNode;
    return F;
}

// Функція для додавання нового значення х після елемента node
BiNode* insert(BiNode* F, BiNode* node, int x)
{
    // Перевірка на пустий список або наявність вузла
    if (!F)
        return nullptr;
    BiNode* newNode = new BiNode(x);
    // Оновлення вказівників
    newNode->next = node->next;
    newNode->prev = node;
    if (node->next)
        node->next->prev = newNode;
    node->next = newNode;
    return F;
}

// Функція для видалення елементу node зі списку
BiNode* remove(BiNode* F, BiNode* node)
{
    // Перевірка на пустий список або на вузол
    if (!F || !node)
        return nullptr;

    // Оновлення вказівників попереднього і наступного вузлів
    if (node->prev)
        node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;

    // Якщо видаляється перший вузол, оновлення початку списку
    if (F == node)
        F = node->next;

    // Звільнення пам'яті, зайнятої вузлом
    delete node;

    // Повернення початкового вказівника на список
    return F;
}

// Функція для виведення списку у прямому порядку
void forward_view(BiNode* F)
{
    // Виведення значень вузлів у прямому порядку
    while (F)
    {
        std::cout << F->data << " ";
        F = F->next;
    }
    std::cout << std::endl;
}

// Функція для виведення списку у зворотному порядку
void reverse_view(BiNode* F)
{
    // Виведення значень вузлів у зворотному порядку
    BiNode* last = get_back(F);
    while (last)
    {
        std::cout << last->data << " ";
        last = last->prev;
    }
    std::cout << std::endl;
}

// Функція для очищення списку
BiNode* clear(BiNode* F)
{
    // Вивільнення пам'яті, зайнятої усіма вузлами
    while (F)
    {
        BiNode* temp = F;
        F = F->next;
        delete temp;
    }
    return nullptr;
}

// Функція для пошуку елементу з заданим значенням key у списку
BiNode* find(BiNode* F, int key)
{
    // Пошук елементу зі значенням key
    while (F)
    {
        if (F->data == key)
            return F;
        F = F->next;
    }
    return nullptr;
}



//1 ЗАВДАННЯ ДОДАТКОВЕ
// Функція для вставки всіх елементів зі списку F2 до F1 після елемента з заданим номером index
void splice_in(BiNode* F1, BiNode* F2, int index)
{
    // Перевірка на пусті списки
    if (!F1 || !F2)
        return;

    // Пошук вузла в F1 за індексом
    BiNode* current = F1;
    int count = 0;
    while (current && count < index)
    {
        current = current->next;
        count++;
    }

    // Вставка F2 перед знайденим вузлом
    if (current)
    {
        // Отримання останнього вузла F2
        BiNode* lastF2 = get_back(F2);

        // Оновлення вказівників для вставки F2 перед знайденим вузлом
        lastF2->next = current->next;
        if (current->next)
            current->next->prev = lastF2;
        current->next = F2;
        F2->prev = current;
    }
}

// Функція для переміщення всіх елементів, починаючи з index1 до index2 включно зі списку F1 в кінець списку F2
void splice_out(BiNode* F1, BiNode* F2, int index1, int index2)
{
    // Перевірка на пусті списки
    if (!F1 || !F2)
        return;

    // Пошук вузла в F1 за індексом
    BiNode* current = F1;
    int count = 0;
    while (current && count < index1)
    {
        current = current->next;
        count++;
    }

    // Переміщення вузлів від index1 до index2 з F1 в кінець F2
    if (current)
    {
        // Оновлення вказівників на попередній та наступний вузли в F1 та F2
        BiNode* prevNode = current->prev;
        BiNode* nextNode = current->next;

        // Переміщення вузлів з F1 в кінець F2
        while (current && count <= index2)
        {
            BiNode* temp = current;
            current = current->next;

            // Оновлення вказівників для вилучення вузла з F1 та вставки його в кінець F2
            if (prevNode)
                prevNode->next = current;
            if (current)
                current->prev = prevNode;

            // Від'єднання вузла від списку F1
            temp->prev = nullptr;
            temp->next = nullptr;

            // Вставка вузла в кінець F2
            if (!F2)
            {
                F2 = temp;
            }
            else
            {
                BiNode* lastF2 = get_back(F2);
                lastF2->next = temp;
                temp->prev = lastF2;
            }

            count++;
        }

        // Оновлення вказівника наступного вузла попереднього вузла в F1
        if (nextNode)
            nextNode->prev = prevNode;
    }
}



//ДРУГЕ ЗАВДАННЯ
BiNode* swap(BiNode* n1, BiNode* n2)
{
    // Перевірка на пусті вузли або співпадіння вузлів
    if (!n1 || !n2 || n1 == n2)
        return nullptr;

    // Якщо n1 і n2 сусідні
    if (n1->next == n2) {
        n1->next = n2->next;
        n2->prev = n1->prev;
        if (n1->prev)
            n1->prev->next = n2;
        if (n2->next)
            n2->next->prev = n1;
        n2->next = n1;
        n1->prev = n2;
    }
    else if (n2->next == n1) {
        n2->next = n1->next;
        n1->prev = n2->prev;
        if (n2->prev)
            n2->prev->next = n1;
        if (n1->next)
            n1->next->prev = n2;
        n1->next = n2;
        n2->prev = n1;
    }
    else {
        // Збереження сусідніх вузлів n1 і n2
        BiNode* temp1Prev = n1->prev;
        BiNode* temp1Next = n1->next;
        BiNode* temp2Prev = n2->prev;
        BiNode* temp2Next = n2->next;

        // Обмін місцями n1 і n2
        n1->prev = temp2Prev;
        n1->next = temp2Next;
        n2->prev = temp1Prev;
        n2->next = temp1Next;

        // Оновлення сусідніх вузлів для n1
        if (temp2Prev)
            temp2Prev->next = n1;
        if (temp2Next)
            temp2Next->prev = n1;

        // Оновлення сусідніх вузлів для n2
        if (temp1Prev)
            temp1Prev->next = n2;
        if (temp1Next)
            temp1Next->prev = n2;
    }

    return n2 == n1->prev ? n1 : n2;
}

//перевірка чи n2 є попереднім вузлом для n1. Якщо  так, то n1 був 
    //змінений, був перенесений перед n2, тому функція повертає n1, в іншому випадку n2




BiNode* sort(BiNode* F)
{
    // Перевірка на пустий список
    if (!F)
        return nullptr;

    // Прохід через всі вузли списку
    BiNode* current = F;
    while (current)
    {
        BiNode* min = current;
        BiNode* temp = current->next;
        // Знаходження найменшого елемента
        while (temp)
        {
            if (temp->data < min->data)
                min = temp;
            temp = temp->next;
        }
        // Обмін значень між поточним та мінімальним елементами
        if (min != current)
        {
            if (F == current)
            {
                F = swap(current, min);
                current = F->next;
            }
            else
            {
                BiNode* tempCurrentNext = current->next;
                swap(current, min);
                current = tempCurrentNext;
            }
        }
        else
        {
            current = current->next;
        }
    }
    return F;
}






// Умова condition1: парні числа
bool condition1(int x) 
{
    return x % 2 == 0;
}

// Умова condition2: числа менше 10
bool condition2(int x) 
{
    return x < 10;
}

int main() 
{
    BiNode* list = nullptr;

    int x;

    // Зчитування цілих чисел з консолі до тих пір, поки користувач не введе 0
    std::cout << "Enter integers (0 to finish):" << std::endl;
    while (true)
    {
        std::cin >> x;
        if (x == 0)
            break;
        list = push_back(list, x);
    }

    std::cout << "List after input:" << std::endl;
    forward_view(list);


 
    // Вставка перед кожним елементом списку, що не відповідає умові condition1,
    // елемента, що більше знайденого елемента на 1
    BiNode*  current = list;
    while (current != nullptr) 
    {
        if (!condition1(current->data)) 
        {
            list = insert(list, current, current->data + 1);
            current = current->next; // Перемикаємося на наступний елемент, оскільки ми вставили новий елемент
        }
        current = current->next;
    }

    std::cout << "List after insertion:" << std::endl;
    forward_view(list);

    // Видалення зі списку кожного елемента, що відповідає умові condition2
    current = list;
    while (current != nullptr) 
    {
        if (condition2(current->data)) 
        {
            BiNode* temp = current;
            current = current->next; // Перемикаємося на наступний елемент перед видаленням поточного
            list = remove(list, temp); // Видаляємо поточний елемент
        }
        else 
        {
            current = current->next;
        }
    }

    std::cout << "List after removal:" << std::endl;
    forward_view(list);


    // Перевірка, чи список не порожній
    if (list != nullptr) 
    {
        // Виклик функції sort, якщо список не порожній
        list = sort(list);
        // Виведення відсортованого списку
        std::cout << "Sorted list:" << std::endl;
        forward_view(list);
    }
    else 
    {
        std::cout << "The list is empty. Cannot sort." << std::endl;
    }



    // Очищення списку
    list = clear(list);

    return 0;
}

