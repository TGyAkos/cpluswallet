//
// Created by Gyula108 on 1/5/2024.
//

#ifndef EXPENSEWRAPPER_H
#define EXPENSEWRAPPER_H
#include <list>

#include "../data/data.h"

namespace utils {

class expenseWrapper {
    std::list<data::expense> expenses;
    int lastId;

public:
    explicit expenseWrapper()
        : lastId(0) {
        findMaxId();
    }

    [[nodiscard]] std::list<data::expense> getExpenses() const;
    void setExpenses(const std::list<data::expense> &expenses);
    void setLastId(const int &newLastId);

    [[nodiscard]] data::expense getExpenseById(const int &id);
    [[nodiscard]] std::list<data::expense> getExpensesByType(const data::expenseType &type);
    // category and date searches could be done by templates
    [[nodiscard]] std::list<data::expense> getExpensesByCategory(const data::expenseCategory &category);
    // No date type, so this will have to work with string comparison
    [[nodiscard]] std::list<data::expense> getExpensesByDate(const std::string &date);
    [[nodiscard]] std::list<data::expense> getExpensesByDateAndCategory(
        const std::string &date,
        const data::expenseCategory &category
        );

    // TODO this should push to the back of the list, otherwise just loop through it
    void createExpense(data::expense expense);
    void updateExpense(const int &id, const data::expense &expense);
    void deleteExpense(const int &id);
private:
    void findMaxId();
};

} // utils

#endif //EXPENSEWRAPPER_H
