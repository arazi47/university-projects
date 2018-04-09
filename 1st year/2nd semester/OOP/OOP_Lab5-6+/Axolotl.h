//
// Created by sysadmin on 23.03.2018.
//

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

        Axolotl();
        Axolotl(Breed breed, string name, int age, string photograph);
        ~Axolotl();

        Breed getBreed();
        string getName();
        int getAge();
        string getPhoto();

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


#endif //LAB5_6_AXOLOTL_H
