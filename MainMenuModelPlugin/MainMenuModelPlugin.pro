#-------------------------------------------------
#
# Project created by QtCreator 2017-02-01T20:08:55
#
#-------------------------------------------------
TARGET = MainMenuModelPlugin
TEMPLATE = lib
QT += widgets sql

SOURCES += \
    mainmenumodelplugin.cpp

HEADERS +=\
    imainmenumodule.h \
    itaskdbtoolplugin.h \
    mainmenumodelplugin.h \
    ../TimeKeeper/interfaces.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    PluginMeta.json
