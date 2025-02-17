#include "StackException.h"
StackException::StackException(const std::string& msg)
    : ExceptionBase("Stack Error: " + msg) {}
// Функция для обработки ошибки пустого стека
void StackException::handleEmptyStack(const std::string& msg) {
    throw std::runtime_error("Stack is empty. " + msg);
}
// Функция для обработки ошибки переполнения стека
void StackException::handleStackOverflow(const std::string& msg) {
    throw std::runtime_error("Stack Overflow Error: " + msg);
}
// Функция для обработки ошибки, когда элемент не найден
void StackException::handleElementNotFound(const std::string& msg) {
    throw std::runtime_error("Element Not Found Error: " + msg);
}
void StackException::validateStackOverflow(size_t stackSize, size_t maxSize) {
    if (maxSize > 0 && stackSize >= maxSize) {
        throw std::runtime_error("Stack Overflow: Cannot push, stack is full.");
    }
}
// Валидация на пустоту стека
void StackException::validateEmptyStack(bool isEmpty) {
    if (isEmpty) {
        throw std::runtime_error("Stack Underflow: Cannot pop from an empty stack.");
    }
}
// Валидация на отсутствие элемента
void StackException::validateElementNotFound(bool elementNotFound) {
    if (elementNotFound) {
        throw std::runtime_error("Element Not Found: Element with specified CPU capacity not found.");
    }
}