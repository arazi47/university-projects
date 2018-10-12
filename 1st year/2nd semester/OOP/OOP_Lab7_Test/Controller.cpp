//
// Created by sysadmin on 18.04.2018.
//

#include "Controller.h"
#include <algorithm>
#include <iostream>

Controller::Controller() {
    this->addTestProjects();
}

void Controller::addTestProjects() {
    this->repo.addProject(Project("Stairs", "Flin", "2018.08.20", 18, false));
    this->repo.addProject(Project("Website", "Spitalul Judetean Cluj", "2017.01.06", 122, true));
    this->repo.addProject(Project("Data Archiving", "Spitalul Judetean Cluj", "2020.06.06", 200, false));
    this->repo.addProject(Project("Website", "Valuations", "2018.09.01", 2.3, true));
    this->repo.addProject(Project("Revolutie", "Romania", "2018.04.18", 9999, false));
}

bool Controller::customerAlreadyExists(string customer) {
    return this->repo.customerAlreadyExists(move(customer));
}

void Controller::addProject(Project proj) {
    this->repo.addProject(proj);
}

vector<Project>& Controller::getProjects() {
    return this->repo.getVector();
}

float Controller::totalCostOfFinishedProjects() {
    float sum = 0;
    for (const auto& proj : this->repo.getVector()) {
        if (proj.getIsDone()) {
            sum += proj.getCost();
        }
    }

    return sum;
}

int Controller::numberOfFinishedProjects() {
    int cnt = 0;
    for (const auto& proj : this->repo.getVector()) {
        if (proj.getIsDone()) {
            ++cnt;
        }
    }

    return cnt;
}


/*
 * In: string (date), char (delimiter)
 * Out: year * 10000 + month * 100 + day
 * Used for sorting a vector of projects by their date
 */
const int explode(const string& s, const char& c)
{
    string buff;
    int sum = 0;
    int factor = 10000;

    for(auto n:s)
    {
        if(n != c) buff+=n; else
        if(n == c && !buff.empty()) { sum += (atoi(buff.c_str()) * factor); buff = ""; factor /= 100; }
    }
    if(!buff.empty()) {sum += (atoi(buff.c_str())); factor /= 100; }

    return sum;
}

vector<Project> Controller::getSortedProjects() {
    vector<Project> sorted = this->repo.getVector();
    for (int i = 0; i < sorted.size() - 1; ++i) {
        for (int j = i + 1; j < sorted.size(); ++j) {
            int s1 = explode(sorted[i].getDate(), '.');
            int s2 = explode(sorted[j].getDate(), '.');

            if (s1 > s2) {
                Project aux = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = aux;
            }
        }
    }

    return sorted;
}
