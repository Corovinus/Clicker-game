#ifndef PLAYER_H
#define PLAYER_H

#include "gun.h"
#include <QObject>
#include "enemy.h"

class Enemy; // Forward declaration

class Player : public QObject {
    Q_OBJECT
public:
    int max_hp;
    int hp;
    int money;
    Weapon* weapon;

    Player();
    ~Player();
    void Reload();

public slots:
    void Shoot(Enemy* enemy);
};

#endif // PLAYER_H
