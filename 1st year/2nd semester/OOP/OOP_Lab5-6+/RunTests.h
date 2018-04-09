//
// Created by sysadmin on 25.03.2018.
//

#ifndef LAB5_6_RUNTESTS_H
#define LAB5_6_RUNTESTS_H

#include <vector>
#include "Axolotl.h"
#include "Controller.h"

using std::vector;

class RunTests {
    public:
        static void testDynamicVector();
        static void testController();
        static void testAxolotl();

        static void runTests();
};


#endif //LAB5_6_RUNTESTS_H
