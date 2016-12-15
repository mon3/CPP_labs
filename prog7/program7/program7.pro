#-------------------------------------------------
#
# Project created by QtCreator 2016-12-14T22:37:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = program7
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += qwt
CONFIG += console


QMAKE_CXXFLAGS += -std=c++11

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../home/monika03/Downloads/qwt-6.1.3/lib/release/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../home/monika03/Downloads/qwt-6.1.3/lib/debug/ -lqwt
else:unix: LIBS += -L$$PWD/../../../../../../home/monika03/Downloads/qwt-6.1.3/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../../../../home/monika03/Downloads/qwt-6.1.3/lib
DEPENDPATH += $$PWD/../../../../../../home/monika03/Downloads/qwt-6.1.3/lib
