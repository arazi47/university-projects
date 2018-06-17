//
// Created by sysadmin on 14.06.2018.
//

#include "Complex.hpp"

bool Complex::operator==(const Complex &c2) {
    return this->real == c2.real && this->imag == c2.imag;
}

Complex Complex::operator/(int num) {
    if (num == 0) {
        throw runtime_error("Division by zero!");
    }

    return Complex{this->real / num, this->imag / num};
}

ostream& operator<<(ostream &os, const Complex &c) {
    os << c.getReal() << " + " << c.getImaginary() << "i";
    return os;
}
