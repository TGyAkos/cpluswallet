//
// Created by Gyula108 on 1/6/2024.
//

#ifndef UIDISPLAY_H
#define UIDISPLAY_H

#include "data.h"
#include "expenseWrapper.h"

namespace utils {
    // Cant decide if this is shit or not xd
class uiDisplay {
    std::string userInput;
    expenseWrapper expenseModel;

public:
    void displayExpenses();
    void createNewExpense();
    void updateExpense();
    void deleteExpense();
    void displayExpensesByDate();
    void displayExpensesByType();
    void displayExpensesByDateAndType();

    [[nodiscard]] std::string getUserInput() const;

    [[nodiscard]] expenseWrapper getExpenseModel() const;
    void setExpenseModel(const expenseWrapper &expenseModel);

private:
    static void displayExpense(const data::expense &expenses);
    int convertUserInput(const std::string &str);
    std::string validateUserInput(const std::string &str);
    void displayTypes();
    void displayCaregories();
    template <typename T>
    [[nodiscard]] T promptUser();
};

} // utils

#endif //UIDISPLAY_H
