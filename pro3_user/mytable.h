#ifndef MYTABLE_H
#define MYTABLE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
#include <QDate>

extern QSqlDatabase DB;
extern QString _uid;

class mySqlQueryModel : public QSqlTableModel
{
    Q_OBJECT
public:
    mySqlQueryModel(QWidget *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
    {

    }
    QString selectStatement() const override
    {
        QString strSql = QSqlTableModel::selectStatement();
        strSql += (" LIMIT " + QString::number((now_page - 1) * this->recordNum) + ',' +QString::number(this->recordNum));
        return strSql;
    }
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override
    {
        QVariant value = QSqlTableModel::data(index, role);

        if (role == Qt::FontRole)
        {
            if (index.column() == 0)
            {
                QFont myFont;
                myFont.setBold(true);
                return QVariant(myFont);
            }

        }
        else if(role == Qt::DisplayRole)
        {
            //时间显示
            if (index.column() == 4 || index.column() == 5)
            {
                QDateTime q = value.toDateTime();
                return QVariant(q.toString("yyyy-MM-dd HH:mm:ss"));
            }
            //站点外码依赖
            if (index.column() == 2 || index.column() == 3)
            {
                QSqlQuery query(DB);
                QString sqlCount = "SELECT Sname FROM Station WHERE Sno = " + value.toString() + ";";
                query.exec(sqlCount);
                if (query.next())
                {
                    return query.value(0);
                }
            }
        }
        return value;
    }
    void setPage(int now_page)
    {
        this->now_page = now_page;
    }
    int recordNum = 20;
    int now_page = 1;
};

namespace Ui {
class mytable;
}

class mytable : public QWidget
{
    Q_OBJECT

public:
    explicit mytable(QString sqlTable, QWidget *parent = nullptr);
    ~mytable();

public slots:
    void firstPage();
    void pastPage();
    void nextPage();
    void lastPage();
    void jumpPage();

    void flush();
    void readInfo();
    void updateBalance();
    void checkEditPassword();


private:
    int recordNum = 20;
    mySqlQueryModel* model = nullptr;
    QString sqlTable;
    int total_page;
    int now_page = 1;

    Ui::mytable *ui;
};

#endif // MYTABLE_H
