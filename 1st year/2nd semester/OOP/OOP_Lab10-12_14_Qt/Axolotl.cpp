//
// Created by sysadmin on 23.03.2018.
//

#include <iostream>
#include "Axolotl.h"

Axolotl::Axolotl(Breed breed, string name, int age, string photograph) : breed(breed), name(name), age(age), photograph(photograph)
{}

Axolotl::Breed Axolotl::getBreed() const {
    return this->breed;
}

string Axolotl::getName() const {
    return this->name;
}

int Axolotl::getAge() const {
    return this->age;
}

string Axolotl::getPhoto() const {
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
            return -1;
    }
}


istream& operator >> (istream& in, Axolotl& axolotl) {
    string name;
    int age;
    int breed;
    string photo;

    string line;
    in >> line;

    size_t pos = line.find(",");
    name = line.substr(0, pos);
    line.erase(0, pos + 1);

    pos = line.find(",");

    // This crashes, why!?
    //age = stoi(line.substr(0, pos));

    age = atoi(line.substr(0, pos).c_str());
    line.erase(0, pos + 1);

    pos = line.find(",");

    // This crashes too...
    // breed = stoi(line.substr(0, pos));

    breed = atoi(line.substr(0, pos).c_str());
    line.erase(0, pos + 1);

    photo = line;

    axolotl.setName(name);
    axolotl.setAge(age);
    axolotl.setBreed(Axolotl::getBreedFromInt(breed));
    axolotl.setPhoto(photo);

    return in;
}

ostream& operator << (ostream& out, const Axolotl& axolotl) {
    out << axolotl.getName() << " - " << axolotl.getAge() << " - " << Axolotl::getStringFromBreed(axolotl.getBreed()) << " - " << axolotl.getPhoto() << endl;
    return out;
}
