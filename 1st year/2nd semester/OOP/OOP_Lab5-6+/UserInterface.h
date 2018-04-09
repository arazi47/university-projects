//
// Created by sysadmin on 23.03.2018.
//

#ifndef LAB5_6_USERINTERFACE_H
#define LAB5_6_USERINTERFACE_H

#include <iostream>
#include "Controller.h"

using namespace std;


class UserInterface {
    public:
        UserInterface();
        ~UserInterface();

        void printMenu(int admin);
        int readAdminOrUser();
        void run();

        int readInt(string text);
        string readString(string text);

        int handleAdminOptions(int option);
        int handleUserOptions(int option);

        void displayEachPet();

        void displayList(DynamicVector<Axolotl>& v);

    private:
        string administratorMenuString;
        string userMenuString;

        Controller controller;
};


#endif //LAB5_6_USERINTERFACE_H
