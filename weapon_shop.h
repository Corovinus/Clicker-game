#ifndef WEAPON_SHOP_H
#define WEAPON_SHOP_H

#include <QMainWindow>
#include "player.h"

class MainWindow;

namespace Ui {
class Weapon_shop;
}

class Weapon_shop : public QMainWindow
{
    Q_OBJECT

public:
    explicit Weapon_shop(MainWindow *mainWindow, QWidget *parent = nullptr);  // Изменили конструктор
    ~Weapon_shop();
    void setPlayer(Player* player);

signals:
    void returnToMain();

private slots:
    void on_pushButton_AWM_clicked();
    void on_pushButton_Pistolet_clicked();
    void on_pushButton_Machinegun_clicked();
    void on_pushButton_Bazoo_clicked();
    void checkWeaponUnEquipped();
    void checkWeaponEquipped();

private:
    Ui::Weapon_shop *ui;
    Player* player;

    QString styleButton;
    QString styleButtonEquipt;

    bool hasWeapon[5] = {false};  // Инициализируем массив значением false
    MainWindow *mainWindow;  // Добавляем указатель на MainWindow
};

#endif // WEAPON_SHOP_H
