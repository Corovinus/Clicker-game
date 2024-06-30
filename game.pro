QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    enemy.cpp \
    gun.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    upgrade_shop.cpp \
    weapon.cpp \
    weapon_shop.cpp

HEADERS += \
    enemy.h \
    gun.h \
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
    Res.qrc

DISTFILES += \
    pic/Buttons/WoodButton.png \
    pic/Buttons/WoodButton_Equipt.png \
    pic/Buttons/WoodenBackground.png \
    pic/Enemy/Taynaya_Dobycha04.jpg \
    pic/Enemy/de4adc3db2bc3dd6cdaf798cda4c7fda.jpg \
    pic/Enemy/png-clipart-cartoon-blue-cloud-wind-wind-effect.png \
    pic/Enemy/slimeWoman.png \
    pic/Enemy/treasure_chest_PNG78.png \
    pic/Location/231466-P2CJQU-402.jpg \
    pic/Location/Field 2.0.png \
    pic/Location/Field 2.0.png \
    pic/Location/Field.png \
    pic/Location/WeaponShop.png \
    pic/Slime/slime_b.png \
    pic/Slime/slime_p.png
