#include "splitter.h"

Splitter::Splitter(int x, int y, int type, QObject *parent, bool virt)
    : Device(x, y, 2, 1, type, SPLITTER_IMG, parent, virt),
    item(nullptr)
{

}
