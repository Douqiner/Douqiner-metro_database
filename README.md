这是2024年同济大学数据库课设大作业

（目前还未提交，请不要全盘复制）

本项目由3个程序构成，基本（主要是第一个）都由之前的项目衍生而成

## 程序1：pro1_tupo
在本人项目 [metro_system](https://github.com/Douqiner/metro_system)
的基础上加入了保存至数据库功能

![save_to_base](/static_show/save_to_base.png)

## 程序2：pro2_plan
对调度相关的数据库表进行查询修改（列车、耗时、调度）

![plan_cost](/static_show/plan_cost.png)

![plan_train](/static_show/plan_train.png)

对交易进行查询

## 程序3：pro3_user
用户进行登录、注册，可以入站出站（注意时间的先后，本程序默认是现实中发生的情况，不会考虑先出站再入站的情况）

支持一次换乘，即在可换乘站（大站）下车后30分钟内再次进入可换乘站，费用接续计算

![deal](/static_show/deal.png)

指定站点和线路可以查询下1趟车、下2趟车时间

![show](/static_show/show.png)

## 数据库及连接
采用mysql数据库，由于Qt不自带mysql接口库，使用非常麻烦，故使用ODBC进行中转连接

建库以及相关查询语句见merto.sql
