QT  += core
QT  += network
QT  += xml
CONFIG += mobility
MOBILITY = multimedia

SOURCES += \
    ../alquds/gui/mainwindow.cpp \
    ../alquds/prayertimes/location.cpp \
    ../alquds/prayertimes/prayertimesadapter.cpp \
    ../alquds/prayertimes/athanmanager.cpp \
    ../alquds/gui/prayertimeswidget.cpp \
    ../alquds/webservices/downloadmanager.cpp \
    ../alquds/gui/winwidget.cpp \
    ../alquds/gui/winaction.cpp \
    ../alquds/multimedia/mediaplayer.cpp \
    ../alquds/multimedia/playerinterface.cpp \
    ../alquds/multimedia/athanplayer.cpp \
    ../alquds/settings/locationsettings.cpp \
    ../alquds/gui/locationeditor.cpp \
    ../alquds/gui/prayertimeseditor.cpp \
    ../alquds/settings/mediasettings.cpp \
    ../alquds/settings/athansettings.cpp \
    ../alquds/multimedia/mediamanager.cpp \
    ../alquds/gui/athaneditor.cpp \
    ../alquds/webservices/webparser.cpp \
    ../alquds/webservices/islamwayparser.cpp \
    ../alquds/gui/homewidget.cpp \
    ../alquds/webservices/wathakkerservice.cpp

HEADERS += \
    ../alquds/gui/mainwindow.h \
    ../alquds/prayertimes/location.h \
    ../alquds/prayertimes/prayertimes.hpp \
    ../alquds/prayertimes/prayertimesadapter.h \
    ../alquds/prayertimes/athanmanager.h \
    ../alquds/gui/prayertimeswidget.h \
    ../alquds/webservices/downloadmanager.h \
    ../alquds/gui/winwidget.h \
    ../alquds/gui/winaction.h \
    ../alquds/multimedia/mediaplayer.h \
    ../alquds/multimedia/playerinterface.h \
    ../alquds/multimedia/athanplayer.h \
    ../alquds/settings/locationsettings.h \
    ../alquds/gui/prayertimeseditor.h \
    ../alquds/gui/locationeditor.h \
    ../alquds/settings/mediasettings.h \
    ../alquds/settings/athansettings.h \
    ../alquds/multimedia/mediamanager.h \
    ../alquds/gui/athaneditor.h \
    ../alquds/webservices/webparser.h \
    ../alquds/webservices/islamwayparser.h \
    ../alquds/gui/homewidget.h \
    ../alquds/webservices/wathakkerservice.h

FORMS += \
    ../alquds/gui/prayertimeswidget.ui \
    ../alquds/gui/locationeditor.ui \
    ../alquds/gui/prayertimeseditor.ui \
    ../alquds/gui/athaneditor.ui \
    ../alquds/gui/homewidget.ui

RESOURCES += \
    ../alquds/src/main.qrc \
    ../alquds/src/icons.qrc

OTHER_FILES += \
    ../alquds/src/stylesheet.qss.css
