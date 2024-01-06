#include <format>
#include <iostream>

#include "parseFile.h"
#include "run.h"


int main() {
    runtime::run runObject;
    runObject.runMainLoop();
    return 0;
}

