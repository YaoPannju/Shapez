#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QPainter>

#include "config.h"

class Item : public QObject
{
    Q_OBJECT
public:
    //???
    double show;
    //???
    int rx, ry, type, rotation, proc;
    explicit Item(int rx, int ry, int type,
                  QObject *parent = nullptr); // 传入的是像素 x, y
    ~Item();
    void draw(QPainter &painter);
    bool isSplittable();
    // 是否是三角指示标
    bool isMark();
    // 设置元素类别
    void setType(int type);
    // 设置每个方向上的元素类别
    void setDirType(int d0, int d1, int d2, int d3);
    // 告知这是什么类型的
    int getType();
    // 根据矿物贴图编号获取矿物贴图名称
    QString getDirImage(int tp);
    // 获取某个特定方向的矿物名称
    int getDirType(int direct);
    // 获取移动进度
    int getProcess();
    // 设置移动进度
    void setProcess(int pro);
    // 增量移动进度
    void addProcess(int pro);
    // 增量更新位置
    void addPos(int vx, int vy);
    // 设置元素位置
    void setPos(int rx, int ry);
    // 设置元素位置
    void setPos(QPoint p);
    // 是否可见
    void setShow(bool show);
    // 设置旋转角度
    void setRotation(int rot);
    // 重置进度
    void resetProcess();
    //???
    static Item* markType(int rx, int ry, QObject *parent = nullptr); // 返回一个标准的 mark
signals:
};

#endif // ITEM_H
