#pragma once
#include "Stack.h"  // ���������� ��� ���������� ����
#include <vector>
#include <algorithm>

class Algorithms {
public:
    // ���������� ����� �� CPU capacity
    template <typename T>
    static void sortStackByCPU(Stack<T>& stack) {
        std::vector<T> tempVector;

        // ��������� �������� �� ����� � ������
        while (!stack.isEmpty()) {
            tempVector.push_back(stack.top());
            stack.pop();
        }

        // ��������� ������ �� CPU capacity
        std::sort(tempVector.begin(), tempVector.end(), [](const T& a, const T& b) {
            return a.GetCPUcapacity() < b.GetCPUcapacity();
            });

        // ���������� �������� ������� � ����
        for (auto it = tempVector.rbegin(); it != tempVector.rend(); ++it) {
            stack.push(*it);
        }
    }

    // ����� �������� � ����� �� CPU capacity
    template <typename T>
    static T findElementByCPU(Stack<T>& stack, double CPUcapacity) {
        Stack<T> tempStack;
        T foundElement;

        bool isFound = false;

        // ���� ������� � �����
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

        // ��������������� �������� ����
        while (!tempStack.isEmpty()) {
            stack.push(tempStack.top());
            tempStack.pop();
        }

        if (!isFound) {
            throw std::runtime_error("Element with specified CPU capacity not found.");
        }

        return foundElement;
    }

    // ������� �������� � ���� �� ������������ �������
    template <typename T>
    static void insertElementAt(Stack<T>& stack, const T& element, int index) {
        if (index < 0 || index > stack.size()) {
            throw std::out_of_range("Invalid index for insertion.");
        }

        Stack<T> tempStack;

        // ��������� �������� �� ������ ������� �� ��������� ����
        for (int i = 0; i < index; ++i) {
            tempStack.push(stack.top());
            stack.pop();
        }

        // ��������� ����� �������
        stack.push(element);

        // ���������� �������� ������� � ����
        while (!tempStack.isEmpty()) {
            stack.push(tempStack.top());
            tempStack.pop();
        }
    }
};