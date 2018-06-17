//
// Created by sysadmin on 17.06.2018.
//

#ifndef OOP_WRITTEN_S3_MENUBAR_HPP
#define OOP_WRITTEN_S3_MENUBAR_HPP


#include "Menu.hpp"

class MenuBar {
    public:
        void add(const Menu &menu);
        void print();

    private:
        vector<Menu> menus;
};


#endif //OOP_WRITTEN_S3_MENUBAR_HPP
