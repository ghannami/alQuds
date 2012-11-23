QT       += core gui
CONFIG += release

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = alquds
TEMPLATE = app


SOURCES += main.cpp

include(../badi/badi.pri)

DESTDIR = $$PWD/../install
