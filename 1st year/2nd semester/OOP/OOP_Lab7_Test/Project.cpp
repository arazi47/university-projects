//
// Created by sysadmin on 18.04.2018.
//

#include "Project.h"

Project::Project(string name, string customer, string date, float cost, bool isDone) : name(move(name)), customer(move(customer)), date(move(date)), cost(cost), isDone(isDone) {}

void Project::setName(string name) {
    this->name = move(name);
}

void Project::setCustomer(string customer) {
    this->customer = move(customer);
}

void Project::setDate(string date) {
    this->date = move(date);
}

void Project::setCost(float cost) {
    this->cost = cost;
}

void Project::setIsDone(bool isDone) {
    this->isDone = isDone;
}

string Project::getName() const {
    return this->name;
}

string Project::getCustomer() const {
    return this->customer;
}

string Project::getDate() const {
    return this->date;
}

float Project::getCost() const {
    return this->cost;
}

bool Project::getIsDone() const {
    return this->isDone;
}
