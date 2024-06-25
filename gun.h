#ifndef GUN_H
#define GUN_H

#include "weapon.h"
#include <iostream>

class Gun: public Weapon {
public:
    explicit Gun(QObject *parent = nullptr);

    void Shoot() override;
    void Reload() override;
    bool CheckAmmo();
};

#endif // GUN_H
