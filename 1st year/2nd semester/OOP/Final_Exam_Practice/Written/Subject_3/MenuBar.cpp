//
// Created by sysadmin on 17.06.2018.
//

#include "MenuBar.hpp"

void MenuBar::add(const Menu &menu) {
    menus.push_back(menu);
}

void MenuBar::print() {
    for (const auto &menu : menus) {
        menu.print();
    }
}
