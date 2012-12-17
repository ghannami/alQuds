TEMPLATE = lib
CONFIG  += plugin
#CONFIG += release
include(alquds.pri)

SOURCES += \
    ../alquds/alqudslauncher.cpp

HEADERS += \
    ../alquds/alqudslauncher.h

win32:DESTDIR = $$PWD/../install-$$QT_VERSION/plugins
unix:DESTDIR = $$PWD/../install-$$QT_VERSION/alquds.app/Contents/plugins
