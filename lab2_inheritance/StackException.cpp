#include "StackException.h"
StackException::StackException(const std::string& msg)
    : ExceptionBase("Stack Error: " + msg) {}
// ������� ��� ��������� ������ ������� �����
void StackException::handleEmptyStack(const std::string& msg) {
    throw std::runtime_error("Stack is empty. " + msg);
}
// ������� ��� ��������� ������ ������������ �����
void StackException::handleStackOverflow(const std::string& msg) {
    throw std::runtime_error("Stack Overflow Error: " + msg);
}
// ������� ��� ��������� ������, ����� ������� �� ������
void StackException::handleElementNotFound(const std::string& msg) {
    throw std::runtime_error("Element Not Found Error: " + msg);
}
void StackException::validateStackOverflow(size_t stackSize, size_t maxSize) {
    if (maxSize > 0 && stackSize >= maxSize) {
        throw std::runtime_error("Stack Overflow: Cannot push, stack is full.");
    }
}
// ��������� �� ������� �����
void StackException::validateEmptyStack(bool isEmpty) {
    if (isEmpty) {
        throw std::runtime_error("Stack Underflow: Cannot pop from an empty stack.");
    }
}
// ��������� �� ���������� ��������
void StackException::validateElementNotFound(bool elementNotFound) {
    if (elementNotFound) {
        throw std::runtime_error("Element Not Found: Element with specified CPU capacity not found.");
    }
}