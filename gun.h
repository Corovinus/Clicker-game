#ifndef GUN_H
#define GUN_H

#include "weapon.h"
#include <iostream>

class Gun: public Weapon {
public:
    explicit Gun(QObject *parent = nullptr);

    void Shoot() override;
    void Reload() override;
    virtual void GetAmmo() = 0;

    bool CheckAmmo();

protected:
    int max_ammo;
    int ammo;
};

#endif // GUN_H
