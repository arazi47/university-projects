#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QWidget>
#include "Axolotl.h"
#include <QListView>
#include "Controller.h"
#include <QStringListModel>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QWidget* initAdminGUI();
    QWidget* initUserGUI();

    QListView* buildListViewFromVector(QWidget *wdg, const vector<Axolotl> &vec);
    QStringListModel* buildModelFromVector(const vector<Axolotl> &vec);

private slots:

private:
    Ui::MainWindow *ui;

    QWidget* mainWidget;

    Controller ctrl;

    bool ok1;
    bool ok2;
};

#endif // MAINWINDOW_H
