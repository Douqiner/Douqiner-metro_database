#include "mygraph_view.h"
#include <queue>
#include <algorithm>

AbstractGraph::AbstractGraph(MyGraphicsView* view) {
    this->view = view;

    //初始有一条默认线路“未选择”,标识所有未选择线路
    lInfo.append(lNode());
    lMaxId = 0;
    lNum += 1;

    lInfo[0].isExist = false;
    lInfo[0].color = nullColor;
    lInfo[0].isCircle = -1;
    lInfo[0].name = "未选择";

}

bool AbstractGraph::checkExist(int from, int to) {
    if (from > vMaxId || to > vMaxId)
        return false;
    if (!vInfo[from].isExist || !vInfo[to].isExist)
        return false;
    return true;
}

bool AbstractGraph::checkNoLoop(int from, int to) {
    if (from == to)
        return false;
    else
        return true;
}

bool AbstractGraph::checkNoRepetition(int from, int to) {
    for (int e = vInfo[from].posFirst; e != -1; e = posList[e]) {
        if (eInfo[e].to == to)
            return false;
    }
    return true;
}

void AbstractGraph::readsql()
{
    /* 数据库操作 */
    QSqlQuery query(DB);
    //点
    query.exec("SELECT MAX(Sno) FROM Station;");
    query.next();
    vMaxId = query.value(0).toInt();
    vInfo.resize(vMaxId + 1);

    vNum = 0;
    query.exec("SELECT * FROM Station;");
    while (query.next()) {
        vNode v;
        v.isExist = 1;
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        int size = query.value(2).toInt();
        qreal x = query.value(3).toDouble();
        qreal y = query.value(4).toDouble();

        // 新建item
        v.sationAt = new MySationItem(id, QPointF(x, y), size, name, view);
        view->myGraphicsScene->addItem(v.sationAt);
        vInfo[id] = v;

        vNum++;
    }
    //线路
    query.exec("SELECT MAX(Lno) FROM Line;");
    query.next();
    lMaxId = query.value(0).toInt();
    lInfo.resize(lMaxId + 1);

    lNum = 0;
    query.exec("SELECT * FROM Line;");
    while (query.next()) {
        lNode l;
        l.isExist = 1;
        int id = query.value(0).toInt();
        l.name = query.value(1).toString();
        QString colorStr = query.value(2).toString();
        l.color = QColor(colorStr.toUInt(NULL,16));
        l.isCircle = query.value(3).toInt();
        lInfo[id] = l;

        view->tellAddLine(id, l.name);

        lNum++;
    }
    //边和边线所属
    query.exec("SELECT MAX(Eno) FROM Edge;");
    query.next();

    eMaxId = query.value(0).toInt();
    eInfo.resize(eMaxId + 1);
    posList.resize(eMaxId + 1, -1);
    invList.resize(eMaxId + 1, -1);

    eNum = 0;
    query.exec("SELECT * FROM Edge;");
    while (query.next()) {
        eNode e;
        e.isExist = 1;
        int id = query.value(0).toInt();
        e.from = query.value(1).toInt();
        e.to = query.value(2).toInt();
        e.weight = query.value(3).toDouble();
        int style = query.value(4).toInt();

        // 修改正逆邻接表(头插法)
        posList[id] = vInfo[e.from].posFirst;
        vInfo[e.from].posFirst = id;
        ++vInfo[e.from].outDegree;

        invList[id] = vInfo[e.to].invFirst;
        vInfo[e.to].invFirst = id;
        ++vInfo[e.to].inDegree;

        eInfo[id] = e;

        // 新建item
        eInfo[id].edgeAt = new MyEdgeItem(id, (enum myShape)style, view);
        eInfo[id].edgeAt->setZValue(-1);
        view->myGraphicsScene->addItem(eInfo[id].edgeAt);

        eNum++;
    }
    query.exec("SELECT * FROM Belong;");
    while (query.next()) {
        int eid = query.value(0).toInt();
        int lid = query.value(1).toInt();

        //修改边上线路
        if (eInfo[eid].belongLine[0])
            eInfo[eid].belongLine[1] = lid;
        else
            eInfo[eid].belongLine[0] = lid;
        //更新线路的边集合
        lInfo[lid].contain.insert(eid);
    }
    for (eNode e : eInfo) {
        if (e.isExist)
            e.edgeAt->reSetStyle();
    }
}


