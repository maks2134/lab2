#include "Monoblock.h"
#include "StationaryComputer.h"
#include <iomanip>
#include <iostream>
#include <limits>
#include "InputException.h"
// Конструктор по умолчанию
Monoblock::Monoblock()
    : StationaryComputer(), OS(""), weight(0) {}

// Конструктор с параметрами
Monoblock::Monoblock(double CPUcapacity, double RAM, int DiskSpace, int CPUcores, const std::string& MotherBoardChipset, const std::string& GPU, const std::string& OS, int weight)
    : StationaryComputer(CPUcapacity, RAM, DiskSpace, CPUcores, MotherBoardChipset, GPU), OS(OS), weight(weight) {
    // Валидация данных
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

// Конструктор копирования
Monoblock::Monoblock(const Monoblock& other)
    : StationaryComputer(other), OS(other.OS), weight(other.weight) {}

// Оператор присваивания
Monoblock& Monoblock::operator=(const Monoblock& other) {
    if (this == &other) {
        return *this; // Защита от самоприсваивания
    }

    StationaryComputer::operator=(other); // Присваивание базового класса
    OS = other.OS;
    weight = other.weight;

    return *this;
}

// Деструктор
Monoblock::~Monoblock() {
    // Освобождение ресурсов, если это необходимо
}

// Геттер для OS
std::string Monoblock::GetOS() const {
    return OS;
}

// Сеттер для OS с валидацией
void Monoblock::SetOS(const std::string& newOS) {
    if (newOS.empty()) {
        std::cerr << "Error: Operating System cannot be empty." << std::endl;
        return;
    }
    OS = newOS;
}

// Геттер для weight
int Monoblock::GetWeight() const {
    return weight;
}

// Сеттер для weight с валидацией
void Monoblock::SetWeight(int newWeight) {
    if (newWeight <= 0) {
        std::cerr << "Error: Weight must be positive." << std::endl;
        return;
    }
    weight = newWeight;
}

// Перегрузка вывода
std::ostream& operator<<(std::ostream& os, const Monoblock& mb) {
    const int valueWidth = 8; // Ширина значения
    const int colWidth = 15;
    os << std::right << std::setw(valueWidth) << mb.CPUcapacity << " GHz "
        << std::right << std::setw(valueWidth) << mb.RAM << " GB "
        << std::right << std::setw(valueWidth) << mb.DiskSpace << " GB "
        << std::right << std::setw(valueWidth) << mb.OS << " "
        << std::right << std::setw(valueWidth) << mb.weight << " kg";

    return os;
}

// Перегрузка ввода с валидацией
std::istream& operator>>(std::istream& is, Monoblock& mb) {
    // Ввод данных базового класса
    is >> static_cast<StationaryComputer&>(mb);

    // Ввод операционной системы с проверкой
    while (true) {
        try {
            std::cout << "Enter Operating System: ";
            std::getline(is >> std::ws, mb.OS); // Считываем строку с учётом возможных пробелов

            if (mb.OS.empty()) {
                throw InputException("Operating System cannot be empty. Please enter a valid value.");
            }

            
            break;
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            // Поток очищать не нужно, так как `std::getline` не выставляет флаг ошибки
        }
    }

    // Ввод веса с проверкой
    while (true) {
        try {
            std::cout << "Enter Weight (kg): ";
            is >> mb.weight;

            if (is.fail() || mb.weight <= 0) {
                throw InputException("Weight must be a positive number. Please enter a valid value.");
            }

            break; // Выходим из цикла, если ввод корректный
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            is.clear(); // Сбрасываем состояние потока
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
        }
    }

    return is;
}


void Monoblock::show() {
    const std::string title = "Monoblock";
    const int tableWidth = 80; // Общая ширина таблицы
    const int titlePadding = (tableWidth - title.size()) / 2; // Вычисление отступа

    // Вывод заголовка по центру
    std::cout << std::string(titlePadding, ' ') << title << std::endl;
    std::cout << std::string(tableWidth, '-') << std::endl;

    // Заголовки таблицы
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
    // Сериализация данных базового класса (StationaryComputer)
    StationaryComputer::Serialize(os);

    // Сериализация данных специфичных для Monoblock
    os << OS << std::endl; // Сохраняем операционную систему
    os << weight << std::endl; // Сохраняем вес
}

void Monoblock::Deserialize(std::istream& is) {
    std::string separator;
    std::getline(is, separator);
    StationaryComputer::Deserialize(is);
    // Десериализация данных специфичных для Monoblock
    std::getline(is, OS); // Восстанавливаем операционную систему
    is >> weight; // Восстанавливаем вес

    // Пропускаем символ новой строки после ввода веса
    is.ignore();
}
