#include "mytable.h"
#include "ui_mytable.h"

mytable::mytable(QString sqlTable, int mode, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mytable)
{
    ui->setupUi(this);
    this->sqlTable = sqlTable;
    this->mode = mode;

    QObject::connect(ui->firstButton, &QPushButton::clicked, this, &mytable::firstPage);
    QObject::connect(ui->pastButton, &QPushButton::clicked, this, &mytable::pastPage);
    QObject::connect(ui->nextButton, &QPushButton::clicked, this, &mytable::nextPage);
    QObject::connect(ui->lastButton, &QPushButton::clicked, this, &mytable::lastPage);
    QObject::connect(ui->jumpButton, &QPushButton::clicked, this, &mytable::jumpPage);
    QObject::connect(ui->addButton, &QPushButton::clicked, this, &mytable::addRecord);
    QObject::connect(ui->delButton, &QPushButton::clicked, this, &mytable::delRecord);
    QObject::connect(ui->flushButton, &QPushButton::clicked, this, &mytable::flush);
    QObject::connect(ui->submitButton, &QPushButton::clicked, this, &mytable::updateRecord);
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
        if (getPage == 225095)
        {
            // timecost
            // // 11号线
            // QTime jian910(1,21);
            // QTime jia11(0,9);
            // QTime jia12(0,24);
            // int station[28]={121,120,119,118,117,116,115,114,113,112,64,11,30,110,19,97,98,99,100,101,102,103,104,105,106,107,108,109};
            // int time_sta[28]={3,4,3,4,3,2,2,3,2,2,2,2,3,4,2,3,3,2,2,3,5,2,2,5,3,3,3,4};
            // // 3号线
            // QTime jian5(1,12);
            // QTime jia6(0,0);
            // int station[28]={81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,3,66,65,64,63,31,57,58,59,60,61,62,23};
            // int time_sta[28]={3,3,2,3,2,2,3,3,3,3,3,2,2,3,2,3,3,3,3,2,2,3,2,3,2,3,2,2};
            // QString sqlText1,sqlText2;

            // QSqlQuery query(DB);
            // for (int i = 0; i < 28; ++i)
            // {
            //     jian5 = jian5.addSecs(-time_sta[i] * 60);
            //     jia6 = jia6.addSecs(time_sta[i] * 60);
            //     sqlText1 = "INSERT INTO Costtime VALUES (5, " + QString::number(station[i]) + ", \"" + jian5.toString("HH:mm:ss") + "\");";
            //     sqlText2 = "INSERT INTO Costtime VALUES (6, " + QString::number(station[i]) + ", \"" + jia6.toString("HH:mm:ss") + "\");";
            //     query.exec(sqlText1);
            //     query.next();
            //     query.exec(sqlText2);
            //     query.next();
            // }
            // plan
            // QTime startTime(5,20);
            // QTime endTime(22,35);
            // int two_gap = 8 * 60;
            // int now_train = 0;
            // int l = 61;
            // int mod = 18;
            // QString sqlText1;
            // QSqlQuery query(DB);
            // while (startTime <= endTime)
            // {
            //     sqlText1 = "INSERT INTO Plan VALUES (NULL, 6, " + QString::number(now_train + l) + ", \"" + startTime.toString("HH:mm:ss") + "\");";
            //     query.exec(sqlText1);
            //     query.next();
            //     // qDebug() << sqlText1;
            //     startTime = startTime.addSecs(two_gap);
            //     now_train = (now_train + 1) % mod;
            // }

            message.setText("开放人员使用!\n");
        }
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
        this->model = new mySqlQueryModel(this, DB, this->mode);
        this->model->setTable(this->sqlTable);
        //对所有模型改变立即用到数据库
        this->model->setEditStrategy(QSqlTableModel::OnManualSubmit);

        //设置视图不可编辑
        if (mode == 4)
        {
            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->groupBox_2->setDisabled(true);
        }
        //设置外键  
        ui->tableView->setModel(model);
    }
    model->setPage(this->now_page);
    model->select();
}

void mytable::addRecord()
{
    this->updateRecord();
    QSqlQuery query(DB);
    QString sqlAdd;
    switch (this->mode) {
    case 1:
        sqlAdd = "INSERT INTO Train VALUES (NULL, NULL, NULL, NULL);";
        break;
    case 2:
        sqlAdd = "INSERT INTO Costtime VALUES (0, 0, \"23:59:59\");";
        break;
    case 3:
        sqlAdd = "INSERT INTO Plan VALUES (NULL, NULL, NULL, \"23:59:59\");";
        break;
    default:
        break;
    }

    query.exec(sqlAdd);
    query.next();
    this->flush();
    this->lastPage();
}

void mytable::delRecord()
{
    // 获取选中的行
    int curRow = ui->tableView->currentIndex().row();
    // 删除该行
    model->removeRow(curRow);
    this->updateRecord();
    this->flush();
}

void mytable::updateRecord()
{
    //开启事务
    model->database().transaction();
    if (model->submitAll())
    {
        //提交事务
        model->database().commit();
        QMessageBox message(this);
        message.setWindowTitle("提示");
        message.setIconPixmap(QPixmap(":/icon/img/tips.png"));
        message.setText("唉！好了");
        message.exec();
    }
    else
    {
        //回滚事务
        model->database().rollback();
        QMessageBox message(this);
        message.setWindowTitle("警告");
        message.setIconPixmap(QPixmap(":/icon/img/warn.png"));
        message.setText("数据库错误:\n" + model->lastError().text());
        message.exec();
    }
}
