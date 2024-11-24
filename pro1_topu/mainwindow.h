#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QShortcut>

extern QString filePath;

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

    void askRead();
    void enableSql(bool connected = true);

public slots:
    void setSideToolView();
    void setSideToolEdit();
    void setTitleEdited(bool edited);

    void askSave();
    void askSavesql();
    void askOther();

signals:
    void sendAskSave(QString filePath);
    void sendAskSavesql();
    void sendAskOther(QString filePath);
    void sendAskRead(QString filePath);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
