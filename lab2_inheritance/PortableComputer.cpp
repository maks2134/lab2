#include "PortableComputer.h"
#include "ComputingMachine.h"
#include <iomanip>
#include <limits>
#include <iostream>
#include "InputException.h"

// Конструктор по умолчанию
PortableComputer::PortableComputer()
    : ComputingMachine(), DisplaySize(0), Resolution(""), BatteryCapacity(0) {}

// Конструктор с параметрами
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

// Конструктор копирования
PortableComputer::PortableComputer(const PortableComputer& other)
    : ComputingMachine(other), DisplaySize(other.DisplaySize), Resolution(other.Resolution), BatteryCapacity(other.BatteryCapacity) {}

// Оператор присваивания
PortableComputer& PortableComputer::operator=(const PortableComputer& other) {
    if (this == &other) {
        return *this; // Защита от самоприсваивания
    }

    ComputingMachine::operator=(other); // Присваивание базового класса
    DisplaySize = other.DisplaySize;
    Resolution = other.Resolution;
    BatteryCapacity = other.BatteryCapacity;

    return *this;
}

// Деструктор
PortableComputer::~PortableComputer() {
    // Освобождение ресурсов, если это необходимо
}

// Геттеры и сеттеры с валидацией
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

// Перегрузка вывода
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

// Перегрузка ввода с валидацией
std::istream& operator>>(std::istream& is, PortableComputer& pc) {
    // Ввод данных базового класса
    is >> static_cast<ComputingMachine&>(pc);

    // Ввод Display Size с проверкой
    while (true) {
        try {
            std::cout << "Enter Display Size (inches): ";
            is >> pc.DisplaySize;
            if (is.fail() || pc.DisplaySize <= 0) {
                throw InputException("Invalid input for Display Size. Must be a positive number.");
            }
            break; // Ввод корректен, выходим из цикла
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
            is.clear(); // Очищаем состояние потока
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Удаляем лишние данные из буфера
        }
    }

    // Очистка буфера перед вводом строки
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Ввод Resolution с проверкой
    while (true) {
        try {
            std::cout << "Enter Resolution: ";
            std::getline(is, pc.Resolution);
            InputException::validateResolution(pc.Resolution); // Используем функцию валидации
            break; // Ввод корректен, выходим из цикла
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
        }
    }

    // Ввод Battery Capacity с проверкой
    while (true) {
        try {
            std::cout << "Enter Battery Capacity (mAh): ";
            is >> pc.BatteryCapacity;
            InputException::validateBatteryCapacity(pc.BatteryCapacity); // Используем функцию валидации
            break; // Ввод корректен, выходим из цикла
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
            is.clear(); // Очищаем состояние потока
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Удаляем лишние данные из буфера
        }
    }

    return is;
}

// Вывод заголовка и таблицы
void PortableComputer::show() {
    const std::string title = "PortableComputer";
    const int tableWidth = 80;
    const int titlePadding = (tableWidth - title.size()) / 2;

    // Вывод заголовка по центру
    std::cout << std::string(titlePadding, ' ') << title << std::endl;
    std::cout << std::string(tableWidth, '-') << std::endl;

    // Заголовки таблицы
    std::cout << std::left
        << std::setw(15) << "CPU Capacity"
        << std::setw(10) << "RAM"
        << std::setw(15) << "Disk Space"
        << std::setw(15) << "Display Size"
        << std::setw(15) << "Resolution"
        << std::setw(20) << "Battery Capacity"
        << std::endl;
}

// Сериализация данных
void PortableComputer::Serialize(std::ostream& os) const {
    // Сериализация данных базового класса (ComputingMachine)
    ComputingMachine::Serialize(os);

    // Сериализация данных, специфичных для PortableComputer
    os << DisplaySize << std::endl;         // Сохраняем размер экрана
    os << Resolution << std::endl;          // Сохраняем разрешение экрана
    os << BatteryCapacity << std::endl;     // Сохраняем емкость батареи
}

// Десериализация данных
void PortableComputer::Deserialize(std::istream& is) {
    // Десериализация данных базового класса (ComputingMachine)
    ComputingMachine::Deserialize(is);

    // Десериализация данных, специфичных для PortableComputer
    is >> DisplaySize;                       // Восстанавливаем размер экрана
    is.ignore();                              // Игнорируем символ новой строки после ввода числа
    std::getline(is, Resolution);             // Восстанавливаем разрешение экрана
    is >> BatteryCapacity;                   // Восстанавливаем емкость батареи
    is.ignore();                              // Игнорируем символ новой строки после ввода числа
}
