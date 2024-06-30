#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QSpacerItem>
#include <QFont>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , atk_Timer(new QTimer(this))
    , reload_Timer(new QTimer(this))
    , noAmmo_Timer(new QTimer(this))
    , enemy_Timer(new QTimer(this))
    , newLabel(nullptr)
    , labelAdded(false) // Инициализация флага
{
    setFixedSize(800, 600);
    ui->setupUi(this);
    createNewEnemy();

    // Убедитесь, что центральный виджет заполняет все пространство окна
    ui->centralwidget->setStyleSheet("border: none;");

    // Установите изображение фона
    this->setStyleSheet("QWidget#centralwidget { border-image: url(:/pic/Location/Field 2.0.png) 0 0 0 0 stretch stretch; }");

    QPixmap pix(enemy->path);

    ui->pushButton_Shoot->setStyleSheet("border-image: url(:/pic/Buttons/WoodButton.png) stretch; ");
    ui->pushButton_Player->setStyleSheet("border-image: url(:/pic/Buttons/WoodButton.png) stretch; ");
    ui->pushButton_Reload->setStyleSheet("border-image: url(:/pic/Buttons/WoodButton.png) stretch; ");
    ui->pushButton_Weapons->setStyleSheet("border-image: url(:/pic/Buttons/WoodButton.png) stretch; ");

    int w = ui->enemy->width();
    int h = ui->enemy->height();
    ui->enemy->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    ui->atk_Bar->hide();
    ui->ammoBar->setMaximum(player.weapon->max_ammo);
    ui->ammoBar->setValue(player.weapon->max_ammo); // Установка значения на максимум
    if (player.weapon->max_ammo < 26)
        ui->ammoBar->setStyleSheet(
            QString("QProgressBar {"
                    "    border: 0px solid grey;"
                    "    border-radius: 0px;"
                    "    text-align: center;"
                    "    margin: 0.5px;"
                    "}"
                    "QProgressBar::chunk {"
                    "    background-color: rgb(%1, %2, %3);"
                    "    width: %4px;"
                    "    margin: 1px;"
                    "}").arg(255).arg(165).arg(0).arg(170/player.weapon->max_ammo));
    else
        ui->ammoBar->setStyleSheet(
            QString("QProgressBar {"
                    "    border: 2px solid grey;"
                    "    border-radius: 2px;"
                    "    text-align: center;"
                    "    margin: 0.5px;"
                    "}"
                    "QProgressBar::chunk {"
                    "    background-color: rgb(%1, %2, %3);"
                    "    width: 1px;"
                    "}").arg(255).arg(165).arg(0));
    ui->hpBar->setStyleSheet(
        QString("QProgressBar {"
                "    border: 2px solid grey;"
                "    border-radius: 2px;"
                "    text-align: center;"
                "}"
                "QProgressBar::chunk {"
                "    background-color: rgb(%1, %2, %3);"
                "    width: 1px;"
                "}").arg(255).arg(0).arg(0));
    ui->hpBar->setMaximum(player.max_hp);
    ui->hpBar->setValue(player.max_hp); // Установка значения на максимум

    ui->hpEnemmyBar->setStyleSheet(
        QString("QProgressBar {"
                "    border: 2px solid grey;"
                "    border-radius: 2px;"
                "    text-align: center;"
                "}"
                "QProgressBar::chunk {"
                "    background-color: rgb(%1, %2, %3);"
                "    width: 1px;"
                "}").arg(255).arg(0).arg(0));
    ui->hpEnemmyBar->setMaximum(enemy->max_hp);
    ui->hpEnemmyBar->setValue(enemy->max_hp); // Установка значения на максимум

    stackedWidget = new QStackedWidget(this);
    upgradeWidget = new upgrade_shop(this);
    shopWidget = new Weapon_shop(this, this);

    QWidget *mainWidget = new QWidget(this);
    layout = new QVBoxLayout(mainWidget);
    layout->setContentsMargins(0, 0, 0, 0); // Удалите отступы
    layout->setSpacing(0); // Удалите промежутки
    mainWidget->setLayout(layout);

    stackedWidget->addWidget(ui->centralwidget);
    stackedWidget->addWidget(shopWidget);
    stackedWidget->addWidget(upgradeWidget);

    layout->addWidget(stackedWidget);
    setCentralWidget(mainWidget);

    connect(shopWidget, &Weapon_shop::returnToMain, this, &MainWindow::returnToMain);
    connect(upgradeWidget, &upgrade_shop::returnToMain, this, &MainWindow::returnToMain);
    connect(atk_Timer, &QTimer::timeout, this, &MainWindow::updateProgressBar);
    connect(reload_Timer, &QTimer::timeout, this, &MainWindow::updateProgressBarReload);
    connect(noAmmo_Timer, &QTimer::timeout, this, &MainWindow::SetEnableToShoot);

    shopWidget->setPlayer(&player);

    UpdateStats(); // Инициализация состояния статов
}

