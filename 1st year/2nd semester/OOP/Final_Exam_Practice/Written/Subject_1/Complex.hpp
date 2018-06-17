//
// Created by sysadmin on 14.06.2018.
//

#ifndef OOP_WRITTEN_COMPLEX_HPP
#define OOP_WRITTEN_COMPLEX_HPP

#include <iostream>
using namespace std;


class Complex {
    public:
        Complex() : real{0}, imag{0} {}
        Complex(int r, int i) : real{r}, imag{i} {}

        // Copy constructor
        Complex(const Complex &that) : real{that.real}, imag{that.imag} {}

        const int getReal() const { return this->real; }
        const int getImaginary() const { return this->imag; }

        // To check if two complex numbers are equal
        bool operator==(const Complex &c2);

        // Divie real and imaginary by num and return a new complex number
        Complex operator/(int num);

        friend ostream& operator<<(ostream &os, const Complex &c);

    private:
        int real;
        int imag;
};



#endif //OOP_WRITTEN_COMPLEX_HPP
