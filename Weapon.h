#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <QString>
#include <QObject>
#include <QWidget>
class Weapon: public QObject {
    Q_OBJECT
public:
    int ammo;
    int max_ammo;
    int damage;
    int atk_speed;
    int reloadSpeed;
    QString name;
    explicit Weapon(QObject *parent = nullptr);
    virtual void Shoot() = 0;
    virtual void Reload() = 0;
};

#endif // WEAPON_H
