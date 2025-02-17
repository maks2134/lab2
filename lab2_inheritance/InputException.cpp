#include "InputException.h"
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cctype>
#include <vector>
#include <algorithm>
#include <set>
#include <regex>

// Конструктор для исключений ввода
InputException::InputException(const std::string& msg)
    : ExceptionBase("Input Error: " + msg) {}




// Валидация CPU (с доп. защитой от ошибок ввода)
void InputException::validateCPUValue(double cpuValue) {
    if (std::cin.fail()) {
        throw InputException("Invalid input for CPU capacity. Must be a numeric value.");
    }
    if (cpuValue < 0.1 || cpuValue > 10.0) {
        throw InputException("CPU capacity must be between 0.1 GHz and 10 GHz.");
    }
}

// Валидация RAM (с доп. защитой от ошибок ввода)
void InputException::validateRAMValue(double ramValue) {
    if (std::cin.fail()) {
        throw InputException("Invalid input for RAM size. Must be a numeric value.");
    }
    if (ramValue < 1.0 || ramValue > 512.0) {
        throw InputException("RAM size must be between 1 GB and 512 GB.");
    }
}

// Валидация Disk Space (с доп. защитой от ошибок ввода)
void InputException::validateDiskSpaceValue(int diskSpace) {
    if (std::cin.fail()) {
        throw InputException("Invalid input for Disk Space. Must be a numeric value.");
    }
    if (diskSpace < 5 || diskSpace > 1024) {
        throw InputException("Disk space must be between 5 GB and 1024 GB.");
    }
}

// Валидация строковых данных
void InputException::validateStringInput(const std::string& value, const std::string& fieldName) {
    if (value.empty()) {
        throw InputException(fieldName + " cannot be empty.");
    }
    // Удаление начальных и конечных пробелов
    std::string trimmedValue = value;
    trimmedValue.erase(trimmedValue.find_last_not_of(" \t\n\r\f\v") + 1);
    trimmedValue.erase(0, trimmedValue.find_first_not_of(" \t\n\r\f\v"));

    if (trimmedValue.empty()) {
        throw InputException(fieldName + " cannot consist only of whitespace.");
    }
}

// Валидация операционной системы
void InputException::validateOS(const std::string& os) {
    const std::vector<std::string> validOS = { "Windows", "Linux", "macOS" };
    if (std::find(validOS.begin(), validOS.end(), os) == validOS.end()) {
        throw InputException("Invalid Operating System. Choose from: Windows, Linux, macOS.");
    }
}

// Валидация видеокарты
void InputException::validateGPU(const std::string& gpu) {
    const std::vector<std::string> validGPU = { "NVIDIA", "AMD", "Intel" };
    if (std::find(validGPU.begin(), validGPU.end(), gpu) == validGPU.end()) {
        throw InputException("Invalid GPU. Choose from: NVIDIA, AMD, Intel.");
    }
}

// Валидация бренда процессора
void InputException::validateCPUBrand(const std::string& cpuBrand) {
    const std::vector<std::string> validCPUBrands = { "Intel", "AMD" };
    if (std::find(validCPUBrands.begin(), validCPUBrands.end(), cpuBrand) == validCPUBrands.end()) {
        throw InputException("Invalid CPU Brand. Choose from: Intel, AMD.");
    }
}
 void InputException::validateCPUcores(int cpuCores) {
    if (cpuCores <= 0) {
        throw InputException("Invalid input for CPU cores. The number of CPU cores must be greater than 0.");
    }
    if (cpuCores > 128) {
        throw InputException("Invalid input for CPU cores. The number of CPU cores is too large (max: 128).");
    }
}
 void InputException::validateMotherboardChipset(const std::string& chipset) {
     if (chipset.empty()) {
         throw InputException("Invalid input for Motherboard Chipset. The chipset cannot be empty.");
     }

     if (chipset.length() > 50) {
         throw InputException("Invalid input for Motherboard Chipset. The chipset name is too long (max: 50 characters).");
     }

     // (Опционально) Проверка на допустимые значения чипсета
     static const std::set<std::string> validChipsets = {
         "Z790", "B760", "X670", "B650", "H610", "Z690", "X570", "B550"
     };
     if (validChipsets.find(chipset) == validChipsets.end()) {
         throw InputException("Invalid input for Motherboard Chipset. Unknown chipset value.(Z790, B760, X670, B650, H610, Z690, X570, B550)");
     }
 }
 void InputException::validateBatteryCapacity(int batteryCapacity) {
     if (batteryCapacity <= 0) {
         throw InputException("Battery Capacity must be a positive number.");
     }
     if (batteryCapacity > 100000) { // Предполагаем, что ёмкость батареи не превышает 100 000 мАч
         throw InputException("Battery Capacity is unrealistically high. Please check the value.");
     }
 }
 
 void  InputException::validateResolution(const std::string& resolution) {
     if (resolution.empty()) {
         throw InputException("Resolution cannot be empty.");
     }

     // Проверка формата "ШиринаxВысота" (например, "1920x1080")
     std::regex resolutionPattern(R"(^\d{3,5}x\d{3,5}$)");
     if (!std::regex_match(resolution, resolutionPattern)) {
         throw InputException("Invalid Resolution format. Expected format is WidthxHeight (e.g., 1920x1080).");
     }

     // Разделение строки и проверка допустимых значений ширины и высоты
     size_t xPos = resolution.find('x');
     int width = std::stoi(resolution.substr(0, xPos));
     int height = std::stoi(resolution.substr(xPos + 1));

     if (width <= 0 || height <= 0) {
         throw InputException("Resolution dimensions must be positive numbers.");
     }
     if (width > 10000 || height > 10000) {
         throw InputException("Resolution dimensions are unrealistically high.");
     }
 }
 
  void InputException::validateScreenType(const std::string& screenType) {
     // Список допустимых типов экранов
     const std::vector<std::string> validScreenTypes = { "LCD", "LED", "OLED", "AMOLED", "IPS" };

     // Проверка наличия значения в списке
     if (std::find(validScreenTypes.begin(), validScreenTypes.end(), screenType) == validScreenTypes.end()) {
         throw InputException("Invalid Screen Type. Accepted values are: LCD, LED, OLED, AMOLED, IPS.");
     }
 }