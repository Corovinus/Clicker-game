#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QSpacerItem>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , atk_Timer(new QTimer(this))
    , ui(new Ui::MainWindow)
    , newLabel(nullptr)
    , labelAdded(false) // Инициализация флага
{
    ui->setupUi(this);

    QPixmap pix(":/pic/Slime/slime_b.png");
    int w = ui->enemy->width();
    int h = ui->enemy->height();
    ui->enemy->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->atk_Bar->hide();
    ui->reload_bar->hide();
    ui->ammoBar->setMaximum(player.weapon->max_ammo);
    ui->ammoBar->setValue(player.weapon->max_ammo); // Установка значения на максимум
    ui->ammoBar->setStyleSheet(
        QString("QProgressBar {"
                "    border: 2px solid grey;"
                "    border-radius: 5px;"
                "    text-align: center;"
                "    margin: 0.5px;"
                "}"
                "QProgressBar::chunk {"
                "    background-color: rgb(%1, %2, %3);"
                "    width: 10px;" // Установите ширину сегментов
                "    margin: 0.5px;" // Установите промежуток между сегментами
                "}").arg(255).arg(165).arg(0));
    ui->hpBar->setStyleSheet(
        QString("QProgressBar {"
                "    border: 2px solid grey;"
                "    border-radius: 5px;"
                "    text-align: center;"
                "}"
                "QProgressBar::chunk {"
                "    background-color: rgb(%1, %2, %3);"
                "    width: 20px;"
                "}").arg(255).arg(0).arg(0));
    ui->hpBar->setMaximum(player.max_hp);
    ui->hpBar->setValue(player.max_hp); // Установка значения на максимум



    stackedWidget = new QStackedWidget(this);
    upgradeWidget = new upgrade_shop(this);
    shopWidget = new Weapon_shop(this);

    QWidget *mainWidget = new QWidget(this);
    layout = new QVBoxLayout(mainWidget);
    mainWidget->setLayout(layout);

    stackedWidget->addWidget(ui->centralwidget);
    stackedWidget->addWidget(shopWidget);
    stackedWidget->addWidget(upgradeWidget);

    layout->addWidget(stackedWidget);
    setCentralWidget(mainWidget);

    connect(shopWidget, &Weapon_shop::returnToMain, this, &MainWindow::returnToMain);
    connect(upgradeWidget, &upgrade_shop::returnToMain, this, &MainWindow::returnToMain);
    connect(atk_Timer, &QTimer::timeout, this, &MainWindow::updateProgressBar);

    UpdateStats(); // Инициализация состояния статов
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateStats() {
    ui->label_Money->setText("Money: " + QString::number(player.money));
    ui->label_Ammo->setText("Ammo: ");
    ui->ammoBar->setValue(player.weapon->ammo);
    ui->label_HP->setText("HP: " + QString::number(player.hp));
    ui->hpBar->setValue(player.hp);
}

void MainWindow::on_pushButton_Shoot_clicked() {
    if (player.weapon->ammo != 0) {
        player.Shoot();
        removeLabel();
        Loading();
    } else {
        addLabel();
    }
    UpdateStats(); // Обновление состояния после выстрела
}

void MainWindow::updateProgressBar() {
    progressBarValue += 1;
    ui->atk_Bar->setValue(progressBarValue);
    if (progressBarValue >= 100) {
        atk_Timer->stop();
        ui->atk_Bar->hide();
        loadingComplete = true;
        ui->pushButton_Shoot->setEnabled(true);
    }
}

void MainWindow::Loading() {
    ui->pushButton_Shoot->setEnabled(false);
    ui->atk_Bar->setValue(0);
    ui->atk_Bar->show();

    progressBarValue = 0;
    loadingComplete = false;
    atk_Timer->start(5 / player.weapon->atk_speed);
    UpdateStats();
}

void MainWindow::on_pushButton_Reload_clicked() {
    player.Reload();
    removeLabel();
    UpdateStats();
}

void MainWindow::on_pushButton_Weapons_clicked() {
    stackedWidget->setCurrentWidget(shopWidget);
    removeLabel();
}

void MainWindow::returnToMain() {
    stackedWidget->setCurrentWidget(stackedWidget->widget(0)); // Возврат к основному виджету
}

void MainWindow::addLabel() {
    removeLabel();
    newLabel = new QLabel("No ammo", this);
    newLabel->setAlignment(Qt::AlignCenter);

    QFont font("MS Serif", 40);
    newLabel->setFont(font);

    newLabel->setGeometry((this->width() - 200) / 2, (this->height() - 50) / 2, 200, 50);
    newLabel->show();
    labelAdded = true;

    QPropertyAnimation *anim = new QPropertyAnimation(newLabel, "pos", this);
    anim->setDuration(3000);
    anim->setStartValue(QPoint(newLabel->x(), newLabel->y()));
    anim->setEndValue(QPoint(newLabel->x(), -50));
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::removeLabel() {
    if (newLabel) {
        newLabel->hide();
        delete newLabel;
        newLabel = nullptr;
        labelAdded = false;
    }
}

void MainWindow::on_pushButton_Player_clicked() {
    stackedWidget->setCurrentWidget(upgradeWidget);
    removeLabel();
}
