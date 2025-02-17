#include "Monoblock.h"
#include "StationaryComputer.h"
#include <iomanip>
#include <iostream>
#include <limits>
#include "InputException.h"
// ����������� �� ���������
Monoblock::Monoblock()
    : StationaryComputer(), OS(""), weight(0) {}

// ����������� � �����������
Monoblock::Monoblock(double CPUcapacity, double RAM, int DiskSpace, int CPUcores, const std::string& MotherBoardChipset, const std::string& GPU, const std::string& OS, int weight)
    : StationaryComputer(CPUcapacity, RAM, DiskSpace, CPUcores, MotherBoardChipset, GPU), OS(OS), weight(weight) {
    // ��������� ������
    if (CPUcapacity <= 0) {
        std::cerr << "Error: Invalid CPU capacity value." << std::endl;
        throw std::invalid_argument("CPU capacity must be positive.");
    }
    if (RAM <= 0) {
        std::cerr << "Error: Invalid RAM value." << std::endl;
        throw std::invalid_argument("RAM must be positive.");
    }
    if (DiskSpace <= 0) {
        std::cerr << "Error: Invalid Disk Space value." << std::endl;
        throw std::invalid_argument("Disk space must be positive.");
    }
    if (weight <= 0) {
        std::cerr << "Error: Invalid weight value." << std::endl;
        throw std::invalid_argument("Weight must be positive.");
    }
    if (OS.empty()) {
        std::cerr << "Error: Operating System cannot be empty." << std::endl;
        throw std::invalid_argument("Operating system cannot be empty.");
    }
}

// ����������� �����������
Monoblock::Monoblock(const Monoblock& other)
    : StationaryComputer(other), OS(other.OS), weight(other.weight) {}

// �������� ������������
Monoblock& Monoblock::operator=(const Monoblock& other) {
    if (this == &other) {
        return *this; // ������ �� ����������������
    }

    StationaryComputer::operator=(other); // ������������ �������� ������
    OS = other.OS;
    weight = other.weight;

    return *this;
}

// ����������
Monoblock::~Monoblock() {
    // ������������ ��������, ���� ��� ����������
}

// ������ ��� OS
std::string Monoblock::GetOS() const {
    return OS;
}

// ������ ��� OS � ����������
void Monoblock::SetOS(const std::string& newOS) {
    if (newOS.empty()) {
        std::cerr << "Error: Operating System cannot be empty." << std::endl;
        return;
    }
    OS = newOS;
}

// ������ ��� weight
int Monoblock::GetWeight() const {
    return weight;
}

// ������ ��� weight � ����������
void Monoblock::SetWeight(int newWeight) {
    if (newWeight <= 0) {
        std::cerr << "Error: Weight must be positive." << std::endl;
        return;
    }
    weight = newWeight;
}

// ���������� ������
std::ostream& operator<<(std::ostream& os, const Monoblock& mb) {
    const int valueWidth = 8; // ������ ��������
    const int colWidth = 15;
    os << std::right << std::setw(valueWidth) << mb.CPUcapacity << " GHz "
        << std::right << std::setw(valueWidth) << mb.RAM << " GB "
        << std::right << std::setw(valueWidth) << mb.DiskSpace << " GB "
        << std::right << std::setw(valueWidth) << mb.OS << " "
        << std::right << std::setw(valueWidth) << mb.weight << " kg";

    return os;
}

// ���������� ����� � ����������
std::istream& operator>>(std::istream& is, Monoblock& mb) {
    // ���� ������ �������� ������
    is >> static_cast<StationaryComputer&>(mb);

    // ���� ������������ ������� � ���������
    while (true) {
        try {
            std::cout << "Enter Operating System: ";
            std::getline(is >> std::ws, mb.OS); // ��������� ������ � ������ ��������� ��������

            if (mb.OS.empty()) {
                throw InputException("Operating System cannot be empty. Please enter a valid value.");
            }

            
            break;
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            // ����� ������� �� �����, ��� ��� `std::getline` �� ���������� ���� ������
        }
    }

    // ���� ���� � ���������
    while (true) {
        try {
            std::cout << "Enter Weight (kg): ";
            is >> mb.weight;

            if (is.fail() || mb.weight <= 0) {
                throw InputException("Weight must be a positive number. Please enter a valid value.");
            }

            break; // ������� �� �����, ���� ���� ����������
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            is.clear(); // ���������� ��������� ������
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ����� �����
        }
    }

    return is;
}


void Monoblock::show() {
    const std::string title = "Monoblock";
    const int tableWidth = 80; // ����� ������ �������
    const int titlePadding = (tableWidth - title.size()) / 2; // ���������� �������

    // ����� ��������� �� ������
    std::cout << std::string(titlePadding, ' ') << title << std::endl;
    std::cout << std::string(tableWidth, '-') << std::endl;

    // ��������� �������
    std::cout << std::left
        << std::setw(15) << "CPU Capacity"
        << std::setw(10) << "RAM"
        << std::setw(15) << "Disk Space"
        << std::setw(15) << "OS"
        << std::setw(15) << "Weight"
        << std::endl;
    std::cout << std::string(tableWidth, '-') << std::endl;
}

void Monoblock::Serialize(std::ostream& os) const {
    // ������������ ������ �������� ������ (StationaryComputer)
    StationaryComputer::Serialize(os);

    // ������������ ������ ����������� ��� Monoblock
    os << OS << std::endl; // ��������� ������������ �������
    os << weight << std::endl; // ��������� ���
}

void Monoblock::Deserialize(std::istream& is) {
    std::string separator;
    std::getline(is, separator);
    StationaryComputer::Deserialize(is);
    // �������������� ������ ����������� ��� Monoblock
    std::getline(is, OS); // ��������������� ������������ �������
    is >> weight; // ��������������� ���

    // ���������� ������ ����� ������ ����� ����� ����
    is.ignore();
}
