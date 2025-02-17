#include "Tablet.h"
#include "PortableComputer.h"
#include<iomanip>
#include "InputException.h"
// Конструктор по умолчанию
Tablet::Tablet() : SIM(false), Gyroscope(false), ports(0) {}

// Конструктор с параметрами
Tablet::Tablet(double CPUcapacity, double RAM, int DiskSpace, double DisplaySize, const std::string& Resolution, int BatteryCapacity,
    bool SIM, bool Gyroscope, int ports)
    : PortableComputer(CPUcapacity, RAM, DiskSpace, DisplaySize, Resolution, BatteryCapacity),
    SIM(SIM), Gyroscope(Gyroscope), ports(ports) {}

// Конструктор копирования
Tablet::Tablet(const Tablet& other)
    : PortableComputer(other), SIM(other.SIM), Gyroscope(other.Gyroscope), ports(other.ports) {}

// Оператор присваивания
Tablet& Tablet::operator=(const Tablet& other) {
    if (this != &other) {
        PortableComputer::operator=(other); // Присваиваем данные базового класса
        SIM = other.SIM;
        Gyroscope = other.Gyroscope;
        ports = other.ports;
    }
    return *this;
}

// Деструктор
Tablet::~Tablet() {}

// Геттеры и сеттеры
bool Tablet::GetSIM() const {
    return SIM;
}

void Tablet::SetSIM(bool newSIM) {
    SIM = newSIM;
}

bool Tablet::GetGyroscope() const {
    return Gyroscope;
}

void Tablet::SetGyroscope(bool newGyroscope) {
    Gyroscope = newGyroscope;
}

int Tablet::GetPorts() const {
    return ports;
}

void Tablet::SetPorts(int newPorts) {
    ports = newPorts;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, Tablet& tablet) {
    // Output the PortableComputer (base class) characteristics
    os << std::setw(15) << tablet.GetCPUcapacity() << " GHz "
        << std::setw(10) << tablet.GetRAM() << " GB "
        << std::setw(15) << tablet.GetDiskSpace() << " GB "
        << std::setw(15) << tablet.GetDisplaySize() << " inches "
        << std::setw(15) << tablet.GetResolution()
        << std::setw(18) << tablet.GetBatteryCapacity() << " mAh "

        // Output the Tablet specific characteristics
        << std::setw(12) << (tablet.GetSIM() ? "Yes" : "No")  // SIM support
        << std::setw(12) << (tablet.GetGyroscope() ? "Yes" : "No")  // Gyroscope presence
        << std::setw(12) << tablet.GetPorts()  // Number of ports
        << std::endl;

    return os;
}


// Перегрузка оператора ввода
std::istream& operator>>(std::istream& is, Tablet& tablet) {
    // Ввод данных базового класса PortableComputer
    is >> static_cast<PortableComputer&>(tablet);

    // Обработка ввода для SIM Support
    while (true) {
        try {
            std::cout << "SIM Support (1 - Yes, 0 - No): ";
            int simInput;
            if (!(is >> simInput)) {
                throw InputException("Invalid input for SIM Support. Expected 1 or 0.");
            }
            if (simInput != 0 && simInput != 1) {
                throw InputException("SIM Support must be 1 (Yes) or 0 (No).");
            }
            tablet.SetSIM(simInput == 1); // Устанавливаем значение
            break; // Выходим из цикла, если ввод корректный
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
            is.clear(); // Сбрасываем состояние потока
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
        }
    }

    // Обработка ввода для Gyroscope
    while (true) {
        try {
            std::cout << "Gyroscope (1 - Yes, 0 - No): ";
            int gyroInput;
            if (!(is >> gyroInput)) {
                throw InputException("Invalid input for Gyroscope. Expected 1 or 0.");
            }
            if (gyroInput != 0 && gyroInput != 1) {
                throw InputException("Gyroscope must be 1 (Yes) or 0 (No).");
            }
            tablet.SetGyroscope(gyroInput == 1); // Устанавливаем значение
            break; // Выходим из цикла, если ввод корректный
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
            is.clear(); // Сбрасываем состояние потока
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
        }
    }

    // Обработка ввода для Number of Ports
    while (true) {
        try {
            std::cout << "Number of Ports: ";
            int portsInput;
            if (!(is >> portsInput)) {
                throw InputException("Invalid input for Number of Ports. Expected a non-negative number.");
            }
            if (portsInput < 0) {
                throw InputException("Number of Ports cannot be negative.");
            }
            tablet.SetPorts(portsInput); // Устанавливаем значение
            break; // Выходим из цикла, если ввод корректный
        }
        catch (const InputException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
            is.clear(); // Сбрасываем состояние потока
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
        }
    }

    return is;
}

void Tablet::show() {
    const std::string title = "Tablet";
    const int tableWidth = 120;  // Total width of the table (increased for more characteristics)
    const int titlePadding = (tableWidth - title.size()) / 2;  // Calculate padding for centering title

    // Display title centered
    std::cout << std::string(titlePadding, ' ') << title << std::endl;
    std::cout << std::string(tableWidth, '-') << std::endl;

    // Display the header row for the tablet's characteristics
    std::cout << std::left
        << std::setw(15) << "Display Size"
        << std::setw(15) << "Resolution"
        << std::setw(18) << "Battery Capacity"
        << std::setw(15) << "SIM Support"
        << std::setw(15) << "Gyroscope"
        << std::setw(12) << "Ports"
        << std::setw(15) << "CPU Capacity"  // Adding CPU Capacity
        << std::setw(10) << "RAM"  // Adding RAM
        << std::setw(12) << "Disk Space"  // Adding Disk Space
        << std::endl;
}

void Tablet::Serialize(std::ostream& os) const {
    // Сериализация данных базового класса (PortableComputer)
    PortableComputer::Serialize(os);

    // Сериализация данных, специфичных для Tablet
    os << SIM << std::endl;           // Сохраняем SIM поддержку
    os << Gyroscope << std::endl;     // Сохраняем наличие гироскопа
    os << ports << std::endl;         // Сохраняем количество портов
}
void Tablet::Deserialize(std::istream& is) {
    std::string separator;
    std::getline(is, separator);
    PortableComputer::Deserialize(is);

    
    int simInt, gyroscopeInt;

    is >> simInt >> gyroscopeInt >> ports;

   
    SIM = (simInt == 1);
    Gyroscope = (gyroscopeInt == 1);
}


