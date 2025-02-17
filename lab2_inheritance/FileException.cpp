#include "FileException.h"
FileException::FileException(const std::string& msg)
    : ExceptionBase("File Error: " + msg) {}
// Открытие файла для записи с валидацией
std::ofstream FileException::openFileForWriting(const std::string& filename) {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        throw FileException("Error opening file for writing: " + filename);
    }

    return outFile;
}

// Открытие файла для чтения с валидацией
std::ifstream FileException::openFileForReading(const std::string& filename) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        throw FileException("Error opening file for reading: " + filename);
    }

    return inFile;
}

// Запись данных в файл с валидацией
void FileException::writeToFile(const std::string& filename, const std::string& data) {
    try {
        std::ofstream outFile = openFileForWriting(filename);  // Открытие файла для записи

        outFile << data;

        if (outFile.fail()) {  // Проверяем, была ли ошибка при записи
            throw FileException("Error writing to file: " + filename);
        }

        outFile.close();
    }
    catch (const FileException& e) {
        std::cerr << e.what() << std::endl;
        throw;  // Прокидываем исключение дальше, если возникла ошибка
    }
}

// Чтение данных из файла с валидацией
std::string FileException::readFromFile(const std::string& filename) {
    std::string data;

    try {
        std::ifstream inFile = openFileForReading(filename);  // Открытие файла для чтения

        std::getline(inFile, data, '\0');  // Чтение всего файла в одну строку

        if (inFile.fail() && !inFile.eof()) {  // Проверяем, была ли ошибка при чтении
            throw FileException("Error reading from file: " + filename);
        }

        inFile.close();
    }
    catch (const FileException& e) {
        std::cerr << e.what() << std::endl;
        throw;  // Прокидываем исключение дальше, если возникла ошибка
    }

    return data;
}