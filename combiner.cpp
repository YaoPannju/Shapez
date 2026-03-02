#include "combiner.h"

#include <QtGlobal>
#include <QDebug>

Combiner::Combiner(int x, int y, int type, QObject *parent, bool virt)
    : Device(x, y, 2, 1, type, COMBINER_IMG, parent, virt),
    item1(nullptr), item2(nullptr)
{

}
