//
// Created by sysadmin on 18.04.2018.
//

#ifndef TEST_OOP_18APR2018_USERINTERFACE_H
#define TEST_OOP_18APR2018_USERINTERFACE_H

#include "Controller.h"

class UserInterface {
    public:
        UserInterface() = default;
        ~UserInterface() = default;

        void run();
        void addProject();
        void displayProjects();
        void totalCostOfFinishedProjects();

    private:
        Controller controller;
};


#endif //TEST_OOP_18APR2018_USERINTERFACE_H
