TARGET = badi
TEMPLATE = lib
CONFIG  += plugin
CONFIG += release

QT  += core

include(badi.pri)


HEADERS += \
    ../badi/pluginloaderlauncher.h


SOURCES += \
    ../badi/pluginloaderlauncher.cpp


DESTDIR = $$PWD/../install
