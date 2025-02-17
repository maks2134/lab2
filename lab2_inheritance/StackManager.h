#pragma once
#include "Stack.h"
#include "StationaryComputer.h"
#include "PortableComputer.h"
#include "Monoblock.h"
#include "Tablet.h"
#include "Laptop.h"
#include "ComputingMachine.h"
#include "Algorithms.h"

class StackManager {
private:
    Stack<StationaryComputer> stationaryComputerStack;
    Stack<PortableComputer> portableComputerStack;
    Stack<Monoblock> monoblockStack;
    Stack<Tablet> tabletStack;
    Stack<Laptop> laptopStack;
    Stack<ComputingMachine> computingMachineStack;

public:
    void addStationaryComputer();
    void addPortableComputer();
    void addMonoblock();
    void addTablet();
    void addLaptop();
    void addComputingMachine();

    void removeStationaryComputer();
    void removePortableComputer();
    void removeMonoblock();
    void removeTablet();
    void removeLaptop();
    void removeComputingMachine();

    void showTopStationaryComputer() const;
    void showTopPortableComputer() const;
    void showTopMonoblock() const;
    void showTopTablet() const;
    void showTopLaptop() const;
    void showTopComputingMachine() const;

    void findElementByCPU(int stackChoice, double cpuCapacity);
    void showStackSize(int stackChoice) const;
    void sortStackByCPU(int stackChoice);
    void insertElementAt(int stackChoice, int index);
    void writeToTextFile(int stackChoice, const std::string& filename) const;
    void writeToBinaryFile(int stackChoice, const std::string& filename) const;

    void iterateThroughStack(int stackChoice) const;
};