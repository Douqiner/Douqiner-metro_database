#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
    QObject::connect(ui->loginButton, &QPushButton::clicked, this, &LoginWidget::startLogin);
    QObject::connect(ui->jumpButton, &QPushButton::clicked, this, &LoginWidget::jumpToRegister);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::jumpToRegister()
{
    emit sendJumpToRegister();
}

void LoginWidget::startLogin()
{
    QString val1 = ui->uidEdit->text();
    QString val2 = ui->passwordEdit->text();
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
    emit sendLogin(val1, val2);
}

void LoginWidget::setErrorText(QString text)
{
    ui->errorLabel->setText(text);
}
