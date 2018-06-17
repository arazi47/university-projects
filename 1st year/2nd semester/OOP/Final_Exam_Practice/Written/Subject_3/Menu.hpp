//
// Created by sysadmin on 17.06.2018.
//

#ifndef OOP_WRITTEN_S3_MENU_HPP
#define OOP_WRITTEN_S3_MENU_HPP


#include "MenuItem.hpp"
#include <vector>

using std::vector;

class Menu : public MenuItem {
    public:
        Menu() : MenuItem("", nullptr) {}
        Menu(const string &text, Action *action) : MenuItem(text, action), text(text) {}

        void add(const MenuItem &menuItem);
        void print() const override;

    private:
        vector<MenuItem> menuItems;
        string text;
};


#endif //OOP_WRITTEN_S3_MENU_HPP
