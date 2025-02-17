#include "StackManager.h"

void StackManager::addStationaryComputer() {
    StationaryComputer sc;
    std::cin >> sc;
    stationaryComputerStack.push(sc);
    std::cout << "StationaryComputer added to the stack!" << std::endl;
}

void StackManager::addPortableComputer() {
    PortableComputer pc;
    std::cin >> pc;
    portableComputerStack.push(pc);
    std::cout << "PortableComputer added to the stack!" << std::endl;
}

void StackManager::addMonoblock() {
    Monoblock mb;
    std::cin >> mb;
    monoblockStack.push(mb);
    std::cout << "Monoblock added to the stack!" << std::endl;
}

void StackManager::addTablet() {
    Tablet tb;
    std::cin >> tb;
    tabletStack.push(tb);
    std::cout << "Tablet added to the stack!" << std::endl;
}

void StackManager::addLaptop() {
    Laptop lp;
    std::cin >> lp;
    laptopStack.push(lp);
    std::cout << "Laptop added to the stack!" << std::endl;
}

void StackManager::addComputingMachine() {
    ComputingMachine cm;
    std::cin >> cm;
    computingMachineStack.push(cm);
    std::cout << "ComputingMachine added to the stack!" << std::endl;
}

void StackManager::removeStationaryComputer() {
    if (!stationaryComputerStack.isEmpty()) {
        stationaryComputerStack.pop();
        std::cout << "Top element removed from StationaryComputer stack." << std::endl;
    }
    else {
        std::cout << "StationaryComputer stack is empty." << std::endl;
    }
}

void StackManager::removePortableComputer() {
    if (!portableComputerStack.isEmpty()) {
        portableComputerStack.pop();
        std::cout << "Top element removed from PortableComputer stack." << std::endl;
    }
    else {
        std::cout << "PortableComputer stack is empty." << std::endl;
    }
}

void StackManager::removeMonoblock() {
    if (!monoblockStack.isEmpty()) {
        monoblockStack.pop();
        std::cout << "Top element removed from Monoblock stack." << std::endl;
    }
    else {
        std::cout << "Monoblock stack is empty." << std::endl;
    }
}

void StackManager::removeTablet() {
    if (!tabletStack.isEmpty()) {
        tabletStack.pop();
        std::cout << "Top element removed from Tablet stack." << std::endl;
    }
    else {
        std::cout << "Tablet stack is empty." << std::endl;
    }
}

void StackManager::removeLaptop() {
    if (!laptopStack.isEmpty()) {
        laptopStack.pop();
        std::cout << "Top element removed from Laptop stack." << std::endl;
    }
    else {
        std::cout << "Laptop stack is empty." << std::endl;
    }
}

void StackManager::removeComputingMachine() {
    if (!computingMachineStack.isEmpty()) {
        computingMachineStack.pop();
        std::cout << "Top element removed from ComputingMachine stack." << std::endl;
    }
    else {
        std::cout << "ComputingMachine stack is empty." << std::endl;
    }
}

void StackManager::showTopStationaryComputer() const {
    if (!stationaryComputerStack.isEmpty()) {
        StationaryComputer sc = stationaryComputerStack.top();
        sc.show();
        std::cout << sc << std::endl;
    }
    else {
        std::cout << "StationaryComputer stack is empty." << std::endl;
    }
}

void StackManager::showTopPortableComputer() const {
    if (!portableComputerStack.isEmpty()) {
        PortableComputer pc = portableComputerStack.top();
        pc.show();
        std::cout << pc << std::endl;
    }
    else {
        std::cout << "PortableComputer stack is empty." << std::endl;
    }
}

void StackManager::showTopMonoblock() const {
    if (!monoblockStack.isEmpty()) {
        Monoblock mb = monoblockStack.top();
        mb.show();
        std::cout << mb << std::endl;
    }
    else {
        std::cout << "Monoblock stack is empty." << std::endl;
    }
}

void StackManager::showTopTablet() const {
    if (!tabletStack.isEmpty()) {
        Tablet tb = tabletStack.top();
        tb.show();
        std::cout << tb << std::endl;
    }
    else {
        std::cout << "Tablet stack is empty." << std::endl;
    }
}

