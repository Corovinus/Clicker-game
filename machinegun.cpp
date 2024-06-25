#include "machinegun.h"
#include <iostream>

Machinegun::Machinegun(QObject *parent) : Gun(parent) {
    max_ammo = 100;
    ammo = max_ammo; // Initialize the ammo to the maximum value
}
