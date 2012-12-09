TARGET = badi
TEMPLATE = lib
CONFIG  += plugin
#CONFIG += release

QT  += core

include(badi.pri)
include(../alquds/alquds.pri)
include(../../3rdparty/qt-solutions/qtsingleapplication/src/qtsingleapplication.pri)


HEADERS += \
    ../badi/pluginloaderlauncher.h \
    ../badi/applicationplugin.h


SOURCES += \
    ../badi/pluginloaderlauncher.cpp \
    ../badi/applicationplugin.cpp


win32{
    DESTDIR = $$PWD/../install
}
unix{
    DESTDIR = $$PWD/../install/alquds.app/Contents/plugins
}
