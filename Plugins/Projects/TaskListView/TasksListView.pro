#-------------------------------------------------
#
# Project created by QtCreator 2017-02-01T20:08:55
#
#-------------------------------------------------
TARGET = TaskListView
TEMPLATE = lib
QT += widgets

DEFINES += PLUGIN_BASE_QWIDGET

include(../../Common/BuildInfo.pri)

SOURCES += \
    tasklistview.cpp \
    addform.cpp \
    designproxymodel.cpp \
    mytreeview.cpp

HEADERS += \
    ../../PluginsInterfaces/itasktreemodel.h \
    tasklistview.h \
    addform.h \
    designproxymodel.h \
    mytreeview.h

DISTFILES += \
    PluginMeta.json

FORMS += \
    addform.ui \
    form.ui

RESOURCES += \
    res.qrc