#include "ExceptionBase.h"
ExceptionBase::ExceptionBase(const std::string& msg) : message(msg) {}

const char* ExceptionBase::what() const noexcept {
    return message.c_str();
}
