#include "StationaryComputer.h"
#include "ComputingMachine.h"
#include<iomanip>
#include "InputException.h"
StationaryComputer::StationaryComputer()
    : ComputingMachine(), CPUcores(0), MotherBoardChipset(""), GPU("") {}
StationaryComputer::StationaryComputer(double CPUcapacity, double RAM, int DiskSpace, int CPUcores, const std::string& MotherBoardChipset, const std::string& GPU)
    : ComputingMachine(CPUcapacity, RAM, DiskSpace), CPUcores(CPUcores), MotherBoardChipset(MotherBoardChipset), GPU(GPU) {}

StationaryComputer::StationaryComputer(const ComputingMachine& other)
    : ComputingMachine(other), CPUcores(0), MotherBoardChipset(""), GPU("") {}
StationaryComputer& StationaryComputer::operator=(const StationaryComputer& other) {
    if (this == &other) {
        return *this;  
    }
    ComputingMachine::operator=(other);
    CPUcores = other.CPUcores;
    MotherBoardChipset = other.MotherBoardChipset;
    GPU = other.GPU;

    return *this;
}
// Геттеры
int StationaryComputer::GetCPUcores() const {
    return CPUcores;
}

void StationaryComputer::SetCPUcores(int newCPUcores) {
    CPUcores = newCPUcores;
}

std::string StationaryComputer::GetMotherBoardChipset() const {
    return MotherBoardChipset;
}

void StationaryComputer::SetMotherBoardChipset(const std::string& newChipset) {
    MotherBoardChipset = newChipset;
}

std::string StationaryComputer::GetGPU() const {
    return GPU;
}

void StationaryComputer::SetGPU(const std::string& newGPU) {
    GPU = newGPU;
}
std::ostream& operator<<(std::ostream& os, StationaryComputer sc) {
    os << std::setw(15) << sc.GetCPUcapacity() << " GHz "
        << std::setw(10) << sc.GetRAM() << " GB "
        << std::setw(15) << sc.GetDiskSpace() << " GB "
        << std::setw(10) << sc.GetCPUcores() << " cores "
        << std::setw(20) << sc.GetMotherBoardChipset()
        << std::setw(15) << sc.GetGPU()
        << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, StationaryComputer& sc) {
    double cpuCapacity, ram;
    int diskSpace, cpuCores;
    std::string motherboardChipset, gpu;

    // Ввод базовых параметров через базовый класс ComputingMachine
    is >> static_cast<ComputingMachine&>(sc);

    // Ввод количества ядер процессора
    while (true) {
        try {
            std::cout << "Enter Number of CPU Cores: ";
            is >> cpuCores;
            if (is.fail()) throw InputException("Invalid input for Number of CPU Cores. Expected an integer.");
            InputException::validateCPUcores(cpuCores); // Проверка валидности значения
            sc.SetCPUcores(cpuCores);
            break; // Выход из цикла, если ввод корректный
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            is.clear(); // Очищаем поток
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Удаляем некорректные данные
        }
    }

    // Ввод чипсета материнской платы
    while (true) {
        try {
            std::cout << "Enter Motherboard Chipset: ";
            is >> motherboardChipset;
            InputException::validateMotherboardChipset(motherboardChipset); // Проверка значения
            sc.SetMotherBoardChipset(motherboardChipset);
            break; // Если ввод корректный, выходим из цикла
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Ввод GPU
    while (true) {
        try {
            std::cout << "Enter GPU (manufacturer): ";
            is >> gpu;
            if (is.fail() || gpu.empty())
                throw InputException("Invalid input for GPU. Expected a non-empty string.");
            sc.SetGPU(gpu);
            break; // Выход из цикла, если ввод корректный
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return is;
}

StationaryComputer::~StationaryComputer() {
   
}
void StationaryComputer::show() {
    const std::string title = "StationaryComputer";
    const int tableWidth = 80;  // Total width of the table
    const int titlePadding = (tableWidth - title.size()) / 2;  // Calculate padding for centering title

    // Display title centered
    std::cout << std::string(titlePadding, ' ') << title << std::endl;
    std::cout << std::string(tableWidth, '-') << std::endl;

    // Display header row for the entire StationaryComputer (including ComputingMachine)
    std::cout << std::left
        << std::setw(15) << "CPU Capacity"
        << std::setw(10) << "RAM"
        << std::setw(15) << "Disk Space"
        << std::setw(10) << "CPU Cores"
        << std::setw(20) << "MotherBoard Chipset"
        << std::setw(15) << "GPU"
        << std::endl;
}
void StationaryComputer::Serialize(std::ostream& os) const {
    // Сериализация данных базового класса (ComputingMachine)
    ComputingMachine::Serialize(os);

    // Сериализация данных, специфичных для StationaryComputer
    os << CPUcores << std::endl;           // Сохраняем количество ядер процессора
    os << MotherBoardChipset << std::endl;  // Сохраняем чипсет материнской платы
    os << GPU << std::endl;                 // Сохраняем информацию о GPU
}
void StationaryComputer::Deserialize(std::istream& is) {
 
    ComputingMachine::Deserialize(is);
    is >> CPUcores;                       // Восстанавливаем количество ядер процессора
    is.ignore();                           // Игнорируем символ новой строки после ввода числа
    std::getline(is, MotherBoardChipset);   // Восстанавливаем чипсет материнской платы
    std::getline(is, GPU);                 // Восстанавливаем GPU
}
