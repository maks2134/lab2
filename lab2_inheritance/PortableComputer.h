    #pragma once
    #include "ComputingMachine.h"
    #include <string>
    #include <iostream>

    class PortableComputer : public ComputingMachine {
    protected:
        int DisplaySize;       // Размер дисплея в дюймах
        std::string Resolution; // Разрешение экрана
        int BatteryCapacity;    // Ёмкость батареи в мАч

    public:
        // Конструктор по умолчанию
        PortableComputer();

        // Конструктор с параметрами
        PortableComputer(double CPUcapacity, double RAM, int DiskSpace, int DisplaySize, const std::string& Resolution, int BatteryCapacity);

        // Конструктор копирования
        PortableComputer(const PortableComputer& other);

        // Оператор присваивания
        PortableComputer& operator=(const PortableComputer& other);

        // Деструктор
        ~PortableComputer();

        // Геттеры и сеттеры
        int GetDisplaySize() const;
        void SetDisplaySize(int newDisplaySize);

        std::string GetResolution() const;
        void SetResolution(const std::string& newResolution);

        int GetBatteryCapacity() const;
        void SetBatteryCapacity(int newBatteryCapacity);
        void Serialize(std::ostream& os) const;
        void Deserialize(std::istream& is);
        // Перегрузка ввода и вывода
        friend std::ostream& operator<<(std::ostream& os, PortableComputer& pc);
        friend std::istream& operator>>(std::istream& is, PortableComputer& pc);
        void show();

    };
