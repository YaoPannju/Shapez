#ifndef ROTATOR_H
#define ROTATOR_H

#include "device.h"

class Rotator: public Device
{
    Q_OBJECT
public:
    Item *item;
    explicit Rotator(int x, int y, int type, QObject *parent = nullptr, bool virt = false);
};

#endif // ROTATOR_H
