#ifndef QSEARCHWINDOW_H
#define QSEARCHWINDOW_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <vector>
#include "Session.h"
#include "Observer.h"

namespace Ui {
class QSearchWindow;
}

class QSearchWindow : public QWidget, public Observer
{
    Q_OBJECT

public:
    QSearchWindow(Session &s, QWidget *parent = 0);
    ~QSearchWindow();

    void update() override;

private:
    Ui::QSearchWindow *ui;

    QPlainTextEdit *searchTextEdit;

    QListWidget *lw;
    vector<QListWidgetItem*> lwItems;
    Session &s;
};

#endif // QSEARCHWINDOW_H
