#ifndef DAYPLANVIEW_H
#define DAYPLANVIEW_H

#include <QWidget>
#include <QDebug>
#include <QString>
#include <QAbstractItemModel>

#include "../../PluginsCommon/plugin_base.h"

#include "../../PluginsInterfaces/idayplanmodel.h"
#include "datetimetypeeditor.h"
#include "designproxymodel.h"

//! addtogroup DayPlanView_imp
//! {
class DayPlanView : public PluginBase
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "TimeKeeper.Module.Test" FILE "PluginMeta.json")
    Q_INTERFACES(
        IPlugin
    )

public:
    explicit DayPlanView(QWidget *parent = nullptr);
    virtual ~DayPlanView() override;

    // PluginBase interface
public:
    virtual void onAllReferencesSet() override;
    virtual void onAllReferencesReady() override;

private:
    QWidget *referenceWidget;

private:
    IDayPlanModel *dayPlanModel;
    QAbstractItemModel * itemModel;
};
//! }
#endif // DAYPLANVIEW_H