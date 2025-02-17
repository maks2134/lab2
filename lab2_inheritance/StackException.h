#pragma once
#include <stdexcept>
#include <string>
#include "ExceptionBase.h"
class StackException : public ExceptionBase {
public:
    explicit StackException(const std::string& msg);
    void handleEmptyStack(const std::string& msg);
    void handleStackOverflow(const std::string& msg);
    static void handleElementNotFound(const std::string& msg);
    static void validateStackOverflow(size_t stackSize, size_t maxSize);
   static  void validateEmptyStack(bool isEmpty);
    void validateElementNotFound(bool elementNotFound);
};