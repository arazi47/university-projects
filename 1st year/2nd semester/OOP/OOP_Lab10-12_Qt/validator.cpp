//
// Created by sysadmin on 24.03.2018.
//

#include <iostream>
#include "validator.h"

bool Validator::validateAxolotl(int breed, string &name, int age, string &photograph) {
    try {
        Validator::validateBreed(breed) && Validator::validateName(name) && Validator::validateAge(age) && Validator::validatePhotograph(photograph);
    } catch (const ValidatorException& e) {
        cout << e.getMessage() << endl;
        return false;
    }

    return true;
}

bool Validator::validateBreed(int breed) {
    if ((breed < 0 || breed > 2)) {
        throw ValidatorException("[ERROR] Breed < 0 or breed > 2");
    }

    return true;
}

bool Validator::validateName(string name) {
    if (name.empty()) {
        throw ValidatorException("[ERROR] Name is empty");
    }

    return true;
}

bool Validator::validateAge(int age) {
    if (age <= 0 || age > 99) {
        throw ValidatorException("[ERROR] age <= 0 or age > 99");
    }

    return true;
}

bool Validator::validatePhotograph(string photograph) {
    if (photograph.empty()) {
        throw ValidatorException("[ERROR] Photograph is empty");
    }

    return true;
}
