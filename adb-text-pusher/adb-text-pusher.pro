#-------------------------------------------------
#
# Project created by QtCreator 2013-11-19T15:01:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = adb-text-pusher
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../keypusher.cpp \
    ../keypusherobj.cpp

HEADERS  += mainwindow.h \
    ../keypusherobj.h \
    ../keypusher.h

FORMS    += mainwindow.ui

INCLUDEPATH += /home/chris/Projects/adb-text-pusher
