//
// Created by Gyula108 on 1/6/2024.
//

#ifndef RUN_H
#define RUN_H
#include "../utils/uiDisplay.h"

namespace runtime {

class run {
    utils::uiDisplay display;
    utils::parseFile parser;
public:
    explicit run() : parser("asd.txt") {}

    void runMainLoop();

private:
    void runSearchLoop();
    void runCreate();
    void loadFromFile();
    void saveToFile() const;
};

} // runtime

#endif //RUN_H
