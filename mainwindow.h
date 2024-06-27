#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "player.h"
#include "weapon_shop.h"
#include "upgrade_shop.h"
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
    void addLabel();
    void removeLabel();

    void on_pushButton_Player_clicked();

private:
    bool labelAdded;
    QPropertyAnimation* _propertyAnimation;
    QTimer *atk_Timer;
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    Weapon_shop *shopWidget;
    upgrade_shop *upgradeWidget;
    Player player;
    QVBoxLayout *layout;
    QLabel *newLabel;
    void Loading();
    void updateProgressBar();
    int progressBarValue;
    bool loadingComplete;
};

#endif // MAINWINDOW_H
