#pragma once
#include "IMenu.h"

class IDequeMenu : public IMenu {
public:
    virtual void addElementToFront() = 0;
    virtual void addElementToBack() = 0;
    virtual void removeElementFromFront() = 0;
    virtual void removeElementFromBack() = 0;
    virtual void showAllElements() = 0;
    virtual void sortElements() = 0;
    virtual void insertElementAtPosition() = 0;
    virtual void showFirstElement() = 0;
    virtual void showLastElement() = 0;
};