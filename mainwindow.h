#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "player.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void on_pushButton_Shoot_clicked();
    void UpdateStats();
    void on_pushButton_Reload_clicked();

private:
    Ui::MainWindow *ui;
    Player player; // Добавляем объект Player
};

#endif // MAINWINDOW_H
