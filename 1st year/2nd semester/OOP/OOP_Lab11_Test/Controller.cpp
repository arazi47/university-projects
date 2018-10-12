//
// Created by sysadmin on 16.05.2018.
//

#include <fstream>
#include "Controller.hpp"
#include "algorithm";

Controller::Controller() {
    // Insert test values
    string hospitalName = "HName1";
    string hospitalName2 = "HName2";
    string hospitalName3 = "HName3";
    string hospitalName4 = "HName4";

    this->addDepartment(new NeonatalUnit(hospitalName, 34, 44, 88, 8.6));
    this->addDepartment(new NeonatalUnit(hospitalName2, 34, 44, 55, 4));
    this->addDepartment(new Surgery(hospitalName3, 15, 5));
    this->addDepartment(new Surgery(hospitalName4, 15, 40));

    // Write test values to file
    this->writeToFile();
}

void Controller::addDepartment(HospitalDepartment *department) {
    this->vec.emplace_back(department);
    if (department->isEfficient()) {
        this->efficientVec.emplace_back(department);
    }

    this->writeToFile();
}

const vector<HospitalDepartment *> &Controller::getAllDepartments() {
    return this->vec;
}

const vector<HospitalDepartment *> &Controller::getAllEfficientDepartments() {
    return this->efficientVec;
}

void Controller::writeToFile() {
    // Sort departments alphabetically & ascending by the name of the hospital
    // using a simple lambda function
    sort(vec.begin(), vec.end(), [](HospitalDepartment *dep1, HospitalDepartment *dep2){
        return dep1->getHospitalName() < dep2->getHospitalName();
    });

    ofstream out("outfile.txt");
    for (const auto& dep : this->vec) {
        out << dep->toString() << endl;
    }

    out.close();
}


