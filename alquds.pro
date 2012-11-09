TARGET = alquds
TEMPLATE = app
QT  += core
QT  += xml
QT  += network
CONFIG += mobility
MOBILITY = multimedia

SOURCES += \
    main.cpp \
    gui/mainwindow.cpp \
    prayertimes/location.cpp \
    prayertimes/prayertimesadapter.cpp \
    prayertimes/athanmanager.cpp \
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
    webservices/wathakkerservice.cpp

HEADERS += \
    gui/mainwindow.h \
    prayertimes/location.h \
    prayertimes/prayertimes.hpp \
    prayertimes/prayertimesadapter.h \
    prayertimes/athanmanager.h \
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
    webservices/wathakkerservice.h

FORMS += \
    gui/prayertimeswidget.ui \
    gui/locationeditor.ui \
    gui/prayertimeseditor.ui \
    gui/athaneditor.ui \
    gui/homewidget.ui

RESOURCES += \
    src/main.qrc \
    src/icons.qrc

OTHER_FILES += \
    src/stylesheet.qss.css
