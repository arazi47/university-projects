//
// Created by sysadmin on 17.06.2018.
//

#ifndef OOP_WRITTEN_S3_MENUITEM_HPP
#define OOP_WRITTEN_S3_MENUITEM_HPP

#include <iostream>
#include <string>
#include "Action.hpp"

using std::cout;
using std::endl;
using std::string;

class MenuItem {
    public:
        explicit MenuItem(const string &text, Action *action) : text{text}, action{action} {}

        virtual void print() const;
        void clicked();

    private:
        string text;
        Action *action;
};


#endif //OOP_WRITTEN_S3_MENUITEM_HPP
