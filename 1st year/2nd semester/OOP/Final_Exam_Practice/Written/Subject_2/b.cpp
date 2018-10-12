#include <iostream>

using namespace std;

class Ex1 {
public:
    Ex1() {
        cout << "Exception 1 ";
    }

    Ex1(const Ex1 &ex) {
        cout << "Copy_ex1 ";
    }
};

class Ex2 : public Ex1 {
public:
    Ex2() {
        cout << "Exception 2 ";
    }

    Ex2(const Ex2 &ex) {
        cout << "Copy_exc2 ";
    }
};

void except(int x) {
    if (x < 0) {
        throw Ex1{};
    } else if (x == 0) {
        throw Ex2{};
    }

    cout <<  "Done ";
}

int main() {
    try {
        cout << "Start: ";
        try {
            except(0);
        } catch (Ex1 &e) {}

        except(-2);
        // If we have Ex1 &e => no Copy_ex1
        // Like that, Copy_ex1 is being printed too, because the copy constructor is called
    } catch (Ex1 e) {}

    return 0;
}