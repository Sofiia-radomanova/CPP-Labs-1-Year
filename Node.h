#pragma once
#include <iostream>
//Описати структуру даних для елементу однонаправленого списку Node :
//struct Node {
//    int data;
//    Node* next;
//    Node() { data = 0; next = nullptr; }
//    Node(int x) { data = x; next = nullptr; }
//};
//Структуру Node розмістити в окремому заголовному файлі <node.h>(про
//    деталі організації багатофайлових програм можна подивитися в матеріалах
//    лекцій першого семестру «Л6_Багатофайлові_програми.docx»).
//    З використанням структури Node реалізувати однонаправлений
//    динамічний список - стек.Додавання / видалення елементів здійснюється з
//    вершини стека Top(змінна - покажчик на вершину стека).Якщо стек порожній,
//    то Top = nullptr.
//    

class Stack;

struct Node
{
    int data;
    Node* next;
    Node()
    {
        data = 0; next = nullptr;
    }

    Node(int x)
    {
        data = x; next = nullptr;
    }
};

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
            newNode->next = top; // Оновлюємо вказівник на наступний елемент
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
            top = top->next; // Переміщаємо вершину на наступний елемент
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

                        // Метод для виводу елементів стеку
                        void viewStack() const
                        {
                            Node* current = top;
                            
                            while (current != nullptr)
                            {
                                std::cout << current->data << " ";
                                current = current->next;
                            }
                            std::cout << std::endl;
                        }

                        // Видалити з стеку верхній елемент
                        void removeFromStack()
                        {
                                pop();            
                        }



                        //void mergeStacks(const Stack& stack1, const Stack& stack2, Stack& resultStack)
                        //{
                        //    while (!stack1.isEmpty() && !stack2.isEmpty())
                        //    {
                        //        if (stack1.top->data > stack2.top->data)
                        //        {
                        //            resultStack.push(stack1.top->data);
                        //            stack1.pop();
                        //        }
                        //        else
                        //        {
                        //            resultStack.push(stack2.top->data);
                        //            stack2.pop();
                        //        }
                        //    }

                        //    // Додатково додаємо елементи з не порожнього стеку
                        //    while (!stack1.isEmpty())
                        //    {
                        //        resultStack.push(stack1.top->data);
                        //        stack1.pop();
                        //    }

                        //    while (!stack2.isEmpty())
                        //    {
                        //        resultStack.push(stack2.top->data);
                        //        stack2.pop();
                        //    }
                        //}




    };





