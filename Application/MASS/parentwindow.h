#ifndef PARENTWINDOW_H
#define PARENTWINDOW_H

#include <QWidget>
#include <QScreen>
#include <QPainter>
#include <QResizeEvent>
#include <QVBoxLayout>

#include "pluginloader.h"
//! \defgroup MASS MASS
//! \brief MASS application.
//! @{

//! \brief Main application widget class.
class ParentWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ParentWindow(QWidget *parent = 0);
    ~ParentWindow();

private:
    PluginLoader *pluginManager;
    QVBoxLayout *layout;
    QWidget *childsJoint;

    void resizeEvent(QResizeEvent* event);
};

//! @}
#endif // PARENTWINDOW_H