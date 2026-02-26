#include "device.h"

Device::Device(int x, int y, int w, int h, int type, QString Icon, QObject *parent, bool virt)
    : QObject{parent},IconPath(Icon), x(x), y(y), w(w), h(h), type(type),virt(virt)
{
    devices.append(this);
    setDirect(getDirect(), false);
}

void Device::put(int x, int y, int direct, bool wipe)
{
    setPos(x, y, wipe);
    setDirect(direct, wipe);
}

void Device::rotate()
{
    direction = (direction + 1) % 4;
}

void Device::draw(QPainter &painter)
{
    if(IconPath == nullptr || IconPath.size() == 0){
        return;
    }
    QPixmap pix = QPixmap(IconPath).transformed(QTransform().rotate(90*getDirect()));
    painter.drawPixmap(QRect(BaseX+x*PX+4, BaseY+y*PX+4, w*PX-2*4, h*PX-2*4),pix);
    painter.save();
}

void Device::setDirect(int direct, bool wipe)
{
    direction = direct;
}

void Device::setPos(int x, int y, bool wipe)
{
    this->x = x;
    this->y = y;
}

void Device::setImage(QString imgPath)
{
    IconPath = imgPath;
}

bool Device::isIn(int px, int py)
{
    if(px < x * PX || px > (x+w) * PX){
        return false;
    }
    else if(py < y * PX || py > (y+h) * PX){
        return false;
    }
    else return true;
}

int Device::getDeviceType()
{
    return type;
}

int Device::getDirect()
{
    return direction;
}
