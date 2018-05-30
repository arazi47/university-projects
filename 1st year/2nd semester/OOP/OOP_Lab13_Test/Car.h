#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

class Car
{
public:
    Car(string manufacturerName, string model, int makeYear, string color) :
        manufacturerName(manufacturerName), model(model), makeYear(makeYear), color(color) {}

    ~Car() = default;

    const string getManufacturer() const { return this-> manufacturerName; }
    const string getModel() const { return this->model; }
    const int getMakeYear() const { return this->makeYear; }
    const string getColor() const { return this->color; }

    const string toString() const;

private:
    string manufacturerName;
    string model;
    int makeYear;
    string color;
};

#endif // CAR_H
