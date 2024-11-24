#include "info_edge.h"
#include "ui_info_edge.h"

InfoEdge::InfoEdge(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InfoEdge)
{
    ui->setupUi(this);
}

InfoEdge::~InfoEdge()
{
    delete ui;
}

void InfoEdge::setInfo(int id, qreal weight, int style, int from, int to, QString line0, QString line1)
{
    ui->idLineEdit->setText(QString::number(id));
    this->id = id;
    ui->lengthSpinBox->setValue(weight);
    ui->styleBox->setCurrentIndex(style);
    ui->startSpinBox->setValue(from);
    ui->endSpinBox->setValue(to);
    ui->lineEdit0->setText(line0);
    ui->lineEdit1->setText(line1);
}


void InfoEdge::setModeUse()
{
    ui->lengthSpinBox->setReadOnly(true);
    ui->styleBox->setEnabled(false);
    ui->deleteButton->setVisible(false);
}
