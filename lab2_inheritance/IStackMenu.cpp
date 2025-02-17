#include "IStackMenu.h"
#include "Stack.h"
#include "StationaryComputer.h"
#include "PortableComputer.h"
#include "Monoblock.h"
#include "Tablet.h"
#include "Laptop.h"
#include "ComputingMachine.h"
#include <iostream>
#include <fstream>

class StackMenu : public IStackMenu {
private:
    Stack<StationaryComputer> stationaryComputerStack;
    Stack<PortableComputer> portableComputerStack;
    Stack<Monoblock> monoblockStack;
    Stack<Tablet> tabletStack;
    Stack<Laptop> laptopStack;
    Stack<ComputingMachine> computingMachineStack;

    // Вспомогательная функция для выбора стека
    template <typename T>
    Stack<T>& selectStack(int stackChoice) {
        switch (stackChoice) {
        case 1: return stationaryComputerStack;
        case 2: return portableComputerStack;
        case 3: return monoblockStack;
        case 4: return tabletStack;
        case 5: return laptopStack;
        case 6: return computingMachineStack;
        default: throw std::invalid_argument("Invalid stack choice.");
        }
    }

public:
    void printMenu() const override {
        std::cout << "=====  Working with stack =====" << std::endl;
        std::cout << "1. Add element to stack" << std::endl;
        std::cout << "2. Remove top element from stack" << std::endl;
        std::cout << "3. Show top element" << std::endl;
        std::cout << "4. Find element by CPU capacity (example)" << std::endl;
        std::cout << "5. Show stack size" << std::endl;
        std::cout << "6. Iterate through stack (test iterator)" << std::endl;
        std::cout << "7. Write to txt file" << std::endl;
        std::cout << "8. Write to binary file" << std::endl;
        std::cout << "9. Back to main menu" << std::endl;
        std::cout << "============================" << std::endl;
    }

    void handleMenu() override {
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
                printMenu();
                std::cout << "Enter your choice: ";
                std::cin >> operationChoice;

                switch (operationChoice) {
                case 1: addElement(stackChoice); break;
                case 2: removeElement(stackChoice); break;
                case 3: showTopElement(stackChoice); break;
                case 4: findElementByCPUCapacity(stackChoice); break;
                case 5: showStackSize(stackChoice); break;
                case 6: iterateThroughStack(stackChoice); break;
                case 7: writeToTextFile(stackChoice, "output.txt"); break;
                case 8: writeToBinaryFile(stackChoice, "output.bin"); break;
                case 9: std::cout << "Returning to stack selection menu..." << std::endl; break;
                default: std::cout << "Invalid choice. Please try again." << std::endl;
                }
            } while (operationChoice != 9);

        } while (stackChoice != 7);
    }

    void addElement(int stackChoice) {
        try {
            auto& stack = selectStack<ComputingMachine>(stackChoice); // Используем базовый тип для примера
            ComputingMachine cm;
            std::cin >> cm;  // Ввод объекта через перегруженный оператор >>
            stack.push(cm);
            std::cout << "Element added to the stack!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void removeElement(int stackChoice) {
        try {
            auto& stack = selectStack<ComputingMachine>(stackChoice);
            if (!stack.isEmpty()) {
                stack.pop();
                std::cout << "Top element removed from the stack." << std::endl;
            }
            else {
                std::cout << "Stack is empty." << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void showTopElement(int stackChoice) {
        try {
            auto& stack = selectStack<ComputingMachine>(stackChoice);
            if (!stack.isEmpty()) {
                std::cout << "Top element: " << stack.top() << std::endl;
            }
            else {
                std::cout << "Stack is empty." << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void findElementByCPUCapacity(int stackChoice) {
        try {
            auto& stack = selectStack<ComputingMachine>(stackChoice);
            double cpuCapacity;
            std::cout << "Enter CPU capacity to search: ";
            std::cin >> cpuCapacity;

            ComputingMachine result = stack.find(cpuCapacity);
            std::cout << "Element found: " << result << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void showStackSize(int stackChoice) {
        try {
            auto& stack = selectStack<ComputingMachine>(stackChoice);
            std::cout << "Stack size: " << stack.size() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void iterateThroughStack(int stackChoice) {
        try {
            auto& stack = selectStack<ComputingMachine>(stackChoice);
            std::cout << "Iterating through stack:" << std::endl;
            for (auto it = stack.begin(); it != stack.end(); ++it) {
                std::cout << *it << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void writeToTextFile(int stackChoice, const std::string& filename) {
        try {
            auto& stack = selectStack<ComputingMachine>(stackChoice);
            stack.writeToTextFile(filename);
            std::cout << "Stack written to " << filename << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void writeToBinaryFile(int stackChoice, const std::string& filename)  {
        try {
            auto& stack = selectStack<ComputingMachine>(stackChoice);
            stack.writeToBinaryFile(filename);
            std::cout << "Stack written to " << filename << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
};