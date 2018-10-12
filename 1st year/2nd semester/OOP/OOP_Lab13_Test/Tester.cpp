#include "Tester.h"
#include "Controller.h"
#include <cassert>

void Tester::TestNumberOfCars() {
    Controller controller;
    assert(controller.getNumberOfCarsFilteredByName("asd") == 0);
    assert(controller.getNumberOfCarsFilteredByName("Audi") == 1);
    assert(controller.getNumberOfCarsFilteredByName("Fiat") == 2);
    assert(controller.getNumberOfCarsFilteredByName("someManufacturer") == 0);

    controller.getVector().push_back(Car("someManufacturer", "testModel", 1962, "pink"));

    assert(controller.getNumberOfCarsFilteredByName("someManufacturer") == 1);
}
