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
    QObject::connect(ui->action_train, &QAction::triggered, this, &MainWindow::setModeTrain);
    QObject::connect(ui->action_cost, &QAction::triggered, this, &MainWindow::setModeCost);
    QObject::connect(ui->action_plan, &QAction::triggered, this, &MainWindow::setModePlan);
    QObject::connect(ui->action_deal, &QAction::triggered, this, &MainWindow::setModeDeal);
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
    ui->action_train->setDisabled(false);
    ui->action_cost->setDisabled(false);
    ui->action_plan->setDisabled(false);
    ui->action_deal->setDisabled(false);
    //切换工作
    ui->centralwidget->setCurrentIndex(0);
}

void MainWindow::setModeTrain()
{
    ui->action_use->setDisabled(false);
    ui->action_train->setDisabled(true);
    ui->action_cost->setDisabled(false);
    ui->action_plan->setDisabled(false);
    ui->action_deal->setDisabled(false);
    //切换工作
    ui->centralwidget->setCurrentIndex(1);
    ui->trainwidget->flush();
}

void MainWindow::setModeCost()
{
    ui->action_use->setDisabled(false);
    ui->action_train->setDisabled(false);
    ui->action_cost->setDisabled(true);
    ui->action_plan->setDisabled(false);
    ui->action_deal->setDisabled(false);
    //切换工作
    ui->centralwidget->setCurrentIndex(2);
    ui->costwidget->flush();
}

void MainWindow::setModePlan()
{
    ui->action_use->setDisabled(false);
    ui->action_train->setDisabled(false);
    ui->action_cost->setDisabled(false);
    ui->action_plan->setDisabled(true);
    ui->action_deal->setDisabled(false);
    //切换工作
    ui->centralwidget->setCurrentIndex(3);
    ui->planwidget->flush();
}

void MainWindow::setModeDeal()
{
    ui->action_use->setDisabled(false);
    ui->action_train->setDisabled(false);
    ui->action_cost->setDisabled(false);
    ui->action_plan->setDisabled(false);
    ui->action_deal->setDisabled(true);
    //切换工作
    ui->centralwidget->setCurrentIndex(4);
    ui->dealwidget->flush();
}


