#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <loginwidget.h>
#include <registerwidget.h>
#include <QStackedWidget>
#include <QSqlDatabase>
#include <mainwindow.h>

extern QSqlDatabase DB;
extern MainWindow* the_w_main;
extern QString _uid;

namespace Ui {
class StartWindow;
}

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();
    void startMainWindow();
    void enableSql(bool connected = true);

public slots:
    void recieveLogin(QString uid, QString password);
    void recieveRegister(QString uid, QString password);
    void jumpToLogin();
    void jumpToRegister();

private:
    Ui::StartWindow *ui;
    LoginWidget *loginWidget;
    RegisterWidget *registerWidget;
    QStackedWidget *mainStack;
};

#endif // STARTWINDOW_H
