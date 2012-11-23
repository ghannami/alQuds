TEMPLATE = lib
CONFIG  += plugin
CONFIG += release
include(alquds.pri)


SOURCES += \
    ../alquds/alqudslauncher.cpp

HEADERS += \
    ../alquds/alqudslauncher.h

win32{
    INCLUDEPATH += C:\QtMobility\include\QtMultimediaKit
    INCLUDEPATH += C:\QtMobility\include\QtMobility

    release{
        LIBS+=-LC:\QtMobility\lib
        LIBS+=-lQtMultimediaKit1
    }
    debug{
        LIBS+=-LC:\QtMobility\lib
        LIBS+=-lQtMultimediaKitd1
    }
}

DESTDIR = $$PWD/../install/plugins
