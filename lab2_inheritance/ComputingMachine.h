#pragma once
#include<iostream>
class ComputingMachine {
protected:
    double CPUcapacity;
    double RAM;
    int DiskSpace;

public:
    ComputingMachine();  
    ComputingMachine(double CPUcapacity, double RAM, int DiskSpace);  
    ComputingMachine(const ComputingMachine& other);  
    ComputingMachine& operator=(const ComputingMachine& other);  
    ~ComputingMachine();  
     int GetDiskSpace() const;  
    void SetDiskSpace(int newDiskSpace);
    double GetCPUcapacity() const;  
    void SetCPUcapacity(double newCPUcapacity); 
    double GetRAM() const;  
    void SetRAM(double newRAM); 
    friend std::ostream& operator<<(std::ostream& os, ComputingMachine& cm);
    friend std::istream& operator>>(std::istream& is, ComputingMachine& cm);
     void show() ;
     void Serialize(std::ostream& os) const;
     void Deserialize(std::istream& is) ;

};

