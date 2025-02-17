#include "ComputingMachine.h"
#include "InputException.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

// Конструктор по умолчанию
ComputingMachine::ComputingMachine() : CPUcapacity(0), RAM(0), DiskSpace(0) {}

// Конструктор с параметрами
ComputingMachine::ComputingMachine(double CPUcapacity, double RAM, int DiskSpace) {
    // Валидация входных данных через InputException
    InputException::validateCPUValue(CPUcapacity);
    InputException::validateRAMValue(RAM);
    InputException::validateDiskSpaceValue(DiskSpace);

    this->CPUcapacity = CPUcapacity;
    this->RAM = RAM;
    this->DiskSpace = DiskSpace;
}

// Конструктор копирования
ComputingMachine::ComputingMachine(const ComputingMachine& other) {
    this->CPUcapacity = other.CPUcapacity;
    this->RAM = other.RAM;
    this->DiskSpace = other.DiskSpace;
}

// Оператор присваивания
ComputingMachine& ComputingMachine::operator=(const ComputingMachine& other) {
    if (this == &other) {
        return *this;
    }

    this->CPUcapacity = other.CPUcapacity;
    this->RAM = other.RAM;
    this->DiskSpace = other.DiskSpace;

    return *this;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, ComputingMachine& cm) {
    const int colWidth = 15; // Ширина заголовка
    const int valueWidth = 8; // Ширина значения

    os
        << std::right << std::setw(valueWidth) << cm.CPUcapacity << " GHz "
        << std::right << std::setw(valueWidth) << cm.RAM << " GB "
        << std::right << std::setw(valueWidth) << cm.DiskSpace << " GB";

    return os;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& is, ComputingMachine& cm) {
    double cpu;
    double ram;
    int disk;

    while (true) {
        try {
            std::cout << "Enter CPU capacity (GHz): ";
            is >> cpu;
            if (is.fail()) throw InputException("Invalid input for CPU capacity. Expected a number.");

            InputException::validateCPUValue(cpu); // Проверка валидности значения
            break; // Если ввод корректный, выходим из цикла
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            is.clear(); // Очищаем поток
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Удаляем некорректные данные
        }
    }

    while (true) {
        try {
            std::cout << "Enter RAM size (GB): ";
            is >> ram;
            if (is.fail()) throw InputException("Invalid input for RAM size. Expected a number.");

            InputException::validateRAMValue(ram); // Проверка валидности значения
            break; // Если ввод корректный, выходим из цикла
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            is.clear(); // Очищаем поток
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Удаляем некорректные данные
        }
    }

    while (true) {
        try {
            std::cout << "Enter Disk Space (GB): ";
            is >> disk;
            if (is.fail()) throw InputException("Invalid input for Disk Space. Expected an integer.");

            InputException::validateDiskSpaceValue(disk); // Проверка валидности значения
            break; // Если ввод корректный, выходим из цикла
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            is.clear(); // Очищаем поток
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Удаляем некорректные данные
        }
    }

    cm.CPUcapacity = cpu;
    cm.RAM = ram;
    cm.DiskSpace = disk;

    return is;
}



// Геттер для DiskSpace
int ComputingMachine::GetDiskSpace() const {
    return DiskSpace;
}

// Сеттер для DiskSpace с валидацией
void ComputingMachine::SetDiskSpace(int newDiskSpace) {
    InputException::validateDiskSpaceValue(newDiskSpace); // Валидация
    DiskSpace = newDiskSpace;
}

// Геттер для CPUcapacity
double ComputingMachine::GetCPUcapacity() const {
    return CPUcapacity;
}

// Сеттер для CPUcapacity с валидацией
void ComputingMachine::SetCPUcapacity(double newCPUcapacity) {
    InputException::validateCPUValue(newCPUcapacity); // Валидация
    CPUcapacity = newCPUcapacity;
}

// Геттер для RAM
double ComputingMachine::GetRAM() const {
    return RAM;
}

// Сеттер для RAM с валидацией
void ComputingMachine::SetRAM(double newRAM) {
    InputException::validateRAMValue(newRAM); // Валидация
    RAM = newRAM;
}

// Деструктор
ComputingMachine::~ComputingMachine() {}

// Метод show для отображения данных в таблице
void ComputingMachine::show() {
    const std::string title = "ComputingMachine";
    const int tableWidth = 40; // Общая ширина таблицы
    const int titlePadding = (tableWidth - title.size()) / 2; // Вычисление отступа

    // Вывод заголовка по центру
    std::cout << std::string(titlePadding, ' ') << title << std::endl;
    std::cout << std::string(tableWidth, '-') << std::endl;

    // Заголовки таблицы
    std::cout << std::left
        << std::setw(15) << "CPU Capacity"
        << std::setw(10) << "RAM"
        << std::setw(15) << "Disk Space"
        << std::endl;

    // Данные
    std::cout << std::right
        << std::setw(15) << CPUcapacity << " GHz"
        << std::setw(10) << RAM << " GB"
        << std::setw(15) << DiskSpace << " GB"
        << std::endl;
}

// Метод для сериализации объекта
void ComputingMachine::Serialize(std::ostream& os) const {
    os << CPUcapacity << std::endl;  // Сохраняем частоту процессора
    os << RAM << std::endl;          // Сохраняем объем ОЗУ
    os << DiskSpace << std::endl;    // Сохраняем пространство на диске
}

// Метод для десериализации объекта
void ComputingMachine::Deserialize(std::istream& is) {
    double cpu;
    double ram;
    int disk;

    is >> cpu >> ram >> disk;

    // Валидация входных данных через InputException
    InputException::validateCPUValue(cpu);
    InputException::validateRAMValue(ram);
    InputException::validateDiskSpaceValue(disk);

    CPUcapacity = cpu;
    RAM = ram;
    DiskSpace = disk;
}
