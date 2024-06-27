#include "upgrade_shop.h"
#include "ui_upgrade_shop.h" // Включаем заголовочный файл для UI

upgrade_shop::upgrade_shop(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::upgrade_shop)
{
    ui->setupUi(this);


    connect(ui->pushButton_Return, &QPushButton::clicked, this, &upgrade_shop::returnToMain);
}

upgrade_shop::~upgrade_shop()
{
    delete ui;
}
