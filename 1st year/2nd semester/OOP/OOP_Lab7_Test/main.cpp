#include <iostream>
#include "UserInterface.h"
#include "RunTests.h"

int main() {
    RunTests::runTests();

    UserInterface UI;
    UI.run();

    return 0;
}