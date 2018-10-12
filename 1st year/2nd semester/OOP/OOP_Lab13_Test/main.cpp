#include "MainWindow.h"
#include <QApplication>
#include <fstream>
#include <iostream>
#include <QDir>
#include "Tester.h"

int main(int argc, char *argv[])
{
    Tester::TestNumberOfCars();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
