//
// Created by sysadmin on 17.06.2018.
//

#include "Menu.hpp"

void Menu::add(const MenuItem &menuItem) {
    menuItems.push_back(menuItem);
}

void Menu::print() const {
    cout << text << endl;
    for (const auto &item : menuItems) {
        item.print();
    }
}
