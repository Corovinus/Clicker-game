#include "weapon_shop.h"
#include "ui_weapon_shop.h"

Weapon_shop::Weapon_shop(MainWindow *mainWindow, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Weapon_shop)
    , player(nullptr)
    , mainWindow(mainWindow)  // Инициализируем указатель
{
    this->setStyleSheet("QWidget#centralwidget { border-image: url(:/pic/Location/WeaponShop.png) 0 0 0 0 stretch stretch; }");
    ui->setupUi(this);
    styleButton = "border-image: url(:/pic/Buttons/WoodButton.png) stretch; ";
    styleButtonEquipt = "border-image: url(:/pic/Buttons/WoodButton_Equipt.png) stretch; ";

    ui->pushButton_AWM->setStyleSheet(styleButton);
    ui->pushButton_Bazoo->setStyleSheet(styleButton);
    ui->pushButton_Machinegun->setStyleSheet(styleButton);
    ui->pushButton_Pistolet->setStyleSheet(styleButton);
    ui->pushButton_Return->setStyleSheet(styleButton);
    ui->label_WhiteOnDesk->setStyleSheet("background-color: rgba(255, 255, 255, 127); border-radius: 15px;");


    QPixmap backgroud(":/pic/Buttons/WoodenBackground.png");
    ui->label_WoodenBackground->setPixmap(backgroud.scaled(ui->label_WoodenBackground->width(), ui->label_WoodenBackground->height(), Qt::IgnoreAspectRatio));

    QPixmap backgroud_Money(":/pic/Buttons/Plank.png");
    ui->label_BackgroundMoney->setPixmap(backgroud_Money.scaled(ui->label_BackgroundMoney->width(), ui->label_BackgroundMoney->height(), Qt::IgnoreAspectRatio));

    connect(ui->pushButton_Return, &QPushButton::clicked, this, &Weapon_shop::returnToMain);

}

void Weapon_shop::setPlayer(Player* player) {
    this->player = player;
    ui->label_Money->setText("Your money: " + QString::number(player->money));
    checkWeaponEquipped();
}

Weapon_shop::~Weapon_shop()
{
    delete ui;
}

void Weapon_shop::on_pushButton_AWM_clicked()
{
    if (player != nullptr && player->money >= 1488 && !hasWeapon[3]) {
        checkWeaponUnEquipped();
        player->weapon = new AWM;
        player->money -= 1488;
        hasWeapon[3] = true;
        checkWeaponEquipped();
        ui->label_Money->setText("Your money: " + QString::number(player->money));
    }
    else if (hasWeapon[3]) {
        checkWeaponUnEquipped();
        player->weapon = new AWM;
        checkWeaponEquipped();
    }
}

void Weapon_shop::on_pushButton_Pistolet_clicked()
{
    if (player->money >= 100 && !hasWeapon[1]) {
        checkWeaponUnEquipped();
        player->weapon = new Pistolet;
        player->money -= 100;
        hasWeapon[1] = true;
        checkWeaponEquipped();
        ui->label_Money->setText("Your money: " + QString::number(player->money));
    }
    else if (hasWeapon[1]) {
        checkWeaponUnEquipped();
        player->weapon = new Pistolet;
        checkWeaponEquipped();
    }
}

void Weapon_shop::on_pushButton_Machinegun_clicked()
{
    if (player->money >= 300 && !hasWeapon[2]) {
        checkWeaponUnEquipped();
        player->weapon = new Machinegun;
        player->money -= 300;
        hasWeapon[2] = true;
        ui->label_cost2->setText("Equipped");
        ui->label_Money->setText("Your money: " + QString::number(player->money));
        checkWeaponEquipped();
    }
    else if (hasWeapon[2]) {
        checkWeaponUnEquipped();
        player->weapon = new Machinegun;
        checkWeaponEquipped();
    }
}

void Weapon_shop::on_pushButton_Bazoo_clicked()
{
    if (player != nullptr && player->money >= 7788 && !hasWeapon[4]) {
        checkWeaponUnEquipped();
        player->weapon = new Bazoo;
        player->money -= 7788;
        hasWeapon[4] = true;
        checkWeaponEquipped();
        ui->label_Money->setText("Your money: " + QString::number(player->money));
    }
    else if (hasWeapon[4]) {
        checkWeaponUnEquipped();
        player->weapon = new Bazoo;
        checkWeaponEquipped();
    }
}

void Weapon_shop::checkWeaponUnEquipped() {
    if (player->weapon->name == "Pistolet") {
        ui->label_cost1->setText("unEquipped");
        ui->pushButton_Pistolet->setStyleSheet(styleButton);
    }
    if (player->weapon->name == "Machinegun") {
        ui->label_cost2->setText("unEquipped");
        ui->pushButton_Machinegun->setStyleSheet(styleButton);
    }
    if (player->weapon->name == "AWM") {
        ui->label_cost3->setText("unEquipped");
        ui->pushButton_AWM->setStyleSheet(styleButton);
    }
    if (player->weapon->name == "Bazoo") {
        ui->label_cost4->setText("unEquipped");
        ui->pushButton_Bazoo->setStyleSheet(styleButton);
    }
}

void Weapon_shop::checkWeaponEquipped() {
    if (player->weapon->name == "Pistolet") {
        ui->label_cost1->setText("Equipped");
        ui->pushButton_Pistolet->setStyleSheet(styleButtonEquipt);
    }
    if (player->weapon->name == "Machinegun") {
        ui->label_cost2->setText("Equipped");
        ui->pushButton_Machinegun->setStyleSheet(styleButtonEquipt);
    }
    if (player->weapon->name == "AWM") {
        ui->label_cost3->setText("Equipped");
        ui->pushButton_AWM->setStyleSheet(styleButtonEquipt);

    }
    if (player->weapon->name == "Bazoo") {
        ui->label_cost4->setText("Equipped");
        ui->pushButton_Bazoo->setStyleSheet(styleButtonEquipt);
    }
}
