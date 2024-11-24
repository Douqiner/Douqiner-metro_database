#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>

#include <QtWidgets/QStackedWidget>

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFormLayout>

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>

#include <QtWidgets/QWidget>

#include "side_tool_edit.h"
#include "mygraph_view.h"
#include "mytable.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_use;
    QAction *action_user;

    QStackedWidget * centralwidget;
    MyGraphicsView *myGraphicsView;
    SideToolEdit *sideToolEdit;

    mytable *userwidget;

    void setupUi(QMainWindow *MainWindow)
    {
        //窗口设置
        MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowState(Qt::WindowMaximized);
        MainWindow->setWindowTitle("调度终端");
        // QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        // sizePolicy.setHorizontalStretch(0);
        // sizePolicy.setVerticalStretch(0);
        // sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        // MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/img/day.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        // MainWindow->setStyleSheet(QString::fromUtf8(""));
        //顶部菜单栏
        action_use = new QAction(MainWindow);
        action_user = new QAction(MainWindow);

        action_use->setObjectName("action_use");
        action_user->setObjectName("action_user");

        action_use->setText("线路查询");
        action_user->setText("用户信息");

        QStatusBar *statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        QMenuBar *menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1920, 24));
        menubar->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 255, 213);"));

        QMenu *menu_mode = new QMenu(menubar);
        menu_mode->setTitle("模式切换");
        menu_mode->setObjectName("menu_mode");
        menu_mode->setStyleSheet(QString::fromUtf8("background-color: rgb(15, 131, 255);"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu_mode->menuAction());
        menu_mode->addAction(action_use);
        menu_mode->addAction(action_user);
        //主体
        centralwidget = new QStackedWidget(MainWindow);
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        //使用界面主体
        QWidget *mainwidget = new QWidget(centralwidget);
        mainwidget->setObjectName("mainwidget");

        QHBoxLayout *horizontalLayout = new QHBoxLayout(mainwidget);
        horizontalLayout->setObjectName("horizontalLayout");

        //使用界面主体左
        myGraphicsView = new MyGraphicsView(mainwidget);
        myGraphicsView->setObjectName("graphicsView");

        horizontalLayout->addWidget(myGraphicsView);
        //使用界面主体右
        sideToolEdit = new SideToolEdit(mainwidget);
        sideToolEdit->setMaximumWidth(334);

        horizontalLayout->addWidget(sideToolEdit);

        centralwidget->addWidget(mainwidget);

        //用户界面主体
        userwidget = new mytable("Deal", centralwidget);
        userwidget->setObjectName("userwidget");
        centralwidget->addWidget(userwidget);


        MainWindow->setCentralWidget(centralwidget);
    }
};

namespace Ui {
class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
