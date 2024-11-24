#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void enableSql(bool connected = true);

public slots:
    void setModeView();
    void setModeTrain();
    void setModeCost();
    void setModePlan();
    void setModeDeal();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
