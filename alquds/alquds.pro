TEMPLATE = lib
CONFIG  += plugin
#CONFIG += release
include(alquds.pri)

SOURCES += \
    ../alquds/alqudslauncher.cpp

HEADERS += \
    ../alquds/alqudslauncher.h

win32{
    INCLUDEPATH += C:\QtMobility\include\QtMultimediaKit
    INCLUDEPATH += C:\QtMobility\include\QtMobility

    CONFIG(release, debug|release){
        LIBS+=-LC:\QtMobility\lib
        LIBS+=-lQtMultimediaKit1
    }
    else CONFIG(debug, debug|release){
        LIBS+=-LC:\QtMobility\lib
        LIBS+=-lQtMultimediaKitd1
    }

DESTDIR = $$PWD/../install/plugins

}

unix{
    INCLUDEPATH += /opt/local/include/QtMultimediaKit
    INCLUDEPATH += /opt/local/include/QtMobility
    DESTDIR = $$PWD/../install/alquds.app/Contents/plugins

    QT_MOBILITY_PREFIX = /Users/ghannami/ghannamis-qt-mobility/install
    QT_MOBILITY_INCLUDE = /Users/ghannami/ghannamis-qt-mobility/install/include
    QT_MOBILITY_LIB = /Users/ghannami/ghannamis-qt-mobility/install/lib
    QT_MOBILITY_BIN = /Users/ghannami/ghannamis-qt-mobility/install/bin
    QT_MOBILITY_PLUGINS = /Users/ghannami/ghannamis-qt-mobility/install/plugins
    QT_MOBILITY_EXAMPLES = /Users/ghannami/ghannamis-qt-mobility/install/bin
    QT_MOBILITY_DEMOS = /Users/ghannami/ghannamis-qt-mobility/install/bin
}
