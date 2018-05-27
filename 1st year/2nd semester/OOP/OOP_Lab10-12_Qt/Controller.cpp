//
// Created by sysadmin on 23.03.2018.
//

#include "Controller.h"
#include "FileManager.h"
#include <string>

Controller::Controller(bool loadPets) {
    // Initialize the dynamic vector with a default capacity of 10
    this->vec = vector<Axolotl>();
    this->userAdoptionVector = vector<Axolotl>();

    // For testing purposes only
    //this->insertTestElements();

    if (loadPets) {
        FileManager::loadFromFile(this->vec);
    }
}

void Controller::insertTestElements() {
    this->vec.emplace_back(Axolotl(Axolotl::BREED_0, "Andi", 1, "photo link here #1"));
    this->vec.emplace_back(Axolotl(Axolotl::BREED_1, "Roger", 3, "photo link here #2"));
    this->vec.emplace_back(Axolotl(Axolotl::BREED_2, "Statham", 2, "photo link here #3"));
    this->vec.emplace_back(Axolotl(Axolotl::BREED_1, "Jason", 5, "photo link here #4"));
    this->vec.emplace_back(Axolotl(Axolotl::BREED_0, "Federer", 8, "photo link here #5"));
    this->vec.emplace_back(Axolotl(Axolotl::BREED_2, "Flying", 3, "photo link here #6"));
    this->vec.emplace_back(Axolotl(Axolotl::BREED_1, "Janis", 2, "photo link here #7"));
    this->vec.emplace_back(Axolotl(Axolotl::BREED_1, "Infinity", 7, "photo link here #8"));
    this->vec.emplace_back(Axolotl(Axolotl::BREED_2, "Stiletto", 4, "photo link here #9"));
    this->vec.emplace_back(Axolotl(Axolotl::BREED_0, "Pristine", 3, "photo link here #10"));
}

bool Controller::addAxolotl(vector<Axolotl>& vec, int breed, string name, int age, string photograph) {
    if (Validator::validateAxolotl(breed, name, age, photograph) && !this->nameAlreadyExists(vec, name))
    {
        Axolotl::Breed currBreed = Axolotl::getBreedFromInt(breed);
        vec.emplace_back(Axolotl(currBreed, name, age, photograph));
        //Axolotl axolotl = Axolotl(currBreed, name, age, photograph);
        //vector = vec + axolotl;
        //vector = axolotl + vec;

        return true;
    }

    return false;
}

int Controller::searchAxolotl(const string& name) {
    return this->searchElement(name);
}

void Controller::deleteAxolotl(int index) {
    this->vec.erase(vec.begin() + index);
}

void Controller::updateAxolotl(int index, int breed, string name, int age, string photograph) {
    if (Validator::validateAxolotl(breed, name, age, photograph) && !this->nameAlreadyExists(this->vec, name)) {
        this->updateElement(index, Axolotl::getBreedFromInt(breed), name, age, photograph);
        return;
    }

    throw "[ERROR] New data could not be validated!";
}

vector<Axolotl>& Controller::getVector() {
    return this->vec;
}

vector<Axolotl>& Controller::getUserAdoptionVector() {
    return this->userAdoptionVector;
}

vector<Axolotl> Controller::buildFilteredVector(int targetBreed, int targetAge) {
    Axolotl::Breed breed = Axolotl::getBreedFromInt(targetBreed);
    vector<Axolotl> filteredVector;
    for (int i = 0; i < this->vec.size(); ++i) {
        if (this->vec[i].getBreed() == breed && this->vec[i].getAge() < targetAge) {
            filteredVector.push_back(vec[i]);
        }
    }

    return filteredVector;
}

bool Controller::nameAlreadyExists(vector<Axolotl>& vec, string name) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i].getName() == name) {
            return true;
        }
    }

    return false;
}

int Controller::searchElement(string name) {
    for (int i = 0; i < this->vec.size(); ++i) {
        if (this->vec[i].getName() == name) {
            return i;
        }
    }

    return -1;
}

void Controller::updateElement(int index, Axolotl::Breed breed, string& name, int age, string& photograph) {
    this->vec[index].setBreed(breed);
    this->vec[index].setName(name);
    this->vec[index].setAge(age);
    this->vec[index].setPhoto(photograph);
}

vector<Axolotl> Controller::filterByNameStartingWith(string startingWith) {
    if (!startingWith.size()) {
        return this->vec;
    }

    vector<Axolotl> vec;
    for (const auto& ax : this->vec) {
        // This only checks the first letter
        //if (ax.getName()[0] == startingWith[0]) {

        // This checks for a whole substring
        if (ax.getName().find(startingWith) != string::npos) {
            vec.push_back(ax);
        }
    }

    return vec;
}


