//
// Created by Gyula108 on 1/4/2024.
//

#ifndef DATA_H
#define DATA_H
#include <string>


struct expense {
    int id;
    std::string date;
    int type;
    int category;
    int amount;
    std::string comment;
};

enum expenseCategory {
    food,
    transport,
    clothes,
    other
};

enum expenseType {
    essential,
    nonessential
};

#endif //DATA_H
