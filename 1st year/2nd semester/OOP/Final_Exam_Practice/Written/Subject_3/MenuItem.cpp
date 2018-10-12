//
// Created by sysadmin on 17.06.2018.
//

#include "MenuItem.hpp"


void MenuItem::print() const {
    cout << text << endl;
}

void MenuItem::clicked() {
    print();

    if (action != nullptr)
        action->execute();
}
