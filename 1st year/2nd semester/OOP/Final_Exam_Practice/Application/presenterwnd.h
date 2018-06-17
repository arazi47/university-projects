#ifndef PRESENTERWND_H
#define PRESENTERWND_H

#include <QWidget>
#include <vector>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPlainTextEdit>
#include <QPushButton>
#include "QuizSession.h"

using std::vector;

namespace Ui {
class PresenterWnd;
}

class PresenterWnd : public QWidget
{
    Q_OBJECT

public:
     PresenterWnd(QuizSession &qs, QWidget *parent = 0);
    ~PresenterWnd();

private:
    Ui::PresenterWnd *ui;
    vector<QListWidgetItem*> lwItems;
    QListWidget* lw;
    QuizSession &qs;

    QPlainTextEdit *newQId, *newQText, *newQAnswer, *newQScore;
    QPushButton *addNewQBtn;
};

#endif // PRESENTERWND_H
