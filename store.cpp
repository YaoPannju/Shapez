#include "store.h"

Store::Store(QWidget *parent)
    : QWidget{parent}
{
    this->setWindowModality(Qt::ApplicationModal); // 应用级模态，阻塞所有窗口交互
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint); // 无边框 + 始终顶层
    this->setFixedSize(400, 500); // 固定商店窗口大小
    this->setStyleSheet("background-color: rgba(30,30,30,240); border-radius: 10px;");
}
