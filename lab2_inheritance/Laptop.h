#pragma once
#include "PortableComputer.h"
#include <string>

class Laptop : public PortableComputer {
protected:
    bool Keyboardlight;   // Подсветка клавиатуры
    bool Microphone;      // Наличие микрофона
    std::string ScreenType; // Тип экрана (например, "IPS", "OLED")

public:
    // Конструктор по умолчанию
    Laptop();

    // Конструктор с параметрами
    Laptop(double CPUcapacity, double RAM, int DiskSpace, double ScreenSize, const std::string& Resolution, int BatteryCapacity, bool Keyboardlight, bool Microphone, const std::string& ScreenType);

    // Конструктор копирования
    Laptop(const Laptop& other);

    // Оператор присваивания
    Laptop& operator=(const Laptop& other);

    // Деструктор
    ~Laptop();

    // Геттеры и сеттеры
    bool GetKeyboardlight() const;
    void SetKeyboardlight(bool newKeyboardlight);

    bool GetMicrophone() const;
    void SetMicrophone(bool newMicrophone);

    std::string GetScreenType() const;
    void SetScreenType(const std::string& newScreenType);
    friend std::ostream& operator<<(std::ostream& os, Laptop& laptop);
    friend std::istream& operator>>(std::istream& is, Laptop& laptop);
    
    void show ();
    void Serialize(std::ostream& os) const;
    void Deserialize(std::istream& is);
};
