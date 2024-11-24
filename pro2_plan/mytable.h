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

class mySqlQueryModel : public QSqlTableModel
{
    Q_OBJECT
public:
    mySqlQueryModel(QWidget *parent, QSqlDatabase db, int mode) : QSqlTableModel(parent, db)
    {
        this->mode = mode;
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
            if ((index.column() == 0  && (mode == 1 || mode == 3 || mode == 4)) || ((index.column() == 0 || index.column() == 1) && mode == 2))
            {
                QFont myFont;
                myFont.setBold(true);
                return QVariant(myFont);
            }

        }
        else if(role == Qt::DisplayRole)
        {
            //时间显示
            if ((index.column() == 2 && mode == 2) || (index.column() == 3 && mode == 3))
            {
                QTime q = value.toTime();
                return QVariant(q.toString("hh:mm:ss"));
            }
            else if (mode == 4 && (index.column() == 4 || index.column() == 5))
            {
                QDateTime q = value.toDateTime();
                return QVariant(q.toString("yyyy.MM.dd,hh:mm:ss"));
            }
            //线路外码依赖
            if ((index.column() == 0 && mode == 2) || (index.column() == 1 && mode == 3))
            {
                QSqlQuery query(DB);
                QString sqlCount = "SELECT Lname FROM Line WHERE Lno = " + value.toString() + ";";
                query.exec(sqlCount);
                if (query.next())
                {
                    return query.value(0);
                }
            }
            //站点外码依赖
            if ((index.column() == 1 && mode == 2) || ((index.column() == 2 || index.column() == 3) && mode == 4))
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
        else if(role == Qt::EditRole)
        {
            if ((index.column() == 2 && mode == 2) || (index.column() == 3 && mode == 3))
            {
                QTime q = value.toTime();
                return QVariant(q.toString("hh:mm:ss"));
            }
        }
        return value;
    }
    void setPage(int now_page)
    {
        this->now_page = now_page;
    }
    int mode;
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
    explicit mytable(QString sqlTable, int mode, QWidget *parent = nullptr);
    ~mytable();

public slots:
    void firstPage();
    void pastPage();
    void nextPage();
    void lastPage();
    void jumpPage();

    void flush();
    void addRecord();
    void delRecord();

    void updateRecord();


private:
    int recordNum = 20;
    mySqlQueryModel* model = nullptr;
    QString sqlTable;
    int mode;
    int total_page;
    int now_page = 1;

    Ui::mytable *ui;
};

#endif // MYTABLE_H
