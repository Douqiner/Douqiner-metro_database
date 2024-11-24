#include "startwindow.h"
#include "ui_startwindow.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QCryptographicHash>

StartWindow::StartWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    loginWidget = new LoginWidget(this);
    registerWidget = new RegisterWidget(this);
    mainStack = new QStackedWidget(this);
    mainStack->addWidget(loginWidget);
    mainStack->addWidget(registerWidget);
    ui->mainLayout->addWidget(mainStack);

    this->setWindowTitle("登录");

    //切换模式
    QObject::connect(loginWidget, &LoginWidget::sendJumpToRegister, this, &StartWindow::jumpToRegister);
    QObject::connect(registerWidget, &RegisterWidget::sendJumpToLogin, this, &StartWindow::jumpToLogin);
    //检查登录注册
    QObject::connect(loginWidget, &LoginWidget::sendLogin, this, &StartWindow::recieveLogin);
    QObject::connect(registerWidget, &RegisterWidget::sendRegister, this, &StartWindow::recieveRegister);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::startMainWindow()
{
    the_w_main->enableSql();
    the_w_main->setWindowTitle('#' + _uid);
    the_w_main->show();
    this->close();
}

void StartWindow::enableSql(bool connected)
{
    if (!connected)
    {
        QMessageBox message(this);
        message.setWindowTitle("哎呀!");
        message.setIconPixmap(QPixmap(":/icon/img/warn.png"));
        message.setText("数据库连接失败，程序无法继续运行");
        message.exec();
        this->close();
    }
}

void StartWindow::recieveLogin(QString uid, QString password)
{
    /* 数据库操作 */
    QSqlQuery query(DB);
    QString sqlText = "SELECT * FROM User WHERE Uid = \"" + uid +"\";";
    query.exec(sqlText);

    if (query.next())
    {
        QString hash = QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Sha256).toHex();
        if (hash != query.value(1).toString())
        {
            this->loginWidget->setErrorText("密码错误");
            return;
        }
    }
    else
    {
        this->loginWidget->setErrorText("账号错误");
        return;
    }
    // 登录更新用户状态
    _uid = uid;
    this->startMainWindow();
}

void StartWindow::recieveRegister(QString uid, QString password)
{
    /* 数据库操作 */
    QSqlQuery query(DB);
    QString sqlText = "SELECT * FROM User WHERE Uid = \"" + uid +"\";";
    query.exec(sqlText);

    if (query.next())
    {
        this->registerWidget->setErrorText("账号已存在");
        return;
    }
    else
    {
        // 添加用户
        QString hash = QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Sha256).toHex();
        sqlText = "INSERT INTO User VALUES (\"" + uid + "\", \"" + hash + "\", 0, \"out\");";
        qDebug() << sqlText;
        query.exec(sqlText);
        query.next();
    }
    // 登录更新用户状态
    _uid = uid;
    this->startMainWindow();
}

void StartWindow::jumpToLogin()
{
    this->mainStack->setCurrentIndex(0);
    this->setWindowTitle("登录");
}

void StartWindow::jumpToRegister()
{
    this->mainStack->setCurrentIndex(1);
    this->setWindowTitle("注册");
}
