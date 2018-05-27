//
// Created by sysadmin on 24.03.2018.
//

#ifndef LAB5_6_VALIDATOR_H
#define LAB5_6_VALIDATOR_H

#include "Axolotl.h"

class ValidatorException {
public:
    explicit ValidatorException(string message) : message(std::move(message)) {};
    const string& getMessage() const {
        return this->message;
    }

private:
    string message;
};

class Validator {
    public:
        static bool validateAxolotl(int breed, string &name, int age, string &photograph);
        static bool validateBreed(int breed);
        static bool validateName(string name);
        static bool validateAge(int age);
        static bool validatePhotograph(string photograph);
};


#endif //LAB5_6_VALIDATOR_H
