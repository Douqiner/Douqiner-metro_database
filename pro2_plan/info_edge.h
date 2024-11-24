#ifndef INFO_EDGE_H
#define INFO_EDGE_H

#include <QWidget>

namespace Ui {
class InfoEdge;
}

class InfoEdge : public QWidget
{
    Q_OBJECT

public:
    explicit InfoEdge(QWidget *parent = nullptr);
    ~InfoEdge();
    void setInfo(int id, qreal weight, int style, int from, int to, QString line0, QString line1);
    void setModeUse();

    int id;


private:
    Ui::InfoEdge *ui;
};

#endif // INFO_EDGE_H
