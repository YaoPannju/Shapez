#include "toolbar.h"

#include <QPushButton>

ToolBar::ToolBar(QWidget *parent)
    : QWidget{parent},
    img({":/res/building_icons/miner.png", ":/res/building_icons/belt.png", ":/res/building_icons/cutter.png", ":/res/building_icons/stacker.png", ":/res/building_icons/rotator.png", ":/res/building_icons/trash.png", ":/res/building_icons/Eraser.png", ":/res/building_icons/storage.png"}), layout(this),
    types({3, 2, 4, 7, 9, 5, 8, 0}),
    pressStyle("border-radius: 10px; background-color: rgba(36, 173, 243, 127);"),
    normalStyle("background-color: transparent;")
{
    setFixedSize(712, 112);
    setStyleSheet("QPushButton{ border: none; margin-top: 5px; }"
                  "QPushButton:hover { background-color: rgba(36, 173, 243, 50); border-radius: 10px 10px; }");
    for(int i=0;i<8;++i){
        tool[i].setInLayor(PX, PX, img[i], this);
        layout.addWidget(&tool[i]);
        if(i<7){
            connect(&tool[i], &QPushButton::clicked, this, [=](){
                tool[i].setStyleSheet(pressStyle);
                emit put(types[i], x()+PX*(i+1), y());
            });
        }else{
            connect(&tool[i], &QPushButton::clicked, this, [=](){
                tool[i].setStyleSheet(pressStyle);
                emit toggleStore();
            });
        }
    }
    layout.setContentsMargins(20, 0, 20, 0);
    layout.setAlignment(Qt::AlignCenter);
    setLayout(&layout);
}

void ToolBar::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(
        QRect(0, 0, width(), height()),
        QPixmap(":/res/ToolBar.png")
        );
}

void ToolBar::resetBtn(int id){
    for(int i=0;i<8;++i){
        if(types[i] == id){
            id = i; break;
        }
    }
    tool[id].setStyleSheet(normalStyle);
}
