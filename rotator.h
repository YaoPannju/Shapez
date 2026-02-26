#ifndef ROTATOR_H
#define ROTATOR_H

#include "device.h"

class Rotator : public Device
{
public:
    explicit Rotator(QObject *parent = nullptr);
};

#endif // ROTATOR_H
