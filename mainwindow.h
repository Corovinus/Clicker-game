#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "player.h"
#include "weapon_shop.h"
#include "upgrade_shop.h"
#include "enemy.h"
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Shoot_clicked();
    void UpdateStats();
    void on_pushButton_Reload_clicked();
    void on_pushButton_Weapons_clicked();
    void returnToMain();
    void updateAmmoBarStyle();
    void addLabel();
    void removeLabel();
    void on_pushButton_Player_clicked();
    void EnemyAtk();
    void createNewEnemy();
private:
    Ui::MainWindow *ui;
    QPropertyAnimation* _propertyAnimation;
    QTimer *atk_Timer;
    QTimer *reload_Timer;
    QTimer *noAmmo_Timer;
    QTimer *enemy_Timer;

    QStackedWidget *stackedWidget;
    Weapon_shop *shopWidget;
    upgrade_shop *upgradeWidget;
    Player player;
    Enemy *enemy;
    QVBoxLayout *layout;
    QLabel *newLabel;

    void SetEnableToShoot();
    void Loading();
    void LoadingReload();
    void updateProgressBar();
    void updateProgressBarReload();

    double progressBarValue;
    bool loadingComplete;
    bool labelAdded;
    bool isShotClicked;
};

#endif // MAINWINDOW_H
