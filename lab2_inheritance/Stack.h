#pragma once
#include <iostream>
#include <stdexcept>
#include <fstream> // ��� ifstream � ofstream
#include "StackException.h" // ��� ��������� ������ �����
#include "FileException.h"  // ��� ��������� ������ ������

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* topNode;  // ��������� �� ������� �����
    size_t stackSize;  // ������� ������ �����
    size_t maxSize;  // ������������ ������ ����� (�����������)

public:
    Stack(size_t maxSize = 0) : topNode(nullptr), stackSize(0), maxSize(maxSize) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // ���������� �������� � ����
    void push(const T& element) {
        try {
            StackException::validateStackOverflow(stackSize, maxSize);
        }
        catch (const std::runtime_error& e) {
            throw; // �������� ������� ����������
        }

        Node* newNode = new Node(element);
        newNode->next = topNode;
        topNode = newNode;
        ++stackSize;
    }

    // �������� �������� �� �����
    void pop() {
        try {

            StackException::validateEmptyStack(isEmpty());
        }
        catch (const std::runtime_error& e) {
            throw; // �������� ������� ����������
        }

        Node* tempNode = topNode;
        topNode = topNode->next;
        delete tempNode;
        --stackSize;
    }

    // ��������� �������� �������� �����
    T top() const {
        try {
            StackException::validateEmptyStack(isEmpty());
        }
        catch (const std::runtime_error& e) {
            throw; // �������� ������� ����������
        }
        return topNode->data;
    }

    // �������� �� ������� �����
    bool isEmpty() const {
        return topNode == nullptr;
    }

    // ������� ������ �����
    size_t size() const {
        return stackSize;
    }

    // ������ ������ � �������� ���� � �������������� FileException
    void writeToBinaryFile(const std::string& filename) const {
        try {
            std::ofstream outputFile = FileException::openFileForWriting(filename);

            for (auto it = begin(); it != end(); ++it) {
                outputFile.write(reinterpret_cast<const char*>(&(*it)), sizeof(T));
                if (outputFile.fail()) {
                    throw FileException("Error writing to binary file: " + filename);
                }
            }

            outputFile.close();
        }
        catch (const FileException& e) {
            std::cerr << e.what() << std::endl;
            throw; // ����������� ���������� ������
        }
    }

    // ������ ������ �� ��������� ����� � �������������� FileException
    void readFromBinaryFile(const std::string& filename) {
        try {
            std::ifstream inputFile = FileException::openFileForReading(filename);

            T element;
            while (inputFile.read(reinterpret_cast<char*>(&element), sizeof(T))) {
                push(element);
            }

            if (inputFile.fail() && !inputFile.eof()) {
                throw FileException("Error reading from binary file: " + filename);
            }

            inputFile.close();
        }
        catch (const FileException& e) {
            std::cerr << e.what() << std::endl;
            throw; // ����������� ���������� ������
        }
    }

    // ������ ������ � ��������� ���� � �������������� FileException
    void writeToTextFile(const std::string& filename) const {
        try {
            std::ofstream outputFile = FileException::openFileForWriting(filename);

            for (auto it = begin(); it != end(); ++it) {
                outputFile << *it << std::endl;
                if (outputFile.fail()) {
                    throw FileException("Error writing to text file: " + filename);
                }
            }

            outputFile.close();
        }
        catch (const FileException& e) {
            std::cerr << e.what() << std::endl;
            throw; // ����������� ���������� ������
        }
    }

    // ������ ������ �� ���������� ����� � �������������� FileException
    void readFromTextFile(const std::string& filename) {
        try {
            std::ifstream inputFile = FileException::openFileForReading(filename);

            T element;
            while (inputFile >> element) { // ������������, ��� T ������������ �������� >>
                push(element);
            }

            if (inputFile.fail() && !inputFile.eof()) {
                throw FileException("Error reading from text file: " + filename);
            }

            inputFile.close();
        }
        catch (const FileException& e) {
            std::cerr << e.what() << std::endl;
            throw; // ����������� ���������� ������
        }
    }

    // ����� �������� � �����

T find(double CPUcapacity) {
    Node* currentNode = topNode;  // ������ ������ � ������� �����
    while (currentNode != nullptr) {
        if (currentNode->data.GetCPUcapacity() == CPUcapacity) {
            return currentNode->data;  // ������� ���������� ��������
        }
        currentNode = currentNode->next;  // ������� � ���������� ����
    }
    throw StackException("CPU capacity not found in stack.");  // ����������, ���� ������� �� ������
}

    // ����� ����������� �����
    void print() const {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }

        for (auto it = begin(); it != end(); ++it) {
            std::cout << *it << std::endl; // ������� ������ ������ � ������� �������������� ��������� <<
        }
    }

    // ��������� ����� ���������
    class Iterator {
    private:
        Node* currentNode;

    public:
        explicit Iterator(Node* node) : currentNode(node) {}

        T& operator*() const {
            if (!currentNode) {
                throw std::out_of_range("Iterator is out of range.");
            }
            return currentNode->data;
        }

        T* operator->() const {
            if (!currentNode) {
                throw std::out_of_range("Iterator is out of range.");
            }
            return &(currentNode->data);
        }

        Iterator& operator++() {
            if (currentNode) {
                currentNode = currentNode->next;
            }
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator& other) const {
            return currentNode == other.currentNode;
        }

        bool operator!=(const Iterator& other) const {
            return currentNode != other.currentNode;
        }
    };

    Iterator begin() const {
        return Iterator(topNode);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
};
