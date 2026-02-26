#ifndef STORE_H
#define STORE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class Store : public QWidget
{
    Q_OBJECT
public:
    explicit Store(QWidget *parent = nullptr);

    QPushButton* ExitBtn, RF_CBtn, RF_VBtn, RF_MBtn;

signals:
    void store_closed();
};

#endif // STORE_H
