#pragma once
#include <stdexcept>
#include <string>
#include "ExceptionBase.h"
#include <stdexcept>
#include <string>
#include <fstream> 
#include <iostream>
class FileException : public ExceptionBase {
public:
    explicit FileException(const std::string& msg);
    static std::ofstream openFileForWriting(const std::string& filename);
    static std::ifstream openFileForReading(const std::string& filename);
    static void writeToFile(const std::string& filename, const std::string& data);
    static std::string readFromFile(const std::string& filename);
};