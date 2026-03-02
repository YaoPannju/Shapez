#include "rotator.h"

Rotator::Rotator(int x, int y, int type, QObject *parent, bool virt)
    : Device(x, y, 1, 1, type, ":/img/RoaterRight.png", parent, virt),
    item(nullptr)
{}
