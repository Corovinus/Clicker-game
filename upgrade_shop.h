#ifndef UPGRADE_SHOP_H
#define UPGRADE_SHOP_H

#include <QMainWindow>

namespace Ui {
class upgrade_shop;
}

class upgrade_shop : public QMainWindow
{
    Q_OBJECT

public:
    explicit upgrade_shop(QWidget *parent = nullptr);
    ~upgrade_shop();
signals:
    void returnToMain();
private:
    Ui::upgrade_shop *ui;
};

#endif // UPGRADE_SHOP_H
