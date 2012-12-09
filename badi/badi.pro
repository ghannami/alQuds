<<<<<<< HEAD
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
=======
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
>>>>>>> Fixed start application and install updates
