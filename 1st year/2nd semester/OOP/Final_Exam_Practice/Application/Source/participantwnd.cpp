#include "participantwnd.h"
#include "ui_participantwnd.h"
#include <QModelIndex>

ParticipantWnd::ParticipantWnd(QuizSession &qs, const string name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParticipantWnd),
    name(name),
    qs(qs)
{
    ui->setupUi(this);
    qs.registerObserver(this);

    this->setWindowTitle(this->getName().c_str());
    this->setFixedSize(500, 500);

    lw = new QListWidget(this);
    lw->setGeometry(0, 0, 500, 300);
    this->score = 0;

    for (const auto &q : this->qs.getQuestions()) {
        lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));
        solvedQuestions.push_back(false);
    }

    answerTextEdit = new QPlainTextEdit(this);
    answerTextEdit->setGeometry(0, 300, 150, 300);
    answerTextEdit->setPlaceholderText("Answer");

    submitAnswerBtn = new QPushButton(this);
    submitAnswerBtn->setGeometry(150, 300, 150, 30);
    submitAnswerBtn->setText("Submit answer");

    connect(submitAnswerBtn, &QPushButton::clicked, this, [this](){
        string inputAnswer = answerTextEdit->toPlainText().toUtf8().constData();

        // Get selected question from the list
        QModelIndex index = this->lw->currentIndex();

        //printf("index %d\n", index.row());
        //printf("input ans %s\n", inputAnswer.c_str());
        //printf("correct ans %s\n", this->qs.getQuestions()[index.row()].getAnswer().c_str());

        // Correct answer
        if (this->qs.getQuestions()[index.row()].getAnswer() == inputAnswer) {
            this->score += this->qs.getQuestions()[index.row()].getScore();

            string newWindowTitle = this->getName() + " - Score: " + to_string(this->score);
            this->setWindowTitle(newWindowTitle.c_str());

            this->answerTextEdit->clear();

            this->lwItems[index.row()]->setBackground(QBrush(QColor(Qt::GlobalColor::green)));
            this->solvedQuestions[index.row()] = true;
            this->submitAnswerBtn->setEnabled(false);
        }
    });

    connect(lw, &QListWidget::clicked, this, [this](){
        QModelIndex index = this->lw->currentIndex();
        if (this->solvedQuestions[index.row()]) {
            this->submitAnswerBtn->setEnabled(false);
        } else {
            this->submitAnswerBtn->setEnabled(true);
        }
    });
}

ParticipantWnd::~ParticipantWnd()
{
    qs.unregisterObserver(this);
    delete ui;
}

void ParticipantWnd::update() {
    //lw->clear();
    //lwItems.clear();
    //for (const auto &q : this->qs.getQuestions()) {
    //    lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));
    //}

    lwItems.emplace_back(new QListWidgetItem(this->qs.getQuestions().back().toString().c_str(), lw));
}