QVector<int> AbstractGraph::lowDistance(int from, int to)
{
    //用于搜索的结构体
    struct disNode {
        int v;        // 当前点编号
        double g;     // 当前走过路径
        int edgeFrom; // 此节点来自哪条边
        bool operator<(const disNode &b) const
        {
            return g > b.g;
        }
    };

    // 优先队列
    std::priority_queue<disNode> q;
    // 路径记录 某个点来自哪条边
    QVector<int> path(vMaxId + 1, -1);
    // 路径 顺序边记录
    QVector<int> ans;
    // 起点
    disNode startNode;
    startNode.v      = from;
    startNode.g        = 0;
    startNode.edgeFrom = -2;
    q.push(startNode);

    while (!q.empty()) {
        disNode curNode = q.top();
        q.pop();

        // 判断是否拓展
        if (path[curNode.v] != -1)
            continue;
        else
            path[curNode.v] = curNode.edgeFrom;

        if (curNode.v == to) {
            // 找到终点 计算路径
            int cur      = curNode.v;
            int edgeFrom = curNode.edgeFrom;

            while (path[cur] != -2) {
                ans.push_back(edgeFrom);
                cur      = eInfo[path[cur]].from;
                edgeFrom = path[cur];
            }
            std::reverse(ans.begin(), ans.end());
            break;
        }

        // 拓展节点
        for (int i = vInfo[curNode.v].posFirst; i != -1; i = posList[i]) {
            disNode nextNode;
            nextNode.v        = eInfo[i].to;
            nextNode.g        = curNode.g + eInfo[i].weight;
            nextNode.edgeFrom = i;

            q.push(nextNode);
        }
    }

    return ans;
}


QVector<int> AbstractGraph::lowChange(int from, int to)
{
    //用于搜索的结构体
    struct chgNode {
        int v;        // 当前点编号
        int change;   // 当前换乘次数(包括第一次)
        int l;        // 当前线路
        int edgeFrom; // 此节点来自哪条边
        int pathFrom; // 此节点来自哪个路径记录节点
        bool operator<(const chgNode &b) const
        {
            return change > b.change;
        }
    };
    //用于路径记录的结构体
    struct chgPath {
        int edgeFrom; // 此节点来自哪条边
        int pathFrom; // 此节点来自哪个路径记录节点
        chgPath(int e, int p) {
            edgeFrom = e;
            pathFrom = p;
        }
    };

    // 优先队列
    std::priority_queue<chgNode> q;
    // 访问记录 某个点未访问为-1，访问过记录换乘数
    QVector<int> vis(vMaxId + 1, -1);
    // 路径记录 某个搜索节点来自哪条边和哪个路径记录节点
    QVector<chgPath> path;
    // 路径 顺序边记录
    QVector<int> ans;
    // 起点
    chgNode startNode;
    startNode.v      = from;
    startNode.change = 0;
    startNode.l      = -1;
    startNode.edgeFrom = -2;
    startNode.pathFrom = -1;
    q.push(startNode);

    while (!q.empty()) {
        chgNode curNode = q.top();
        q.pop();

        // 判断是否拓展
        //换乘具有特殊性，到达同一点可能位于不同线路，因此相等情况不能直接跳过
        if (vis[curNode.v] != -1 && curNode.change > vis[curNode.v])
            continue;
        else {
            vis[curNode.v] = curNode.change;

            chgPath nowPath(curNode.edgeFrom, curNode.pathFrom);
            path.append(nowPath);
        }

        if (curNode.v == to) {
            // 找到终点 计算路径
            int curPathId = path.size() - 1;
            int edgeFrom  = path[curPathId].edgeFrom;

            while (path[curPathId].pathFrom != -1) {
                ans.push_back(edgeFrom);
                curPathId = path[curPathId].pathFrom;
                edgeFrom = path[curPathId].edgeFrom;
            }
            std::reverse(ans.begin(), ans.end());
            break;
        }

        // 拓展节点
        for (int i = vInfo[curNode.v].posFirst; i != -1; i = posList[i]) {
            QSet nextLine = eInfo[i].getLineSet();
            chgNode nextNode;
            for (int l : nextLine) {
                nextNode.v        = eInfo[i].to;
                nextNode.l        = l;
                nextNode.edgeFrom = i;
                nextNode.pathFrom = path.size() - 1;
                if (curNode.l != l)
                    nextNode.change = curNode.change + 1;
                else
                    nextNode.change = curNode.change;
                q.push(nextNode);
            }
        }
    }

    return ans;
}

