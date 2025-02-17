#include "ComputingMachine.h"
#include "InputException.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

// ����������� �� ���������
ComputingMachine::ComputingMachine() : CPUcapacity(0), RAM(0), DiskSpace(0) {}

// ����������� � �����������
ComputingMachine::ComputingMachine(double CPUcapacity, double RAM, int DiskSpace) {
    // ��������� ������� ������ ����� InputException
    InputException::validateCPUValue(CPUcapacity);
    InputException::validateRAMValue(RAM);
    InputException::validateDiskSpaceValue(DiskSpace);

    this->CPUcapacity = CPUcapacity;
    this->RAM = RAM;
    this->DiskSpace = DiskSpace;
}

// ����������� �����������
ComputingMachine::ComputingMachine(const ComputingMachine& other) {
    this->CPUcapacity = other.CPUcapacity;
    this->RAM = other.RAM;
    this->DiskSpace = other.DiskSpace;
}

// �������� ������������
ComputingMachine& ComputingMachine::operator=(const ComputingMachine& other) {
    if (this == &other) {
        return *this;
    }

    this->CPUcapacity = other.CPUcapacity;
    this->RAM = other.RAM;
    this->DiskSpace = other.DiskSpace;

    return *this;
}

// ���������� ��������� ������
std::ostream& operator<<(std::ostream& os, ComputingMachine& cm) {
    const int colWidth = 15; // ������ ���������
    const int valueWidth = 8; // ������ ��������

    os
        << std::right << std::setw(valueWidth) << cm.CPUcapacity << " GHz "
        << std::right << std::setw(valueWidth) << cm.RAM << " GB "
        << std::right << std::setw(valueWidth) << cm.DiskSpace << " GB";

    return os;
}

// ���������� ��������� �����
std::istream& operator>>(std::istream& is, ComputingMachine& cm) {
    double cpu;
    double ram;
    int disk;

    while (true) {
        try {
            std::cout << "Enter CPU capacity (GHz): ";
            is >> cpu;
            if (is.fail()) throw InputException("Invalid input for CPU capacity. Expected a number.");

            InputException::validateCPUValue(cpu); // �������� ���������� ��������
            break; // ���� ���� ����������, ������� �� �����
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            is.clear(); // ������� �����
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������������ ������
        }
    }

    while (true) {
        try {
            std::cout << "Enter RAM size (GB): ";
            is >> ram;
            if (is.fail()) throw InputException("Invalid input for RAM size. Expected a number.");

            InputException::validateRAMValue(ram); // �������� ���������� ��������
            break; // ���� ���� ����������, ������� �� �����
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            is.clear(); // ������� �����
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������������ ������
        }
    }

    while (true) {
        try {
            std::cout << "Enter Disk Space (GB): ";
            is >> disk;
            if (is.fail()) throw InputException("Invalid input for Disk Space. Expected an integer.");

            InputException::validateDiskSpaceValue(disk); // �������� ���������� ��������
            break; // ���� ���� ����������, ������� �� �����
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            is.clear(); // ������� �����
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������������ ������
        }
    }

    cm.CPUcapacity = cpu;
    cm.RAM = ram;
    cm.DiskSpace = disk;

    return is;
}



// ������ ��� DiskSpace
int ComputingMachine::GetDiskSpace() const {
    return DiskSpace;
}

// ������ ��� DiskSpace � ����������
void ComputingMachine::SetDiskSpace(int newDiskSpace) {
    InputException::validateDiskSpaceValue(newDiskSpace); // ���������
    DiskSpace = newDiskSpace;
}

// ������ ��� CPUcapacity
double ComputingMachine::GetCPUcapacity() const {
    return CPUcapacity;
}

// ������ ��� CPUcapacity � ����������
void ComputingMachine::SetCPUcapacity(double newCPUcapacity) {
    InputException::validateCPUValue(newCPUcapacity); // ���������
    CPUcapacity = newCPUcapacity;
}

// ������ ��� RAM
double ComputingMachine::GetRAM() const {
    return RAM;
}

// ������ ��� RAM � ����������
void ComputingMachine::SetRAM(double newRAM) {
    InputException::validateRAMValue(newRAM); // ���������
    RAM = newRAM;
}

// ����������
ComputingMachine::~ComputingMachine() {}

// ����� show ��� ����������� ������ � �������
void ComputingMachine::show() {
    const std::string title = "ComputingMachine";
    const int tableWidth = 40; // ����� ������ �������
    const int titlePadding = (tableWidth - title.size()) / 2; // ���������� �������

    // ����� ��������� �� ������
    std::cout << std::string(titlePadding, ' ') << title << std::endl;
    std::cout << std::string(tableWidth, '-') << std::endl;

    // ��������� �������
    std::cout << std::left
        << std::setw(15) << "CPU Capacity"
        << std::setw(10) << "RAM"
        << std::setw(15) << "Disk Space"
        << std::endl;

    // ������
    std::cout << std::right
        << std::setw(15) << CPUcapacity << " GHz"
        << std::setw(10) << RAM << " GB"
        << std::setw(15) << DiskSpace << " GB"
        << std::endl;
}

// ����� ��� ������������ �������
void ComputingMachine::Serialize(std::ostream& os) const {
    os << CPUcapacity << std::endl;  // ��������� ������� ����������
    os << RAM << std::endl;          // ��������� ����� ���
    os << DiskSpace << std::endl;    // ��������� ������������ �� �����
}

// ����� ��� �������������� �������
void ComputingMachine::Deserialize(std::istream& is) {
    double cpu;
    double ram;
    int disk;

    is >> cpu >> ram >> disk;

    // ��������� ������� ������ ����� InputException
    InputException::validateCPUValue(cpu);
    InputException::validateRAMValue(ram);
    InputException::validateDiskSpaceValue(disk);

    CPUcapacity = cpu;
    RAM = ram;
    DiskSpace = disk;
}
