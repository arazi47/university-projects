//
// Created by sysadmin on 18.04.2018.
//

#include <cassert>
#include "RunTests.h"
#include "Controller.h"

void RunTests::runTests() {
    Controller controller;
    assert(controller.getProjects().size() == 5);
    controller.addProject(Project("testNameProj", "testCustomerProj", "2021.03.03", 1234.5, false));
    assert(controller.getProjects().size() == 6);

    assert(controller.numberOfFinishedProjects() == 2);
    controller.addProject(Project("testNameProj", "testCustomerProj2", "2021.03.03", 1234.5, true));
    assert(controller.numberOfFinishedProjects() == 3);
}
