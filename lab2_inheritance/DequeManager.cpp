#include "DequeManager.h"

void DequeManager::handleLaptopDeque() {
    int choice;
    do {
        printDequeMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Laptop lp;
            std::cin >> lp;
            laptopDeque.push_front(lp);
            std::cout << "Laptop added to the front of the deque!" << std::endl;
            break;
        }
        case 2: {
            Laptop lp;
            std::cin >> lp;
            laptopDeque.push_back(lp);
            std::cout << "Laptop added to the back of the deque!" << std::endl;
            break;
        }
        case 3: {
            if (!laptopDeque.empty()) {
                laptopDeque.pop_front();
                std::cout << "Laptop removed from the front of the deque!" << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 4: {
            if (!laptopDeque.empty()) {
                laptopDeque.pop_back();
                std::cout << "Laptop removed from the back of the deque!" << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 5: {
            std::cout << "Elements in the deque:" << std::endl;
            for (const auto& lp : laptopDeque) {
                Laptop tempLP = lp;
                tempLP.show();
                std::cout << tempLP << std::endl;
            }
            break;
        }
        case 6: {
            std::sort(laptopDeque.begin(), laptopDeque.end(), [](Laptop& a, Laptop& b) {
                return a.GetCPUcapacity() < b.GetCPUcapacity();
                });
            std::cout << "Deque sorted by CPU capacity!" << std::endl;
            break;
        }
        case 7: {
            int index;
            Laptop lp;
            std::cout << "Enter the position to insert the element (0-based): ";
            std::cin >> index;
            std::cout << "Enter Laptop details: ";
            std::cin >> lp;
            if (index >= 0 && index <= laptopDeque.size()) {
                auto it = laptopDeque.begin() + index;
                laptopDeque.insert(it, lp);
                std::cout << "Laptop inserted at position " << index << "!" << std::endl;
            }
            else {
                std::cout << "Invalid position!" << std::endl;
            }
            break;
        }
        case 8: {
            if (!laptopDeque.empty()) {
                std::cout << "First element in the deque: " << laptopDeque.front() << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 9: {
            if (!laptopDeque.empty()) {
                std::cout << "Last element in the deque: " << laptopDeque.back() << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 10:
            std::cout << "Returning to the previous menu..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
            break;
        }
    } while (choice != 10);
}

void DequeManager::handleTabletDeque() {
    int choice;
    do {
        printDequeMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Tablet tb;
            std::cin >> tb;
            tabletDeque.push_front(tb);
            std::cout << "Tablet added to the front of the deque!" << std::endl;
            break;
        }
        case 2: {
            Tablet tb;
            std::cin >> tb;
            tabletDeque.push_back(tb);
            std::cout << "Tablet added to the back of the deque!" << std::endl;
            break;
        }
        case 3: {
            if (!tabletDeque.empty()) {
                tabletDeque.pop_front();
                std::cout << "Tablet removed from the front of the deque!" << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 4: {
            if (!tabletDeque.empty()) {
                tabletDeque.pop_back();
                std::cout << "Tablet removed from the back of the deque!" << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 5: {
            std::cout << "Elements in the deque:" << std::endl;
            for (const auto& tb : tabletDeque) {
                Tablet tempTB = tb;
                tempTB.show();
                std::cout << tempTB << std::endl;
            }
            break;
        }
        case 6: {
            std::sort(tabletDeque.begin(), tabletDeque.end(), [](Tablet& a, Tablet& b) {
                return a.GetCPUcapacity() < b.GetCPUcapacity();
                });
            std::cout << "Deque sorted!" << std::endl;
            break;
        }
        case 7: {
            int index;
            Tablet tb;
            std::cout << "Enter the position to insert the element (0-based): ";
            std::cin >> index;
            std::cout << "Enter Tablet details: ";
            std::cin >> tb;
            if (index >= 0 && index <= tabletDeque.size()) {
                auto it = tabletDeque.begin() + index;
                tabletDeque.insert(it, tb);
                std::cout << "Tablet inserted at position " << index << "!" << std::endl;
            }
            else {
                std::cout << "Invalid position!" << std::endl;
            }
            break;
        }
        case 8: {
            if (!tabletDeque.empty()) {
                std::cout << "First element in the deque: " << tabletDeque.front() << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 9: {
            if (!tabletDeque.empty()) {
                std::cout << "Last element in the deque: " << tabletDeque.back() << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 10:
            std::cout << "Returning to the previous menu..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
            break;
        }
    } while (choice != 10);
}

void DequeManager::handleStationaryComputerDeque() {
    int choice;
    do {
        printDequeMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            StationaryComputer sc;
            std::cin >> sc;
            stationaryComputerDeque.push_front(sc);
            std::cout << "StationaryComputer added to the front of the deque!" << std::endl;
            break;
        }
        case 2: {
            StationaryComputer sc;
            std::cin >> sc;
            stationaryComputerDeque.push_back(sc);
            std::cout << "StationaryComputer added to the back of the deque!" << std::endl;
            break;
        }
        case 3: {
            if (!stationaryComputerDeque.empty()) {
                stationaryComputerDeque.pop_front();
                std::cout << "StationaryComputer removed from the front of the deque!" << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 4: {
            if (!stationaryComputerDeque.empty()) {
                stationaryComputerDeque.pop_back();
                std::cout << "StationaryComputer removed from the back of the deque!" << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 5: {
            std::cout << "Elements in the deque:" << std::endl;
            for (const auto& sc : stationaryComputerDeque) {
                std::cout << sc << std::endl;
            }
            break;
        }
        case 6: {
            std::sort(stationaryComputerDeque.begin(), stationaryComputerDeque.end(), [](StationaryComputer& a, StationaryComputer& b) {
                return a.GetCPUcapacity() < b.GetCPUcapacity();
                });
            std::cout << "Deque sorted!" << std::endl;
            break;
        }
        case 7: {
            int index;
            StationaryComputer sc;
            std::cout << "Enter the position to insert the element (0-based): ";
            std::cin >> index;
            std::cout << "Enter StationaryComputer details: ";
            std::cin >> sc;
            if (index >= 0 && index <= stationaryComputerDeque.size()) {
                auto it = stationaryComputerDeque.begin() + index;
                stationaryComputerDeque.insert(it, sc);
                std::cout << "StationaryComputer inserted at position " << index << "!" << std::endl;
            }
            else {
                std::cout << "Invalid position!" << std::endl;
            }
            break;
        }
        case 8: {
            if (!stationaryComputerDeque.empty()) {
                std::cout << "First element in the deque: " << stationaryComputerDeque.front() << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 9: {
            if (!stationaryComputerDeque.empty()) {
                std::cout << "Last element in the deque: " << stationaryComputerDeque.back() << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 10:
            std::cout << "Returning to the previous menu..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
            break;
        }
    } while (choice != 10);
}

void DequeManager::handleMonoblockDeque() {
    int choice;
    do {
        printDequeMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Monoblock mb;
            std::cin >> mb;
            monoblockDeque.push_front(mb);
            std::cout << "Monoblock added to the front of the deque!" << std::endl;
            break;
        }
        case 2: {
            Monoblock mb;
            std::cin >> mb;
            monoblockDeque.push_back(mb);
            std::cout << "Monoblock added to the back of the deque!" << std::endl;
            break;
        }
        case 3: {
            if (!monoblockDeque.empty()) {
                monoblockDeque.pop_front();
                std::cout << "Monoblock removed from the front of the deque!" << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 4: {
            if (!monoblockDeque.empty()) {
                monoblockDeque.pop_back();
                std::cout << "Monoblock removed from the back of the deque!" << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 5: {
            std::cout << "Elements in the deque:" << std::endl;
            for (const auto& mb : monoblockDeque) {
                std::cout << mb << std::endl;
            }
            break;
        }
        case 6: {
            std::sort(monoblockDeque.begin(), monoblockDeque.end(), [](Monoblock& a, Monoblock& b) {
                return a.GetCPUcapacity() < b.GetCPUcapacity();
                });
            std::cout << "Deque sorted!" << std::endl;
            break;
        }
        case 7: {
            int index;
            Monoblock mb;
            std::cout << "Enter the position to insert the element (0-based): ";
            std::cin >> index;
            std::cout << "Enter Monoblock details: ";
            std::cin >> mb;
            if (index >= 0 && index <= monoblockDeque.size()) {
                auto it = monoblockDeque.begin() + index;
                monoblockDeque.insert(it, mb);
                std::cout << "Monoblock inserted at position " << index << "!" << std::endl;
            }
            else {
                std::cout << "Invalid position!" << std::endl;
            }
            break;
        }
        case 8: {
            if (!monoblockDeque.empty()) {
                std::cout << "First element in the deque: " << monoblockDeque.front() << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 9: {
            if (!monoblockDeque.empty()) {
                std::cout << "Last element in the deque: " << monoblockDeque.back() << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 10:
            std::cout << "Returning to the previous menu..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
            break;
        }
    } while (choice != 10);
}

void DequeManager::handlePortableComputerDeque() {
    int choice;
    do {
        printDequeMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            PortableComputer pc;
            std::cin >> pc;
            portableComputerDeque.push_front(pc);
            std::cout << "PortableComputer added to the front of the deque!" << std::endl;
            break;
        }
        case 2: {
            PortableComputer pc;
            std::cin >> pc;
            portableComputerDeque.push_back(pc);
            std::cout << "PortableComputer added to the back of the deque!" << std::endl;
            break;
        }
        case 3: {
            if (!portableComputerDeque.empty()) {
                portableComputerDeque.pop_front();
                std::cout << "PortableComputer removed from the front of the deque!" << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 4: {
            if (!portableComputerDeque.empty()) {
                portableComputerDeque.pop_back();
                std::cout << "PortableComputer removed from the back of the deque!" << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 5: {
            std::cout << "Elements in the deque:" << std::endl;
            for (const auto& pc : portableComputerDeque) {
                PortableComputer tempPC = pc;
                tempPC.show();
                std::cout << tempPC << std::endl;
            }
            break;
        }
        case 6: {
            std::sort(portableComputerDeque.begin(), portableComputerDeque.end(), [](PortableComputer& a, PortableComputer& b) {
                return a.GetCPUcapacity() < b.GetCPUcapacity();
                });
            std::cout << "Deque sorted!" << std::endl;
            break;
        }
        case 7: {
            int index;
            PortableComputer pc;
            std::cout << "Enter the position to insert the element (0-based): ";
            std::cin >> index;
            std::cout << "Enter PortableComputer details: ";
            std::cin >> pc;
            if (index >= 0 && index <= portableComputerDeque.size()) {
                auto it = portableComputerDeque.begin() + index;
                portableComputerDeque.insert(it, pc);
                std::cout << "PortableComputer inserted at position " << index << "!" << std::endl;
            }
            else {
                std::cout << "Invalid position!" << std::endl;
            }
            break;
        }
        case 8: {
            if (!portableComputerDeque.empty()) {
                std::cout << "First element in the deque: " << portableComputerDeque.front() << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 9: {
            if (!portableComputerDeque.empty()) {
                std::cout << "Last element in the deque: " << portableComputerDeque.back() << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 10:
            std::cout << "Returning to the previous menu..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
            break;
        }
    } while (choice != 10);
}

void DequeManager::handleComputingMachineDeque() {
    int choice;
    do {
        printDequeMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            ComputingMachine cm;
            std::cin >> cm;
            computingMachineDeque.push_front(cm);
            std::cout << "ComputingMachine added to the front of the deque!" << std::endl;
            break;
        }
        case 2: {
            ComputingMachine cm;
            std::cin >> cm;
            computingMachineDeque.push_back(cm);
            std::cout << "ComputingMachine added to the back of the deque!" << std::endl;
            break;
        }
        case 3: {
            if (!computingMachineDeque.empty()) {
                computingMachineDeque.pop_front();
                std::cout << "ComputingMachine removed from the front of the deque!" << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 4: {
            if (!computingMachineDeque.empty()) {
                computingMachineDeque.pop_back();
                std::cout << "ComputingMachine removed from the back of the deque!" << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 5: {
            std::cout << "Elements in the deque:" << std::endl;
            for (const auto& cm : computingMachineDeque) {
                ComputingMachine tempCM = cm;
                tempCM.show();
                std::cout << tempCM << std::endl;
            }
            break;
        }
        case 6: {
            std::sort(computingMachineDeque.begin(), computingMachineDeque.end(), [](ComputingMachine& a, ComputingMachine& b) {
                return a.GetCPUcapacity() < b.GetCPUcapacity();
                });
            std::cout << "Deque sorted!" << std::endl;
            break;
        }
        case 7: {
            int index;
            ComputingMachine cm;
            std::cout << "Enter the position to insert the element (0-based): ";
            std::cin >> index;
            std::cout << "Enter ComputingMachine details: ";
            std::cin >> cm;
            if (index >= 0 && index <= computingMachineDeque.size()) {
                auto it = computingMachineDeque.begin() + index;
                computingMachineDeque.insert(it, cm);
                std::cout << "ComputingMachine inserted at position " << index << "!" << std::endl;
            }
            else {
                std::cout << "Invalid position!" << std::endl;
            }
            break;
        }
        case 8: {
            if (!computingMachineDeque.empty()) {
                std::cout << "First element in the deque: " << computingMachineDeque.front() << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 9: {
            if (!computingMachineDeque.empty()) {
                std::cout << "Last element in the deque: " << computingMachineDeque.back() << std::endl;
            }
            else {
                std::cout << "Deque is empty!" << std::endl;
            }
            break;
        }
        case 10:
            std::cout << "Returning to the previous menu..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
            break;
        }
    } while (choice != 10);
}

void DequeManager::printDequeMenu() const {
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