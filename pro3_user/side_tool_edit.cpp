#include "side_tool_edit.h"
#include "ui_side_tool_edit.h"

SideToolEdit::SideToolEdit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SideToolEdit)
{
    ui->setupUi(this);

    ui->lineBox->addItem("未选择", 0);

    //颜色
    colorButton = new myColorBotton(this);
    colorButton->setText("颜色");
    ui->horizontalLayout_6->addWidget(colorButton);

    //信息栏
    information = new QStackedWidget(this);
    infoSation = new InfoSation(information);
    infoEdge = new InfoEdge(information);

    information->addWidget(infoSation);
    information->addWidget(infoEdge);
    // information->setMaximumWidth(260);


    ui->verticalLayout_2->addWidget(information);
    information->hide();

    // 时间控件
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit->setCalendarPopup(true);  // 日历弹出

    connect(ui->lineBox, &QComboBox::currentIndexChanged, this, &SideToolEdit::askLineChange);
    //查询请求
    connect(ui->lowDistanceButton, &QPushButton::clicked, this, &SideToolEdit::askLowDistancePath);
    connect(ui->lowChangeButton, &QPushButton::clicked, this, &SideToolEdit::askLowChangePath);
    //提示
    connect(ui->tipsButton, &QPushButton::clicked, this, &SideToolEdit::showTips);
    // 回应乘客请求

}

SideToolEdit::~SideToolEdit()
{
    delete ui;
}

void SideToolEdit::setModeUse()
{
    ui->addEdgeGroup->setVisible(false);
    ui->useBox->setVisible(true);

    //信息栏
    infoSation->setModeUse();
    infoEdge->setModeUse();

    //线路栏
    ui->addLineButton->setVisible(false);
    ui->deleteLineButton->setVisible(false);
    colorButton->setEnabled(false);
    ui->circleCheck->setEnabled(false);
    ui->nameEdit->setReadOnly(true);

}

QDateTime SideToolEdit::getNowTime()
{
    return ui->dateTimeEdit->dateTime();
}

void SideToolEdit::setInfoSation(int id, QString name, int size, QPointF center)
{
    infoSation->setInfo(id, name, size, center);
    information->setCurrentIndex(0);
    information->show();
    ui->addEdgeButton->setEnabled(true);
}

void SideToolEdit::setInfoEdge(int id, qreal weight, int style, int from, int to, QString line0, QString line1)
{
    infoEdge->setInfo(id, weight, style, from, to, line0, line1);
    information->setCurrentIndex(1);
    information->show();
    ui->addEdgeButton->setEnabled(false);
}

void SideToolEdit::setInfoClose()
{
    information->hide();
    ui->addEdgeButton->setEnabled(false);
}

void SideToolEdit::addLine(int index, QString name)
{
    ui->lineBox->addItem(name, index);
}


void SideToolEdit::lineChange(QString name, QColor color, int isCircle)
{
    ui->nameEdit->setText(name);
    colorButton->set_rgb(color.red(), color.green(), color.blue());
    ui->circleCheck->setChecked(isCircle);
}

void SideToolEdit::setPathText(QString way)
{
    ui->wayTextEdit->setPlainText(way);
}

void SideToolEdit::showTips()
{
    QMessageBox message(this);
    message.setWindowTitle("提示");
    message.setIconPixmap(QPixmap(":/icon/img/tips.png"));
    message.setText("模式：查询模式\n\n"
                    "操作：左键单击点或边选中查看信息\n"
                    "滚轮放缩，右键拖动界面\n"
                    "选中线路时将线路虚线标出\n"
                    "查询时将路线虚线标出\n\n"
                    "准备了上海的线路图参考\n");
    message.exec();
}

void SideToolEdit::askLineChange()
{
    int id = ui->lineBox->currentData().toInt();
    emit sendAskLineChange(id);

}

void SideToolEdit::askLowDistancePath()
{
    ui->lineBox->setCurrentIndex(0);
    emit sendAskLineChange(0);
    emit sendAskLowDistancePath(ui->useStartBox->value(), ui->useEndBox->value());
}

void SideToolEdit::askLowChangePath()
{
    ui->lineBox->setCurrentIndex(0);
    emit sendAskLineChange(0);
    emit sendAskLowChangePath(ui->useStartBox->value(), ui->useEndBox->value());
}
