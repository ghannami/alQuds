TEMPLATE  = lib
CONFIG   += plugin
#CONFIG   += release

SOURCES += \
    wakiblauncher.cpp
HEADERS += \
    wakiblauncher.h


include(wakib.pri)
include(../badi/badi.pri)
include($$[QT_INSTALL_PREFIX]/src/3rdparty/zlib.pri)

mac:LIBS +=/opt/local/lib/libquazip.dylib

win32{
INCLUDEPATH +=$$PWD/../third-party/win/quazip/include
debug{
    LIBS+=-L$$PWD/../third-party/win/quazip/lib
    LIBS+=-lquazipd1
}

release{
    LIBS+=-L$$PWD/../third-party/win/quazip/lib
    LIBS+=-lquazip1
}
    DESTDIR = $$PWD/../install/plugins
}

unix{
    DESTDIR = $$PWD/../install/alquds.app/Contents/plugins
}
