TEMPLATE  = lib
CONFIG   += plugin
#CONFIG   += release

SOURCES += \
    wakiblauncher.cpp
HEADERS += \
    wakiblauncher.h


include(wakib.pri)
include(../badi/badi.pri)
include(../alquds/alquds.pri)
include($$[QT_INSTALL_PREFIX]/src/3rdparty/zlib.pri)
include(../../3rdparty/qt-solutions/qtsingleapplication/src/qtsingleapplication.pri)

win32{
INCLUDEPATH +=$$PWD/../third-party/win/quazip/include

    CONFIG(release, debug|release){
    LIBS+=-L$$PWD/../third-party/win/quazip/lib
    LIBS+=-lquazip1
    }
    CONFIG(debug, debug|release){
    LIBS+=-L$$PWD/../third-party/win/quazip/lib
    LIBS+=-lquazipd1
    }
}

win32{
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/../install_($$QT_VERSION)_debug/plugins
    } else {
        DESTDIR = $$PWD/../install_($$QT_VERSION)_release/plugins
    }
}
unix{
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/../install_($$QT_VERSION)_debug/alquds.app/Contents/plugins
    } else {
        DESTDIR = $$PWD/../install_($$QT_VERSION)_release/alquds.app/Contents/plugins
    }
}

mac:LIBS +=/opt/local/lib/libquazip.dylib
