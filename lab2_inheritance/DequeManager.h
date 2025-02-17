#pragma once
#include <deque>
#include <algorithm>
#include "StationaryComputer.h"
#include "PortableComputer.h"
#include "Monoblock.h"
#include "Tablet.h"
#include "Laptop.h"
#include "ComputingMachine.h"

class DequeManager {
private:
    std::deque<Laptop> laptopDeque;
    std::deque<Tablet> tabletDeque;
    std::deque<StationaryComputer> stationaryComputerDeque;
    std::deque<Monoblock> monoblockDeque;
    std::deque<PortableComputer> portableComputerDeque;
    std::deque<ComputingMachine> computingMachineDeque;

public:
    void handleLaptopDeque();
    void handleTabletDeque();
    void handleStationaryComputerDeque();
    void handleMonoblockDeque();
    void handlePortableComputerDeque();
    void handleComputingMachineDeque();

    void printDequeMenu() const;
};