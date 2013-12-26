QT       += core gui
#CONFIG += release

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = alquds
TEMPLATE = app


SOURCES += main.cpp

include(../../3rdparty/qt-solutions/qtsingleapplication/src/qtsingleapplication.pri)
#include(../../3rdparty/qt-solutions/qtservice/src/qtservice.pri)
#include(../badi/badi.pri)
include(../badi/badiplugin.pri)
include(../alquds/alquds.pri)

#DESTDIR = $$PWD/../install-$$QT_VERSION

win32{
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/../install_($$QT_VERSION)_debug
    } else {
        DESTDIR = $$PWD/../install_($$QT_VERSION)_release
    }
}
unix{
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/../install_($$QT_VERSION)_debug
    } else {
        DESTDIR = $$PWD/../install_($$QT_VERSION)_release
    }
}
