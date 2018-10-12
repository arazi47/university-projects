//
// Created by sysadmin on 16.05.2018.
//

#ifndef OOPTEST16MAI_CONTROLLER_HPP
#define OOPTEST16MAI_CONTROLLER_HPP


#include "HospitalDepartment.hpp"
#include <vector>

class Controller {
    public:
        Controller();
        ~Controller() = default;

        void addDepartment(HospitalDepartment *department);
        const vector<HospitalDepartment*> &getAllDepartments();
        const vector<HospitalDepartment*> &getAllEfficientDepartments();
        void writeToFile();


    private:
        vector<HospitalDepartment*> vec;
        vector<HospitalDepartment*> efficientVec;
};


#endif //OOPTEST16MAI_CONTROLLER_HPP
