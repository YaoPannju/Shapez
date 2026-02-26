#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "toolbutton.h"
#include "toolbar.h"
#include "device.h"
#include "conveyor.h"
#include "center.h"
#include "config.h"
#include "store.h"

#include <QWidget>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QEvent>
#include <QQueue>
#include <QTimer>
#include <QPainter>

class GameScene : public QWidget
{
    Q_OBJECT
public:
    explicit GameScene(QWidget *parent = nullptr);

    void loadGame(const QString& filename);

    void save(); // 保存进度
    void start(); // 开始游戏
    bool checkPut(); // 验证是否能够放置
    // 地图渲染
    void drawMap(QPainter &painter);
    // 设置背景音乐和图片
    void setBack();

    void paintEvent(QPaintEvent *);

    void play();

    // 事件暂存
    QQueue<QEvent *>events;

    // 更新计时
    qint64 lastUpdate, lastRender;

private:
    // 全局计时
    unsigned long long flip;
    // 游戏是否处于暂停状态、暂停按钮、提示按钮
    bool pause;
    ToolButton pauseBtn, storeBtn;

    // 背景音乐播放器、背景图片路径
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QString background;

    // 工具栏
    ToolBar tools;

    Store *store;

    //待放置的物品类型，0则是没有
    int things2put;
    // 是否处于拖动地图状态
    bool onDrag;
    int startBaseX, startBaseY;
    double dragX, dragY;

    // 当前被选择的设备
    Device* select;

    bool conveyorDown, mouseDown;
    bool exist, reverse;
    Device *putting;
    QList<Conveyor *> putConveyor;

    // 存储中心
    Center *center;

    QTimer timer;

signals:
    void RTM_signal();
};

#endif // GAMESCENE_H
