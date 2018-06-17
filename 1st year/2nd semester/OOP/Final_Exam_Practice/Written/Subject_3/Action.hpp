//
// Created by sysadmin on 17.06.2018.
//

#ifndef OOP_WRITTEN_S3_ACTION_HPP
#define OOP_WRITTEN_S3_ACTION_HPP

#include <iostream>

using std::cout;
using std::endl;


class Action {
    public:
        virtual void execute() = 0;
};

class CreateAction : public Action {
    void execute() override {
        cout << "Create action" << endl;
    }
};

class ExitAction : public Action {
    void execute() override {
        cout << "Exit application" << endl;
    }
};

#endif //OOP_WRITTEN_S3_ACTION_HPP
