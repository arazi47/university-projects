#include <iostream>
#include "MenuBar.hpp"

int main() {
    MenuBar menuBar;
    Menu fileMenu("File menu", nullptr);
    Menu aboutMenu("About menu", nullptr);

    Menu newSubmenu("New submenu", nullptr);
    Menu exitSubmenu("Exit submenu", new ExitAction);

    fileMenu.add(newSubmenu);
    fileMenu.add(exitSubmenu);

    Menu textSubmenu("Text submenu", new CreateAction);
    Menu cppSubmenu("CPP Submenu", new CreateAction);

    newSubmenu.add(textSubmenu);
    newSubmenu.add(cppSubmenu);

    menuBar.add(fileMenu);
    menuBar.add(aboutMenu);

    menuBar.print();
    cout << "\n\n";

    // Simulate File -> New -> C++, then exit
    fileMenu.clicked();
    cout << "\n";
    newSubmenu.clicked();
    cout << "\n";
    cppSubmenu.clicked();

    exitSubmenu.clicked();

    return 0;
}