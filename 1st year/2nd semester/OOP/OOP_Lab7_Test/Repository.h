//
// Created by sysadmin on 18.04.2018.
//

#ifndef TEST_OOP_18APR2018_REPOSITORY_H
#define TEST_OOP_18APR2018_REPOSITORY_H

#include <vector>
#include "Project.h"


class Repository {
    public:
        Repository() = default;
        ~Repository() = default;

        void addProject(Project proj);
        bool customerAlreadyExists(string customer);

        vector<Project>& getVector();

    private:
        vector<Project> vec;
};


#endif //TEST_OOP_18APR2018_REPOSITORY_H
