#include "IDequeMenu.h"
#include <deque>
#include "StationaryComputer.h"
#include "PortableComputer.h"
#include "Monoblock.h"
#include "Tablet.h"
#include "Laptop.h"
#include "ComputingMachine.h"

class DequeMenu : public IDequeMenu {
private:
    std::deque<StationaryComputer> stationaryComputerDeque;
    std::deque<PortableComputer> portableComputerDeque;
    std::deque<Monoblock> monoblockDeque;
    std::deque<Tablet> tabletDeque;
    std::deque<Laptop> laptopDeque;
    std::deque<ComputingMachine> computingMachineDeque;

public:
    void printMenu() const override {
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

    void handleMenu() override {
        int choice = 0;
        do {
            printMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1: addElementToFront(); break;
            case 2: addElementToBack(); break;
            case 3: removeElementFromFront(); break;
            case 4: removeElementFromBack(); break;
            case 5: showAllElements(); break;
            case 6: sortElements(); break;
            case 7: insertElementAtPosition(); break;
            case 8: showFirstElement(); break;
            case 9: showLastElement(); break;
            case 10: std::cout << "Returning to the previous menu..." << std::endl; break;
            default: std::cout << "Invalid choice, please try again." << std::endl;
            }
        } while (choice != 10);
    }

    void addElementToFront() override {
        // Реализация добавления элемента в начало очереди
    }

    void addElementToBack() override {
        // Реализация добавления элемента в конец очереди
    }

    void removeElementFromFront() override {
        // Реализация удаления элемента из начала очереди
    }

    void removeElementFromBack() override {
        // Реализация удаления элемента из конца очереди
    }

    void showAllElements() override {
        // Реализация показа всех элементов очереди
    }

    void sortElements() override {
        // Реализация сортировки элементов очереди
    }

    void insertElementAtPosition() override {
        // Реализация вставки элемента на определенную позицию
    }

    void showFirstElement() override {
        // Реализация показа первого элемента очереди
    }

    void showLastElement() override {
        // Реализация показа последнего элемента очереди
    }
};