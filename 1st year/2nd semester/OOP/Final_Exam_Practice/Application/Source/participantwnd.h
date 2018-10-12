#ifndef PARTICIPANTWND_H
#define PARTICIPANTWND_H

#include <QWidget>
#include "Observer.h"
#include <string>
#include <vector>
#include <QListWidget>
#include <QListWidgetItem>
#include "QuizSession.h"
#include <QPushButton>
#include <QPlainTextEdit>

using std::string;
using std::vector;

namespace Ui {
class ParticipantWnd;
}

class ParticipantWnd : public QWidget, public Observer
{
    Q_OBJECT

public:
    ParticipantWnd(QuizSession &qs, const string name, QWidget *parent = 0);
    ~ParticipantWnd();

    const string getName() const { return this->name; }

    void update() override;

private:
    Ui::ParticipantWnd *ui;
    string name;
    QuizSession &qs;

    vector<QListWidgetItem*> lwItems;
    vector<int> solvedQuestions;

    QListWidget* lw;
    int score;

    QPlainTextEdit *answerTextEdit;
    QPushButton *submitAnswerBtn;
};

#endif // PARTICIPANTWND_H
