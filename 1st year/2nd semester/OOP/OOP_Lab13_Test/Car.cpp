#include "Car.h"

const string Car::toString() const {
    return this->getManufacturer() + " - " + this->getModel() + " - " + to_string(this->getMakeYear()) + " - " + this->getColor();
}
