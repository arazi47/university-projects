#ifndef RUNTESTS_H
#define RUNTESTS_H

#include "Session.h"
#include <cassert>

class RunTests
{
public:
    static void testAddQuestion();
    static void testGetAllAnswersForGivenQuestion();

    static void runTests();
};

#endif // RUNTESTS_H
