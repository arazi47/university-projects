#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "FileManager.h"
#include <QListWidget>
#include "Controller.h"
#include <QPushButton>
#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *mainWidget = new QWidget(this);
    this->setFixedSize(500, 500);
    setCentralWidget(mainWidget);

    QListWidget *lw = new QListWidget(mainWidget);
    lw->setGeometry(QRect(QPoint(0, 0), QSize(300, 300)));

    vector<QListWidgetItem*> lwItems;
    for (const auto& car : controller.getVectorSortedByManufacturer()) {
        //lw->addItem(car.toString().c_str());
        lwItems.push_back(new QListWidgetItem(car.toString().c_str(), lw));

        if (car.getColor() == "black") {
            lwItems.back()->setBackground(QBrush(QColor(Qt::GlobalColor::black)));
        } else if (car.getColor() == "blue") {
            lwItems.back()->setBackground(QBrush(QColor(Qt::GlobalColor::blue)));
        } else if (car.getColor() == "red") {
            lwItems.back()->setBackground(QBrush(QColor(Qt::GlobalColor::red)));
        } else if (car.getColor() == "yellow") {
            lwItems.back()->setBackground(QBrush(QColor(Qt::GlobalColor::yellow)));
        } else if (car.getColor() == "green") {
            lwItems.back()->setBackground(QBrush(QColor(Qt::GlobalColor::green)));
        }
    }

    QPlainTextEdit *manufacturer = new QPlainTextEdit(mainWidget);
    manufacturer->setGeometry(QRect(QPoint(0, 320), QSize(200, 30)));

    QPushButton *showNumBtn = new QPushButton(mainWidget);
    showNumBtn->setText("Display number");
    showNumBtn->setGeometry(QRect(QPoint(0, 355), QSize(100, 35)));

    connect(showNumBtn, &QPushButton::clicked, this, [this, manufacturer]() {
        string filterData = manufacturer->toPlainText().toUtf8().constData();
        manufacturer->document()->setPlainText(to_string(controller.getNumberOfCarsFilteredByName(filterData)).c_str());
    });

    mainWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}







