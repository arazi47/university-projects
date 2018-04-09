//
// Created by sysadmin on 23.03.2018.
//

#include "Controller.h"

Controller::Controller() {
    // Initialize the dynamic vector with a default capacity of 10
    this->vector = DynamicVector<Axolotl>();
    this->userAdoptionVector = DynamicVector<Axolotl>();

    // For testing purposes only
    this->insertTestElements();
}

Controller::~Controller() {

}

void Controller::insertTestElements() {
    this->vector.add(Axolotl(Axolotl::BREED_0, "Andi", 1, "photo link here #1"));
    this->vector.add(Axolotl(Axolotl::BREED_1, "Roger", 3, "photo link here #2"));
    this->vector.add(Axolotl(Axolotl::BREED_2, "Statham", 2, "photo link here #3"));
    this->vector.add(Axolotl(Axolotl::BREED_1, "Jason", 5, "photo link here #4"));
    this->vector.add(Axolotl(Axolotl::BREED_0, "Federer", 8, "photo link here #5"));
    this->vector.add(Axolotl(Axolotl::BREED_2, "Flying", 3, "photo link here #6"));
    this->vector.add(Axolotl(Axolotl::BREED_1, "Janis", 2, "photo link here #7"));
    this->vector.add(Axolotl(Axolotl::BREED_1, "Infinity", 7, "photo link here #8"));
    this->vector.add(Axolotl(Axolotl::BREED_2, "Stiletto", 4, "photo link here #9"));
    this->vector.add(Axolotl(Axolotl::BREED_0, "Pristine", 3, "photo link here #10"));
}

bool Controller::addAxolotl(DynamicVector<Axolotl>& vector, int breed, string name, int age, string photograph) {
    if (Validator::validateAxolotl(breed, name, age, photograph) && !this->nameAlreadyExists(vector, name))
    {
        Axolotl::Breed currBreed = Axolotl::getBreedFromInt(breed);
        vector.add(Axolotl(currBreed, name, age, photograph));
        //Axolotl axolotl = Axolotl(currBreed, name, age, photograph);
        //vector = vector + axolotl;
        //vector = axolotl + vector;

        return true;
    }

    return false;
}

int Controller::searchAxolotl(string name) {
    return this->vector.searchElement(name);
}

void Controller::deleteAxolotl(int index) {
    this->vector.deleteElement(index);
}

bool Controller::updateAxolotl(int index, int breed, string name, int age, string photograph) {
    if (Validator::validateAxolotl(breed, name, age, photograph) && !this->nameAlreadyExists(this->vector, name)) {
        this->vector.updateElement(index, Axolotl::getBreedFromInt(breed), name, age, photograph);
        return true;
    }

    return false;
}

DynamicVector<Axolotl> &Controller::getVector() {
    return this->vector;
}

DynamicVector<Axolotl> &Controller::getUserAdoptionVector() {
    return this->userAdoptionVector;
}

DynamicVector<Axolotl> Controller::buildFilteredVector(int targetBreed, int targetAge) {
    Axolotl::Breed breed = Axolotl::getBreedFromInt(targetBreed);
    DynamicVector<Axolotl> filteredVector = DynamicVector<Axolotl>();
    for (int i = 0; i < this->vector.getSize(); ++i) {
        if (this->vector[i].getBreed() == breed && this->vector[i].getAge() < targetAge) {
            filteredVector.add(vector[i]);
        }
    }

    return filteredVector;
}

bool Controller::nameAlreadyExists(DynamicVector<Axolotl>& v, string name) {
    for (int i = 0; i < v.getSize(); ++i) {
        if (v[i].getName() == name) {
            return true;
        }
    }

    return false;
}