QString AbstractGraph::pathToText(QVector<int> path)
{
    if (path.size() == 0)
        return "无路可走";

    qreal distance = eInfo[path[0]].weight;

    QSet<int> line = eInfo[path[0]].getLineSet();
    int change = 0;

    QString text;

    for (int i = 1; i < path.size(); ++i) {
        int e = path[i];
        distance += eInfo[e].weight;

        //换乘检测
        QSet<int> nextLine = eInfo[path[i]].getLineSet();
        const QSet<int> copyLine = line;

        for (int l : copyLine) {
            //若无法接着走，选择换乘
            if (nextLine.find(l) == nextLine.end()) {
                if (line.size() >= 2)
                    line.remove(l);
                else {
                    //进行换乘 输出文本
                    text += QString::number(change + 1);
                    text += ": 换乘 ";
                    bool huo = false;
                    for (int t : copyLine) {
                        if (copyLine.size() >= 2) {
                            if (huo)
                                text += " 或 ";
                            else
                                huo = true;
                        }
                        text += lInfo[t].name;
                    }
                    text += " 至 ";
                    text += vInfo[eInfo[e].from].sationAt->name;
                    text += ";\n";

                    line = nextLine;
                    ++change;
                }
            }
        }
    }

    //最后一站
    text += QString::number(change + 1);
    text += ": 换乘 ";
    bool huo = false;
    for (int t : line) {
        if (line.size() >= 2) {
            if (huo)
                text += " 或 ";
            else
                huo = true;
        }
        text += lInfo[t].name;
    }
    text += " 至 ";
    text += vInfo[eInfo[path[path.size() - 1]].to].sationAt->name;
    text += ";\n";


    text += "总路程公里: ";
    text += QString::number(distance);
    text += ",总换乘次数: ";
    text += QString::number(change);

    return text;
}

qreal AbstractGraph::pathToLen(QVector<int> path)
{
    qreal distance = 0;
    for (int i = 0; i < path.size(); ++i) {
        int e = path[i];
        distance += eInfo[e].weight;
    }
    return distance;
}

void MyGraphicsView::setNewSelected(QGraphicsItem* newSelectItem) {
    if (newSelectItem) {
        newSelectItem->setSelected(true);

        // 发出更新信息
        if (newSelectItem->type() == myType::mySationItem) {
            MySationItem* sation = (MySationItem*)newSelectItem;
            emit showSationInfo(sation->id, sation->name, sation->size,
                                sation->getCenter());
        } else if (newSelectItem->type() == myType::myEdgeItem) {
            MyEdgeItem* edge = (MyEdgeItem*)newSelectItem;
            int id = edge->id;
            QString line0, line1;
            line0 = tupo.lInfo[tupo.eInfo[id].belongLine[0]].name;
            line1 = tupo.lInfo[tupo.eInfo[id].belongLine[1]].name;

            emit showEdgeInfo(id, tupo.eInfo[id].weight, edge->style,
                              tupo.eInfo[id].from, tupo.eInfo[id].to, line0,
                              line1);
        }

        SELECTED = true;
        if (selectItem && newSelectItem != selectItem) {
            selectItem->setSelected(false);
        }
        selectItem = newSelectItem;
    } else {
        SELECTED = false;

        // 发出无需显示信息
        emit unshow();

        if (selectItem) {
            selectItem->setSelected(false);
        }
        selectItem = newSelectItem;
    }
}

MyGraphicsView::MyGraphicsView(QWidget* parent) : QGraphicsView{parent} {
    myGraphicsScene = new QGraphicsScene(parent);

    this->setScene(myGraphicsScene);
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
    this->setSceneRect(this->rect());
    this->centerOn(0, 0);

    // this->setMouseTracking(true);

    // 无滑轮
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 抗锯齿
    this->setRenderHint(QPainter::Antialiasing);

    // 指针
    this->setCursor(backModeCurser());

    // this->show();
}

enum Qt::CursorShape MyGraphicsView::backModeCurser() {
    return Qt::ArrowCursor;
}


MyGraphicsView::~MyGraphicsView() {
    myGraphicsScene->clear();
}

