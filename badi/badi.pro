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
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/../install_($$QT_VERSION)_debug/plugins
    } else {
        DESTDIR = $$PWD/../install_($$QT_VERSION)_release/plugins
    }
}
unix{
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/../install_($$QT_VERSION)_debug/alquds.app/Contents/plugins
    } else {
        DESTDIR = $$PWD/../install_($$QT_VERSION)_release/alquds.app/Contents/plugins
    }
}
