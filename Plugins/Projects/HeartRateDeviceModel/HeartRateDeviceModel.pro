
TARGET = HeartRateDeviceModel
TEMPLATE = lib
QT += widgets serialport serialbus charts

DEFINES += PLUGIN_BASE_QOBJECT

include(../../Common/BuildInfo.pri)

SOURCES += \
    heartratedevicemodel.cpp

HEADERS +=\
    heartratedevicemodel.h

DISTFILES += \
    PluginMeta.json