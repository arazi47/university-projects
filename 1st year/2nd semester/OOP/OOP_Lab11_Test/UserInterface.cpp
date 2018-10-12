//
// Created by sysadmin on 16.05.2018.
//

#include "UserInterface.hpp"

void UserInterface::run() {
    while (true) {
        cout << "0. Exit\n";
        cout << "1. Add department\n";
        cout << "2. Display all departments\n";
        cout << "3. Display all efficient departments\n";

        cout << ">>> ";
        int option;
        cin >> option;

        switch(option) {
            case 0:
                exit(EXIT_SUCCESS);

            case 1: {
                cout << "Type (1 - Neonatal Unit, 2 - Surgery): ";
                int type;
                cin >> type;

                string hospitalName;
                cout << "Hospital name: ";
                cin >> hospitalName;

                int noOfDocs;
                cout << "Number of doctors: ";
                cin >> noOfDocs;


                if (type == 1) {
                    int noOfMothers, noOfNewborns;
                    cout << "Number of mothers: ";
                    cin >> noOfMothers;

                    cout << "Number of newborns: ";
                    cin >> noOfNewborns;

                    double avgGrade;
                    cout << "Average grade of babies: ";
                    cin >> avgGrade;


                    this->controller.addDepartment(new NeonatalUnit(hospitalName, noOfDocs, noOfMothers, noOfNewborns, avgGrade));
                } else {
                    int noOfPatients;
                    cout << "Number of patients: ";
                    cin >> noOfPatients;

                    this->controller.addDepartment(new Surgery(hospitalName, noOfDocs, noOfPatients));
                }
            }
                break;

            case 2: {
                for (const auto& dep : this->controller.getAllDepartments()) {
                    cout << dep->toString() << endl;
                }
            }

            break;

            case 3: {
                for (const auto& dep : this->controller.getAllEfficientDepartments()) {
                    cout << dep->toString() << endl;
                }
            }

            break;

            default:
                cout << "Unknown option entered!\n";
                break;
        }
        cout << "\n\n";
    }
}
