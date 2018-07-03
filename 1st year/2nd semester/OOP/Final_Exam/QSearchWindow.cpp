#include "QSearchWindow.h"
#include "ui_qsearchwindow.h"

QSearchWindow::QSearchWindow(Session &s, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QSearchWindow),
    s{s}
{
    ui->setupUi(this);
    s.registerObserver(this);
    this->setWindowTitle("Search a question");
    this->setFixedSize(500, 500);

    searchTextEdit = new QPlainTextEdit(this);
    searchTextEdit->setGeometry(0, 0, 300, 30);

    lw = new QListWidget(this);
    lw->setGeometry(0, 50, 500, 400);
    for (const auto &q : s.getQuestions()) {
        lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));
    }

    connect(searchTextEdit, &QPlainTextEdit::textChanged, this, [this](){
        this->lw->clear();
        this->lwItems.clear();
        string input = this->searchTextEdit->toPlainText().toUtf8().constData();
       /* for (const auto &q : this->s.sortByMatchingCharacters(input)) {
            lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));
        }*/

        // Show top 3 answers after the top matching question
        for (int i = 0; i < this->s.sortByMatchingCharacters(input).size(); ++i) {
            if (i == 0) {
                auto q = this->s.sortByMatchingCharacters(input)[i];
                lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));

                for (int j = 0; j < this->s.getTopThreeAnswers(q.getId()).size(); ++j) {
                    string itemStr = "\t" + this->s.getTopThreeAnswers(q.getId())[j].toString();
                    lwItems.emplace_back(new QListWidgetItem(itemStr.c_str(), lw));
                }
            } else {
                auto q = this->s.sortByMatchingCharacters(input)[i];
                lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));
            }
        }
    });
}

QSearchWindow::~QSearchWindow()
{
    delete ui;
    s.unregisterObserver(this);
}

void QSearchWindow::update() {
    lw->clear();
    lwItems.clear();
    for (const auto &q : s.getQuestions()) {
        lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));
    }
}
