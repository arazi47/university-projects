//
// Created by sysadmin on 18.04.2018.
//

#include "Repository.h"

void Repository::addProject(Project proj) {
    this->vec.push_back(proj);
}

bool Repository::customerAlreadyExists(string customer) {
    for (const auto& project : this->vec) {
        if (project.getCustomer() == customer) {
            return true;
        }
    }

    return false;
}

vector<Project>& Repository::getVector() {
    return this->vec;
}
