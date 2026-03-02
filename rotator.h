#ifndef ROTATOR_H
#define ROTATOR_H

#include "device.h"

class Rotator: public Device
{
    Q_OBJECT
public:
    Item *item;
    explicit Rotator(int x, int y, int type, QObject *parent = nullptr, bool virt = false);

    void update(int flip) override;
    bool output(bool mark=false) override;
    bool checkIpt(int ix, int iy, QVector<Item *> &ipt) override;
    void input(QVector<Item *> &ipt, int ix=0, int iy=0) override;
};

#endif // ROTATOR_H
