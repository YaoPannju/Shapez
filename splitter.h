#ifndef SPLITTER_H
#define SPLITTER_H

#include "device.h"

class Splitter : public Device
{
public:
    explicit Splitter(QObject *parent = nullptr);
};

#endif // SPLITTER_H
