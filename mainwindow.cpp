#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPropertyAnimation>
#include <QTimer>
#include <QMessageBox>
#include <QFileDialog>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(1440,810);
    setWindowIcon(QIcon(":/res/icon.ico"));
    setWindowTitle("Shapez");

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/res/menu.wav"));
    audioOutput->setVolume(0.3);
    player->play();

    QPushButton * newbtn = new QPushButton("新游戏",this);
    newbtn->setObjectName("NewGameButton");
    newbtn->move(602,405);
    newbtn->resize(236,60);

    QPushButton * readbtn = new QPushButton("读取存档",this);
    readbtn->setObjectName("LoadSaveButton");
    readbtn->move(602,575);
    readbtn->resize(236,60);

    QPushButton * continuebtn = new QPushButton("继续游戏",this);
    continuebtn->setObjectName("ContinueButton");
    continuebtn->move(602,490);
    continuebtn->resize(236,60);

    BtnClickAnimation(newbtn, [this]() {
        QTimer::singleShot(500, this, [=](){
            gamescene = new GameScene;
            player->pause();
            this->hide();
            gamescene->setGeometry(this->geometry());
            connect(gamescene, &GameScene::RTM_signal, this, [this]() {
                this->show();
                player->play();
                delete gamescene;
                gamescene = nullptr;
                qDebug() << "当前在主界面";
            });
            gamescene->show();
            qDebug() << "当前在游戏界面";
        });
    }, 100);

    BtnClickAnimation(readbtn, [this]() {
        QTimer::singleShot(500,this,[=](){
            QString filename = QFileDialog::getOpenFileName(this, tr("选择存档文件"), "saves", tr("JSON 文件 (*.json)"));

            if (!filename.isEmpty()) {
                //loadGameAndSwitchToGameScene(filename);
            } else {
                QMessageBox::warning(this, "警告", "未选择存档文件");
            }
        });
    }, 100);

    BtnClickAnimation(continuebtn, [this]() {
        QTimer::singleShot(500,this,[=](){
            QString defaultSaveFile = "auto_save/auto_save.json";
            QFile file(defaultSaveFile);

            if (file.exists()) {
                //loadGameAndSwitchToGameScene(defaultSaveFile);
            } else {
                QMessageBox::warning(this, "继续游戏", "未找到存档文件，请开始新游戏或加载其他存档。");
            }
        });
    }, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gamescene;
}

void MainWindow::BtnClickAnimation(QPushButton *btn, const std::function<void ()> &releaseCallback, int animationDuration)
{
    QPropertyAnimation *newbtnanimation = new QPropertyAnimation(btn, "geometry");
    newbtnanimation->setDuration(animationDuration);
    newbtnanimation->setEasingCurve(QEasingCurve::OutQuad);
    QRect newbtnGeometry = btn->geometry();
    connect(btn,&QPushButton::pressed,this,[=](){
        QRect rect = btn->geometry();
        newbtnanimation->setStartValue(rect);
        newbtnanimation->setEndValue(QRect(rect.x() + rect.width() * 0.025, rect.y() + rect.height() * 0.025,
                                           rect.width() * 0.95, rect.height() * 0.95));
        newbtnanimation->start();
    });
    connect(btn,&QPushButton::released,this,[=]() {
        newbtnanimation->setStartValue(btn->geometry());
        newbtnanimation->setEndValue(newbtnGeometry);
        newbtnanimation->start();
        if (releaseCallback) {
            releaseCallback();
        }
    });
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(":/res/background_pic.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    QBrush brush(QColor(255,255,255));
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(552,390,340,260,10,10);

    pix.load(":/res/logo.png");
    painter.drawPixmap(360,105,pix);
}

void MainWindow::loadGameAndSwitchToGameScene(const QString &filename)
{
    gamescene = new GameScene;

    //gamescene->loadGame(filename);

    player->pause();

    this->hide();
    gamescene->setGeometry(this->geometry());
    gamescene->show();

    connect(gamescene, &GameScene::RTM_signal, this, [this]() {
        this->show();
        player->play();
        gamescene = nullptr;
    });
}
