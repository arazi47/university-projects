#-------------------------------------------------
#
# Project created by QtCreator 2018-05-30T13:57:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestOOP30Mai
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    FileManager.cpp \
    Car.cpp \
    Controller.cpp \
    Tester.cpp

HEADERS  += MainWindow.h \
    FileManager.h \
    Car.h \
    Controller.h \
    Tester.h

FORMS    += MainWindow.ui

DISTFILES += \
    file.txt
