#include "participantwnd.h"
#include "ui_participantwnd.h"

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

    for (const auto &q : this->qs.getQuestions()) {
        lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));
    }

}

ParticipantWnd::~ParticipantWnd()
{
    qs.unregisterObserver(this);
    delete ui;
}

void ParticipantWnd::update() {
    lw->clear();
    lwItems.clear();
    for (const auto &q : this->qs.getQuestions()) {
        lwItems.emplace_back(new QListWidgetItem(q.toString().c_str(), lw));
    }
}
