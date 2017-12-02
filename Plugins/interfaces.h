#ifndef INTERFACES_H
#define INTERFACES_H

#include "../Application/icoreplugin.h"
#include <QtGlobal>
#include <QObject>

class QSqlDatabase;
class QSqlQuery;

//! \addtogroup MainMenuPlugin_int
//! @{

//! Enumeration of MASS system modules types.
enum PluginTypes
{
    COREPLUGIN,      //!< Module type that implements IRootModelPlugin
    MODELPLUGIN,    //!< Module type that implements IModelPlugin
    VIEWPLUGIN,     //!< Module type that implements IViewPlugin
    DATASOURCEPLUGIN,     //!< Module type that implements IDataSourcePlugin
    DATAMANAGERPLUGIN,    //!< Module type that implements IDataManagerPlugin
};

//! \brief Holds information about plugin.
struct MetaInfo{
    //! \brief Type of plugin.
    PluginTypes Type;
    //! \brief Name of plugin interface.
    QString InterfaceName;
    //! \brief Plugin name.
    QString Name;
    //! \brief Name of parent plugin (in tree structure).
    QList<QString> RelatedPluginNames;
};

class PluginInfo;
//! \brief This interface provides basic methods for all plugins.
class IPlugin
{
public:
    virtual ~IPlugin() {}
    //! \brief Method
    virtual void SetPluginInfo(PluginInfo *pluginInfo) = 0;
    //! \brief Method which calls when system setup all connections between plugins.
    virtual void OnAllSetup() = 0;
    //! \brief Gets last error message from plugin.
    virtual QString GetLastError() = 0;
    virtual void AddReferencePlugin(PluginInfo *pluginInfo) = 0;
public slots:
    virtual void ReferencePluginClosed(PluginInfo *pluginInfo) = 0;
signals:
    void OnClose(PluginInfo *pointer);
    void OnClose();
};

//! \brief This interface describes DataSource plugin.
//!
//! DataSource plugin implements interaction with data source. In place of
//! data source could be data base, network connection, some device and etc.
class IDataSourcePlugin : public IPlugin
{
public:
    virtual ~IDataSourcePlugin() {}
    //! \brief Install connection with source.
    virtual void Setup() = 0;
};
Q_DECLARE_INTERFACE(IDataSourcePlugin, "IDataSourcePlugin v0.1")

//! \brief This interface describes DataManager plugn.
//!
//! DataManager plugin implements interaction with DataSource plugin.
class IDataManagerPlugin : public IPlugin
{
public:
    virtual ~IDataManagerPlugin() {}
};
Q_DECLARE_INTERFACE(IDataManagerPlugin, "IDBToolPlugin v0.1")

//! \brief The IModelPlugin class
class IModelPlugin : public IPlugin
{
public:
    virtual ~IModelPlugin() {}
public slots:
    virtual bool Open(IModelPlugin* model) = 0;
    virtual void Close() = 0;
};
Q_DECLARE_INTERFACE(IModelPlugin, "IModelPlugin v0.1")

//! \brief This interface describes DataManager plugn.
class IViewPlugin : public IPlugin
{
public:
    virtual ~IViewPlugin() {}
public slots:
    virtual bool Open(IModelPlugin* model) = 0;
    virtual bool Close() = 0;
signals:
    void OnOpen(QWidget*);
};
Q_DECLARE_INTERFACE(IViewPlugin, "IViewPlugin v0.1")

//! \brief Structure for internal needs.
struct PluginInfo
{
    PluginInfo(IDataSourcePlugin *plugin, QObject *instance, MetaInfo *meta) :
        Instance(instance), Meta(meta) { Plugin.dataSource = plugin; }
    PluginInfo(IDataManagerPlugin *plugin, QObject *instance, MetaInfo *meta) :
        Instance(instance), Meta(meta) { Plugin.dataManager = plugin; }
    PluginInfo(IModelPlugin *plugin, QObject *instance, MetaInfo *meta) :
        Instance(instance), Meta(meta) { Plugin.model = plugin; }
    PluginInfo(IViewPlugin *plugin, QObject *instance, MetaInfo *meta) :
        Instance(instance), Meta(meta) { Plugin.view = plugin; }

    //! \brief Class instance of plugin.
    union PluginsUnion{
        IDataSourcePlugin *dataSource;
        IDataManagerPlugin *dataManager;
        IModelPlugin *model;
        IViewPlugin *view;
        IPlugin *any;
    } Plugin;
    //! \brief QObject instance of plugin.
    QObject *Instance;
    //! \brief Meta information of plugin.
    MetaInfo *Meta;
};

//! @}
#endif // INTERFACES_H
