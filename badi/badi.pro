TARGET = badi
TEMPLATE = lib
CONFIG  += plugin
#CONFIG += release

QT  += core

include(badi.pri)
include(../alquds/alquds.pri)


HEADERS += \
    ../badi/pluginloaderlauncher.h


SOURCES += \
    ../badi/pluginloaderlauncher.cpp


win32{
    DESTDIR = $$PWD/../install
}
unix{
    DESTDIR = $$PWD/../install/alquds.app/Contents/plugins
}
