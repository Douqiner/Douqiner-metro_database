#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>

QSqlDatabase DB;
QString filePath;

static bool createConnection(){
    //连接数据库MYSQL
    DB = QSqlDatabase::addDatabase("QODBC");//需要使用的数据库驱动和联检建立的名称（方便建立多个数据库连接【使用不同的数据库时】区分）
    DB.setHostName("127.0.0.1");
    DB.setPort(3306);
    DB.setUserName("root");//数据库账户
    DB.setPassword("123456");//密码

    DB.setDatabaseName("localhost_3306");//需要用到的数据库

    if (!DB.open())
        return false;
    else
        return true;
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // 连接数据库
    w.enableSql(createConnection());

    return a.exec();
}
