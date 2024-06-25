#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Weapon.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateStats() {
    ui->label_Money->setText("Money: " + QString::number(player.money));
    ui->label_Ammo->setText("Ammo: " + QString::number(player.weapon->ammo));
    ui->label_HP->setText("HP: " + QString::number(player.hp));
}

void MainWindow::on_pushButton_Shoot_clicked() {
    player.Shoot();
    UpdateStats();
}

void MainWindow::on_pushButton_Reload_clicked() {
    player.Reload();
    UpdateStats();
}
