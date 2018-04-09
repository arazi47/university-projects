//
// Created by sysadmin on 23.03.2018.
//

#include "Axolotl.h"

// This is needed to initialize an array of Axolotls in class DynamicArray
Axolotl::Axolotl()
{}

Axolotl::Axolotl(Breed breed, string name, int age, string photograph) : breed(breed), name(name), age(age), photograph(photograph)
{}


Axolotl::~Axolotl() {

}

Axolotl::Breed Axolotl::getBreed() {
    return this->breed;
}

string Axolotl::getName() {
    return this->name;
}

int Axolotl::getAge() {
    return this->age;
}

string Axolotl::getPhoto() {
    return this->photograph;
}

void Axolotl::setBreed(Breed breed) {
    this->breed = breed;
}

void Axolotl::setName(string name) {
    this->name = name;
}

void Axolotl::setAge(int age) {
    this->age = age;
}

void Axolotl::setPhoto(string photo) {
    this->photograph = photo;
}

Axolotl::Breed Axolotl::getBreedFromInt(int breed) {
    switch (breed) {
        case 0:
            return Axolotl::BREED_0;

        case 1:
            return Axolotl::BREED_1;

        case 2:
            return Axolotl::BREED_2;

        // We should never get here
        default:
            return Axolotl::BREED_0;
    }
}

string Axolotl::getStringFromBreed(Breed breed) {
    switch (breed) {
        case BREED_0:
            return "Breed 0";

        case BREED_1:
            return "Breed 1";

        case BREED_2:
            return "Breed 2";

        default:
            return "Unknown breed";
    }
}

int Axolotl::getIntFromBreed(Axolotl::Breed breed) {
    switch (breed) {
        case BREED_0:
            return 0;

        case BREED_1:
            return 1;

        case BREED_2:
            return 2;

        default:
            return 0;
    }
}
