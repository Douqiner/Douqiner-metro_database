#include "info_sation.h"
#include "ui_info_sation.h"

InfoSation::InfoSation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InfoSation)
{
    ui->setupUi(this);
}

InfoSation::~InfoSation()
{
    delete ui;
}

void InfoSation::setInfo(int id, QString name, int size, QPointF center)
{
    ui->idLineEdit->setText(QString::number(id));
    this->id = id;
    ui->nameLineEdit->setText(name);
    ui->sizeBox->setCurrentIndex(size);
    ui->xSpinBox->setValue(center.x());
    ui->ySpinBox->setValue(center.y());
}

void InfoSation::setModeUse()
{
    ui->nameLineEdit->setReadOnly(true);
    ui->sizeBox->setEnabled(false);
    ui->xSpinBox->setReadOnly(true);
    ui->ySpinBox->setReadOnly(true);
    ui->deleteButton->setVisible(false);
}

