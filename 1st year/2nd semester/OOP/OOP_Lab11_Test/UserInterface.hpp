//
// Created by sysadmin on 16.05.2018.
//

#ifndef OOPTEST16MAI_USERINTERFACE_HPP
#define OOPTEST16MAI_USERINTERFACE_HPP


#include "Controller.hpp"

class UserInterface {
    public:
        UserInterface() = default;
        ~UserInterface() = default;

        void run();

    private:
        Controller controller;
};

#endif //OOPTEST16MAI_USERINTERFACE_HPP
