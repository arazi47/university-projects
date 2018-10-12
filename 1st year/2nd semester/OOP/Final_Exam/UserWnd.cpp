#include "UserWnd.h"
#include "ui_userwnd.h"
#include <iostream>

using namespace std;

UserWnd::UserWnd(string name, Session &s, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWnd),
    name{name},
    s{s}
{
    ui->setupUi(this);
    s.registerObserver(this);
    this->setWindowTitle(name.c_str());
    this->setFixedSize(800, 500);

    lw = new QListWidget(this);
    lw->setGeometry(0, 0, 500, 200);
    for (const auto &q : s.getQuestions()) {
        lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));
    }

    newQuestionText = new QPlainTextEdit(this);
    newQuestionText->setPlaceholderText("Question text");
    newQuestionText->setGeometry(0, 200, 250, 250);

    addQuestionBtn = new QPushButton(this);
    addQuestionBtn->setText("Add question");
    addQuestionBtn->setGeometry(250, 200, 250, 50);

    connect(addQuestionBtn, &QPushButton::clicked, this, [this](){
        string questionText = this->newQuestionText->toPlainText().toUtf8().constData();
       /* if (!questionText.empty()) {
            this->s.addQuestion(questionText, this->name);
        }
        else {
            throw std::runtime_error("Question text cannot be empty!");
        }*/

        try {
            this->s.addQuestion(questionText, this->name);
        } catch (std::runtime_error &e) {
            cout << e.what() << endl;
        }
    });

    answersLW = new QListWidget(this);
    answersLW->setGeometry(500, 0, 300, 300);

    connect(lw, &QListWidget::clicked, this, [this](){
        QModelIndex index = this->lw->currentIndex();
        this->answersLW->clear();
        this->answersLwItems.clear();

        for (const auto &ans : this->s.getAnswersForQuestion(this->s.getQuestions()[index.row()].getId())) {
            answersLwItems.push_back(new QListWidgetItem(ans.toString().c_str(), this->answersLW));
            if (ans.getCreator() == this->name) {
                answersLwItems.back()->setBackground(QBrush(QColor(Qt::GlobalColor::yellow)));
            }
        }
    });

    addAnswerBtn = new QPushButton(this);
    addAnswerBtn->setText("Add answer");
    addAnswerBtn->setGeometry(250, 250, 250, 50);

    newAnswerText = new QPlainTextEdit(this);
    newAnswerText->setPlaceholderText("Answer text");
    newAnswerText->setGeometry(250, 300, 550, 150);

    connect (addAnswerBtn, &QPushButton::clicked, this, [this]() {
        QModelIndex index = this->lw->currentIndex();
        string answerText = this->newAnswerText->toPlainText().toUtf8().constData();
        int questionId = this->s.getQuestions()[index.row()].getId();
        try {
            this->s.addAnswer(questionId, answerText, this->name);
        } catch (std::runtime_error &e) {
            cout << e.what() << endl;
        }
    });
}

UserWnd::~UserWnd()
{
    delete ui;
    s.unregisterObserver(this);
}

void UserWnd::update() {
    lw->clear();
    lwItems.clear();
    for (const auto &q : s.getQuestions()) {
        lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));
    }
}