MainWindow::~MainWindow()
{
    delete ui;
    delete enemy;
}

void MainWindow::EnemyAtk(){
    enemy->DealDamage(&player);
    enemy_Timer->start(enemy->atk_speed);
}

void MainWindow::UpdateStats() {
    ui->label_Money->setText("Money: " + QString::number(player.money));
    ui->label_Ammo->setText("Ammo: ");
    ui->ammoBar->setValue(player.weapon->ammo);

    ui->label_HP->setText("HP: ");
    ui->hpBar->setValue(player.hp);
    ui->hpEnemmyBar->setValue(enemy->hp);

    ui->label_Equipt->setText("Equipt: " + player.weapon->name);
    shopWidget->setPlayer(&player);
}

void MainWindow::on_pushButton_Shoot_clicked() {
    reload_Timer->stop();
    ui->pushButton_Reload->setEnabled(true);

    if (player.weapon->ammo != 0) {
        player.Shoot(enemy);
        removeLabel();
        Loading();
        if (enemy->hp <= 0) {
            player.money += enemy->value;
            createNewEnemy();  // Создание нового противника, если текущий побеждён
        }
    } else {
        addLabel();
    }
    UpdateStats();  // Обновление состояния после выстрела
}

void MainWindow::updateProgressBar() {
    progressBarValue += 1;
    ui->atk_Bar->setValue(progressBarValue);

    int red = 255 - progressBarValue / 100.0 * 255;
    int blue = 0;
    int green = progressBarValue / 100.0 * 150;

    ui->atk_Bar->setStyleSheet(
        QString("QProgressBar {"
                "    border: 2px solid grey;"
                "    border-radius: 5px;"
                "    text-align: center;"
                "}"
                "QProgressBar::chunk {"
                "    background-color: rgb(%1, %2, %3);"
                "    width: 1px;"
                "}").arg(red).arg(green).arg(blue)
        );

    if (progressBarValue >= 100) {
        atk_Timer->stop();
        ui->atk_Bar->hide();
        loadingComplete = true;
        ui->pushButton_Reload->setEnabled(true);
        ui->pushButton_Shoot->setEnabled(true);
    }
}

void MainWindow::createNewEnemy() {
    if (enemy != nullptr) {
        delete enemy;
    }
    int chooseEnemy = rand() % 1000;
    if (chooseEnemy <= 500)
        enemy = new SlimeWoman();
    if (chooseEnemy >500 and chooseEnemy <= 850)
        enemy = new Skeleton();
    if (chooseEnemy > 850)
        enemy = new Chest();
    ui->enemy->setPixmap(QPixmap(enemy->path).scaled(ui->enemy->width(), ui->enemy->height(), Qt::KeepAspectRatio));
    ui->hpEnemmyBar->setMaximum(enemy->max_hp);
    ui->hpEnemmyBar->setValue(enemy->max_hp);

    // Обновление стилей или любых других связанных данных
    ui->hpEnemmyBar->setStyleSheet(
        QString("QProgressBar {"
                "    border: 2px solid grey;"
                "    border-radius: 2px;"
                "    text-align: center;"
                "}"
                "QProgressBar::chunk {"
                "    background-color: rgb(%1, %2, %3);"
                "    width: 1px;"
                "}").arg(255).arg(0).arg(0)
        );
}

