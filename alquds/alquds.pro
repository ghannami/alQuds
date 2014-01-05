########################################################
# Project File Alquds.pro
# autor: Aziz Ghannami
########################################################

QT       += core gui xml network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TEMPLATE = app

include(qtsingleapplication/src/qtsingleapplication.pri)

win32:RC_FILE = winapp.rc

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


SOURCES += \
    gui/mainwindow.cpp \
    prayertimes/location.cpp \
    prayertimes/prayertimesadapter.cpp \
    gui/prayertimeswidget.cpp \
    webservices/downloadmanager.cpp \
    gui/winwidget.cpp \
    gui/winaction.cpp \
    multimedia/mediaplayer.cpp \
    multimedia/playerinterface.cpp \
    multimedia/athanplayer.cpp \
    settings/locationsettings.cpp \
    gui/locationeditor.cpp \
    gui/prayertimeseditor.cpp \
    settings/mediasettings.cpp \
    settings/athansettings.cpp \
    multimedia/mediamanager.cpp \
    gui/athaneditor.cpp \
    webservices/webparser.cpp \
    webservices/islamwayparser.cpp \
    gui/homewidget.cpp \
    webservices/wathakkerservice.cpp \
    settings/pathsettings.cpp \
    main.cpp \
    settings/generalsettings.cpp \
    gui/aboutwidget.cpp \
    gui/athantraywidget.cpp \
    prayertimes/athanmanager.cpp \
    gui/notificationcenter.cpp

HEADERS += \
    gui/mainwindow.h \
    prayertimes/location.h \
    prayertimes/prayertimes.hpp \
    prayertimes/prayertimesadapter.h \
    gui/prayertimeswidget.h \
    webservices/downloadmanager.h \
    gui/winwidget.h \
    gui/winaction.h \
    multimedia/mediaplayer.h \
    multimedia/playerinterface.h \
    multimedia/athanplayer.h \
    settings/locationsettings.h \
    gui/prayertimeseditor.h \
    gui/locationeditor.h \
    settings/mediasettings.h \
    settings/athansettings.h \
    multimedia/mediamanager.h \
    gui/athaneditor.h \
    webservices/webparser.h \
    webservices/islamwayparser.h \
    gui/homewidget.h \
    webservices/wathakkerservice.h \
    version.h \
    settings/pathsettings.h \
    settings/generalsettings.h \
    gui/aboutwidget.h \
    gui/athantraywidget.h \
    prayertimes/athanmanager.h \
    gui/notificationcenter.h

FORMS += \
    gui/prayertimeswidget.ui \
    gui/locationeditor.ui \
    gui/prayertimeseditor.ui \
    gui/athaneditor.ui \
    gui/homewidget.ui \
    gui/aboutwidget.ui

RESOURCES += \
    src/main.qrc \
    src/icons.qrc

OTHER_FILES += \
    src/stylesheet.qss.css

win32{
    CONFIG(debug, debug|release) {
        LIBS += -L$$PWD/../WinSparkle/debug/ -lWinSparkle
        INCLUDEPATH += $$PWD/../WinSparkle/debug
        DEPENDPATH += $$PWD/../WinSparkle/debug
        PRE_TARGETDEPS += $$PWD/../WinSparkle/debug/WinSparkle.lib
    }
    else
    {
        LIBS += -L$$PWD/../WinSparkle/release/ -lWinSparkle
        INCLUDEPATH += $$PWD/../WinSparkle/release
        DEPENDPATH += $$PWD/../WinSparkle/release
        PRE_TARGETDEPS += $$PWD/../WinSparkle/release/WinSparkle.lib
    }

}

INCLUDEPATH += gui
INCLUDEPATH += multimedia
INCLUDEPATH += prayertimes
INCLUDEPATH += settings
INCLUDEPATH += webservices
