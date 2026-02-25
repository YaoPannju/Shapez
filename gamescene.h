#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "toolbutton.h"
#include "toolbar.h"

#include <QWidget>
#include <QMediaPlayer>
#include <QAudioOutput>

class GameScene : public QWidget
{
    Q_OBJECT
public:
    // 全局计时
    unsigned long long flip;
    // 游戏是否处于暂停状态、暂停按钮、提示按钮
    bool pause;
    ToolButton pauseBtn;

    // 背景音乐播放器、背景图片路径
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QString background;

    // 工具栏
    ToolBar tools;

    explicit GameScene(QWidget *parent = nullptr);

signals:
    void RTM_signal();
};

#endif // GAMESCENE_H
