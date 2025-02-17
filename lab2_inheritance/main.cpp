#include "Menu.h"
#include <iostream>


int main() {
    Menu menu; // ������� ������ ����
    int choice = 0;

    do {
        // ������� ������� ����
        menu.printMainMenu();

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            // ������� � ���� ������ �� ������
            menu.workWithStacksMenu();
            break;
        case 2: menu.handleDequeTypeMenu(); break;
        case 3:
            // ����� �� ���������
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            break;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}




