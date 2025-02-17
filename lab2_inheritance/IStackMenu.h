#pragma once
#include "IMenu.h"

class IStackMenu : public IMenu {
public:
    void printMenu() const override;
    virtual void addElement() = 0;
    virtual void removeElement() = 0;
    virtual void showTopElement() = 0;
    virtual void findElementByCPUCapacity() = 0;
    virtual void showStackSize() = 0;
    virtual void iterateThroughStack() = 0;
    virtual void writeToTextFile(const std::string& filename) = 0;
    virtual void writeToBinaryFile(const std::string& filename) = 0;
};