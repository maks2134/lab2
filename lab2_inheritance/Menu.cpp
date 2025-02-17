#include "Menu.h"

void Menu::printMainMenu() const {
    std::cout << "===== Main Menu =====" << std::endl;
    std::cout << "1. Working with stack" << std::endl;
    std::cout << "2. Deque control" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "=====================" << std::endl;
}

void Menu::printStackMenu() const {
    std::cout << "=====  Working with stack =====" << std::endl;
    std::cout << "1. Add element to stack" << std::endl;
    std::cout << "2. Remove top element from stack" << std::endl;
    std::cout << "3. Show top element" << std::endl;
    std::cout << "4. Find element by CPU capacity" << std::endl;
    std::cout << "5. Show stack size" << std::endl;
    std::cout << "6. Sort stack by CPU capacity" << std::endl;
    std::cout << "7. Insert element at a specific position" << std::endl;
    std::cout << "8. Write to text file" << std::endl;
    std::cout << "9. Write to binary file" << std::endl;
    std::cout << "10. Iterate through stack" << std::endl;
    std::cout << "11. Back to main menu" << std::endl;
    std::cout << "============================" << std::endl;
}

void Menu::printDequeMenu() const {
    std::cout << "=====  Working with Deque =====" << std::endl;
    std::cout << "1. Add element to the front" << std::endl;
    std::cout << "2. Add element to the back" << std::endl;
    std::cout << "3. Remove element from the front" << std::endl;
    std::cout << "4. Remove element from the back" << std::endl;
    std::cout << "5. Show all elements in the deque" << std::endl;
    std::cout << "6. Sort elements in the deque" << std::endl;
    std::cout << "7. Insert element at a specific position" << std::endl;
    std::cout << "8. Access the first element" << std::endl;
    std::cout << "9. Access the last element" << std::endl;
    std::cout << "10. Back to previous menu" << std::endl;
    std::cout << "=============================" << std::endl;
}

void Menu::printIteratorMenu() const {
    std::cout << "===== Iterator Menu =====" << std::endl;
    std::cout << "1. Iterate through StationaryComputer stack" << std::endl;
    std::cout << "2. Iterate through PortableComputer stack" << std::endl;
    std::cout << "3. Iterate through Monoblock stack" << std::endl;
    std::cout << "4. Iterate through Tablet stack" << std::endl;
    std::cout << "5. Iterate through Laptop stack" << std::endl;
    std::cout << "6. Iterate through ComputingMachine stack" << std::endl;
    std::cout << "7. Back to stack menu" << std::endl;
    std::cout << "==========================" << std::endl;
}

