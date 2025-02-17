#pragma once
#include "StationaryComputer.h"
class Monoblock : public StationaryComputer {
protected:
    std::string OS; // Операционная система
    int weight;     // Вес

public:
    // Конструктор по умолчанию
    Monoblock();
    
    // Конструктор с параметрами
    Monoblock(double CPUcapacity, double RAM, int DiskSpace, int CPUcores, const std::string& MotherBoardChipset, const std::string& GPU, const std::string& OS, int weight);

    // Конструктор копирования
    Monoblock(const Monoblock& other);

    // Оператор присваивания
    Monoblock& operator=(const Monoblock& other);

    // Деструктор
    ~Monoblock();

    // Геттеры и сеттеры
    std::string GetOS() const;
    void SetOS(const std::string& newOS);

    int GetWeight() const;
    void SetWeight(int newWeight);
    
    // Перегрузка ввода и вывода
    friend std::ostream& operator<<(std::ostream& os, const Monoblock& mb);
    friend std::istream& operator>>(std::istream& is, Monoblock& mb);
    void show();
    void Serialize(std::ostream& os) const;
    void Deserialize(std::istream& is);

};

