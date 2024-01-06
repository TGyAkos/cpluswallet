//
// Created by Gyula108 on 1/5/2024.
//

#include "expenseWrapper.h"

namespace utils {
    std::list<data::expense> expenseWrapper::getExpenses() const {
        return this->expenses;
    }

    void expenseWrapper::setExpenses(const std::list<data::expense> &expenses) {
        this->expenses = expenses;
    }

    void expenseWrapper::setLastId(const int &newLastId) {
        this->lastId = newLastId;
    }

    void expenseWrapper::findMaxId() {
        for (const data::expense &expense : this->expenses) {
            if (expense.id > lastId) {
                lastId = expense.id;
            }
        }
    }

    data::expense expenseWrapper::getExpenseById(const int &id) {
        for (data::expense &expense : this->expenses) {
            if (expense.id == id) return expense;
        }
        return {};
    }

    std::list<data::expense> expenseWrapper::getExpensesByType(const data::expenseType &type) {
        std::list<data::expense> returnExpenses;
        for (data::expense &expense : this->expenses) {
            if (expense.type == type) returnExpenses.push_back(expense);
        }
        return returnExpenses;
    }

    std::list<data::expense> expenseWrapper::getExpensesByCategory(const data::expenseCategory &category) {
        std::list<data::expense> returnExpenses;
        for (data::expense &expense : this->expenses) {
            if (expense.category == category) returnExpenses.push_back(expense);
        }
        return returnExpenses;
    }

    std::list<data::expense> expenseWrapper::getExpensesByDate(const std::string &date) {
        std::list<data::expense> returnExpenses;
        for (data::expense &expense : this->expenses) {
            if (expense.date == date) returnExpenses.push_back(expense);
        }
        return returnExpenses;
    }

    std::list<data::expense> expenseWrapper::getExpensesByDateAndCategory(
        const std::string &date,
        const data::expenseCategory &category) {
        std::list<data::expense> returnExpenses;

        for (data::expense &expense : this->expenses) {
            if (expense.date == date && expense.category ==  category) returnExpenses.push_back(expense);
        }

        return returnExpenses;
    }

    void expenseWrapper::createExpense(data::expense expense) {
        // Idk if this only adds 1 locally, or to the private field as well, we'll see
        expense.id = this->lastId++;
        this->expenses.push_back(expense);
        this->lastId++;
    }

    void expenseWrapper::updateExpense(const int &id, const data::expense &newExpense) {
        this->deleteExpense(id);
        this->createExpense(newExpense);
    }

    void expenseWrapper::deleteExpense(const int &id) {
        this->expenses.remove_if([&](const data::expense &expense) {
            return expense.id == id;
        });
    }
} // utils