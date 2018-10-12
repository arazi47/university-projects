#-------------------------------------------------
#
# Project created by QtCreator 2018-06-19T15:01:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PracticExamOOP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Question.cpp \
    Answer.cpp \
    UserWnd.cpp \
    Session.cpp \
    QSearchWindow.cpp \
    RunTests.cpp

HEADERS  += mainwindow.h \
    Observer.h \
    Question.h \
    Answer.h \
    UserWnd.h \
    Session.h \
    Repository.h \
    QSearchWindow.h \
    RunTests.h

FORMS    += mainwindow.ui \
    userwnd.ui \
    qsearchwindow.ui
