//
// Created by Gyula108 on 1/4/2024.
//

#ifndef PARSEFILE_H
#define PARSEFILE_H
#include <list>
#include <string>
#include "data.h"

namespace utils {

class parseFile {
public:
    explicit parseFile(const std::string& fileName);
    [[nodiscard]] std::string getFileName();
    [[nodiscard]] std::string getFileContent();
    std::list<expense> getExpenses();
    void setExpenses(const std::list<expense>& expenses);

    void appendToFile() const;
    void clearFile() const;

private:
    std::string fileName;
    std::string fileContent;
    std::list<std::string> lines;
    std::list<expense> expenses;

    void readFileContent();
    void parseFileContent();
    static std::list<std::string> convertData(const std::list<expense>& expenses);
};

}

#endif //PARSEFILE_H
