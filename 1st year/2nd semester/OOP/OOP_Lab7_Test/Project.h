//
// Created by sysadmin on 18.04.2018.
//

#ifndef TEST_OOP_18APR2018_PROJECT_H
#define TEST_OOP_18APR2018_PROJECT_H

#include <string>

using namespace std;

class Project {
    public:
        Project(string name, string customer, string date, float cost, bool isDone);
        ~Project() = default;

        void setName(string name);
        void setCustomer(string customer);
        void setDate(string date);
        void setCost(float cost);
        void setIsDone(bool isDone);

        string getName() const;
        string getCustomer() const;
        string getDate() const;
        float getCost() const;
        bool getIsDone() const;

    private:
        string name;
        string customer;
        string date;
        float cost;
        bool isDone;
};


#endif //TEST_OOP_18APR2018_PROJECT_H
