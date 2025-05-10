!contains(PROFILES,$$_FILE_){
PROFILES+=$$_FILE_

CONFIG += sdk_no_version_check

include($$PWD/../quazip/quazip.pri)

INCLUDEPATH += $$PWD

SOURCES += \
    $$PWD/cprojectpage.cpp

HEADERS += \
    $$PWD/cprojectpage.h

FORMS += \
    $$PWD/cprojectpage.ui

RESOURCES += \
    $$PWD/projectpage.qrc
}
