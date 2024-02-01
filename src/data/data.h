//
// Created by Gyula108 on 1/4/2024.
//

#ifndef DATA_H
#define DATA_H
#include <string>

namespace data {
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

    std::ostream &operator << (std::ostream& strm, expenseCategory exCat);
    std::ostream &operator << (std::ostream& strm, expenseType exType);
    std::string categoryToString(const expenseCategory &exCat);
    std::string typeToString(const expenseType &exType);
} // data


#endif //DATA_H
