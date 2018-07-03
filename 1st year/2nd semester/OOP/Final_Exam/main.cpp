#include "mainwindow.h"
#include <QApplication>
#include "Session.h"
#include "Repository.h"
#include "QSearchWindow.h"
#include "RunTests.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RunTests::runTests();

    Session s;
    Repository repo(s);

    for (const auto &user : repo.getUsers()) {
        user->show();
    }

    QSearchWindow searchWnd(s);
    searchWnd.show();

    return a.exec();
}
