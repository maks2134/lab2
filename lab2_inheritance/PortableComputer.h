    #pragma once
    #include "ComputingMachine.h"
    #include <string>
    #include <iostream>

    class PortableComputer : public ComputingMachine {
    protected:
        int DisplaySize;       // ������ ������� � ������
        std::string Resolution; // ���������� ������
        int BatteryCapacity;    // ������� ������� � ���

    public:
        // ����������� �� ���������
        PortableComputer();

        // ����������� � �����������
        PortableComputer(double CPUcapacity, double RAM, int DiskSpace, int DisplaySize, const std::string& Resolution, int BatteryCapacity);

        // ����������� �����������
        PortableComputer(const PortableComputer& other);

        // �������� ������������
        PortableComputer& operator=(const PortableComputer& other);

        // ����������
        ~PortableComputer();

        // ������� � �������
        int GetDisplaySize() const;
        void SetDisplaySize(int newDisplaySize);

        std::string GetResolution() const;
        void SetResolution(const std::string& newResolution);

        int GetBatteryCapacity() const;
        void SetBatteryCapacity(int newBatteryCapacity);
        void Serialize(std::ostream& os) const;
        void Deserialize(std::istream& is);
        // ���������� ����� � ������
        friend std::ostream& operator<<(std::ostream& os, PortableComputer& pc);
        friend std::istream& operator>>(std::istream& is, PortableComputer& pc);
        void show();

    };
