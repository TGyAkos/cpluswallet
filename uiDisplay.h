//
// Created by Gyula108 on 1/6/2024.
//

#ifndef UIDISPLAY_H
#define UIDISPLAY_H

#include "data.h"
#include "expenseWrapper.h"
#include "parseFile.h"

namespace utils {
    // Cant decide if this is shit or not xd
class uiDisplay {
    expenseWrapper expenseModel;

public:
    void createNewExpense();
    void updateExpense();
    void deleteExpense();
    void displayAllExpenses() const;
    void displayExpenseById();
    void displayExpensesByDate();
    void displayExpensesByType();
    void displayExpensesByCategory();
    void displayExpensesByDateAndType();
    static void displayMainMenu();
    static void displaySearchMenu();
    static void displayError();

    template <typename T>
    [[nodiscard]] T promptUser();

    [[nodiscard]] expenseWrapper getExpenseModel() const;
    void setExpenseModel(const expenseWrapper &expenseModel);

private:
    data::expense promtUserForExpense();
    static void displayExpense(const data::expense &expense);
    int convertUserInput(const std::string &str);
    std::string validateUserInput(const std::string &str);
    static void displayTypes();
    static void displayCaregories();
    static void displayExpenses(const std::list<data::expense> &expenses);
};

} // utils

#endif //UIDISPLAY_H
