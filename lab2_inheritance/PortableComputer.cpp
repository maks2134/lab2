#include "PortableComputer.h"
#include "ComputingMachine.h"
#include <iomanip>
#include <limits>
#include <iostream>
#include "InputException.h"

// ����������� �� ���������
PortableComputer::PortableComputer()
    : ComputingMachine(), DisplaySize(0), Resolution(""), BatteryCapacity(0) {}

// ����������� � �����������
PortableComputer::PortableComputer(double CPUcapacity, double RAM, int DiskSpace, int DisplaySize, const std::string& Resolution, int BatteryCapacity)
    : ComputingMachine(CPUcapacity, RAM, DiskSpace), DisplaySize(DisplaySize), Resolution(Resolution), BatteryCapacity(BatteryCapacity) {
    if (DisplaySize <= 0) {
        std::cerr << "Error: Invalid Display Size." << std::endl;
        throw std::invalid_argument("Display Size must be positive.");
    }
    if (BatteryCapacity <= 0) {
        std::cerr << "Error: Invalid Battery Capacity." << std::endl;
        throw std::invalid_argument("Battery Capacity must be positive.");
    }
}

// ����������� �����������
PortableComputer::PortableComputer(const PortableComputer& other)
    : ComputingMachine(other), DisplaySize(other.DisplaySize), Resolution(other.Resolution), BatteryCapacity(other.BatteryCapacity) {}

// �������� ������������
PortableComputer& PortableComputer::operator=(const PortableComputer& other) {
    if (this == &other) {
        return *this; // ������ �� ����������������
    }

    ComputingMachine::operator=(other); // ������������ �������� ������
    DisplaySize = other.DisplaySize;
    Resolution = other.Resolution;
    BatteryCapacity = other.BatteryCapacity;

    return *this;
}

// ����������
PortableComputer::~PortableComputer() {
    // ������������ ��������, ���� ��� ����������
}

// ������� � ������� � ����������
int PortableComputer::GetDisplaySize() const {
    return DisplaySize;
}

void PortableComputer::SetDisplaySize(int newDisplaySize) {
    if (newDisplaySize <= 0) {
        std::cerr << "Error: Display Size must be positive." << std::endl;
        return;
    }
    DisplaySize = newDisplaySize;
}

std::string PortableComputer::GetResolution() const {
    return Resolution;
}

void PortableComputer::SetResolution(const std::string& newResolution) {
    if (newResolution.empty()) {
        std::cerr << "Error: Resolution cannot be empty." << std::endl;
        return;
    }
    Resolution = newResolution;
}

int PortableComputer::GetBatteryCapacity() const {
    return BatteryCapacity;
}

void PortableComputer::SetBatteryCapacity(int newBatteryCapacity) {
    if (newBatteryCapacity <= 0) {
        std::cerr << "Error: Battery Capacity must be positive." << std::endl;
        return;
    }
    BatteryCapacity = newBatteryCapacity;
}

// ���������� ������
std::ostream& operator<<(std::ostream& os, PortableComputer& pc) {
    const int colWidth = 15;  // Width for the labels
    const int valueWidth = 8; // Width for the values

    // Display ComputingMachine data
    os << std::right
        << std::setw(valueWidth) << pc.GetCPUcapacity() << " GHz "
        << std::setw(valueWidth) << pc.GetRAM() << " GB "
        << std::setw(valueWidth) << pc.GetDiskSpace() << " GB ";

    // Display PortableComputer data in a similar format
    os << std::setw(valueWidth) << pc.GetDisplaySize() << " inches "
        << std::setw(valueWidth) << pc.GetResolution() << " "
        << std::setw(valueWidth) << pc.GetBatteryCapacity() << " mAh";

    return os;
}

// ���������� ����� � ����������
std::istream& operator>>(std::istream& is, PortableComputer& pc) {
    // ���� ������ �������� ������
    is >> static_cast<ComputingMachine&>(pc);

    // ���� Display Size � ���������
    while (true) {
        try {
            std::cout << "Enter Display Size (inches): ";
            is >> pc.DisplaySize;
            if (is.fail() || pc.DisplaySize <= 0) {
                throw InputException("Invalid input for Display Size. Must be a positive number.");
            }
            break; // ���� ���������, ������� �� �����
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
            is.clear(); // ������� ��������� ������
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������ ������ �� ������
        }
    }

    // ������� ������ ����� ������ ������
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // ���� Resolution � ���������
    while (true) {
        try {
            std::cout << "Enter Resolution: ";
            std::getline(is, pc.Resolution);
            InputException::validateResolution(pc.Resolution); // ���������� ������� ���������
            break; // ���� ���������, ������� �� �����
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
        }
    }

    // ���� Battery Capacity � ���������
    while (true) {
        try {
            std::cout << "Enter Battery Capacity (mAh): ";
            is >> pc.BatteryCapacity;
            InputException::validateBatteryCapacity(pc.BatteryCapacity); // ���������� ������� ���������
            break; // ���� ���������, ������� �� �����
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
            is.clear(); // ������� ��������� ������
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������ ������ �� ������
        }
    }

    return is;
}

// ����� ��������� � �������
void PortableComputer::show() {
    const std::string title = "PortableComputer";
    const int tableWidth = 80;
    const int titlePadding = (tableWidth - title.size()) / 2;

    // ����� ��������� �� ������
    std::cout << std::string(titlePadding, ' ') << title << std::endl;
    std::cout << std::string(tableWidth, '-') << std::endl;

    // ��������� �������
    std::cout << std::left
        << std::setw(15) << "CPU Capacity"
        << std::setw(10) << "RAM"
        << std::setw(15) << "Disk Space"
        << std::setw(15) << "Display Size"
        << std::setw(15) << "Resolution"
        << std::setw(20) << "Battery Capacity"
        << std::endl;
}

// ������������ ������
void PortableComputer::Serialize(std::ostream& os) const {
    // ������������ ������ �������� ������ (ComputingMachine)
    ComputingMachine::Serialize(os);

    // ������������ ������, ����������� ��� PortableComputer
    os << DisplaySize << std::endl;         // ��������� ������ ������
    os << Resolution << std::endl;          // ��������� ���������� ������
    os << BatteryCapacity << std::endl;     // ��������� ������� �������
}

// �������������� ������
void PortableComputer::Deserialize(std::istream& is) {
    // �������������� ������ �������� ������ (ComputingMachine)
    ComputingMachine::Deserialize(is);

    // �������������� ������, ����������� ��� PortableComputer
    is >> DisplaySize;                       // ��������������� ������ ������
    is.ignore();                              // ���������� ������ ����� ������ ����� ����� �����
    std::getline(is, Resolution);             // ��������������� ���������� ������
    is >> BatteryCapacity;                   // ��������������� ������� �������
    is.ignore();                              // ���������� ������ ����� ������ ����� ����� �����
}
