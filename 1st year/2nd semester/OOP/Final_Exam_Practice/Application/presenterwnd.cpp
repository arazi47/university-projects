#include "presenterwnd.h"
#include "ui_presenterwnd.h"

#include <iostream>
using namespace std;

PresenterWnd::PresenterWnd(QuizSession &qs, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PresenterWnd),
    qs(qs)
{
    ui->setupUi(this);
    this->setWindowTitle("Presenter");
    this->setFixedSize(500, 500);

    lw = new QListWidget(this);
    lw->setGeometry(0, 0, 500, 300);

    for (const auto &q : qs.getQuestions()) {
        lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));
    }


    newQId = new QPlainTextEdit(this);
    newQId->setGeometry(0, 300, 150, 30);
    newQId->setPlaceholderText("Question ID");

    newQText = new QPlainTextEdit(this);
    newQText->setGeometry(0, 330, 150, 30);
    newQText->setPlaceholderText("Question text");

    newQAnswer = new QPlainTextEdit(this);
    newQAnswer->setGeometry(0, 360, 150, 30);
    newQAnswer->setPlaceholderText("Question answer");

    newQScore = new QPlainTextEdit(this);
    newQScore->setGeometry(0, 390, 150, 30);
    newQScore->setPlaceholderText("Question score");

    addNewQBtn = new QPushButton(this);
    addNewQBtn->setGeometry(0, 420, 150, 30);
    addNewQBtn->setText("Add question");

    connect(addNewQBtn, &QPushButton::clicked, this, [this](){
        auto newQ = Question(stoi(newQId->toPlainText().toUtf8().constData()), newQText->toPlainText().toUtf8().constData(), newQAnswer->toPlainText().toUtf8().constData(), stoi(newQScore->toPlainText().toUtf8().constData()));
        this->qs.addQuestion(newQ);
        this->lwItems.emplace_back(new QListWidgetItem(newQ.toString().c_str(), lw));
    });
}

PresenterWnd::~PresenterWnd()
{
    delete ui;
}
