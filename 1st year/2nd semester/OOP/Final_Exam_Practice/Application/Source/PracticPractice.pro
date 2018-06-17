#-------------------------------------------------
#
# Project created by QtCreator 2018-06-15T19:38:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PracticPractice
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Question.cpp \
    FileManager.cpp \
    presenterwnd.cpp \
    participantwnd.cpp \
    Repository.cpp

HEADERS  += MainWindow.h \
    Question.h \
    FileManager.h \
    Observer.h \
    QuizSession.h \
    presenterwnd.h \
    participantwnd.h \
    Repository.h

FORMS    += mainwindow.ui \
    presenterwnd.ui \
    participantwnd.ui

DISTFILES += \
    PresenterWindowForm.ui.qml \
    PresenterWindow.qml
