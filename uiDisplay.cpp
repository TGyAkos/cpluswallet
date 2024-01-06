//
// Created by Gyula108 on 1/6/2024.
//

#include "uiDisplay.h"

#include <format>
#include <iostream>

#include "convert.h"

namespace utils {
    void uiDisplay::displayExpense(const data::expense &expense) {
        std::cout << std::format("id: {}\ndate: {}\ntype: {}\ncategory: {}\namount: {}\ncomment: {}\n",
            expense.id,
            expense.date,
            expense.type,
            expense.category,
            expense.amount,
            expense.comment
            );
    }

    template<typename T>
    T uiDisplay::promptUser() {
        std::cout << "Enter: \n";
        std::string userInput;
        std::cin >> userInput;
        if constexpr (std::is_same_v<T, int>) {
            return convertUserInput(userInput);
        }
        else {
            return validateUserInput(userInput);
        }

    }

    int uiDisplay::convertUserInput(const std::string &str) {
        const int converted = convert::tryConvertToInt(str);
        // INFO This can easly memoryleak, cus this will keep spawning functions, potentially infinitely
        if (converted == NULL) {
            std::cout << "Please try again, not a number\n";
            promptUser<int>();
        }
        return converted;
    }

    std::string uiDisplay::validateUserInput(const std::string &str) {
        if (str.empty()) {
            std::cout << "Please try again, not a string\n";
            // This we want to discard, i think
            promptUser<std::string>();
        }
        return str;
    }

    void uiDisplay::displayTypes() {
        // TODO finish this, pretty obvious
    }

    void uiDisplay::displayCaregories() {
        // TODO finish this, pretty obvious
    }

    void uiDisplay::createNewExpense() {
        data::expense newExpense;
        newExpense.id = 0;
        std::cout << std::format("Provide date\n");
        newExpense.date = promptUser<std::string>();

        // TODO after calling displaycategories, the user should enter an int corresponding to the enum, maybe add 1
        // to the display to be a bit more user friendly
        std::cout << std::format("Provide type\n");
        newExpense.date = promptUser<std::string>();\

        // TODO same here
        std::cout << std::format("Provide category\n");
        newExpense.date = promptUser<std::string>();

        // TODO finish this
        std::cout << std::format("Provide amount?\n");
        newExpense.date = promptUser<std::string>();

        // TODO this is self evident
        std::cout << std::format("Provide comment\n");
        newExpense.date = promptUser<std::string>();
    }

    // TODO finish, it should be based on expense.id, the user should provide that
    void uiDisplay::updateExpense() {
        std::cout << std::format("");
    }

    // TODO finish, almost the same as updateExpense()
    void uiDisplay::deleteExpense() {
        std::cout << std::format("");
    }

    void uiDisplay::displayExpenses() {
        std::cout << "Every expense:\n";
        for (auto const &expense: this->expenseModel.getExpenses()) {
            displayExpense(expense);
        }
    }

    // TODO these may not be completely needed, cus it could be done with template<typename T>
    void uiDisplay::displayExpensesByDate() {
    }

    void uiDisplay::displayExpensesByType() {
    }

    void uiDisplay::displayExpensesByDateAndType() {
    }

    std::string uiDisplay::getUserInput() const {
        return this->userInput;
    }

    expenseWrapper uiDisplay::getExpenseModel() const {
        return this->expenseModel;
    }

    void uiDisplay::setExpenseModel(const expenseWrapper &expenseModel) {
        this->expenseModel = expenseModel;
    }
} // utils