//
// Created by Gyula108 on 1/6/2024.
//

#include "data.h"

#include <ostream>

namespace data {
    std::ostream &operator << (std::ostream& strm, expenseCategory exCat)
    {
        const std::string nameExCat[] = { "food", "transport", "clothes", "other" };
        return strm << nameExCat[exCat];
    }

    std::ostream &operator << (std::ostream& strm, expenseType exType)
    {
        const std::string nameExType[] = { "essential", "nonessential" };
        return strm << nameExType[exType];
    }

    std::string categoryToString(const expenseCategory &exCat) {
        const std::string nameExCat[] = { "food", "transport", "clothes", "other" };
        return nameExCat[exCat];
    }

    std::string typeToString(const expenseType &exType) {
        const std::string nameExType[] = { "essential", "nonessential" };
        return nameExType[exType];
    }
} // data