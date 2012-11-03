TARGET = alquds
TEMPLATE = app
QT  += core
QT  += xml
QT  += network

SOURCES += \
    main.cpp \
    gui/mainwindow.cpp \
    prayertimes/location.cpp \
    prayertimes/prayertimesadapter.cpp \
    tools/settings.cpp \
    prayertimes/athanmanager.cpp \
    gui/prayertimeswidget.cpp \
    gui/prayertimessettings.cpp \
    gui/locationsettings.cpp \
    webservices/downloadmanager.cpp \
    gui/winwidget.cpp \
    gui/winaction.cpp \
    multimedia/audiomanager.cpp

HEADERS += \
    gui/mainwindow.h \
    prayertimes/location.h \
    prayertimes/prayertimes.hpp \
    prayertimes/prayertimesadapter.h \
    tools/settings.h \
    prayertimes/athanmanager.h \
    gui/prayertimeswidget.h \
    gui/prayertimessettings.h \
    gui/locationsettings.h \
    webservices/downloadmanager.h \
    gui/winwidget.h \
    gui/winaction.h \
    multimedia/audiomanager.h

FORMS += \
    gui/prayertimeswidget.ui \
    gui/prayertimessettings.ui \
    gui/locationsettings.ui

RESOURCES += \
    src/main.qrc \
    src/icons.qrc

OTHER_FILES += \
    src/stylesheet.qss.css
