#展示数据库
SHOW DATABASES;
#创建数据库
CREATE DATABASE metro_system;
#使用数据库
USE metro_system;

#站点
CREATE TABLE Station(
    Sno INT PRIMARY KEY,
    Sname VARCHAR(20),
    Stransfer INT,
    Sx DOUBLE,
    Sy DOUBLE
);
SELECT * FROM Station;
DELETE FROM Station;
INSERT INTO Station VALUES (1, '站名', 0, 0.0, 0.0);
SELECT MAX(Sno) FROM Station;
#边
CREATE TABLE Edge(
    Eno INT PRIMARY KEY,
    Estart INT,
    Eend INT,
    Elength DOUBLE,
    Etype INT
);
SELECT * FROM Edge;
DELETE FROM Edge;
INSERT INTO Edge VALUES (1, 2, 3, 6.6, 0);
#线路
CREATE TABLE Line(
    Lno INT PRIMARY KEY,
    Lname VARCHAR(50),
    Lcolor VARCHAR(10),
    Lcircle INT
);
SELECT * FROM Line;
DELETE FROM Line;
INSERT INTO Line VALUES (1, '线路名', 111111, 0);
#线路与边所属
CREATE TABLE Belong(
    Eno INT,
    Lno INT,
    PRIMARY KEY (Eno, Lno)
);
SELECT * FROM Belong;
DELETE FROM Belong;
INSERT INTO Belong VALUES (1, 2);

#调度部分
#列车
CREATE TABLE Train(
    Tno INT PRIMARY KEY AUTO_INCREMENT,
    Tmodel VARCHAR(20),
    Ttemperature INT,
    Tcrowd INT
);
SELECT COUNT(*) FROM Train;
SELECT * FROM Train;
SELECT * FROM Train WHERE Tno = 1;
INSERT INTO Train VALUES (NULL, "AC-16", 25, 5);
INSERT INTO Train VALUES (NULL, NULL, NULL, NULL);
#调度
CREATE TABLE Plan(
    Pno INT PRIMARY KEY AUTO_INCREMENT,
    Pline INT,
    Ptrain INT,
    Ptime TIME
);
CREATE INDEX Plan_time_index ON Plan(Ptime ASC);
INSERT INTO Plan VALUES (NULL, NULL, NULL, "23:59:59");
SELECT * FROM Plan;
SELECT * FROM Plan WHERE Pline = 11 AND Ptime >= "5:59:59" ORDER BY Ptime ASC LIMIT 2;
#耗时
CREATE TABLE Costtime(
    Cline INT,
    Ctarget INT,
    Ctime TIME,
    PRIMARY KEY (Cline, Ctarget)
);
SELECT * FROM Costtime;
SELECT * FROM Costtime WHERE Cline = 1 AND Ctarget = 2;
CREATE INDEX Cost_time_index ON Costtime(Ctime ASC);
#嘉定北
INSERT INTO Costtime VALUES (9, 122, "01:21:00");
#花桥
INSERT INTO Costtime VALUES (10, 122, "01:21:00");
#从嘉定北
INSERT INTO Costtime VALUES (11, 122, "00:09:00");
#从花桥
INSERT INTO Costtime VALUES (12, 122, "00:24:00");
#5上海南
INSERT INTO Costtime VALUES (5, 82, "01:12:00");
#6江杨北路
INSERT INTO Costtime VALUES (6, 82, "00:00:00");
#用户部分
#用户
CREATE TABLE User(
    Uid VARCHAR(20) PRIMARY KEY,
    Upassword VARCHAR(100),
    Ubalance NUMERIC(6, 2),
    Ustate VARCHAR(4)
);
SELECT * FROM User;
INSERT INTO User VALUES ("uid", "password", 0, "out");
UPDATE User SET Ustate = "in" WHERE Uid = "18278409587";
UPDATE User SET Ubalance = 3 WHERE Uid = "18278409587";
UPDATE User SET Upassword = "44" WHERE Uid = "uid";
#交易
CREATE TABLE Deal(
    Dno INT PRIMARY KEY AUTO_INCREMENT,
    DUid VARCHAR(20),
    Dstart INT,
    Dend INT,
    Din_time DATETIME,
    Dout_time DATETIME,
    Dcost NUMERIC(4, 2),
    Dtransfer INT
);
--CREATE INDEX Deal_outtime_index ON Deal(Dout_time DESC);
CREATE INDEX Deal_uid_index ON Deal(DUid ASC);
SELECT * FROM Deal;
#新入站
INSERT INTO Deal VALUES (NULL, "uid", 1, NULL, "2024-11-14 15:32:47", NULL, NULL, NULL);
#出站
SELECT * FROM Deal WHERE DUid = "uid" ORDER BY Din_time DESC;
SELECT * FROM Deal WHERE DUid = "uid" 
AND Dtransfer = 1 AND 
Dout_time >= "2024-11-14 15:22:47" AND
Din_time < "2024-11-14 15:52:47"
ORDER BY Dout_time DESC;
UPDATE Deal SET Dend = 2, Dout_time = "2024-11-14 15:32:47", Dcost = 3, Dtransfer = 0 WHERE Dno = 1;