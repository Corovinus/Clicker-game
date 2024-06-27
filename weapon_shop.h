#ifndef WEAPON_SHOP_H
#define WEAPON_SHOP_H

#include <QMainWindow>

namespace Ui {
class Weapon_shop;
}

class Weapon_shop : public QMainWindow
{
    Q_OBJECT

public:
    explicit Weapon_shop(QWidget *parent = nullptr);
    ~Weapon_shop();
signals:
    void returnToMain();
private:
    Ui::Weapon_shop *ui;

};

#endif // WEAPON_SHOP_H
