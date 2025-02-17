#pragma once
#include "ComputingMachine.h"
#include <string>

class StationaryComputer : public ComputingMachine {
protected:
    int CPUcores;
    std::string MotherBoardChipset;
    std::string GPU;

public:
    StationaryComputer();  // ����������� �� ���������
    StationaryComputer(double CPUcapacity, double RAM, int DiskSpace, int CPUcores, const std::string& MotherBoardChipset, const std::string& GPU);
    StationaryComputer(const ComputingMachine& other);  // ���������� �����������
    StationaryComputer& operator=(const StationaryComputer& other);  // �������� ������������
    int GetCPUcores() const;
    void SetCPUcores(int newCPUcores);

    std::string GetMotherBoardChipset() const;
    void SetMotherBoardChipset(const std::string& newChipset);

    std::string GetGPU() const;
    void SetGPU(const std::string& newGPU);

    // ���������� ����� � ������
    friend std::ostream& operator<<(std::ostream& os, StationaryComputer sc);
    friend std::istream& operator>>(std::istream& is, StationaryComputer& sc);
    ~StationaryComputer();  // ����������
    void show();
    void Serialize(std::ostream& os) const;
    void Deserialize(std::istream& is);
    // �������������� ������ ��� ������� � ������ ������ ����� ���� ���������

};
