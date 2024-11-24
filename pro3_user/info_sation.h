#ifndef INFO_SATION_H
#define INFO_SATION_H

#include <QWidget>

namespace Ui {
class InfoSation;
}

class InfoSation : public QWidget
{
    Q_OBJECT

public:
    explicit InfoSation(QWidget *parent = nullptr);
    ~InfoSation();
    void setInfo(int id, QString name, int size, QPointF center);
    void setModeUse();

    int id;

public slots:
    void inStation();
    void outStation();
    void showStation();
signals:
    void sendStationAsk(int id, QString ask);

private:
    Ui::InfoSation *ui;
};

#endif // INFO_SATION_H
