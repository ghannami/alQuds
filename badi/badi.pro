TARGET = badi
TEMPLATE = lib
CONFIG  += plugin
CONFIG += release

QT  += core

include(badi.pri)
include(../alquds/alquds.pri)
include(../wakib/wakib.pri)

HEADERS += \
    ../badi/pluginloaderlauncher.h


SOURCES += \
    ../badi/pluginloaderlauncher.cpp


win32{
    DESTDIR = $$PWD/../install/plugins
}
unix{
    DESTDIR = $$PWD/../install/alquds.app/Contents/plugins
}
