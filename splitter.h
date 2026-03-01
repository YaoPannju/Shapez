#ifndef SPLITTER_H
#define SPLITTER_H

#include "device.h"

class Splitter : public Device
{
    Q_OBJECT
public:
    Item *item;
    explicit Splitter(int x, int y, int type, QObject *parent = nullptr, bool virt = false);
signals:
};

#endif // SPLITTER_H
