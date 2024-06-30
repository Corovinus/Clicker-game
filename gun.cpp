#include "gun.h"
#include <iostream>


////////////////////////////////////////////////////////
/// \brief Gun::Gun
////////////////////////////////////////////////////////


Gun::Gun(QObject *parent) : Weapon(parent) {
}
void Gun::Shoot(){
    if (CheckAmmo()) {
        return;
    }
    ammo--;
}
void Gun::Reload()  {
    ammo = max_ammo;
}
bool Gun::CheckAmmo() {
        if (ammo == 0) {
            return true;
        }
        return false;
}


//////////////////////////////////////////////////////////
/// \brief Pistolet::Pistolet
/// //////////////////////////////////////////////////////


Pistolet::Pistolet(QObject *parent) : Gun(parent) {
    max_ammo = 14;
    ammo = max_ammo;
    atk_speed = 4000;
    reloadSpeed = 1000;
    damage = 1;
    name = "Pistolet";
}


/////////////////////////////////////////////////////////
/// \brief Machinegun::Machinegun
/////////////////////////////////////////////////////////


Machinegun::Machinegun(QObject *parent) : Gun(parent) {
    max_ammo = 100;
    ammo = max_ammo;
    atk_speed = 25000;
    reloadSpeed = 6000;
    damage = 1;
    name = "Machinegun";
}


/////////////////////////////////////////////////////////
/// \brief AWM::AWM
/////////////////////////////////////////////////////////


AWM::AWM(QObject *parent) : Gun(parent) {
    max_ammo = 5;
    ammo = max_ammo;
    atk_speed = 500;
    reloadSpeed = 2000;
    damage = 20;
    name = "AWM";
}


////////////////////////////////////////////////////////
/// \brief Bazoo::Bazoo
////////////////////////////////////////////////////////


Bazoo::Bazoo(QObject *parent) : Gun(parent) {
    max_ammo = 1;
    ammo = max_ammo;
    atk_speed = 400;
    reloadSpeed = 4000;
    damage = 40;
    name = "Bazoo";
}
