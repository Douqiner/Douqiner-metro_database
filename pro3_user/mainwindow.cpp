#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sideToolEdit->setModeUse();
    this->setModeView();
    //切换模式
    QObject::connect(ui->action_use, &QAction::triggered, this, &MainWindow::setModeView);
    QObject::connect(ui->action_user, &QAction::triggered, this, &MainWindow::setModeUser);
    //发出信息更新需求
    QObject::connect(ui->myGraphicsView, &MyGraphicsView::showSationInfo, ui->sideToolEdit, &SideToolEdit::setInfoSation);
    QObject::connect(ui->myGraphicsView, &MyGraphicsView::showEdgeInfo, ui->sideToolEdit, &SideToolEdit::setInfoEdge);
    QObject::connect(ui->myGraphicsView, &MyGraphicsView::unshow, ui->sideToolEdit, &SideToolEdit::setInfoClose);
    //线路信息
    QObject::connect(ui->myGraphicsView, &MyGraphicsView::sendReplyAddLine, ui->sideToolEdit, &SideToolEdit::addLine);
    QObject::connect(ui->sideToolEdit, &SideToolEdit::sendAskLineChange, ui->myGraphicsView, &MyGraphicsView::replyLineChange);
    QObject::connect(ui->myGraphicsView, &MyGraphicsView::sendLineInfo, ui->sideToolEdit, &SideToolEdit::lineChange);
    //换乘指南
    QObject::connect(ui->sideToolEdit, &SideToolEdit::sendAskLowDistancePath, ui->myGraphicsView, &MyGraphicsView::replyLowDistance);
    QObject::connect(ui->sideToolEdit, &SideToolEdit::sendAskLowChangePath, ui->myGraphicsView, &MyGraphicsView::replyLowChange);
    QObject::connect(ui->myGraphicsView, &MyGraphicsView::sendPathText, ui->sideToolEdit, &SideToolEdit::setPathText);
    //乘客请求
    QObject::connect(ui->sideToolEdit->infoSation, &InfoSation::sendStationAsk, this, &MainWindow::replyAsk);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enableSql(bool connected)
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
    ui->myGraphicsView->tupo.readsql();
}

void MainWindow::setModeView()
{
    ui->action_use->setDisabled(true);
    ui->action_user->setDisabled(false);
    //切换工作
    ui->centralwidget->setCurrentIndex(0);
}

void MainWindow::setModeUser()
{
    ui->action_use->setDisabled(false);
    ui->action_user->setDisabled(true);
    //切换工作
    ui->centralwidget->setCurrentIndex(1);
    ui->userwidget->flush();
}

