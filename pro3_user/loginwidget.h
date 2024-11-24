#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

public slots:
    void jumpToRegister();
    void startLogin();
    void setErrorText(QString text);
signals:
    void sendJumpToRegister();
    void sendLogin(QString uid, QString password);

private:
    Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H
