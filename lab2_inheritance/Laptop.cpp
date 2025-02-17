#include "Laptop.h"
#include "PortableComputer.h"
#include "ComputingMachine.h"
#include <iomanip>
#include <iostream>
#include <limits>
#include "InputException.h"
// ����������� �� ���������
Laptop::Laptop() : Keyboardlight(false), Microphone(false), ScreenType("Unknown") {}

// ����������� � �����������
Laptop::Laptop(double CPUcapacity, double RAM, int DiskSpace, double ScreenSize, const std::string& Resolution, int BatteryCapacity,
    bool Keyboardlight, bool Microphone, const std::string& ScreenType)
    : PortableComputer(CPUcapacity, RAM, DiskSpace, ScreenSize, Resolution, BatteryCapacity),
    Keyboardlight(Keyboardlight), Microphone(Microphone), ScreenType(ScreenType) {
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
    if (ScreenSize <= 0) {
        std::cerr << "Error: Invalid Screen Size value." << std::endl;
        throw std::invalid_argument("Screen size must be positive.");
    }
    if (BatteryCapacity <= 0) {
        std::cerr << "Error: Invalid Battery Capacity value." << std::endl;
        throw std::invalid_argument("Battery capacity must be positive.");
    }
    if (ScreenType.empty()) {
        std::cerr << "Error: Screen Type cannot be empty." << std::endl;
        throw std::invalid_argument("Screen type cannot be empty.");
    }
}

// ����������� �����������
Laptop::Laptop(const Laptop& other)
    : PortableComputer(other), Keyboardlight(other.Keyboardlight), Microphone(other.Microphone), ScreenType(other.ScreenType) {}

// �������� ������������
Laptop& Laptop::operator=(const Laptop& other) {
    if (this != &other) {
        PortableComputer::operator=(other);  // ����������� ������ �������� ������
        Keyboardlight = other.Keyboardlight;
        Microphone = other.Microphone;
        ScreenType = other.ScreenType;
    }
    return *this;
}

// ����������
Laptop::~Laptop() {}

// ������� � �������
bool Laptop::GetKeyboardlight() const {
    return Keyboardlight;
}

void Laptop::SetKeyboardlight(bool newKeyboardlight) {
    Keyboardlight = newKeyboardlight;
}

bool Laptop::GetMicrophone() const {
    return Microphone;
}

void Laptop::SetMicrophone(bool newMicrophone) {
    Microphone = newMicrophone;
}

std::string Laptop::GetScreenType() const {
    return ScreenType;
}

void Laptop::SetScreenType(const std::string& newScreenType) {
    if (newScreenType.empty()) {
        std::cerr << "Error: Screen Type cannot be empty." << std::endl;
        return;
    }
    ScreenType = newScreenType;
}

// ���������� ��������� ������
std::ostream& operator<<(std::ostream& os, Laptop& laptop) {
    const int valueWidth = 8; // ������ ��������
    const int colWidth = 15;
    // ������� ������ �������� ������
    os << static_cast<ComputingMachine&>(laptop);

    // ��������� ���������� ���� Laptop
    os << std::right << std::setw(valueWidth) << (laptop.Keyboardlight ? "Yes" : "No") << " "
        << std::right << std::setw(valueWidth) << (laptop.Microphone ? "Yes" : "No") << " "
        << std::right << std::setw(valueWidth) << laptop.ScreenType;

    return os;
}

std::istream& operator>>(std::istream& is, Laptop& laptop) {
    // ���� ������ �������� ������
    is >> static_cast<PortableComputer&>(laptop);

    // ���� Keyboard Light � ���������
    while (true) {
        try {
            std::cout << "Keyboard Light (1 - Yes, 0 - No): ";
            is >> laptop.Keyboardlight;

            if (is.fail() || (laptop.Keyboardlight != 0 && laptop.Keyboardlight != 1)) {
                throw InputException("Invalid input for Keyboard Light. Please enter 1 for Yes or 0 for No.");
            }
            break; // ���� ���� ����������, ������� �� �����
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            is.clear(); // ���������� ��������� ������
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ����� �����
        }
    }

    // ���� Microphone � ���������
    while (true) {
        try {
            std::cout << "Microphone (1 - Yes, 0 - No): ";
            is >> laptop.Microphone;

            if (is.fail() || (laptop.Microphone != 0 && laptop.Microphone != 1)) {
                throw InputException("Invalid input for Microphone. Please enter 1 for Yes or 0 for No.");
            }
            break; // ���� ���� ����������, ������� �� �����
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // ���� Screen Type � ���������
    while (true) {
        try {
            std::cout << "Enter Screen Type: ";
            is >> laptop.ScreenType;

            if (is.fail() || laptop.ScreenType.empty()) {
                throw InputException("Screen Type cannot be empty. Please enter a valid value.");
            }

           
            InputException::validateScreenType(laptop.ScreenType); // ��������� ���������� ScreenType
            break; // ���� ���� ����������, ������� �� �����
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return is;
}


void Laptop::show() {
    const std::string title = "Laptop";
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
        << std::setw(10) << "Keyboard"
        << std::setw(10) << "Mic"
        << std::setw(15) << "Screen Type"
        << std::endl;
    std::cout << std::string(tableWidth, '-') << std::endl;
}

void Laptop::Serialize(std::ostream& os) const {
    // ������� ����������� ������ �������� ������
    PortableComputer::Serialize(os);

    // ����� ���������� ���������� ���� Laptop
    os << Keyboardlight << " "   // ����������� bool � 1/0
        << Microphone << " "      // ����������� bool � 1/0
        << ScreenType << std::endl; // ������
}

void Laptop::Deserialize(std::istream& is) {
    std::string separator;
    std::getline(is, separator);
    PortableComputer::Deserialize(is);

    // ����� ��������� ���������� ���� Laptop
    is >> Keyboardlight >> Microphone >> ScreenType;
}
