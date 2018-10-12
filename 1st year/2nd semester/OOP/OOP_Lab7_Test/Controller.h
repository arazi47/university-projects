//
// Created by sysadmin on 18.04.2018.
//

#ifndef TEST_OOP_18APR2018_CONTROLLER_H
#define TEST_OOP_18APR2018_CONTROLLER_H

#include "Repository.h"

class Controller {
    public:
        Controller();
        ~Controller() = default;

        void addTestProjects();

        bool customerAlreadyExists(string customer);
        void addProject(Project proj);

        float totalCostOfFinishedProjects();
        int numberOfFinishedProjects();

        vector<Project> getSortedProjects();

        vector<Project>& getProjects();

    private:
        Repository repo;
};


#endif //TEST_OOP_18APR2018_CONTROLLER_H
