#include "registerwidget.h"
#include "ui_registerwidget.h"

RegisterWidget::RegisterWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegisterWidget)
{
    ui->setupUi(this);
    QObject::connect(ui->registerButton, &QPushButton::clicked, this, &RegisterWidget::startRegister);
    QObject::connect(ui->jumpButton, &QPushButton::clicked, this, &RegisterWidget::jumpToLogin);
}

RegisterWidget::~RegisterWidget()
{
    delete ui;
}

void RegisterWidget::jumpToLogin()
{
    emit sendJumpToLogin();
}

void RegisterWidget::startRegister()
{
    QString val1 = ui->uidEdit->text();
    QString val2 = ui->passwordEdit->text();
    QString val3 = ui->confirmEdit->text();
    if (val1.isEmpty())
    {
        setErrorText("账号不能为空");
        return;
    }
    else if (val2.isEmpty())
    {
        setErrorText("密码不能为空");
        return;
    }
    else if (val3.isEmpty())
    {
        setErrorText("确认密码不能为空");
        return;
    }
    else if (val2 != val3)
    {
        setErrorText("密码与确认密码不一致");
        return;
    }
    else if (val2.size() < 6)
    {
        setErrorText("密码需大于等于6位");
        return;
    }
    emit sendRegister(val1, val2);
}

void RegisterWidget::setErrorText(QString text)
{
    ui->errorlabel->setText(text);
}
