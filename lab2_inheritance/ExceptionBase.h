#pragma once
#include <stdexcept>
#include <string>
class ExceptionBase : public std::exception {
protected:
    std::string message;

public:
    explicit ExceptionBase(const std::string& msg);
    const char* what() const noexcept override;
};