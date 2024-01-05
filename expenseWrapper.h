//
// Created by Gyula108 on 1/5/2024.
//

#ifndef EXPENSEWRAPPER_H
#define EXPENSEWRAPPER_H
#include <list>

#include "data.h"

namespace utils {
    // TODO implement this
class expenseWrapper {
    std::list<expense> expenses;

public:
    [[nodiscard]] std::list<expense> getExpenses() const;
    void setExpenses(const std::list<expense> &expenses);

    [[nodiscard]] expense getExpenseById(const int &id);
    [[nodiscard]] std::list<expense> getExpensesByType(const expenseType &type);
    [[nodiscard]] std::list<expense> getExpensesByCategory(const expenseType &category);
    // No date type, so this will have to work with string comparison
    [[nodiscard]] std::list<expense> getExpensesByDate(const std::string &date);

    // TODO this should push to the back of the list, otherwise just loop through it
    void createExpense(const expense &expense);
    void updateExpense(const int &id, const expense &expense);
    void deleteExpense(const int &id);
};

} // utils

#endif //EXPENSEWRAPPER_H
