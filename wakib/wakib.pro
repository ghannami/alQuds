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

    DESTDIR = $$PWD/../install-$$QT_VERSION/plugins
}
unix{
    DESTDIR = $$PWD/../install-$$QT_VERSION/alquds.app/Contents/plugins
}
mac:LIBS +=/opt/local/lib/libquazip.dylib
