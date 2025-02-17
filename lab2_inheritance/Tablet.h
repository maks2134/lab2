#pragma once
#include "PortableComputer.h"
#include <iostream>
#include <string>

class Tablet : public PortableComputer {
protected:
    bool SIM;          // ��������� SIM-�����
    bool Gyroscope;    // ������� ���������
    int ports;         // ���������� ������

public:
    // ����������� �� ���������
    Tablet();

    // ����������� � �����������
    Tablet(double CPUcapacity, double RAM, int DiskSpace, double DisplaySize, const std::string& Resolution, int BatteryCapacity,
        bool SIM, bool Gyroscope, int ports);

    // ����������� �����������
    Tablet(const Tablet& other);

    // �������� ������������
    Tablet& operator=(const Tablet& other);

    // ����������
    ~Tablet();

    // ������� � �������
    bool GetSIM() const;
    void SetSIM(bool newSIM);

    bool GetGyroscope() const;
    void SetGyroscope(bool newGyroscope);

    int GetPorts() const;
    void SetPorts(int newPorts);

    // ���������� ����� � ������
    friend std::ostream& operator<<(std::ostream& os, Tablet& tablet);
    friend std::istream& operator>>(std::istream& is, Tablet& tablet); 
    void show();
    void Serialize(std::ostream& os) const;
    void Deserialize(std::istream& is);
};
