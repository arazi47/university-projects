#include "MainWindow.h"
#include <QApplication>
#include "QuizSession.h"
#include "presenterwnd.h"
#include "participantwnd.h"
#include "Repository.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    QuizSession qs;
    Repository repo(qs);

    PresenterWnd pwnd(qs);
    pwnd.show();


    for (const auto &plr : repo.getPlayers()) {
        plr->show();
    }


    return a.exec();
}
