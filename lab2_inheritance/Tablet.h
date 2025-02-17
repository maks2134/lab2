#pragma once
#include "PortableComputer.h"
#include <iostream>
#include <string>

class Tablet : public PortableComputer {
protected:
    bool SIM;          // Поддержка SIM-карты
    bool Gyroscope;    // Наличие гироскопа
    int ports;         // Количество портов

public:
    // Конструктор по умолчанию
    Tablet();

    // Конструктор с параметрами
    Tablet(double CPUcapacity, double RAM, int DiskSpace, double DisplaySize, const std::string& Resolution, int BatteryCapacity,
        bool SIM, bool Gyroscope, int ports);

    // Конструктор копирования
    Tablet(const Tablet& other);

    // Оператор присваивания
    Tablet& operator=(const Tablet& other);

    // Деструктор
    ~Tablet();

    // Геттеры и сеттеры
    bool GetSIM() const;
    void SetSIM(bool newSIM);

    bool GetGyroscope() const;
    void SetGyroscope(bool newGyroscope);

    int GetPorts() const;
    void SetPorts(int newPorts);

    // Перегрузка ввода и вывода
    friend std::ostream& operator<<(std::ostream& os, Tablet& tablet);
    friend std::istream& operator>>(std::istream& is, Tablet& tablet); 
    void show();
    void Serialize(std::ostream& os) const;
    void Deserialize(std::istream& is);
};
