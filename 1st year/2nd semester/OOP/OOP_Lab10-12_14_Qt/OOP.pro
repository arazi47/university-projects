#-------------------------------------------------
#
# Project created by QtCreator 2018-05-03T19:36:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OOP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphicaluserinterface.cpp \
    validator.cpp \
    FileManager.cpp \
    Axolotl.cpp \
    Controller.cpp \
    UndoOperation.cpp

HEADERS  += mainwindow.h \
    graphicaluserinterface.h \
    validator.h \
    FileManager.h \
    Axolotl.h \
    Controller.h \
    comparator.h \
    UndoOperation.h

FORMS    += mainwindow.ui

DISTFILES += \
    outfilevectorall.txt \
    outfile.html \
    outfile.txt
