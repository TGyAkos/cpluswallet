//
// Created by Gyula108 on 1/4/2024.
//

#ifndef PARSEFILE_H
#define PARSEFILE_H
#include <list>
#include <string>
#include "../data/data.h"

namespace utils {

class parseFile {
    std::string fileName;
    std::string fileContent;
    std::list<std::string> lines;
    std::list<data::expense> expenses;

public:
    explicit parseFile(const std::string& fileName);
    [[nodiscard]] std::string getFileName();
    [[nodiscard]] std::string getFileContent();
    [[nodiscard]] std::list<data::expense> getExpenses();
    void setExpenses(const std::list<data::expense>& expenses);

    void appendToFile() const;
    void loadDataToFile(const std::list<data::expense> &expenses) const;
    void clearFile() const;

private:
    void readFileContent();
    void parseFileContent();
    static std::list<std::string> convertData(const std::list<data::expense>& expenses);
};

} // utils

#endif //PARSEFILE_H
