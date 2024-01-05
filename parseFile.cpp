//
// Created by Gyula108 on 1/4/2024.
//

#include "parseFile.h"
#include "data.h"

#include <algorithm>
#include <format>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace utils {
    parseFile::parseFile(const std::string& fileName) {
        this->fileName = fileName;
    }

    std::string parseFile::getFileContent() {
        return this->fileContent;
    }

    std::list<expense> parseFile::getExpenses() {
        // Clear all data to be safe
        this->fileContent = "";
        this->lines.clear();
        this->expenses.clear();

        this->readFileContent();
        this->parseFileContent();
        return this->expenses;

    }

    void parseFile::setExpenses(const std::list<expense> &expenses) {
        this->expenses = expenses;
    }

    std::string parseFile::getFileName() {
        return this->fileName;
    }

    void parseFile::readFileContent() {
        std::ifstream file(this->fileName);
        for (std::string line; std::getline(file, line);) {
            this->lines.push_back(line);
        }
        file.close();
    }

    void parseFile::parseFileContent() {
        std::ranges::for_each(this->lines.begin(), this->lines.end(), [this](const std::string& n) {
            std::string expenseData[6];

            std::istringstream lineToParse;
            lineToParse.str(n);

            int i = 0;
            for (std::string part; std::getline(lineToParse, part ,';');) {
                expenseData[i] = part;
                i++;
            }

            expense newExpense;
            newExpense.id = std::stoi(expenseData[0]);
            newExpense.date = expenseData[1];
            newExpense.type = static_cast<expenseType>(std::stoi(expenseData[2]));
            newExpense.category = static_cast<expenseCategory>(std::stoi(expenseData[3]));
            newExpense.amount = std::stoi(expenseData[4]);
            newExpense.comment = expenseData[5];
            this->expenses.push_back(newExpense);
        });

    }

    void parseFile::appendToFile() const {
        std::ofstream outfile;
        outfile.open(this->fileName,std::ios_base::app);
        for (const std::string& data: convertData(this->expenses)) {
            outfile << data;
        }
        outfile.close();
    }

    void parseFile::clearFile() const {
        std::ofstream outfile;
        outfile.open(this->fileName, std::ofstream::out | std::ofstream::trunc);
        outfile.close();
    }

    std::list<std::string> parseFile::convertData(const std::list<expense>& expenses) {
        std::list<std::string> convertedString;
        std::ranges::for_each(expenses.begin(), expenses.end(), [&convertedString](expense n) {
            convertedString.push_front(
                std::format("{};{};{};{};{};{}\n",
                    n.id,
                    n.date,
                    n.type,
                    n.category,
                    n.amount,
                    n.comment
                    ));
        });
        return convertedString;
    }
}
