#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QCoreApplication>
#include <QListView>
#include <QStringListModel>
#include <string>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QTextEdit>
#include <QListWidget>
#include <QSortFilterProxyModel>
#include <QTableView>

#include "FileManager.h"
#include "Axolotl.h"
#include "CustomTableModel.h"

MainWindow::MainWindow(Controller &ctrl, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ctrl(ctrl)
{
    ui->setupUi(this);

    this->ok1 = false;
    this->ok2 = false;

    //this->ctrl = Controller(true);

    this->mainWidget = new QWidget(this);
    QPushButton *admin = new QPushButton(mainWidget);
    admin->setText(tr("Admin login"));
    admin->setGeometry(QRect(QPoint(100, 50), QSize(200, 50)));
    //setCentralWidget(mainWidget);

    QPushButton *user = new QPushButton(mainWidget);
    user->setText("User login");
    user->setGeometry(QRect(QPoint(100, 125), QSize(200, 50)));
    setCentralWidget(mainWidget);

    connect(admin, &QPushButton::clicked, this, [this]() {
        QWidget* wdg = this->initAdminGUI();
        wdg->show();
    });

    connect(user, &QPushButton::clicked, this, [this]() {
        QWidget* wdg = this->initUserGUI();
        wdg->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

QWidget* MainWindow::initAdminGUI() {
    QWidget* wdg = new QWidget();
    //wdg->setGeometry(100, 150, 800, 800);
    wdg->setFixedSize(800, 800);

    QListView* lv = this->buildListViewFromVector(wdg, this->ctrl.getVector());
    lv->setGeometry(QRect(QPoint(0, 0), QSize(350, 200)));

    // for testing purposes
    //QListWidget *lw = new QListWidget(wdg);
    //lw->setGeometry(0, 0, 350, 200);
    //lw->addItem("1");
    //lw->items(0)->setFont(QFont("Verdana", -1, 600, false));

    FileManager* TFM = new TextFileManager();

    ////////////////////////////////////////////

    QPlainTextEdit *breed = new QPlainTextEdit(wdg);
    breed->document()->setPlainText("Breed (0, 1, 2)");
    breed->setGeometry(QRect(QPoint(25, 275), QSize(200, 26)));

    QPlainTextEdit *name = new QPlainTextEdit(wdg);
    name->document()->setPlainText("Name");
    name->setGeometry(QRect(QPoint(25, 275 + 25), QSize(200, 26)));

    QPlainTextEdit *age = new QPlainTextEdit(wdg);
    age->document()->setPlainText("Age (0-99)");
    age->setGeometry(QRect(QPoint(25, 275 + 50), QSize(200, 26)));

    QPlainTextEdit *photo = new QPlainTextEdit(wdg);
    photo->document()->setPlainText("Link to photo (no spaces)");
    photo->setGeometry(QRect(QPoint(25, 275 + 75), QSize(200, 26)));

    ////////////////////////////////////////////

    QPushButton *undoBtn = new QPushButton(wdg);
    undoBtn->setText("Undo");
    undoBtn->setGeometry(QRect(QPoint(80 + 200, 255), QSize(50, 50)));

    connect(undoBtn, &QPushButton::clicked, this, [this, lv, TFM]() {
        this->ctrl.undo();
        lv->setModel(this->buildModelFromVector(this->ctrl.getVector()));
        TFM->writeToFile(this->ctrl.getVector(), "/home/sysadmin/OOP/outfilevectorall.txt");
    });

    ////////////////////////////////////////////

    QPushButton *redoBtn = new QPushButton(wdg);
    redoBtn->setText("Redo");
    redoBtn->setGeometry(QRect(QPoint(80 + 200, 255 + 50), QSize(50, 50)));

    connect(redoBtn, &QPushButton::clicked, this, [this, lv, TFM]() {
        this->ctrl.redo();
        lv->setModel(this->buildModelFromVector(this->ctrl.getVector()));
        TFM->writeToFile(this->ctrl.getVector(), "/home/sysadmin/OOP/outfilevectorall.txt");
    });

    QPushButton *newBtn = new QPushButton(wdg);
    newBtn->setText("New");
    newBtn->setGeometry(QRect(QPoint(80 + 0, 205), QSize(50, 50)));

    connect(newBtn, &QPushButton::clicked, this, [TFM, wdg, lv, breed, name, age, photo, this]() {
        cout << this->ctrl.getVector().size() << endl;
        this->ctrl.addAxolotl(this->ctrl.getVector(), stoi(breed->toPlainText().toUtf8().constData()), name->toPlainText().toUtf8().constData(), stoi(age->toPlainText().toUtf8().constData()), photo->toPlainText().toUtf8().constData());

        cout << this->ctrl.getVector().size() << endl;

        lv->setModel(this->buildModelFromVector(this->ctrl.getVector()));

        //lv = this->buildListViewFromVector(wdg, this->ctrl.getVector());
        //lv->show();

        TFM->writeToFile(this->ctrl.getVector(), "/home/sysadmin/OOP/outfilevectorall.txt");
    });

    ////////////////////////////////////////////

    QPushButton *delBtn = new QPushButton(wdg);
    delBtn->setText("Delete");
    delBtn->setGeometry(QRect(QPoint(80 + 75, 205), QSize(50, 50)));

    connect(delBtn, &QPushButton::clicked, this, [TFM, wdg, lv, this]() {
        //cout << this->ctrl.getVector().size() << endl;

        QModelIndex index = lv->currentIndex();
        ctrl.deleteAxolotl(index.row());
        lv->setModel(this->buildModelFromVector(this->ctrl.getVector()));

        //cout << this->ctrl.getVector().size() << endl;
        //this->buildListViewFromVector(wdg, this->ctrl.getVector());
        //lv->show();

        TFM->writeToFile(this->ctrl.getVector(), "/home/sysadmin/OOP/outfilevectorall.txt");
    });

    ////////////////////////////////////////////

    QPushButton *updBtn = new QPushButton(wdg);
    updBtn->setText("Update");
    updBtn->setGeometry(QRect(QPoint(80 + 150, 205), QSize(50, 50)));

    connect(updBtn, &QPushButton::clicked, this, [TFM, wdg, lv, breed, age, name, photo, this]() {
        //cout << this->ctrl.getVector().size() << endl;

        QModelIndex index = lv->currentIndex();
        ctrl.updateAxolotl(index.row(), stoi(breed->toPlainText().toUtf8().constData()), name->toPlainText().toUtf8().constData(), stoi(age->toPlainText().toUtf8().constData()), photo->toPlainText().toUtf8().constData());
        lv->setModel(this->buildModelFromVector(this->ctrl.getVector()));

        //cout << this->ctrl.getVector().size() << endl;
        //this->buildListViewFromVector(wdg, this->ctrl.getVector());
        //lv->show();

        TFM->writeToFile(this->ctrl.getVector(), "/home/sysadmin/OOP/outfilevectorall.txt");
    });


    ////////////////////////////////////////////

    return wdg;
}

QStringListModel* MainWindow::buildModelFromVector(const vector<Axolotl> &vec) {
    QStringListModel *model = new QStringListModel(this);
    QStringList list;
    // Show data to QListView
    for (int i = 0; i < vec.size(); ++i) {
        //string x = vec[i];
        //list << vec[i];
        //cout << vec[i];
        string currAxolotl = vec[i].getName() + " - " + to_string(vec[i].getAge()) + " - " + Axolotl::getStringFromBreed(vec[i].getBreed()) + " - " + vec[i].getPhoto();
        list << currAxolotl.c_str();
    }

    model->setStringList(list);

    return model;
}

QListView* MainWindow::buildListViewFromVector(QWidget *wdg, const vector<Axolotl> &vec) {
    QListView *listView = new QListView(wdg);
    QStringListModel *model = new QStringListModel(this);
    QStringList list;

    // Make QListView non editable
    listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //vector<Axolotl> vec;
    //data->loadFromFile(vec);

    // Show data to QListView
    for (int i = 0; i < vec.size(); ++i) {
        string currAxolotl = vec[i].getName() + " - " + to_string(vec[i].getAge()) + " - " + Axolotl::getStringFromBreed(vec[i].getBreed()) + " - " + vec[i].getPhoto();
        list << currAxolotl.c_str();
    }

    model->setStringList(list);
    listView->setModel(model);

    return listView;
}

QWidget* MainWindow::initUserGUI() {
    QWidget* wdg = new QWidget();
    //wdg->setGeometry(100, 150, 800, 800);
    wdg->setFixedSize(1200, 1200);

    // all pets
    QListView* lv = this->buildListViewFromVector(wdg, this->ctrl.getVector());
    lv->setGeometry(QRect(QPoint(0, 0), QSize(350, 200)));

    // my list of adoptions
    QListView* adoptionsLV = this->buildListViewFromVector(wdg, this->ctrl.getUserAdoptionVector());
    adoptionsLV->setGeometry(QRect(QPoint(300, 0), QSize(350, 200)));

    QTableView *tableView = new QTableView(wdg);
    tableView->setGeometry(QRect(QPoint(500, 500), QSize(420, 200)));
    CustomTableModel *tableModel = new CustomTableModel(this->ctrl);
    tableView->setModel(tableModel);

    //connect(tableView, &QTableView::entered, this, [this, tableView]() {
    //    CustomTableModel *tableModel = new CustomTableModel(this->ctrl);
    //    tableView->setModel(tableModel);
    //});

    // filtered list
    QListView* filteredLV = this->buildListViewFromVector(wdg, this->ctrl.getVector());
    filteredLV->setGeometry(QRect(QPoint(300, 200), QSize(350, 200)));

    QListView *liveFilteredLV = this->buildListViewFromVector(wdg, this->ctrl.getVector());
    liveFilteredLV->setGeometry(QRect(QPoint(25, 500), QSize(350, 200)));

    FileManager* TFM = new TextFileManager();
    FileManager* HTMLFM = new HTMLFileManager();

    ////////////////////////////////////////////

    // For filtering
    QPlainTextEdit *breed = new QPlainTextEdit(wdg);
    breed->document()->setPlainText("Breed (0, 1, 2)");
    breed->setGeometry(QRect(QPoint(25, 275), QSize(200, 26)));

    QPlainTextEdit *age = new QPlainTextEdit(wdg);
    age->document()->setPlainText("Age less than (0-99)");
    age->setGeometry(QRect(QPoint(25, 275 + 50), QSize(200, 26)));

    QPlainTextEdit *liveFilter = new QPlainTextEdit(wdg);
    //liveFilter->setPlainText();
    liveFilter->setGeometry(QRect(QPoint(25, 450), QSize(200, 26)));

    connect(liveFilter, &QPlainTextEdit::textChanged, this, [liveFilter, liveFilteredLV, this](){
        liveFilteredLV->setModel(this->buildModelFromVector(this->ctrl.filterByNameStartingWith(liveFilter->toPlainText().toUtf8().constData())));
    });


    ////////////////////////////////////////////

    QPushButton *adoptBtn = new QPushButton(wdg);
    adoptBtn->setText("Adopt");
    adoptBtn->setGeometry(QRect(QPoint(80 + 0, 205), QSize(50, 50)));

    connect(lv, &QListView::clicked, this, [filteredLV, lv, this](){
        filteredLV->selectionModel()->clearSelection();
        this->ok1 = true;
        this->ok2 = false;
    });

    connect(filteredLV, &QListView::clicked, this, [lv, this](){
        lv->selectionModel()->clearSelection();
        this->ok1 = false;
        this->ok2 = true;
    });

    connect(adoptBtn, &QPushButton::clicked, this, [tableView, TFM, HTMLFM, lv, adoptionsLV, filteredLV, breed, age, this]() {
        QModelIndex index = lv->currentIndex();
        if (true == this->ok1) {
        auto ax = this->ctrl.getVector()[index.row()];
        this->ctrl.addAxolotl(this->ctrl.getUserAdoptionVector(), Axolotl::getIntFromBreed(ax.getBreed()), ax.getName(), ax.getAge(), ax.getPhoto());
        }

        index = filteredLV->currentIndex();
        if (true == this->ok2) {
            auto ax = this->ctrl.buildFilteredVector(stoi(breed->toPlainText().toUtf8().constData()), stoi(age->toPlainText().toUtf8().constData()))[index.row()];
            this->ctrl.addAxolotl(this->ctrl.getUserAdoptionVector(), Axolotl::getIntFromBreed(ax.getBreed()), ax.getName(), ax.getAge(), ax.getPhoto());
        }

        adoptionsLV->setModel(this->buildModelFromVector(this->ctrl.getUserAdoptionVector()));

        TFM->writeToFile(this->ctrl.getUserAdoptionVector(), "/home/sysadmin/OOP/outfile.txt");
        HTMLFM->writeToFile(this->ctrl.getUserAdoptionVector(), "/home/sysadmin/OOP/outfile.html");

        CustomTableModel *tableModel = new CustomTableModel(this->ctrl);
        tableView->setModel(tableModel);
    });

    ////////////////////////////////////////////

    QPushButton *filterBtn = new QPushButton(wdg);
    filterBtn->setText("Filter");
    filterBtn->setGeometry(QRect(QPoint(80 + 75, 205), QSize(50, 50)));

    connect(filterBtn, &QPushButton::clicked, this, [filteredLV, breed, age, this]() {
        filteredLV->setModel(this->buildModelFromVector(this->ctrl.buildFilteredVector(stoi(breed->toPlainText().toUtf8().constData()), stoi(age->toPlainText().toUtf8().constData()))));
    });

    return wdg;
}

