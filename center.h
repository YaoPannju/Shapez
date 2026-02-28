#ifndef CENTER_H
#define CENTER_H

#include "device.h"

class Center : public Device
{
    Q_OBJECT
public:
    Item reqItem;
    int reqType, reqNum;
    explicit Center(int x, int y, QObject *parent = nullptr);
    //初始化的时候用的
    void setRequire(int pro, bool reset=true);
    //放到里面去的意思
    void input(QVector<Item *> &ipt, int ix=0, int iy=0) override;
    void draw(QPainter &painter) override;

signals:
    void finishSubsection();
    void finishSection();
};

#endif // CENTER_H
