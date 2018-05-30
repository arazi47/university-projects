#include "Controller.h"
#include "FileManager.h"
#include <algorithm>

Controller::Controller()
{
    FileManager::loadFromFile(v);
}

// Return a new vector with all the cars
// Sorted by manufacturer name
vector<Car> Controller::getVectorSortedByManufacturer() {
    vector<Car> vec = this->v;
    sort(vec.begin(), vec.end(), [](const Car c1, const Car c2){
        return c1.getManufacturer() < c2.getManufacturer();
    });
    return vec;
}

/*
 * Return the number of cars which are produced by the manufacturer
 * included in the string "name"
 */

int Controller::getNumberOfCarsFilteredByName(string name) {
    int cnt = 0;
    for (const auto& car : this->v) {
        if (car.getManufacturer() == name) {
            ++cnt;
        }
    }

    return cnt;
}
