//
// Created by Gyula108 on 1/6/2024.
//

#include "uiDisplay.h"

#include <format>
#include <iostream>

#include "convert.h"

namespace utils {
    void uiDisplay::displayExpense(const data::expense &expense) {
        std::cout << std::format("id: {}\ndate: {}\ntype: {}\ncategory: {}\namount: {}\ncomment: {}\n\n",
            expense.id,
            expense.date,
            typeToString(static_cast<data::expenseType>(expense.type)),
            categoryToString(static_cast<data::expenseCategory>(expense.category)),
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

    data::expense uiDisplay::promtUserForExpense() {
        data::expense newExpense;
        newExpense.id = 0;
        std::cout << std::format("Provide date\n");
        newExpense.date = promptUser<std::string>();

        std::cout << std::format("Provide type\n");
        displayTypes();
        // This could cause bugs, its never checked if the user has entered a correct int
        newExpense.type = promptUser<int>() - 1;

        std::cout << std::format("Provide category\n");
        displayCaregories();
        // Same here
        newExpense.category = promptUser<int>() - 1;

        std::cout << std::format("Provide amount\n");
        newExpense.amount = promptUser<int>();

        std::cout << std::format("Provide comment\n");
        newExpense.comment = promptUser<std::string>();
        return newExpense;
    }

    // subtarct 1 after getting userInput, this adds 1 for clarity
    void uiDisplay::displayTypes() {
        // TODO there has to be a way to do it better
        std::cout << std::format("1. ") << data::expenseType::essential << "\n";
        std::cout << std::format("2. ") << data::expenseType::nonessential << "\n";
    }

    void uiDisplay::displayCaregories() {
        std::cout << std::format("1.") << data::expenseCategory::food << "\n";
        std::cout << std::format("2.") << data::expenseCategory::transport << "\n";
        std::cout << std::format("3.") << data::expenseCategory::clothes << "\n";
        std::cout << std::format("4.") << data::expenseCategory::other << "\n";

    }

    void uiDisplay::displayExpenses(const std::list<data::expense> &expenses) {
        for (auto const &expense: expenses) {
            displayExpense(expense);
        }
    }

    void uiDisplay::createNewExpense() {
        const data::expense newExpense = promtUserForExpense();
        expenseModel.createExpense(newExpense);
    }

    // This does not validate if the user entered a correct expense.id
    void uiDisplay::updateExpense() {
        std::cout << std::format("Provide the id of the expense, you want to edit");
        const int &id = promptUser<int>();

        displayExpense(expenseModel.getExpenseById(id));
        const data::expense newExpense = promtUserForExpense();

        // This will blindly rewrite anything at that id
        expenseModel.updateExpense(id, newExpense);
    }

    // TODO finish, almost the same as updateExpense()
    void uiDisplay::deleteExpense() {
        std::cout << std::format("Provide the id of the expense, you want to delete");
        const int &id = promptUser<int>();
        expenseModel.deleteExpense(id);
    }

    void uiDisplay::displayExpenseById() {
        std::cout << std::format("Provide the id of the expense");
        const int &id = promptUser<int>();
        displayExpense(expenseModel.getExpenseById(id));
    }

    void uiDisplay::displayAllExpenses() const {
        std::cout << "Every expense:\n";
        displayExpenses(expenseModel.getExpenses());
    }

    // TODO these may not be completely needed, cus it could be done with template<typename T>
    void uiDisplay::displayExpensesByDate() {
        std::cout << "Provide date\n";
        const auto userInput = promptUser<std::string>();
        displayExpenses(expenseModel.getExpensesByDate(userInput));
    }

    void uiDisplay::displayExpensesByType() {
        displayTypes();
        std::cout << "Provide type (number)\n";
        const auto userInput = static_cast<data::expenseType>(promptUser<int>());
        displayExpenses(expenseModel.getExpensesByType(userInput));
    }

    void uiDisplay::displayExpensesByCategory() {
        displayCaregories();
        std::cout << "Provide category (number)\n";
        const auto userInput = static_cast<data::expenseCategory>(promptUser<int>());
        displayExpenses(expenseModel.getExpensesByCategory(userInput));
    }

    void uiDisplay::displayExpensesByDateAndType() {
        std::cout << "Provide date\n";
        const auto date = promptUser<std::string>();
        displayTypes();
        std::cout << "Provide category (number)\n";
        const auto category = static_cast<data::expenseCategory>(promptUser<int>());
        displayExpenses(expenseModel.getExpensesByDateAndCategory(date, category));
    }

    void uiDisplay::displayMainMenu() {
        std::cout << "1. Create new expense\n"
                     "2. Search in exiting expenses\n"
                     "3. Exit\n";
    }

    void uiDisplay::displaySearchMenu() {
        std::cout << "1. Display every expense\n"
                     "2. Search expense by Id\n"
                     "3. Search expense by Date\n"
                     "4. Search expense by Type\n"
                     "5. Search expense by Category\n"
                     "6. Search expense by Date and Type\n"
                     "7. Exit\n";
    }

    void uiDisplay::displayError() {
        std::cout << "This does not exit\n";
    }


    expenseWrapper uiDisplay::getExpenseModel() const {
        return this->expenseModel;
    }

    void uiDisplay::setExpenseModel(const expenseWrapper &expenseModel) {
        this->expenseModel = expenseModel;
    }
} // utils