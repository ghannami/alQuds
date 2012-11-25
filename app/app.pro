QT       += core gui
#CONFIG += release

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = alquds
TEMPLATE = app


SOURCES += main.cpp \
    app.cpp

include(../../3rdparty/qt-solutions/qtsingleapplication/src/qtsingleapplication.pri)
#include(../../3rdparty/qt-solutions/qtservice/src/qtservice.pri)
include(../badi/badi.pri)
include(../alquds/alquds.pri)

DESTDIR = $$PWD/../install

HEADERS += \
    app.h
