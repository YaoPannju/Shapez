#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QPushButton>
#include <QFile>

#include "gamescene.h"
#include "device.h"
#include "config.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

    GameScene *gamescene;

    void GameInit();

    void BtnClickAnimation(QPushButton* btn, const std::function<void()>& releaseCallback,int animationDuration = 100);

    void paintEvent(QPaintEvent *);

    void loadGameAndSwitchToGameScene(const QString& filename);

    void resizeEvent(QResizeEvent *event) override;
};
#endif // MAINWINDOW_H
