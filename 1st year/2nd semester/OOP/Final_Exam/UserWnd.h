#ifndef USERWND_H
#define USERWND_H

#include <QWidget>
#include "Observer.h"
#include <QListWidget>
#include <QListWidgetItem>
#include "Session.h"
#include <QPushButton>
#include <QPlainTextEdit>

namespace Ui {
class UserWnd;
}

class UserWnd : public QWidget, public Observer
{
    Q_OBJECT

public:
    UserWnd(string name, Session &s, QWidget *parent = 0);
    ~UserWnd();

    void update() override;

private:
    Ui::UserWnd *ui;
    string name;
    Session &s;

    QListWidget *lw;
    vector<QListWidgetItem*> lwItems;

    QPushButton *addQuestionBtn;
    QPlainTextEdit *newQuestionText;

    // Answers
    QListWidget *answersLW;
    vector<QListWidgetItem*> answersLwItems;

    QPlainTextEdit *newAnswerText;
    QPushButton *addAnswerBtn;
};

#endif // USERWND_H
