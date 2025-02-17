#pragma once
#include "PortableComputer.h"
#include <string>

class Laptop : public PortableComputer {
protected:
    bool Keyboardlight;   // ��������� ����������
    bool Microphone;      // ������� ���������
    std::string ScreenType; // ��� ������ (��������, "IPS", "OLED")

public:
    // ����������� �� ���������
    Laptop();

    // ����������� � �����������
    Laptop(double CPUcapacity, double RAM, int DiskSpace, double ScreenSize, const std::string& Resolution, int BatteryCapacity, bool Keyboardlight, bool Microphone, const std::string& ScreenType);

    // ����������� �����������
    Laptop(const Laptop& other);

    // �������� ������������
    Laptop& operator=(const Laptop& other);

    // ����������
    ~Laptop();

    // ������� � �������
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
