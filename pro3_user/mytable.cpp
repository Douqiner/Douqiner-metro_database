#include "mytable.h"
#include "ui_mytable.h"
#include <QCryptographicHash>

mytable::mytable(QString sqlTable, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mytable)
{
    ui->setupUi(this);
    this->sqlTable = sqlTable;

    // 记录表项
    QObject::connect(ui->firstButton, &QPushButton::clicked, this, &mytable::firstPage);
    QObject::connect(ui->pastButton, &QPushButton::clicked, this, &mytable::pastPage);
    QObject::connect(ui->nextButton, &QPushButton::clicked, this, &mytable::nextPage);
    QObject::connect(ui->lastButton, &QPushButton::clicked, this, &mytable::lastPage);
    QObject::connect(ui->jumpButton, &QPushButton::clicked, this, &mytable::jumpPage);
    QObject::connect(ui->flushButton, &QPushButton::clicked, this, &mytable::flush);

    // 个人信息
    QObject::connect(ui->payButton, &QPushButton::clicked, this, &mytable::updateBalance);
    QObject::connect(ui->submitButton, &QPushButton::clicked, this, &mytable::checkEditPassword);
}

mytable::~mytable()
{
    delete ui;
    if (model)
    {
        delete model;
    }
}

void mytable::firstPage()
{
    this->now_page = 1;
    ui->pagelabel->setText(QString::number(now_page) + '/' + QString::number(total_page));
    model->setPage(this->now_page);
    model->select();
}

void mytable::pastPage()
{
    if (this->now_page == 1)
        return;
    this->now_page -= 1;
    ui->pagelabel->setText(QString::number(now_page) + '/' + QString::number(total_page));
    model->setPage(this->now_page);
    model->select();
}

void mytable::nextPage()
{
    if (this->now_page == this->total_page)
        return;
    this->now_page += 1;
    ui->pagelabel->setText(QString::number(now_page) + '/' + QString::number(total_page));
    model->setPage(this->now_page);
    model->select();
}

void mytable::lastPage()
{
    this->now_page = this->total_page;
    ui->pagelabel->setText(QString::number(now_page) + '/' + QString::number(total_page));
    model->setPage(this->now_page);
    model->select();
}

void mytable::jumpPage()
{
    int getPage = ui->pageBox->value();
    if (getPage < 1 || getPage > this->total_page)
    {
        QMessageBox message(this);
        message.setWindowTitle("警告");
        message.setIconPixmap(QPixmap(":/icon/img/warn.png"));
        message.setText("超出范围\n");
        if (getPage == 114514)
            message.setText(">_<!\n");
        message.exec();
        return;
    }
    this->now_page = getPage;
    ui->pagelabel->setText(QString::number(now_page) + '/' + QString::number(total_page));
    model->setPage(this->now_page);
    model->select();
}

void mytable::flush()
{
    //重算页数
    QSqlQuery query(DB);
    QString sqlCount = "SELECT COUNT(*) FROM " + this->sqlTable + ";";
    query.exec(sqlCount);
    query.next();
    this->total_page = query.value(0).toInt() / this->recordNum + 1;
    if (this->now_page > this->total_page)
        this->now_page = this->total_page;
    ui->pagelabel->setText(QString::number(now_page) + '/' + QString::number(total_page));
    //初始设定
    if (this->model == nullptr)
    {
        this->model = new mySqlQueryModel(this, DB);
        this->model->setTable(this->sqlTable);

        //设置视图不可编辑
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        //设置外键  
        ui->tableView->setModel(model);

        //设置过滤
        this->model->setFilter("DUid = " + _uid);
    }
    model->setPage(this->now_page);
    model->select();

    this->readInfo();
}

void mytable::readInfo()
{
    QSqlQuery query(DB);
    QString sqlText = "SELECT * FROM User WHERE Uid = \"" + _uid +"\";";
    query.exec(sqlText);
    query.next();

    ui->balanceSpinBox->setValue(query.value(2).toDouble());
    ui->uidEdit->setText(_uid);

    QString state = query.value(3).toString();
    if (state == "in")
        ui->stateEdit->setText("在站点内");
    else
        ui->stateEdit->setText("正常状态");
}

void mytable::updateBalance()
{
    QSqlQuery query(DB);
    QString sqlText = "SELECT * FROM User WHERE Uid = \"" + _uid +"\";";
    query.exec(sqlText);
    query.next();

    qreal oldBalance = query.value(2).toDouble();
    qreal addBalance = ui->paySpinBox->value();
    QString state = query.value(3).toString();
    if (state == "in")
        ui->stateEdit->setText("在站点内");
    else
        ui->stateEdit->setText("正常状态");

    if (oldBalance + addBalance >= 10000)
    {
        QMessageBox message(this);
        message.setWindowTitle("警告");
        message.setIconPixmap(QPixmap(":/icon/img/warn.png"));
        message.setText("账户余额不能超过10000元");
        message.exec();
    }
    else
    {
        sqlText = "UPDATE User SET Ubalance = " + QString::number(oldBalance + addBalance, 'f', 2) + " WHERE Uid = \"" + _uid + "\";";
        query.exec(sqlText);
        query.next();
        QMessageBox message(this);
        message.setWindowTitle("提示");
        message.setIconPixmap(QPixmap(":/icon/img/tips.png"));
        message.setText("充值成功");
        message.exec();
        ui->balanceSpinBox->setValue(oldBalance + addBalance);
    }
}

void mytable::checkEditPassword()
{
    QString val1 = ui->newpasswordEdit->text();
    QString val2 = ui->confirmEdit->text();

    if (val1 != val2)
    {
        QMessageBox message(this);
        message.setWindowTitle("警告");
        message.setIconPixmap(QPixmap(":/icon/img/warn.png"));
        message.setText("两次密码不相同");
        message.exec();
    }
    else
    {
        if (val1.size() < 6)
        {
            QMessageBox message(this);
            message.setWindowTitle("警告");
            message.setIconPixmap(QPixmap(":/icon/img/warn.png"));
            message.setText("密码长度小于6位");
            message.exec();
        }
        else
        {
            QString hash = QCryptographicHash::hash(val1.toLatin1(),QCryptographicHash::Sha256).toHex();
            QSqlQuery query(DB);
            QString sqlText = "UPDATE User SET Upassword = \"" + hash + "\" WHERE Uid = \"" + _uid +"\";";
            query.exec(sqlText);
            query.next();

            QMessageBox message(this);
            message.setWindowTitle("提示");
            message.setIconPixmap(QPixmap(":/icon/img/tips.png"));
            message.setText("修改密码成功");
            message.exec();
        }
    }
}



