#-------------------------------------------------
#
# Project created by QtCreator 2017-02-01T20:08:55
#
#-------------------------------------------------
TARGET = TaskSketchModel
TEMPLATE = lib
QT += widgets

DEFINES += PLUGIN_BASE_QOBJECT

include(../../PluginsCommon/BuildInfo.pri)

SOURCES += \
    tasksketchmodel.cpp \
    rawimagedelegate.cpp

HEADERS +=\
    tasksketchmodel.h \
    rawimagedelegate.h

DISTFILES += \
    PluginMeta.json