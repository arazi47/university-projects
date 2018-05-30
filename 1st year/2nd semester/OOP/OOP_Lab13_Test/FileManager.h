#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Car.h"
#include <vector>

class FileManager
{
public:
    static void loadFromFile(vector<Car> &v);
    //static void writeToFile(const vector<Car> &v);
};

#endif // FILEMANAGER_H


