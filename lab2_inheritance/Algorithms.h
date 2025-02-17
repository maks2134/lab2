#pragma once
#include "Stack.h"  // Подключаем ваш самописный стек
#include <vector>
#include <algorithm>

class Algorithms {
public:
    // Сортировка стека по CPU capacity
    template <typename T>
    static void sortStackByCPU(Stack<T>& stack) {
        std::vector<T> tempVector;

        // Переносим элементы из стека в вектор
        while (!stack.isEmpty()) {
            tempVector.push_back(stack.top());
            stack.pop();
        }

        // Сортируем вектор по CPU capacity
        std::sort(tempVector.begin(), tempVector.end(), [](const T& a, const T& b) {
            return a.GetCPUcapacity() < b.GetCPUcapacity();
            });

        // Возвращаем элементы обратно в стек
        for (auto it = tempVector.rbegin(); it != tempVector.rend(); ++it) {
            stack.push(*it);
        }
    }

    // Поиск элемента в стеке по CPU capacity
    template <typename T>
    static T findElementByCPU(Stack<T>& stack, double CPUcapacity) {
        Stack<T> tempStack;
        T foundElement;

        bool isFound = false;

        // Ищем элемент в стеке
        while (!stack.isEmpty()) {
            T currentElement = stack.top();
            stack.pop();
            tempStack.push(currentElement);

            if (currentElement.GetCPUcapacity() == CPUcapacity) {
                foundElement = currentElement;
                isFound = true;
                break;
            }
        }

        // Восстанавливаем исходный стек
        while (!tempStack.isEmpty()) {
            stack.push(tempStack.top());
            tempStack.pop();
        }

        if (!isFound) {
            throw std::runtime_error("Element with specified CPU capacity not found.");
        }

        return foundElement;
    }

    // Вставка элемента в стек на определенную позицию
    template <typename T>
    static void insertElementAt(Stack<T>& stack, const T& element, int index) {
        if (index < 0 || index > stack.size()) {
            throw std::out_of_range("Invalid index for insertion.");
        }

        Stack<T> tempStack;

        // Переносим элементы до нужной позиции во временный стек
        for (int i = 0; i < index; ++i) {
            tempStack.push(stack.top());
            stack.pop();
        }

        // Вставляем новый элемент
        stack.push(element);

        // Возвращаем элементы обратно в стек
        while (!tempStack.isEmpty()) {
            stack.push(tempStack.top());
            tempStack.pop();
        }
    }
};