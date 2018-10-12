//
// Created by sysadmin on 23.03.2018.
//

#include <fstream>
#include <string>

using namespace std;


#ifndef LAB5_6_AXOLOTL_H
#define LAB5_6_AXOLOTL_H

class Axolotl {
    public:
        enum Breed {
            BREED_0,
            BREED_1,
            BREED_2
        };

        // This is needed to initialize an array of Axolotls in class DynamicArray
        Axolotl() = default;
        Axolotl(Breed breed, string name, int age, string photograph);
        ~Axolotl() = default;

        Breed getBreed() const;
        string getName() const;
        int getAge() const;
        string getPhoto() const;

        void setBreed(Breed breed);
        void setName(string name);
        void setAge(int age);
        void setPhoto(string photo);

        static Axolotl::Breed getBreedFromInt(int breed);
        static string getStringFromBreed(Breed breed);
        static int getIntFromBreed(Breed breed);

    private:
        Breed breed;
        string name;
        int age;
        string photograph;
};

istream& operator >> (istream& in, Axolotl& axolotl);
ostream& operator << (ostream& out, const Axolotl& axolotl);

#endif //LAB5_6_AXOLOTL_H
