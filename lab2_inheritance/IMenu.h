#pragma once
#include <iostream>
#include <string>

class IMenu {
public:
    virtual ~IMenu() = default;
    virtual void printMenu() const = 0;
    virtual void handleMenu() = 0;
};