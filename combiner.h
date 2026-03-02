#ifndef COMBINER_H
#define COMBINER_H

#include "device.h"

class Combiner : public Device
{
public:
    Item *item1, *item2;
    explicit Combiner(int x, int y, int type, QObject *parent = nullptr, bool virt = false);
};

#endif // COMBINER_H
