TARGET = alquds
TEMPLATE = app
QT  += core
QT  += xml


SOURCES += \
    main.cpp \
    gui/mainwindow.cpp \
    prayertimes/location.cpp \
    prayertimes/prayertimesadapter.cpp

HEADERS += \
    gui/mainwindow.h \
    prayertimes/location.h \
    prayertimes/prayertimes.hpp \
    prayertimes/prayertimesadapter.h
