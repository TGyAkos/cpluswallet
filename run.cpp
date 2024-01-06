//
// Created by Gyula108 on 1/6/2024.
//

#include "run.h"

#include <iostream>

namespace runtime {
    void run::runMainLoop() {
        loadFromFile();
        bool isRunning = true;
        while (isRunning) {
            utils::uiDisplay::displayMainMenu();
            std::cout << "What do you want to do?\n";
            switch (display.promptUser<int>()) {
                case 1:
                    runCreate();
                break;
                case 2:
                    runSearchLoop();
                break;
                case 3:
                    isRunning = false;
                break;
                default:
                    utils::uiDisplay::displayError();
                break;
            }
        }
        saveToFile();
    }

    void run::runCreate() {
        display.createNewExpense();
    }

    void run::runSearchLoop() {
        bool isRunning = true;
        while (isRunning) {
            utils::uiDisplay::displaySearchMenu();
            std::cout << "What do you want to do?\n";
            switch (display.promptUser<int>()) {
                case 1:
                    display.displayAllExpenses();
                break;
                case 2:
                    display.displayExpenseById();
                break;
                case 3:
                    display.displayExpensesByDate();
                break;
                case 4:
                    display.displayExpensesByType();
                break;
                case 5:
                    display.displayExpensesByCategory();
                break;
                case 6:
                    display.displayExpensesByDateAndType();
                break;
                case 7:
                    isRunning = false;
                break;
                default:
                    utils::uiDisplay::displayError();
                break;
            }
        }
    }

    void run::loadFromFile() {
        utils::expenseWrapper fromFileExpenses;
        fromFileExpenses.setExpenses(parser.getExpenses());
        display.setExpenseModel(fromFileExpenses);
    }

    void run::saveToFile() const {
        parser.loadDataToFile(display.getExpenseModel().getExpenses());
    }

} // runtime