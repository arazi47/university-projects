//
// Created by sysadmin on 24.03.2018.
//

#include "Validator.h"

bool Validator::validateAxolotl(int breed, string name, int age, string photograph) {
    return Validator::validateBreed(breed) && Validator::validateName(name) && Validator::validateAge(age) && Validator::validatePhotograph(photograph);
}

bool Validator::validateBreed(int breed) {
    if (breed < 0 || breed > 3)
        return false;

    return true;
}

bool Validator::validateName(string name) {
    if (name.length() == 0) {
        return false;
    }

    return true;
}

bool Validator::validateAge(int age) {
    if (age <= 0 || age > 99) {
        return false;
    }

    return true;
}

bool Validator::validatePhotograph(string photograph) {
    if (photograph.length() == 0) {
        return false;
    }

    return true;
}