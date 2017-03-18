 #-------------------------------------------------
#
# Project created by QtCreator 2017-02-01T20:08:55
#
#-------------------------------------------------
TARGET = MainMenuViewPlugin
TEMPLATE = lib
QT += widgets

SOURCES += \
    draggablebutton.cpp \
    mainwindow.cpp \
    mainmenupluginview.cpp

HEADERS +=\
    draggablebutton.h \
    mainwindow.h \
    mainmenupluginview.h \
    ../MainMenuModelPlugin/imainmenumodule.h

include(../../System/MASS/BuildInfo.pri)

DISTFILES += \
    PluginMeta.json

RESOURCES += \
    mainwindow.qrc
