#-------------------------------------------------
#
# Project created by QtCreator 2013-06-18T19:31:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = smsapp
TEMPLATE = app

QT +=network
QT +=CONSOLE
SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