void StackManager::showTopLaptop() const {
    if (!laptopStack.isEmpty()) {
        Laptop lp = laptopStack.top();
        lp.show();
        std::cout << lp << std::endl;
    }
    else {
        std::cout << "Laptop stack is empty." << std::endl;
    }
}

void StackManager::showTopComputingMachine() const {
    if (!computingMachineStack.isEmpty()) {
        ComputingMachine cm = computingMachineStack.top();
        cm.show();
        std::cout << cm << std::endl;
    }
    else {
        std::cout << "ComputingMachine stack is empty." << std::endl;
    }
}

void StackManager::findElementByCPU(int stackChoice, double cpuCapacity) {
	
    try {
        switch (stackChoice) {
        case 1: {
            auto result = Algorithms::findElementByCPU(stationaryComputerStack, cpuCapacity);
            std::cout << "Element found: " << result << std::endl;
            break;
        }
        case 2: {
            auto result = Algorithms::findElementByCPU(portableComputerStack, cpuCapacity);
            std::cout << "Element found: " << result << std::endl;
            break;
        }
        case 3: {
            auto result = Algorithms::findElementByCPU(monoblockStack, cpuCapacity);
            std::cout << "Element found: " << result << std::endl;
            break;
        }
        case 4: {
            auto result = Algorithms::findElementByCPU(tabletStack, cpuCapacity);
            std::cout << "Element found: " << result << std::endl;
            break;
        }
        case 5: {
            auto result = Algorithms::findElementByCPU(laptopStack, cpuCapacity);
            std::cout << "Element found: " << result << std::endl;
            break;
        }
        case 6: {
            auto result = Algorithms::findElementByCPU(computingMachineStack, cpuCapacity);
            std::cout << "Element found: " << result << std::endl;
            break;
        }
        default:
            std::cout << "Invalid stack choice." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void StackManager::showStackSize(int stackChoice) const {
    switch (stackChoice) {
    case 1: std::cout << "Size: " << stationaryComputerStack.size() << std::endl; break;
    case 2: std::cout << "Size: " << portableComputerStack.size() << std::endl; break;
    case 3: std::cout << "Size: " << monoblockStack.size() << std::endl; break;
    case 4: std::cout << "Size: " << tabletStack.size() << std::endl; break;
    case 5: std::cout << "Size: " << laptopStack.size() << std::endl; break;
    case 6: std::cout << "Size: " << computingMachineStack.size() << std::endl; break;
    default: std::cout << "Invalid stack choice." << std::endl;
    }
}

void StackManager::sortStackByCPU(int stackChoice) {
    switch (stackChoice) {
    case 1:
        Algorithms::sortStackByCPU(stationaryComputerStack);
        std::cout << "StationaryComputer stack sorted by CPU capacity." << std::endl;
        break;
    case 2:
        Algorithms::sortStackByCPU(portableComputerStack);
        std::cout << "PortableComputer stack sorted by CPU capacity." << std::endl;
        break;
    case 3:
        Algorithms::sortStackByCPU(monoblockStack);
        std::cout << "Monoblock stack sorted by CPU capacity." << std::endl;
        break;
    case 4:
        Algorithms::sortStackByCPU(tabletStack);
        std::cout << "Tablet stack sorted by CPU capacity." << std::endl;
        break;
    case 5:
        Algorithms::sortStackByCPU(laptopStack);
        std::cout << "Laptop stack sorted by CPU capacity." << std::endl;
        break;
    case 6:
        Algorithms::sortStackByCPU(computingMachineStack);
        std::cout << "ComputingMachine stack sorted by CPU capacity." << std::endl;
        break;
    default:
        std::cout << "Invalid stack choice." << std::endl;
    }
}

void StackManager::insertElementAt(int stackChoice, int index) {
    switch (stackChoice) {
    case 1: {
        StationaryComputer sc;
        std::cin >> sc;
        Algorithms::insertElementAt(stationaryComputerStack, sc, index);
        std::cout << "Element inserted at position " << index << " in StationaryComputer stack." << std::endl;
        break;
    }
    case 2: {
        PortableComputer pc;
        std::cin >> pc;
        Algorithms::insertElementAt(portableComputerStack, pc, index);
        std::cout << "Element inserted at position " << index << " in PortableComputer stack." << std::endl;
        break;
    }
    case 3: {
        Monoblock mb;
        std::cin >> mb;
        Algorithms::insertElementAt(monoblockStack, mb, index);
        std::cout << "Element inserted at position " << index << " in Monoblock stack." << std::endl;
        break;
    }
    case 4: {
        Tablet tb;
        std::cin >> tb;
        Algorithms::insertElementAt(tabletStack, tb, index);
        std::cout << "Element inserted at position " << index << " in Tablet stack." << std::endl;
        break;
    }
    case 5: {
        Laptop lp;
        std::cin >> lp;
        Algorithms::insertElementAt(laptopStack, lp, index);
        std::cout << "Element inserted at position " << index << " in Laptop stack." << std::endl;
        break;
    }
    case 6: {
        ComputingMachine cm;
        std::cin >> cm;
        Algorithms::insertElementAt(computingMachineStack, cm, index);
        std::cout << "Element inserted at position " << index << " in ComputingMachine stack." << std::endl;
        break;
    }
    default:
        std::cout << "Invalid stack choice." << std::endl;
    }
}

void StackManager::writeToTextFile(int stackChoice, const std::string& filename) const {
    switch (stackChoice) {
    case 1: stationaryComputerStack.writeToTextFile(filename); break;
    case 2: portableComputerStack.writeToTextFile(filename); break;
    case 3: monoblockStack.writeToTextFile(filename); break;
    case 4: tabletStack.writeToTextFile(filename); break;
    case 5: laptopStack.writeToTextFile(filename); break;
    case 6: computingMachineStack.writeToTextFile(filename); break;
    default: std::cout << "Invalid stack choice." << std::endl;
    }
}

void StackManager::writeToBinaryFile(int stackChoice, const std::string& filename) const {
    switch (stackChoice) {
    case 1: stationaryComputerStack.writeToBinaryFile(filename); break;
    case 2: portableComputerStack.writeToBinaryFile(filename); break;
    case 3: monoblockStack.writeToBinaryFile(filename); break;
    case 4: tabletStack.writeToBinaryFile(filename); break;
    case 5: laptopStack.writeToBinaryFile(filename); break;
    case 6: computingMachineStack.writeToBinaryFile(filename); break;
    default: std::cout << "Invalid stack choice." << std::endl;
    }
}

void StackManager::iterateThroughStack(int stackChoice) const {
    switch (stackChoice) {
    case 1:
        if (stationaryComputerStack.isEmpty()) {
            std::cout << "StationaryComputer stack is empty." << std::endl;
        }
        else {
            for (auto it = stationaryComputerStack.begin(); it != stationaryComputerStack.end(); ++it) {
                it->show();
                std::cout << *it << std::endl;
            }
        }
        break;
    case 2:
        if (portableComputerStack.isEmpty()) {
            std::cout << "PortableComputer stack is empty." << std::endl;
        }
        else {
            for (auto it = portableComputerStack.begin(); it != portableComputerStack.end(); ++it) {
                it->show();
                std::cout << *it << std::endl;
            }
        }
        break;
    case 3:
        if (monoblockStack.isEmpty()) {
            std::cout << "Monoblock stack is empty." << std::endl;
        }
        else {
            for (auto it = monoblockStack.begin(); it != monoblockStack.end(); ++it) {
                it->show();
                std::cout << *it << std::endl;
            }
        }
        break;
    case 4:
        if (tabletStack.isEmpty()) {
            std::cout << "Tablet stack is empty." << std::endl;
        }
        else {
            for (auto it = tabletStack.begin(); it != tabletStack.end(); ++it) {
                it->show();
                std::cout << *it << std::endl;
            }
        }
        break;
    case 5:
        if (laptopStack.isEmpty()) {
            std::cout << "Laptop stack is empty." << std::endl;
        }
        else {
            for (auto it = laptopStack.begin(); it != laptopStack.end(); ++it) {
                it->show();
                std::cout << *it << std::endl;
            }
        }
        break;
    case 6:
        if (computingMachineStack.isEmpty()) {
            std::cout << "ComputingMachine stack is empty." << std::endl;
        }
        else {
            for (auto it = computingMachineStack.begin(); it != computingMachineStack.end(); ++it) {
                it->show();
                std::cout << *it << std::endl;
            }
        }
        break;
    default:
        std::cout << "Invalid stack choice." << std::endl;
    }
}