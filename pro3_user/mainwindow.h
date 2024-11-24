#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

extern QSqlDatabase DB;
extern QString _uid;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void enableSql(bool connected = true);

public slots:
    void setModeView();
    void setModeUser();
    void replyAsk(int id, QString ask);// 回复乘客请求

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
