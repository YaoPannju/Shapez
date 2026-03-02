QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    begin.cpp \
    center.cpp \
    combiner.cpp \
    config.cpp \
    conveyor.cpp \
    device.cpp \
    eraser.cpp \
    gamescene.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    miner.cpp \
    rotator.cpp \
    splitter.cpp \
    store.cpp \
    toolbar.cpp \
    toolbutton.cpp \
    trash.cpp

HEADERS += \
    begin.h \
    center.h \
    combiner.h \
    config.h \
    conveyor.h \
    device.h \
    eraser.h \
    gamescene.h \
    item.h \
    mainwindow.h \
    miner.h \
    rotator.h \
    splitter.h \
    store.h \
    toolbar.h \
    toolbutton.h \
    trash.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
