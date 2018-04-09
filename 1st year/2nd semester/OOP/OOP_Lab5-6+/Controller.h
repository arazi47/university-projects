//
// Created by sysadmin on 23.03.2018.
//

#ifndef LAB5_6_CONTROLLER_H
#define LAB5_6_CONTROLLER_H

#include <iostream>

using namespace std;

#include <vector>
#include "Axolotl.h"
#include "Validator.h"

class Controller {
    public:
        Controller();
        ~Controller();

        void insertTestElements();

        bool addAxolotl(vector<Axolotl>& vec, int breed, string name, int age, string photograph);
        int searchAxolotl(string name);
        void deleteAxolotl(int index);
        bool updateAxolotl(int index, int breed, string name, int age, string photograph);

        vector<Axolotl>& getVector();
        vector<Axolotl>& getUserAdoptionVector();
        vector<Axolotl> buildFilteredVector(int targetBreed, int targetAge);

        bool nameAlreadyExists(vector<Axolotl>& vec, string name);

        int searchElement(string name);
        void updateElement(int index, Axolotl::Breed breed, string name, int age, string photograph);

    private:
        vector<Axolotl> vec;
        vector<Axolotl> userAdoptionVector;
};


#endif //LAB5_6_CONTROLLER_H
