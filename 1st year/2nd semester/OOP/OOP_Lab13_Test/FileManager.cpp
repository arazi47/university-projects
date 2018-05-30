#include "FileManager.h"
#include <fstream>

void FileManager::loadFromFile(vector<Car> &v) {
    string manufacturerName;
    string model;
    int year;
    string color;

    string delimiter;

    ifstream f("/home/sysadmin/TestOOP30Mai/file.txt");
    while (f >> manufacturerName >> delimiter >> model >> delimiter >> year >> delimiter >> color) {
        v.emplace_back(Car(manufacturerName, model, year, color));
    }

    f.close();
}
