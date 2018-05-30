#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Car.h"
#include <vector>

class Controller
{
public:
    Controller();
    ~Controller() = default;

    vector<Car> &getVector() { return this->v; }
    vector<Car> getVectorSortedByManufacturer();
    int getNumberOfCarsFilteredByName(string name);

private:
    vector<Car> v;

};

#endif // CONTROLLER_H
