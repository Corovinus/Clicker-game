QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gun.cpp \
    machinegun.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    upgrade_shop.cpp \
    weapon.cpp \
    weapon_shop.cpp

HEADERS += \
    gun.h \
    machinegun.h \
    mainwindow.h \
    player.h \
    upgrade_shop.h \
    weapon.h \
    weapon_shop.h

FORMS += \
    mainwindow.ui \
    upgrade_shop.ui \
    weapon_shop.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Models.qrc
