//
// Created by sysadmin on 23.03.2018.
//

#ifndef LAB5_6_CONTROLLER_H
#define LAB5_6_CONTROLLER_H

#include <iostream>
#include <vector>
#include "Axolotl.h"
#include "validator.h"

using namespace std;

class Controller {
    public:
        Controller() = default;

        explicit Controller(bool loadPets);

        ~Controller() = default;

        void insertTestElements();

        bool addAxolotl(vector<Axolotl>& vec, int breed, string name, int age, string photograph);
        int searchAxolotl(const string& name);
        void deleteAxolotl(int index);
        void updateAxolotl(int index, int breed, string name, int age, string photograph);

        vector<Axolotl>& getVector();
        vector<Axolotl>& getUserAdoptionVector();
        vector<Axolotl> buildFilteredVector(int targetBreed, int targetAge);
        vector<Axolotl> filterByNameStartingWith(string startingWith);

        bool nameAlreadyExists(vector<Axolotl>& vec, string name);

        int searchElement(string name);
        void updateElement(int index, Axolotl::Breed breed, string& name, int age, string& photograph);

    private:
        vector<Axolotl> vec;
        vector<Axolotl> userAdoptionVector;
};


#endif //LAB5_6_CONTROLLER_H
