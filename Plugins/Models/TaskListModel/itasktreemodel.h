#ifndef ITASKLISTMODEL_H
#define ITASKLISTMODEL_H

#include "../../interfaces.h"

class QVariant;
class QAbstractItemModel;
template <class A> class QVector;
template <class A, class B> class QMap;
enum QVariant::Type;

//! \defgroup TaskTreeModel
//!     \ingroup MainMenuPlugin_rel_m
//! \defgroup TaskTreeModel_int Interface
//!     \ingroup TaskTreeModel
//! \defgroup TaskTreeModel_imp Implementation
//!     \ingroup TaskTreeModel

//! \addtogroup TaskTreeModel_int
//! \{
class ITaskTreeModel : public IModelPlugin
{
public:
    virtual QAbstractItemModel* GetTreeModel() = 0;

signals:
    void OpenTaskEdit(int id);
};
//! \}
Q_DECLARE_INTERFACE(ITaskTreeModel, "ITaskTreeModel v0.1")
#endif // ITASKLISTMODEL_H