#ifndef MINER_H
#define MINER_H

#include "device.h"

class Miner : public Device
{
public:
    explicit Miner(QObject *parent = nullptr);
};

#endif // MINER_H
