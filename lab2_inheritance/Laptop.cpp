#include "Laptop.h"
#include "PortableComputer.h"
#include "ComputingMachine.h"
#include <iomanip>
#include <iostream>
#include <limits>
#include "InputException.h"
// Конструктор по умолчанию
Laptop::Laptop() : Keyboardlight(false), Microphone(false), ScreenType("Unknown") {}

// Конструктор с параметрами
Laptop::Laptop(double CPUcapacity, double RAM, int DiskSpace, double ScreenSize, const std::string& Resolution, int BatteryCapacity,
    bool Keyboardlight, bool Microphone, const std::string& ScreenType)
    : PortableComputer(CPUcapacity, RAM, DiskSpace, ScreenSize, Resolution, BatteryCapacity),
    Keyboardlight(Keyboardlight), Microphone(Microphone), ScreenType(ScreenType) {
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

// Конструктор копирования
Laptop::Laptop(const Laptop& other)
    : PortableComputer(other), Keyboardlight(other.Keyboardlight), Microphone(other.Microphone), ScreenType(other.ScreenType) {}

// Оператор присваивания
Laptop& Laptop::operator=(const Laptop& other) {
    if (this != &other) {
        PortableComputer::operator=(other);  // Присваиваем данные базового класса
        Keyboardlight = other.Keyboardlight;
        Microphone = other.Microphone;
        ScreenType = other.ScreenType;
    }
    return *this;
}

// Деструктор
Laptop::~Laptop() {}

// Геттеры и сеттеры
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

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, Laptop& laptop) {
    const int valueWidth = 8; // Ширина значения
    const int colWidth = 15;
    // Выводим данные базового класса
    os << static_cast<ComputingMachine&>(laptop);

    // Добавляем уникальные поля Laptop
    os << std::right << std::setw(valueWidth) << (laptop.Keyboardlight ? "Yes" : "No") << " "
        << std::right << std::setw(valueWidth) << (laptop.Microphone ? "Yes" : "No") << " "
        << std::right << std::setw(valueWidth) << laptop.ScreenType;

    return os;
}

std::istream& operator>>(std::istream& is, Laptop& laptop) {
    // Ввод данных базового класса
    is >> static_cast<PortableComputer&>(laptop);

    // Ввод Keyboard Light с проверкой
    while (true) {
        try {
            std::cout << "Keyboard Light (1 - Yes, 0 - No): ";
            is >> laptop.Keyboardlight;

            if (is.fail() || (laptop.Keyboardlight != 0 && laptop.Keyboardlight != 1)) {
                throw InputException("Invalid input for Keyboard Light. Please enter 1 for Yes or 0 for No.");
            }
            break; // Если ввод корректный, выходим из цикла
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            is.clear(); // Сбрасываем состояние потока
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
        }
    }

    // Ввод Microphone с проверкой
    while (true) {
        try {
            std::cout << "Microphone (1 - Yes, 0 - No): ";
            is >> laptop.Microphone;

            if (is.fail() || (laptop.Microphone != 0 && laptop.Microphone != 1)) {
                throw InputException("Invalid input for Microphone. Please enter 1 for Yes or 0 for No.");
            }
            break; // Если ввод корректный, выходим из цикла
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Ввод Screen Type с проверкой
    while (true) {
        try {
            std::cout << "Enter Screen Type: ";
            is >> laptop.ScreenType;

            if (is.fail() || laptop.ScreenType.empty()) {
                throw InputException("Screen Type cannot be empty. Please enter a valid value.");
            }

           
            InputException::validateScreenType(laptop.ScreenType); // Проверяем валидность ScreenType
            break; // Если ввод корректный, выходим из цикла
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
        << std::setw(10) << "Keyboard"
        << std::setw(10) << "Mic"
        << std::setw(15) << "Screen Type"
        << std::endl;
    std::cout << std::string(tableWidth, '-') << std::endl;
}

void Laptop::Serialize(std::ostream& os) const {
    // Сначала сериализуем данные базового класса
    PortableComputer::Serialize(os);

    // Затем записываем уникальные поля Laptop
    os << Keyboardlight << " "   // Преобразуем bool в 1/0
        << Microphone << " "      // Преобразуем bool в 1/0
        << ScreenType << std::endl; // Строка
}

void Laptop::Deserialize(std::istream& is) {
    std::string separator;
    std::getline(is, separator);
    PortableComputer::Deserialize(is);

    // Затем считываем уникальные поля Laptop
    is >> Keyboardlight >> Microphone >> ScreenType;
}
