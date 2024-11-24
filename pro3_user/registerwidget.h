#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QWidget>

namespace Ui {
class RegisterWidget;
}

class RegisterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWidget(QWidget *parent = nullptr);
    ~RegisterWidget();

public slots:
    void jumpToLogin();
    void startRegister();
    void setErrorText(QString text);
signals:
    void sendJumpToLogin();
    void sendRegister(QString uid, QString password);

private:
    Ui::RegisterWidget *ui;
};

#endif // REGISTERWIDGET_H
