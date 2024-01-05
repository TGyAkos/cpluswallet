//
// Created by Gyula108 on 1/5/2024.
//

#include "expenseWrapper.h"

namespace utils {
    std::list<expense> expenseWrapper::getExpenses() const {
        return this->expenses;
    }

    void expenseWrapper::setExpenses(const std::list<expense> &expenses) {
        this->expenses = expenses;
    }

    expense expenseWrapper::getExpenseById(const int &id) {
        for (expense &expense : this->expenses) {
            if (expense.id == id) return expense;
        }
        return {};
    }

    std::list<expense> expenseWrapper::getExpensesByType(const expenseType &type) {
        std::list<expense> returnExpenses;
        for (expense &expense : this->expenses) {
            if (expense.type == type) returnExpenses.push_back(expense);
        }
        return returnExpenses;
    }

    std::list<expense> expenseWrapper::getExpensesByCategory(const expenseType &category) {
        std::list<expense> returnExpenses;
        for (expense &expense : this->expenses) {
            if (expense.category == category) returnExpenses.push_back(expense);
        }
        return returnExpenses;
    }

    std::list<expense> expenseWrapper::getExpensesByDate(const std::string &date) {
        std::list<expense> returnExpenses;
        for (expense &expense : this->expenses) {
            if (expense.date == date) returnExpenses.push_back(expense);
        }
        return returnExpenses;
    }

    void expenseWrapper::createExpense(const expense &expense) {
        this->expenses.push_back(expense);
    }

    void expenseWrapper::updateExpense(const int &id, const expense &newExpense) {
        this->deleteExpense(id);
        this->createExpense(newExpense);
    }

    void expenseWrapper::deleteExpense(const int &id) {
        this->expenses.remove_if([&](const expense &expense) {
            return expense.id == id;
        });
    }
} // utils