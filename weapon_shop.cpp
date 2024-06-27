#include "weapon_shop.h"
#include "ui_weapon_shop.h"

Weapon_shop::Weapon_shop(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Weapon_shop)
{
    ui->setupUi(this);
    connect(ui->pushButton_Return, &QPushButton::clicked, this, &Weapon_shop::returnToMain);

}
Weapon_shop::~Weapon_shop()
{
    delete ui;
}
