//
// Created by sysadmin on 23.03.2018.
//

#ifndef LAB5_6_CONTROLLER_H
#define LAB5_6_CONTROLLER_H

#include <iostream>

using namespace std;

#include "DynamicVector.h"
#include "Axolotl.h"
#include "Validator.h"

class Controller {
    public:
        Controller();
        ~Controller();

        void insertTestElements();
        void displayList(DynamicVector<Axolotl>& vector);

        bool addAxolotl(DynamicVector<Axolotl>& vector, int breed, string name, int age, string photograph);
        int searchAxolotl(string name);
        void deleteAxolotl(int index);
        bool updateAxolotl(int index, int breed, string name, int age, string photograph);

        DynamicVector<Axolotl> &getVector();
        DynamicVector<Axolotl> &getUserAdoptionVector();
        DynamicVector<Axolotl> buildFilteredVector(int targetBreed, int targetAge);

        bool nameAlreadyExists(DynamicVector<Axolotl>& v, string name);

    private:
        DynamicVector<Axolotl> vector;
        DynamicVector<Axolotl> userAdoptionVector;
};


#endif //LAB5_6_CONTROLLER_H
