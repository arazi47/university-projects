//
// Created by sysadmin on 14.06.2018.
//

#ifndef OOP_WRITTEN_VECTOR_HPP
#define OOP_WRITTEN_VECTOR_HPP

#include <vector>
#include "Complex.hpp"

template <class T>
class Vector {
    public:
        explicit Vector(vector<T> vec) : vec{vec} {}

        void printAll(ostream &os) {
            for (const auto& elem : this->vec) {
                os << elem << ", ";
            }

            os << "\n";
        }

    private:
        vector<T> vec;
};

#endif //OOP_WRITTEN_VECTOR_HPP
