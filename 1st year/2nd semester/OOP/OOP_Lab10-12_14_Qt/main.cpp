#include "mainwindow.h"
#include <QApplication>
#include "Controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller ctrl(true);
    MainWindow w(ctrl);
    w.setFixedSize(400, 300);
    w.show();

    return a.exec();
}