void Menu::workWithStacksMenu() {
    int stackChoice = 0;
    do {
        std::cout << "===== Choose a Stack to Work With =====" << std::endl;
        std::cout << "1. StationaryComputer Stack" << std::endl;
        std::cout << "2. PortableComputer Stack" << std::endl;
        std::cout << "3. Monoblock Stack" << std::endl;
        std::cout << "4. Tablet Stack" << std::endl;
        std::cout << "5. Laptop Stack" << std::endl;
        std::cout << "6. ComputingMachine Stack" << std::endl;
        std::cout << "7. Back to Main Menu" << std::endl;
        std::cout << "=======================================" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> stackChoice;

        if (stackChoice == 7) {
            std::cout << "Returning to Main Menu..." << std::endl;
            break;
        }

        int operationChoice = 0;
        do {
            printStackMenu();
            std::cout << "Enter your choice: ";
            std::cin >> operationChoice;

            switch (operationChoice) {
            case 1:  // Добавление элемента
                switch (stackChoice) {
                case 1: stackManager.addStationaryComputer(); break;
                case 2: stackManager.addPortableComputer(); break;
                case 3: stackManager.addMonoblock(); break;
                case 4: stackManager.addTablet(); break;
                case 5: stackManager.addLaptop(); break;
                case 6: stackManager.addComputingMachine(); break;
                default: std::cout << "Invalid stack choice." << std::endl;
                }
                break;

            case 2:  // Удаление верхнего элемента
                switch (stackChoice) {
                case 1: stackManager.removeStationaryComputer(); break;
                case 2: stackManager.removePortableComputer(); break;
                case 3: stackManager.removeMonoblock(); break;
                case 4: stackManager.removeTablet(); break;
                case 5: stackManager.removeLaptop(); break;
                case 6: stackManager.removeComputingMachine(); break;
                default: std::cout << "Invalid stack choice." << std::endl;
                }
                break;

            case 3:  // Показать верхний элемент
                switch (stackChoice) {
                case 1: stackManager.showTopStationaryComputer(); break;
                case 2: stackManager.showTopPortableComputer(); break;
                case 3: stackManager.showTopMonoblock(); break;
                case 4: stackManager.showTopTablet(); break;
                case 5: stackManager.showTopLaptop(); break;
                case 6: stackManager.showTopComputingMachine(); break;
                default: std::cout << "Invalid stack choice." << std::endl;
                }
                break;

            case 4: {  // Поиск элемента по CPU capacity
                double searchCPU;
                std::cout << "Enter CPU capacity to search: ";
                std::cin >> searchCPU;
                stackManager.findElementByCPU(stackChoice, searchCPU);
                break;
            }

            case 5:  // Показать размер стека
                stackManager.showStackSize(stackChoice);
                break;

            case 6:  // Сортировка стека по CPU capacity
                stackManager.sortStackByCPU(stackChoice);
                break;

            case 7: {  // Вставка элемента на определенную позицию
                int index;
                std::cout << "Enter the position to insert the element (0-based): ";
                std::cin >> index;
                stackManager.insertElementAt(stackChoice, index);
                break;
            }

            case 8: {  // Запись в текстовый файл
                std::string filename;
                std::cout << "Enter the filename: ";
                std::cin >> filename;
                stackManager.writeToTextFile(stackChoice, filename);
                break;
            }

            case 9: {  // Запись в бинарный файл
                std::string filename;
                std::cout << "Enter the filename: ";
                std::cin >> filename;
                stackManager.writeToBinaryFile(stackChoice, filename);
                break;
            }

            case 10:  // Итерация по стеку
                stackManager.iterateThroughStack(stackChoice);
                break;

            case 11:
                std::cout << "Returning to stack selection menu..." << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } while (operationChoice != 11);
    } while (stackChoice != 7);
}

void Menu::handleDequeTypeMenu() {
    int choice = 0;

    do {
        std::cout << "===== Choose Deque Type =====" << std::endl;
        std::cout << "1. Laptop" << std::endl;
        std::cout << "2. Tablet" << std::endl;
        std::cout << "3. Stationary Computer" << std::endl;
        std::cout << "4. Monoblock" << std::endl;
        std::cout << "5. Portable Computer" << std::endl;
        std::cout << "6. Computing Machine" << std::endl;
        std::cout << "7. Back to main menu" << std::endl;
        std::cout << "=============================" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            dequeManager.handleLaptopDeque();
            break;
        case 2:
            dequeManager.handleTabletDeque();
            break;
        case 3:
            dequeManager.handleStationaryComputerDeque();
            break;
        case 4:
            dequeManager.handleMonoblockDeque();
            break;
        case 5:
            dequeManager.handlePortableComputerDeque();
            break;
        case 6:
            dequeManager.handleComputingMachineDeque();
            break;
        case 7:
            std::cout << "Returning to main menu..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 7);
}

void Menu::handleIteratorMenu() {
    int iteratorChoice = 0;

    do {
        printIteratorMenu();
        std::cout << "Enter your choice: ";
        std::cin >> iteratorChoice;

        switch (iteratorChoice) {
        case 1:
            stackManager.iterateThroughStack(1);  // StationaryComputer
            break;
        case 2:
            stackManager.iterateThroughStack(2);  // PortableComputer
            break;
        case 3:
            stackManager.iterateThroughStack(3);  // Monoblock
            break;
        case 4:
            stackManager.iterateThroughStack(4);  // Tablet
            break;
        case 5:
            stackManager.iterateThroughStack(5);  // Laptop
            break;
        case 6:
            stackManager.iterateThroughStack(6);  // ComputingMachine
            break;
        case 7:
            std::cout << "Returning to stack menu..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (iteratorChoice != 7);
}

void Menu::run() {
    int choice = 0;

    do {
        printMainMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            workWithStacksMenu();
            break;
        case 2:
            handleDequeTypeMenu();
            break;
        case 3:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);
}