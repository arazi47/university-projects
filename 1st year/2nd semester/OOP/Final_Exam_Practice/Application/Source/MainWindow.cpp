#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include "QuizSession.h"
#include "presenterwnd.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QWidget *adminWdg = new QWidget();
    /*
    vector<QWidget*> playerWidgets;
    for (int i = 0; i < repo.getPlayerCount(); ++i) {
        playerWidgets.emplace_back(new QWidget());
        playerWidgets.back()->setWindowTitle(repo.getPlayers()[i].getName().c_str());
        playerWidgets.back()->show();
    }
    */

    //PresenterWnd pwnd(qs);
    //pwnd.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
