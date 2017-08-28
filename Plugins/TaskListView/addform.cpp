#include "addform.h"
#include "ui_addform.h"

AddForm::AddForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddForm)
{
    ui->setupUi(this);
    mapper = new QDataWidgetMapper(this);
    hide();
}

AddForm::~AddForm()
{
    delete ui;
}

void AddForm::SetModel(QAbstractItemModel *model)
{
    mapper->setModel(model);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    ui->label_2->setText(model->headerData(0, Qt::Horizontal).toString());
    mapper->addMapping(ui->lineEdit_2, 0);
}

void AddForm::ShowModelData(const QModelIndex &index, bool isNew)
{
    show();
    ui->lineEdit_2->setFocus();
    mapper->setRootIndex(index.parent());
    mapper->setCurrentModelIndex(index);
    if(isNew)
        ui->lineEdit_2->setText("");
}

void AddForm::on_buttonOk_clicked()
{
    mapper->submit();
    on_buttonClose_clicked();
}

void AddForm::on_buttonClose_clicked()
{
    emit OnClose();
    hide();
}

bool AddForm::event(QEvent *event)
{
    qDebug() << "!Event!" << event->type();
    switch (event->type()) {
    case QEvent::KeyRelease:{
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        switch (keyEvent->key()) {
#ifdef Q_OS_ANDROID
        case Qt::Key_Return:
            on_buttonOk_clicked();
            break;
#else
        case Qt::Key_Enter:
            on_buttonOk_clicked();
            break;
        case Qt::Key_Escape:
            on_buttonClose_clicked();
            break;
#endif
        default:
            qDebug() << "!Keycode!" << keyEvent->key();
            break;
        }

    }break;
    default:
        return false;
        break;
    }
}
