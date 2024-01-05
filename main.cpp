#include <format>
#include <iostream>

#include "parseFile.h"


int main() {
    std::string a = "sdfm;msdf;";
    std::cout << "Hello, World!" << std::endl;
    std::cout << std::format("Hello, {}!", a) << std::endl;
    utils::parseFile parsefile("asd.txt");
    const expense testExpense = {"123", essential, other,2, "test test test"};
    std::list<expense> testExpenses;
    testExpenses.push_back(testExpense);
    parsefile.setExpenses(testExpenses);
    parsefile.appendToFile();
    for (const auto& c: parsefile.getExpenses()) {
        std::cout << c.date;
        std::cout << c.type;
        std::cout << c.category;
        std::cout << c.amount;
        std::cout << c.comment;
    }
    return 0;
}

std::string a() {
    return "Hello, World!";
}