void MyGraphicsView::wheelEvent(QWheelEvent* event) {
#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
    QPointF cursorPoint = event->position();
#else
    QPointF cursorPoint = event->posF();
#endif
    QPointF scenePos =
        this->mapToScene(QPoint(cursorPoint.x(), cursorPoint.y()));

    qreal scaleFactor = this->transform().m11();
    int wheelDeltaValue = event->angleDelta().y();
    if (wheelDeltaValue > 0) {
        if (scaleFactor > 2)
            return;
        this->scale(1.1, 1.1);
    } else {
        if (scaleFactor < 0.5)
            return;
        this->scale(1.0 / 1.1, 1.0 / 1.1);
    }
    this->centerOn(scenePos);
}

void MyGraphicsView::mousePressEvent(QMouseEvent* event) {
    setNewSelected(nullptr);
    if (event->button() == Qt::RightButton) {
        onRightPress = true;
        lastPos = mapToScene(event->pos());
        setCursor(Qt::ClosedHandCursor);
    } else if (!onRightPress && event->button() == Qt::LeftButton) {
        QGraphicsItem* find = nullptr;
        QList<QGraphicsItem*> finds = this->items(event->pos());
        foreach (QGraphicsItem* i, finds) {
            if (i && (i->type() == myType::mySationItem ||
                      i->type() == myType::myEdgeItem)) {
                find = i;
                break;
            }
        }

        if (find) {
            // 正在点击图元设置选中
            onLeftPress = true;
            setCursor(Qt::ClosedHandCursor);
            setNewSelected(find);
        }
    }
    QGraphicsView::mousePressEvent(event);
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent* event) {
    if (onRightPress && !(event->buttons() & Qt::RightButton)) {
        onRightPress = false;
        setCursor(backModeCurser());
    }
    if (onLeftPress && !(event->buttons() & Qt::LeftButton)) {
        onLeftPress = false;
        setCursor(backModeCurser());
    }

    QGraphicsView::mouseReleaseEvent(event);
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent* event) {
    if (onRightPress) {
        QPointF dp = mapToScene(event->pos()) - lastPos;
        setSceneRect(sceneRect().x() - dp.x(), sceneRect().y() - dp.y(),
                     sceneRect().width(), sceneRect().height());
        lastPos = mapToScene(event->pos());
    }
    QGraphicsView::mouseMoveEvent(event);
}


void MyGraphicsView::tellAddLine(int index, QString name)
{
    emit sendReplyAddLine(index, name);
}

void MyGraphicsView::replyLineChange(int id)
{
    //线路切换相关工作
    if (id != currentLine) {
        //通知信息
        if (id != 0)
            emit sendLineInfo(tupo.lInfo[id].name, tupo.lInfo[id].color, tupo.lInfo[id].isCircle);
        //切换工作
        //清除旧的
        if (SHOWING) {
            for (int e : showPath) {
                tupo.eInfo[e].edgeAt->setChoosed(false);
            }
            showPath.clear();
            SHOWING = false;
        }
        for (int e : tupo.lInfo[currentLine].contain){
            tupo.eInfo[e].edgeAt->setChoosed(false);
        }
        //标记新的
        for (int e : tupo.lInfo[id].contain){
            tupo.eInfo[e].edgeAt->setChoosed(true);
        }
        currentLine = id;
    }
}


void MyGraphicsView::replyLowDistance(int from, int to)
{
    QMessageBox message(this);
    message.setWindowTitle("警告");
    message.setIconPixmap(QPixmap(":/icon/img/warn.png"));

    if (!tupo.checkExist(from, to)) {
        message.setText("指定的点不存在");
        message.exec();
        return;
    }

    if (!tupo.checkNoLoop(from, to)) {
        message.setText("已经到了");
        message.exec();
        return;
    }

    if (SHOWING) {
        for (int e : showPath) {
            tupo.eInfo[e].edgeAt->setChoosed(false);
        }
        showPath.clear();
        SHOWING = false;
    }

    // 调用查找函数
    showPath = tupo.lowDistance(from, to);
    // 标亮查找到的边
    for (int e : showPath) {
        tupo.eInfo[e].edgeAt->setChoosed(true);
    }
    SHOWING = true;
    // 回复文本
    QString info = "起点站: " + tupo.vInfo[from].sationAt->name + ",终点站: " + tupo.vInfo[to].sationAt->name + "\n";
    emit sendPathText(info + tupo.pathToText(showPath));
}

