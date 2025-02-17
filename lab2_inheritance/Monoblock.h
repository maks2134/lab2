#pragma once
#include "StationaryComputer.h"
class Monoblock : public StationaryComputer {
protected:
    std::string OS; // ������������ �������
    int weight;     // ���

public:
    // ����������� �� ���������
    Monoblock();
    
    // ����������� � �����������
    Monoblock(double CPUcapacity, double RAM, int DiskSpace, int CPUcores, const std::string& MotherBoardChipset, const std::string& GPU, const std::string& OS, int weight);

    // ����������� �����������
    Monoblock(const Monoblock& other);

    // �������� ������������
    Monoblock& operator=(const Monoblock& other);

    // ����������
    ~Monoblock();

    // ������� � �������
    std::string GetOS() const;
    void SetOS(const std::string& newOS);

    int GetWeight() const;
    void SetWeight(int newWeight);
    
    // ���������� ����� � ������
    friend std::ostream& operator<<(std::ostream& os, const Monoblock& mb);
    friend std::istream& operator>>(std::istream& is, Monoblock& mb);
    void show();
    void Serialize(std::ostream& os) const;
    void Deserialize(std::istream& is);

};

