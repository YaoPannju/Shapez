#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QPainter>
#include "config.h"

class Device : public QObject
{
    Q_OBJECT
public:
    QString IconPath;

    int type;

    int direction;

    //横纵坐标
    int x;
    int y;
    int w;
    int h;

    bool selected;

    bool virt;

    explicit Device(int x, int y, int w, int h, int type, QString imgPath,
                    QObject *parent = nullptr, bool virt = false);

    virtual void put(int x, int y, int direct, bool wipe);

    void rotate();

    virtual void draw(QPainter &painter);

    void setDirect(int direct, bool wipe=true);

    void setPos(int x, int y, bool wipe=true);

    void setImage(QString imgPath);

    bool isIn(int px, int py);

    int getDeviceType();

    int getDirect();

signals:
};

extern QList<Device *> devices;
extern QMap<QPair<int,int>, Device*> devicesMap;

#endif // DEVICE_H
