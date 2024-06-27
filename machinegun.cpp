#include "machinegun.h"
#include <iostream>

Machinegun::Machinegun(QObject *parent) : Gun(parent) {
    max_ammo = 10;
    ammo = max_ammo;
    atk_speed = 5;
}
