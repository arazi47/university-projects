//
// Created by sysadmin on 12.04.2018.
//

#ifndef LAB5_6_COMPARATOR_H
#define LAB5_6_COMPARATOR_H

#include "Axolotl.h"

class Comparator {
    public:
        virtual bool compare(const Axolotl &t1, const Axolotl &t2) const = 0;
};

class CompareAscendingByName : public Comparator {
public:
    bool compare(const Axolotl &t1, const Axolotl &t2) const override {
        return t1.getName() > t2.getName();
    }
};

class CompareAscendingByAge : public Comparator {
public:
    bool compare(const Axolotl &t1, const Axolotl &t2) const override {
        return t1.getAge() > t2.getAge();
    }
};

#endif //LAB5_6_COMPARATOR_H
