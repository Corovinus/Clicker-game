#include "weapon.h"

Weapon::Weapon(QObject *parent) : QObject(parent) {
    max_ammo = -1;
    ammo = -1;
}
