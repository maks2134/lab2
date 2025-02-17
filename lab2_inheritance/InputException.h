#pragma once
#include "ExceptionBase.h"
class InputException : public ExceptionBase
{
public:
    explicit InputException(const std::string& msg);
   
    static void validateCPUValue(double cpuValue);
    static void validateRAMValue(double ramValue);
    static void validateDiskSpaceValue(int diskSpace);
    static void validateStringInput(const std::string& value, const std::string& fieldName);
    static void validateOS(const std::string& os);
    static void validateGPU(const std::string& gpu);
    static void validateCPUBrand(const std::string& cpuBrand);
    static void validateCPUcores(int cpuCores);
    static void validateMotherboardChipset(const std::string& chipset);
   static void validateBatteryCapacity(int batteryCapacity);
    static void validateResolution(const std::string& resolution);
    static void validateScreenType(const std::string& screenType);
};