void MyGraphicsView::replyLowChange(int from, int to)
{
    QMessageBox message(this);
    message.setWindowTitle("警告");
    message.setIconPixmap(QPixmap(":/icon/img/warn.png"));

    if (!tupo.checkExist(from, to)) {
        message.setText("指定的点不存在");
        message.exec();
        return;
    }

    if (!tupo.checkNoLoop(from, to)) {
        message.setText("已经到了");
        message.exec();
        return;
    }

    if (SHOWING) {
        for (int e : showPath) {
            tupo.eInfo[e].edgeAt->setChoosed(false);
        }
        showPath.clear();
        SHOWING = false;
    }

    // 调用查找函数
    showPath = tupo.lowChange(from, to);
    // 标亮查找到的边
    for (int e : showPath) {
        tupo.eInfo[e].edgeAt->setChoosed(true);
    }
    SHOWING = true;

    // 回复文本
    QString info = "起点站: " + tupo.vInfo[from].sationAt->name + ",终点站: " + tupo.vInfo[to].sationAt->name + "\n";
    emit sendPathText(info + tupo.pathToText(showPath));
}



/*------------------------------MySationItem------------------------------*/

MySationItem::MySationItem(int id,
                           QPointF center,
                           int size,
                           QString name,
                           MyGraphicsView* view)
    : QGraphicsEllipseItem() {
    this->id = id;
    this->size = size;
    this->name = name;
    this->view = view;

    setFlag(ItemIsSelectable);
    setFlag(ItemSendsScenePositionChanges);

    setPen(myPen);
    // 画刷 - 背景色
    setBrush(myBrush);

    setRect(QRect(center.x() - sizeToRadius[size],
                  center.y() - sizeToRadius[size], 2 * sizeToRadius[size],
                  2 * sizeToRadius[size]));
    // 文字
    this->text = new QGraphicsTextItem(name, this);
    text->setFont(myFont);
    text->setPos(this->rect().x() + 2 * sizeToRadius[size],
                 this->rect().y() - sizeToRadius[size] - fontSize - 2);
}

MySationItem::~MySationItem()
{
    if (text)
        delete text;
}

void MySationItem::rePaint(QPointF center) {
    setRect(QRect(-sizeToRadius[size], -sizeToRadius[size],
                  2 * sizeToRadius[size], 2 * sizeToRadius[size]));
    setPos(center.x(), center.y());
    // 文字
    text->setPlainText(name);
    text->setPos(this->rect().x() + 2 * sizeToRadius[size],
                 this->rect().y() - sizeToRadius[size] - fontSize - 2);
    itemChange(ItemScenePositionHasChanged, QVariant());
}


QPointF MySationItem::getCenter() {
    return mapToScene(rect().center());
}

/*------------------------------MyEdgeItem------------------------------*/
MyEdgeItem::MyEdgeItem(int id, enum myShape style, MyGraphicsView* view)
    : QGraphicsPathItem() {
    this->id = id;
    this->view = view;
    this->style = style;

    secondLine = new QGraphicsPathItem(this);

    setFlag(ItemIsSelectable);
    setFlag(ItemIsMovable, false);

    reSetStyle();
    reSetPath();
}

void MyEdgeItem::reSetStyle() {
    // 颜色
    QColor color0 = view->tupo.lInfo[view->tupo.eInfo[id].belongLine[0]].color;
    QColor color1 = view->tupo.lInfo[view->tupo.eInfo[id].belongLine[1]].color;
    Qt::PenStyle style = Qt::SolidLine;

    if (CHOOSED)
        style = Qt::DashLine;

    switch (view->tupo.eInfo[id].getLineNum()) {
        case 0:
            break;
        case 1:
            if (view->tupo.eInfo[id].belongLine[0])
                color1 = color0;
            else
                color0 = color1;
            break;
        case 2:
            break;
        default:
            break;
    }
    this->setPen(QPen(color0, myPenWidth / 2, style));
    secondLine->setPen(QPen(color1, myPenWidth / 2, style));
}

