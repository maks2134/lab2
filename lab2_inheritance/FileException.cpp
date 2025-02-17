#include "FileException.h"
FileException::FileException(const std::string& msg)
    : ExceptionBase("File Error: " + msg) {}
// �������� ����� ��� ������ � ����������
std::ofstream FileException::openFileForWriting(const std::string& filename) {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        throw FileException("Error opening file for writing: " + filename);
    }

    return outFile;
}

// �������� ����� ��� ������ � ����������
std::ifstream FileException::openFileForReading(const std::string& filename) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        throw FileException("Error opening file for reading: " + filename);
    }

    return inFile;
}

// ������ ������ � ���� � ����������
void FileException::writeToFile(const std::string& filename, const std::string& data) {
    try {
        std::ofstream outFile = openFileForWriting(filename);  // �������� ����� ��� ������

        outFile << data;

        if (outFile.fail()) {  // ���������, ���� �� ������ ��� ������
            throw FileException("Error writing to file: " + filename);
        }

        outFile.close();
    }
    catch (const FileException& e) {
        std::cerr << e.what() << std::endl;
        throw;  // ����������� ���������� ������, ���� �������� ������
    }
}

// ������ ������ �� ����� � ����������
std::string FileException::readFromFile(const std::string& filename) {
    std::string data;

    try {
        std::ifstream inFile = openFileForReading(filename);  // �������� ����� ��� ������

        std::getline(inFile, data, '\0');  // ������ ����� ����� � ���� ������

        if (inFile.fail() && !inFile.eof()) {  // ���������, ���� �� ������ ��� ������
            throw FileException("Error reading from file: " + filename);
        }

        inFile.close();
    }
    catch (const FileException& e) {
        std::cerr << e.what() << std::endl;
        throw;  // ����������� ���������� ������, ���� �������� ������
    }

    return data;
}