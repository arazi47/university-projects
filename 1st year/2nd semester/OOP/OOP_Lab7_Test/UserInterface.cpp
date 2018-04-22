//
// Created by sysadmin on 18.04.2018.
//

#include <iostream>
#include "UserInterface.h"

void UserInterface::run() {
    while (true) {
        cout << "0. Exit\n"
                "1. Add project\n"
                "2. Display projects\n"
                "3. Calculate the total cost of finished projects\n";

        int option;
        cin >> option;

        switch (option) {
            case 0:
                exit(0);

            case 1:
                this->addProject();
                break;

            case 2:
                this->displayProjects();
                break;

            case 3:
                this->totalCostOfFinishedProjects();
                break;
            default:
                cout << "Unknown option entered!";
                break;
        }

        cout << endl;
    }
}

void UserInterface::addProject() {
    string name, customer, date;
    float cost;
    bool isDone;

    cout << "Name: ";
    cin >> name;

    cout << "Customer: ";
    cin >> customer;

    cout << "Date: " ;
    cin >> date;

    cout << "Cost: ";
    cin >> cost;

    cout << "isDone: ";
    cin >> isDone;

    if (!this->controller.customerAlreadyExists(customer)) {
        this->controller.addProject(Project(name, customer, date, cost, isDone));
        cout << "Success!\n";
    } else {
        cout << "Failed to add project! (customer already exists)\n";
    }
}

void UserInterface::displayProjects() {
    for (const auto& proj : this->controller.getSortedProjects()) {
        string done = proj.getIsDone() ? "done" : "not done";
        cout << proj.getName() << ' ' << proj.getCustomer() << ' ' << proj.getDate() << ' ' << proj.getCost() << ' ' << done << endl;
    }
}

void UserInterface::totalCostOfFinishedProjects() {
    cout << "Total cost of finished projects is " << this->controller.totalCostOfFinishedProjects() << "." << endl;
}