void MainWindow::Loading() {
    ui->pushButton_Shoot->setEnabled(false);
    ui->pushButton_Reload->setEnabled(false);
    ui->atk_Bar->setValue(0);
    ui->atk_Bar->show();

    progressBarValue = 0;
    loadingComplete = false;
    atk_Timer->start(1.0/player.weapon->atk_speed*10000);
    UpdateStats();
}

void MainWindow::on_pushButton_Reload_clicked() {
    removeLabel();
    LoadingReload();
}

void MainWindow::LoadingReload() {
    ui->pushButton_Reload->setEnabled(false);
    progressBarValue = player.weapon->ammo; // Начальное значение

    double reloadInterval = player.weapon->reloadSpeed / 100;
    reload_Timer->start(reloadInterval);
    UpdateStats();
}

void MainWindow::updateProgressBarReload(){
    progressBarValue += player.weapon->max_ammo / 100.0;
    if (progressBarValue >= player.weapon->max_ammo) {
        progressBarValue = player.weapon->max_ammo; // Убедитесь, что значение не превышает максимальное
        reload_Timer->stop();
        loadingComplete = true;
        ui->pushButton_Reload->setEnabled(true);
    }

    player.weapon->ammo = progressBarValue;
    ui->ammoBar->setValue(progressBarValue);
    UpdateStats();
}

void MainWindow::on_pushButton_Weapons_clicked() {

    stackedWidget->setCurrentWidget(shopWidget);
    removeLabel();
}

void MainWindow::returnToMain() {
    ui->ammoBar->setMaximum(player.weapon->max_ammo);
    ui->ammoBar->setStyleSheet(QString("QProgressBar {"
                                       "    border: 2px solid grey;"
                                       "    border-radius: 2px;"
                                       "    text-align: center;"
                                       "    margin: 0.5px;"
                                       "}"
                                       "QProgressBar::chunk {"
                                       "    background-color: rgb(%1, %2, %3);"
                                       "    width: %4px;"
                                       "    margin: 0.5px;"
                                       "}").arg(255).arg(165).arg(0).arg(170/player.weapon->max_ammo));
    stackedWidget->setCurrentWidget(stackedWidget->widget(0)); // Возврат к основному виджету
    UpdateStats();
}

void MainWindow::addLabel() {
    newLabel = new QLabel("No ammo", this);
    newLabel->setAlignment(Qt::AlignCenter);
    QFont font("MS Serif", 40);
    newLabel->setFont(font);

    ui->pushButton_Shoot->setEnabled(false);
    noAmmo_Timer->start(1000);


    newLabel->setGeometry((this->width() - 200) / 2, (this->height() - 50) / 2, 200, 50);
    newLabel->show();
    labelAdded = true;

    QPropertyAnimation *anim = new QPropertyAnimation(newLabel, "pos", this);
    anim->setDuration(3000);
    anim->setStartValue(QPoint(newLabel->x(), newLabel->y()));
    anim->setEndValue(QPoint(newLabel->x(), -50));
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::SetEnableToShoot(){
    ui->pushButton_Shoot->setEnabled(true);
}

void MainWindow::updateAmmoBarStyle() {
    // Implement the functionality for updating the ammo bar style here
    if (player.weapon->max_ammo < 26) {
        ui->ammoBar->setStyleSheet(
            QString("QProgressBar {"
                    "    border: 0px solid grey;"
                    "    border-radius: 0px;"
                    "    text-align: center;"
                    "    margin: 0.5px;"
                    "}"
                    "QProgressBar::chunk {"
                    "    background-color: rgb(%1, %2, %3);"
                    "    width: %4px;"
                    "    margin: 1px;"
                    "}").arg(255).arg(165).arg(0).arg(1/player.weapon->max_ammo));
    } else {
        ui->ammoBar->setStyleSheet(
            QString("QProgressBar {"
                    "    border: 2px solid grey;"
                    "    border-radius: 2px;"
                    "    text-align: center;"
                    "    margin: 0.5px;"
                    "}"
                    "QProgressBar::chunk {"
                    "    background-color: rgb(%1, %2, %3);"
                    "    width: 1px;"
                    "}").arg(255).arg(165).arg(0));
    }
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
