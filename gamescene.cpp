#include "gamescene.h"

#include <QPushButton>
#include <QSoundEffect>

GameScene::GameScene(QWidget *parent)
    : QWidget{parent}, tools(this)
{
    setFixedSize(1600,900);
    setWindowIcon(QIcon(":/res/icon.ico"));
    setWindowTitle("Shapez");

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/res/feather.mp3"));
    audioOutput->setVolume(0.3);
    player->play();

    store = new Store(this);

    pause = false;
    onDrag = false;
    pauseBtn.set(width()-PX*2, 0, PX, PX, ":/res/PauseButton.png", this);
    connect(&pauseBtn, &QPushButton::clicked, this, [=](){
        this->pause = !this->pause;
        static QSoundEffect clickSound;
        clickSound.setSource(QUrl("qrc:/sounds/res/sounds/ui_click.wav"));
        clickSound.setVolume(0.5);
        clickSound.play();
        if(this->pause){
            pauseBtn.setImg(":/res/PlayButton.png");
        }else{
            pauseBtn.setImg(":/res/PauseButton.png");
        }
    });

    storeBtn.set(width() - PX, 0, PX, PX, ":/res/store.png", this);
    connect(&storeBtn, &QPushButton::clicked, this, [=](){
        this->pause = true;
        static QSoundEffect clickSound;
        clickSound.setSource(QUrl("qrc:/sounds/res/sounds/ui_click.wav"));
        clickSound.setVolume(0.5);
        clickSound.play();
        //this->hide();
        store->show();
        connect(store, &Store::store_closed, this, [=](){
            this->pause = false;
        });
    });

    tools.move((width()-tools.width())/2, height()-PX-40);
    tools.show();

    setMouseTracking(true);
    grabKeyboard();

    // 绑定计时器槽
    connect(&timer, &QTimer::timeout, this, &GameScene::play);
}

void GameScene::loadGame(const QString &filename)
{
    //qDebug()<<"Load File";
    return;
}

void GameScene::start()
{
    timer.setInterval(0);
    timer.start();
}

bool GameScene::checkPut()
{
    if(things2put == 0) return false;
    return true;
}

void GameScene::drawMap(QPainter &painter)
{
    painter.drawPixmap(
        QRect(BaseX%PX, BaseY%PX, WW+PX*2, WH+PX*2),
        QPixmap(":/res/Grid.png")
        );

    return;
}

void GameScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(QRect(0,0,1440,864), QPixmap(":/res/bg2.png"));

    drawMap(painter);

    painter.end();
}

void GameScene::play()
{
    //游戏的逻辑
    qDebug()<<"666";
}