void MyEdgeItem::reSetPath() {
    // 获取起点和终点
    QPointF startCenter =
        view->tupo.vInfo[view->tupo.eInfo[id].from].sationAt->getCenter();
    QPointF endCenter =
        view->tupo.vInfo[view->tupo.eInfo[id].to].sationAt->getCenter();

    QPainterPath pathL;
    QPainterPath pathR;

    switch((int)style){
    case (int)myShape::straight:{
        // 线样式
        qreal len = sqrt(
            (startCenter.x() - endCenter.x()) * (startCenter.x() - endCenter.x()) +
            (startCenter.y() - endCenter.y()) * (startCenter.y() - endCenter.y()));
        qreal sina = (endCenter.x() - startCenter.x()) / len;
        qreal cosa = (endCenter.y() - startCenter.y()) / len;
        // 一直线
        QPointF startL = QPointF(startCenter.x() - edgeSpace * cosa,
                                 startCenter.y() + edgeSpace * sina);
        QPointF endL = QPointF(endCenter.x() - edgeSpace * cosa,
                               endCenter.y() + edgeSpace * sina);
        QPointF leftArrowPos = (startL + endL * 2) / 3;
        pathL.moveTo(startL);
        pathL.lineTo(endL);
        // 加左箭头
        QPointF leftArrowEnd =
            QPointF(leftArrowPos.x() - (sina * cos(arrowAngle) - cosa * sin(arrowAngle)) * arrowLength,
                    leftArrowPos.y() - (cosa * cos(arrowAngle) + sina * sin(arrowAngle)) * arrowLength);
        pathL.moveTo(leftArrowEnd);
        pathL.lineTo(leftArrowPos);
        // this->setPath(pathL);

        // 二直线
        QPointF startR =
            QPointF(startCenter.x() - (edgeSpace + myPenWidth / 2) * cosa,
                    startCenter.y() + (edgeSpace + myPenWidth / 2) * sina);
        QPointF endR = QPointF(endCenter.x() - (edgeSpace + myPenWidth / 2) * cosa,
                               endCenter.y() + (edgeSpace + myPenWidth / 2) * sina);
        QPointF rightArrowPos = (startR + endR * 2) / 3;
        pathR.moveTo(startR);
        pathR.lineTo(endR);
        // 加右箭头
        QPointF rightArrowEnd =
            QPointF(rightArrowPos.x() - (sina * cos(arrowAngle) + cosa * sin(arrowAngle)) * arrowLength,
                    rightArrowPos.y() - (cosa * cos(arrowAngle) - sina * sin(arrowAngle)) * arrowLength);
        pathR.moveTo(rightArrowEnd);
        pathR.lineTo(rightArrowPos);
        secondLine->setPath(pathR);

        // 碰撞范围
        pathL.addPath(pathR);
        this->setPath(pathL);
    }
        break;

    case (int)myShape::cross_down: {
        //先横后竖
        // 一折线
        QPointF startL;
        if (startCenter.x() < endCenter.x())
            startL = QPointF(startCenter.x(), startCenter.y() + edgeSpace);
        else
            startL = QPointF(startCenter.x(), startCenter.y() - edgeSpace);

        QPointF endL;
        if (startCenter.y() < endCenter.y())
            endL = QPointF(endCenter.x() - edgeSpace, endCenter.y());
        else
            endL = QPointF(endCenter.x() + edgeSpace, endCenter.y());

        QPointF midL = QPointF(endL.x(), startL.y());

        QPointF leftArrowPos = (midL + endL) / 2;
        pathL.moveTo(startL);
        pathL.lineTo(midL);
        pathL.moveTo(midL);
        pathL.lineTo(endL);
        // 加左箭头
        qreal a;
        if (startCenter.y() < endCenter.y())
            a = M_PI / 2;
        else
            a = -M_PI / 2;

        QPointF leftArrowEnd =
            QPointF(leftArrowPos.x() - (cos(a) * cos(arrowAngle) - sin(a) * sin(arrowAngle)) * arrowLength,
                    leftArrowPos.y() - (sin(a) * cos(arrowAngle) + cos(a) * sin(arrowAngle)) * arrowLength);
        pathL.moveTo(leftArrowEnd);
        pathL.lineTo(leftArrowPos);
        // this->setPath(pathL);

        // 二折线
        QPointF startR;
        if (startCenter.x() < endCenter.x())
            startR = QPointF(startCenter.x(), startCenter.y() + (edgeSpace + myPenWidth / 2));
        else
            startR = QPointF(startCenter.x(), startCenter.y() - (edgeSpace + myPenWidth / 2));

        QPointF endR;
        if (startCenter.y() < endCenter.y())
            endR = QPointF(endCenter.x() - (edgeSpace + myPenWidth / 2), endCenter.y());
        else
            endR = QPointF(endCenter.x() + (edgeSpace + myPenWidth / 2), endCenter.y());

        QPointF midR = QPointF(endR.x(), startR.y());

        QPointF rightArrowPos = (midR + endR) / 2;
        rightArrowPos.setY(leftArrowPos.y());
        pathR.moveTo(startR);
        pathR.lineTo(midR);
        pathR.moveTo(midR);
        pathR.lineTo(endR);

        // 加右箭头
        QPointF rightArrowEnd =
            QPointF(rightArrowPos.x() - (cos(a) * cos(arrowAngle) + sin(a) * sin(arrowAngle)) * arrowLength,
                    rightArrowPos.y() - (sin(a) * cos(arrowAngle) - cos(a) * sin(arrowAngle)) * arrowLength);
        pathR.moveTo(rightArrowEnd);
        pathR.lineTo(rightArrowPos);
        secondLine->setPath(pathR);

        // 碰撞范围
        pathL.addPath(pathR);
        this->setPath(pathL);
    }
        break;

    case (int)myShape::down_cross: {
        //先横后竖
        // 一折线
        QPointF startL;
        if (startCenter.y() < endCenter.y())
            startL = QPointF(startCenter.x() - edgeSpace, startCenter.y());
        else
            startL = QPointF(startCenter.x() + edgeSpace, startCenter.y());

        QPointF endL;
        if (startCenter.x() < endCenter.x())
            endL = QPointF(endCenter.x(), endCenter.y() + edgeSpace);
        else
            endL = QPointF(endCenter.x(), endCenter.y() - edgeSpace);

        QPointF midL = QPointF(startL.x(), endL.y());

        QPointF leftArrowPos = (midL + endL) / 2;
        pathL.moveTo(startL);
        pathL.lineTo(midL);
        pathL.moveTo(midL);
        pathL.lineTo(endL);
        // 加左箭头
        qreal a;
        if (startCenter.x() < endCenter.x())
            a = 0;
        else
            a = M_PI;

        QPointF leftArrowEnd =
            QPointF(leftArrowPos.x() - (cos(a) * cos(arrowAngle) - sin(a) * sin(arrowAngle)) * arrowLength,
                    leftArrowPos.y() - (sin(a) * cos(arrowAngle) + cos(a) * sin(arrowAngle)) * arrowLength);
        pathL.moveTo(leftArrowEnd);
        pathL.lineTo(leftArrowPos);
        // this->setPath(pathL);

        // 二折线
        QPointF startR;
        if (startCenter.y() < endCenter.y())
            startR = QPointF(startCenter.x() - (edgeSpace + myPenWidth / 2), startCenter.y());
        else
            startR = QPointF(startCenter.x() + (edgeSpace + myPenWidth / 2), startCenter.y());

        QPointF endR;
        if (startCenter.x() < endCenter.x())
            endR = QPointF(endCenter.x(), endCenter.y() + (edgeSpace + myPenWidth / 2));
        else
            endR = QPointF(endCenter.x(), endCenter.y() - (edgeSpace + myPenWidth / 2));

        QPointF midR = QPointF(startR.x(), endR.y());

        QPointF rightArrowPos = (midR + endR) / 2;
        rightArrowPos.setX(leftArrowPos.x());
        pathR.moveTo(startR);
        pathR.lineTo(midR);
        pathR.moveTo(midR);
        pathR.lineTo(endR);
        // 加右箭头
        QPointF rightArrowEnd =
            QPointF(rightArrowPos.x() - (cos(a) * cos(arrowAngle) + sin(a) * sin(arrowAngle)) * arrowLength,
                    rightArrowPos.y() - (sin(a) * cos(arrowAngle) - cos(a) * sin(arrowAngle)) * arrowLength);
        pathR.moveTo(rightArrowEnd);
        pathR.lineTo(rightArrowPos);
        secondLine->setPath(pathR);

        // 碰撞范围
        pathL.addPath(pathR);
        this->setPath(pathL);
    }
        break;

    }
}

void MyEdgeItem::setChoosed(bool choosed)
{
    if (CHOOSED ^ choosed) {
        CHOOSED = choosed;
        reSetStyle();
    }
}