void MainWindow::replyAsk(int id, QString ask)
{
    QDateTime now_t = ui->sideToolEdit->getNowTime();
    QString now_str = now_t.toString("yyyy-MM-dd HH:mm:ss");
    if (ask == "in")
    {
        // 检查乘客状态
        QSqlQuery query(DB);
        QString sqlText = "SELECT * FROM User WHERE Uid = \"" + _uid +"\";";
        query.exec(sqlText);
        query.next();
        if (query.value(3).toString() == "in")
        {
            QMessageBox message(this);
            message.setWindowTitle("警告");
            message.setIconPixmap(QPixmap(":/icon/img/warn.png"));
            message.setText("乘客已经进站");
            message.exec();
            return;
        }
        // 乘客进站
        sqlText = "INSERT INTO Deal VALUES (NULL, \"" + _uid + "\", " + QString::number(id) + ", NULL, \"" + now_str + "\", NULL, NULL, NULL);";
        query.exec(sqlText);
        query.next();
        // 乘客状态修改
        sqlText = "UPDATE User SET Ustate = \"in\" WHERE Uid = \"" + _uid + "\";";
        query.exec(sqlText);
        query.next();
        // 通知更新
        ui->userwidget->readInfo();

        QMessageBox message(this);
        message.setWindowTitle("提示");
        message.setIconPixmap(QPixmap(":/icon/img/tips.png"));
        message.setText("入闸成功");
        message.exec();
    }
    else if (ask == "out")
    {
        // 检查乘客状态
        QSqlQuery query(DB);
        QString sqlText = "SELECT * FROM User WHERE Uid = \"" + _uid +"\";";
        query.exec(sqlText);
        query.next();
        qreal balance = query.value(2).toDouble();
        if (query.value(3).toString() == "out")
        {
            QMessageBox message(this);
            message.setWindowTitle("警告");
            message.setIconPixmap(QPixmap(":/icon/img/warn.png"));
            message.setText("乘客已经出站");
            message.exec();
            return;
        }
        // 乘客出站
        // 查找最近deal
        sqlText = "SELECT * FROM Deal WHERE DUid = \"" + _uid + "\" ORDER BY Din_time DESC;";
        query.exec(sqlText);
        query.next();
        int Dno = query.value(0).toInt();
        int from = query.value(2).toInt();
        QDateTime Din_time = query.value(4).toDateTime();
        // 查找入站时间30分钟内最近完成可换乘账单
        QDateTime pasthalf = Din_time.addSecs(-1800);
        bool isTran = false;
        int lastCost = 0;
        if (ui->myGraphicsView->tupo.vInfo[from].sationAt->size)
        {
            sqlText = "SELECT * FROM Deal WHERE DUid = \"" + _uid + "\" AND Dtransfer = 1 AND Dout_time >= \"";
            sqlText += (pasthalf.toString("yyyy-MM-dd HH:mm:ss") + "\"  AND Din_time < \"" + Din_time.toString("yyyy-MM-dd HH:mm:ss"));
            sqlText += ("\" ORDER BY Dout_time DESC;");
            query.exec(sqlText);
            if (query.next())
            {
                isTran = true;
                lastCost = query.value(6).toDouble();
                from = query.value(2).toInt();
            }
        }
        // 检查费用
        int cost = 0;
        qreal distance = ui->myGraphicsView->tupo.pathToLen(ui->myGraphicsView->tupo.lowDistance(from, id));
        if (distance <= 6)
            cost = 3;
        else
            cost = 3 + (int)((distance - 6) / 10);
        if (cost > 7)
            cost = 7;
        if (isTran)
        {
            if (cost - lastCost > 0)
                cost -= lastCost;
            else
                cost = 0;
        }

        if (cost > balance)
        {
            QMessageBox message(this);
            message.setWindowTitle("警告");
            message.setIconPixmap(QPixmap(":/icon/img/warn.png"));
            message.setText("用户余额不足，出站失败");
            message.exec();
            return;
        }
        // 完成交易
        sqlText = "UPDATE Deal SET Dend = " + QString::number(id) + ", Dout_time = \"" + now_str + "\", Dcost = ";
        if (isTran)
            sqlText += (QString::number(cost) + ", Dtransfer = 0");
        else
            sqlText += (QString::number(cost) + ", Dtransfer = " + QString::number(ui->myGraphicsView->tupo.vInfo[id].sationAt->size));
        sqlText += (" WHERE Dno = " + QString::number(Dno) + ";");
        query.exec(sqlText);
        query.next();
        // 乘客状态修改
        sqlText = "UPDATE User SET Ustate = \"out\", Ubalance = " + QString::number(balance - cost, 'f', 2) + " WHERE Uid = \"" + _uid + "\";";
        query.exec(sqlText);
        query.next();
        // 通知更新
        ui->userwidget->readInfo();

        QMessageBox message(this);
        message.setWindowTitle("提示");
        message.setIconPixmap(QPixmap(":/icon/img/tips.png"));
        message.setText("出闸成功，扣费" + QString::number(cost));
        message.exec();
    }
    else
    {
        // 查询调度
        int curLine = ui->myGraphicsView->currentLine;
        // 查找耗时表
        QSqlQuery query(DB);
        QString sqlText = "SELECT * FROM Costtime WHERE Cline = " + QString::number(curLine) + " AND Ctarget = " + QString::number(id) + ";";
        query.exec(sqlText);
        if (!query.next())
        {
            QMessageBox message(this);
            message.setWindowTitle("警告");
            message.setIconPixmap(QPixmap(":/icon/img/warn.png"));
            message.setText("未为此线配置耗时或线站不匹配");
            message.exec();
            return;
        }
        QTime timecost = query.value(2).toTime();
        // qDebug() << timecost;
        // 查找调度表
        QTime lastStartTime = now_t.time().addSecs(-timecost.hour() * 3600 - timecost.minute() * 60 - timecost.second());
        // qDebug() << lastStartTime;
        sqlText = "SELECT * FROM Plan WHERE Pline = " + QString::number(curLine);
        sqlText += (" AND Ptime >= \"" + lastStartTime.toString("HH:mm:ss"));
        sqlText += "\" ORDER BY Ptime ASC LIMIT 2;";
        query.exec(sqlText);

        QString messText;
        for (int i = 0; i < 2; ++i)
        {
            messText += ("下" + QString::number(i + 1) + "辆列车：\n");
            if (query.next())
            {
                QTime startTime = query.value(3).toTime();
                QTime gapTime(0, 0);
                gapTime = gapTime.addSecs(lastStartTime.secsTo(startTime));
                messText += ("剩余到达时间：" + gapTime.toString("HH:mm:ss") + "\n");
                int Tid = query.value(2).toInt();
                messText += ("列车号：" + QString::number(Tid) + "\n");

                // 查询列车信息
                QSqlQuery query2(DB);
                QString sqlText2 = "SELECT * FROM Train WHERE Tno = " + QString::number(Tid) + ";";
                query2.exec(sqlText2);
                query2.next();
                messText += ("列车温度：" + QString::number(query2.value(2).toInt()));
                messText += ("  拥挤度：" + QString::number(query2.value(3).toInt()) + "\n\n");
            }
            else
            {
                messText += "无信息\n\n";
            }
        }

        QMessageBox message(this);
        message.setWindowTitle("提示");
        message.setIconPixmap(QPixmap(":/icon/img/tips.png"));
        message.setText(messText);
        message.exec();
    }
}
