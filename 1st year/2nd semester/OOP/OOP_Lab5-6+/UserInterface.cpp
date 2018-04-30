//
// Created by sysadmin on 23.03.2018.
//

#include <limits>
#include "UserInterface.h"
#include "FileManager.h"
#include "Comparator.h"

UserInterface::UserInterface() {
    this->controller = Controller(true);

    this->administratorMenuString = "0. Exit\n"
            "1. Add a new axolotl\n"
            "2. Delete an axolotl\n"
            "3. Update information about an axolotl\n"
            "4. Display all axolotls\n";

    this->userMenuString = "0. Exit\n"
            "1. Display available axolotls\n"
            "2. Display axolotls of a given breed and age\n"
            "3. Display my adoption list\n";
}

UserInterface::~UserInterface() = default;

/*
 * Prints the corresponding menu string (administrator/user)
 */
void UserInterface::printMenu(int admin) {
    if (admin == 1) {
        cout << this->administratorMenuString;
    } else if (admin == 2) {
        cout << this->userMenuString;
    }
}

int UserInterface::readAdminOrUser() {
    int admin = this->readInt("0. Exit\n1. Administrator mode\n2. User mode\n");
    while (!(admin == 0 || admin == 1 || admin == 2))
        admin = this->readInt("0. Exit\n1. Administrator mode\n2. User mode\n");

    return admin;
}


/*
 * This function is called from inside main.cpp
 * It is the main function of this class
 */
void UserInterface::run() {
    int admin = readAdminOrUser();

    if (admin == 0) {
        exit(0);
    }

    // If -1 => person wants to switch to admin/user
    int result;

    while (true) {
        this->printMenu(admin);

        int option = this->readInt(">> ");

        if (admin == 0) {
            exit(0);
        } else if (admin == 1) {
            result = this->handleAdminOptions(option);
        } else {
            result = this->handleUserOptions(option);
        }

        if (result == -1)
            admin = readAdminOrUser();
    }

}

/*
 * Prints out "text", then reads and returns an integer read from the keyboard
 */
int UserInterface::readInt(string text) {
    int input;
    cout << text;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << text;
        cin >> input;
    }

    return input;
}

string UserInterface::readString(string text) {
    cout << text;

    string input;
    cin >> input;

    return input;
}

int UserInterface::handleAdminOptions(int option) {
    FileManager* textFileManager = new TextFileManager();

    switch (option) {
        case 0: {
            return -1;
        }

        // Add axolotl
        case 1: {
            int breed = this->readInt("Breed (0, 1, 2): ");
            string name = this->readString("Name: ");
            int age = this->readInt("Age (1-99): ");
            string photo = this->readString("Link to photograph: ");

            bool result = this->controller.addAxolotl(this->controller.getVector(), breed, name, age, photo);
            if (result) {
                // TODO make this more efficient, it SUCKS right now
                //FileManager::exportAsHTML(this->controller.getVector());
                textFileManager->writeToFile(this->controller.getVector(), "outfilevectorall.txt");

                cout << "Axolotl added successfully!" << endl;
            } else {
                cout << "Failed to add axolotl!" << endl;
            }

            break;
        }

        // Delete axolotl
        case 2: {
            string name = this->readString("Name: ");
            int index = this->controller.searchAxolotl(name);
            if (index == -1) {
                cout << "Could not find axolotl with given name!" << endl;
                break;
            } else {
                // TODO make this more efficient, it SUCKS right now
                //FileManager::exportAsHTML(this->controller.getVector());
                textFileManager->writeToFile(this->controller.getVector(), "outfilevectorall.txt");

                this->controller.deleteAxolotl(index);
                cout << "Axolotl with name " << name << " deleted successfully!" << endl;
            }

            break;
        }

        // Update axolotl
        case 3: {
            string name = this->readString("Name: ");
            int index = this->controller.searchAxolotl(name);
            if (index == -1) {
                cout << "Could not find axolotl with given name!" << endl;
            } else {
                int breed = this->readInt("Breed (0, 1, 2): ");
                name = this->readString("Name: ");
                int age = this->readInt("Age (1-99): ");
                string photo = this->readString("Link to photograph: ");

                try {
                    this->controller.updateAxolotl(index, breed, name, age, photo);

                    // TODO make this more efficient, it SUCKS right now
                    //FileManager::exportAsHTML(this->controller.getVector());
                    textFileManager->writeToFile(this->controller.getVector(), "outfilevectorall.txt");

                    cout << "Information successfully updated!" << endl;
                } catch (const char* msg) {
                    cout << msg << endl;
                }
            }
            break;
        }

        // Display all axolotls
        case 4: {
            this->displayList(this->controller.getVector());
            break;
        }

        default: {
            cout << "Unknown option entered!" << endl;
            break;
        }
    }

    return 0;
}

int UserInterface::handleUserOptions(int option) {
    switch (option) {
        case 0: {
            return -1;
        }

        // Display all available axolotls and let the user choose
        // If they want to adopt an axolotl or not
        case 1: {
            this->displayEachPet();
            break;
        }

        // Display axolotls of a given breed and age < input age
        case 2: {
            int targetBreed = this->readInt("Target breed (0, 1, 2): ");
            int targetAge = this->readInt("Target age (age less than): ");
            vector<Axolotl> vec = this->controller.buildFilteredVector(targetBreed, targetAge);
            this->displayList(vec);
            break;
        }

        // Display the user's adoption list
        case 3: {
            option = this->readInt("1. Display text file\n2. Display HTML file\n");
            if (option == 1) {
                system("gedit /home/sysadmin/CLionProjects/lab5-6/cmake-build-debug/outfile.txt");
            } else if (option == 2) {
                system("xdg-open /home/sysadmin/CLionProjects/lab5-6/cmake-build-debug/outfile.html");
            } else {
                cout << "Unknown option entered!" << endl;
            }
            break;
        }

        default: {
            cout << "Unknown option entered!" << endl;
            break;
        }
    }

    return 0;
}

/*
 * Present each pet, one by one, and let the user choose
 * to adopt one or more pets
 */
void UserInterface::displayEachPet() {
    for (int i = 0; i < this->controller.getVector().size(); ++i) {
        auto pet = this->controller.getVector()[i];
        cout << pet.getName() << " - " << pet.getAge() << " - " << Axolotl::getStringFromBreed(pet.getBreed()) << " - " << pet.getPhoto() << endl;

        int option = this->readInt("0.Exit\n1. Adopt\n2. Next pet\n");
        if (option == 0) {
            break;
        } else if (option == 1) {
            this->controller.addAxolotl(this->controller.getUserAdoptionVector(), Axolotl::getIntFromBreed(pet.getBreed()), pet.getName(), pet.getAge(), pet.getPhoto());
        }

        // Start from the beginning if we reach the end of the list
        // -1 so we don't skip the first pet, because in the next loop ++i will be executed
        // and i will be equal to 0
        if (i == this->controller.getVector().size() - 1) {
            i = -1;
        }
    }

    FileManager* textFileManager = new TextFileManager();
    FileManager* _HTMLFileManager = new HTMLFileManager();
    textFileManager->writeToFile(this->controller.getUserAdoptionVector(), "outfile.txt");
    _HTMLFileManager->writeToFile(this->controller.getUserAdoptionVector(), "outfile.html");
}

void UserInterface::displayList(const vector<Axolotl> &vec) {
    for (const auto& axolotl : vec) {
        cout << axolotl;
    }
}
