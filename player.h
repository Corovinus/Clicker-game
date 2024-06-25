#ifndef PLAYER_H
#define PLAYER_H

#include "machinegun.h"
#include <QObject>
class Player : public QObject {
    Q_OBJECT
public:
    int hp;
    int money;
    Weapon* weapon;

    Player();
    ~Player();
    void Reload();

public slots:
    void Shoot();
};

#endif // PLAYER_H
