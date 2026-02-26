#ifndef TRASH_H
#define TRASH_H

#include "device.h"

class Trash : public Device
{
public:
    explicit Trash(QObject *parent = nullptr);
};

#endif // TRASH_H
