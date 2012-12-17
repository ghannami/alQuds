#! [0]

macx:ICON = $${PWD}/mac.icns
RC_FILE = winapp.rc

TEMPLATE    = subdirs
SUBDIRS	    = alquds \
              badi \
              wakib \
              app
#CONFIG += release

#DESTDIR = $$PWD/install

#! [0]

# install
#target.path = $$[QT_INSTALL_EXAMPLES]/tools/echoplugin
#sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS echoplugin.pro
#sources.path = $$[QT_INSTALL_EXAMPLES]/tools/echoplugin
#INSTALLS += target sources
