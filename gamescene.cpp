#include "gamescene.h"

GameScene::GameScene(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(1440,810);
    setWindowIcon(QIcon(":/res/icon.ico"));
    setWindowTitle("Shapez");

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/res/feather.mp3"));
    audioOutput->setVolume(0.3);
    player->play();
}
