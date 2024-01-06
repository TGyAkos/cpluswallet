cmake_minimum_required(VERSION 3.27)
project(cpluswallet)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpluswallet main.cpp
        parseFile.cpp
        parseFile.h
        data.h
        expenseWrapper.cpp
        expenseWrapper.h
        uiDisplay.cpp
        uiDisplay.h
        convert.cpp
        convert.h
        data.cpp
)
