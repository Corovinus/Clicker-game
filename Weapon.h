#ifndef WEAPON_H
#define WEAPON_H

#include <QString>
#include <QObject>

class Weapon: public QObject {
    Q_OBJECT
protected:
    int damage;
    int atk_speed;
    QString name;
public:
    explicit Weapon(QObject *parent = nullptr);
    virtual void Shoot() = 0;
    virtual void Reload() = 0;
};

#endif // WEAPON_H
