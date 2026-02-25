#include "mainwindow.h"

#include <QApplication>
#include <QElapsedTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qss(":/res/style.qss");
    QElapsedTimer timer;
    timer.start();

    if(qss.open(QFile::ReadOnly)){
        qDebug()<<"Open qss sucessfully!";
        qDebug() << "QSS加载耗时：" << timer.elapsed() << "ms";
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }
    else{
        qDebug()<<"Qss Open failed!";
        qDebug() << "QSS加载耗时：" << timer.elapsed() << "ms";
        return 0;
    }

    MainWindow w;
    w.show();
    return a.exec();
}
