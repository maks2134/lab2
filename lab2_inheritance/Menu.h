#pragma once
#include "StackManager.h"
#include "DequeManager.h"
#include <iostream>

class Menu {
private:
    StackManager stackManager;  // �������� ��� ������ �� �������
    DequeManager dequeManager;  // �������� ��� ������ � ���������

public:
    void printMainMenu() const;
    void printStackMenu() const;
    void printDequeMenu() const;
    void printIteratorMenu() const;

    void workWithStacksMenu();
    void handleDequeTypeMenu();
    void handleIteratorMenu();
    void run();
};