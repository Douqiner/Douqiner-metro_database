#include "info_sation.h"
#include "ui_info_sation.h"

InfoSation::InfoSation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InfoSation)
{
    ui->setupUi(this);

    // 发出乘客请求
    QObject::connect(ui->inButton, &QPushButton::clicked, this, &InfoSation::inStation);
    QObject::connect(ui->outButton, &QPushButton::clicked, this, &InfoSation::outStation);
    QObject::connect(ui->showButton, &QPushButton::clicked, this, &InfoSation::showStation);
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

void InfoSation::inStation()
{
    emit sendStationAsk(this->id, "in");
}

void InfoSation::outStation()
{
    emit sendStationAsk(this->id, "out");
}

void InfoSation::showStation()
{
    emit sendStationAsk(this->id, "show");
}


