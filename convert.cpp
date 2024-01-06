//
// Created by Gyula108 on 1/6/2024.
//
#include <sstream>
#include <iostream>

#include "convert.h"

namespace utils {
    int convert::tryConvertToInt(const std::string &str) {
        std::stringstream convertor;
        int number;

        convertor << str;
        convertor >> number;

        if (convertor.fail()) {
            return NULL;
        }

        return number;
    }

} // utils